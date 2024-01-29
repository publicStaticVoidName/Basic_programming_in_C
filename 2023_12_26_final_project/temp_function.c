#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>

#include "defines.h"

struct option longopts[] =
{
{"help", no_argument, NULL, 'h'},
{"filename", optional_argument, NULL, 'f'},
{"month", required_argument, NULL, 'm'},
{NULL, 0, NULL, 0}
};

void print_data(struct data log)
{
	printf("%hu\t%hhu\t%hhu\t%hhu\t%hhu\t%hhd\n",
			log.year,
			log.month,
			log.day,
			log.hour,
			log.minute,
			log.temperature);
}

void help(void)
{
	puts("./temp.out output temperature statistics from file\n");
	puts("-h, --help\t\t\t\tshow this hekptext\n");
	puts("-f\"<filename>\", -f<filename>\t\ttake data from <filename>");
	puts("--filename=<filename>\n");
	puts("-m <number>, -m\"<number>\"\t\tshow statistics only for the month with <number>");
	puts("--month=<number>, --month <number>\n");
}

int get_month(char *optarg)
{
	int len = strlen(optarg);

	if (len == 1)
	{
		if (optarg[0] > '0' && optarg[0] <= '9')
		{
			return optarg[0] - '0';
		}
	}
	else if (len == 2)
	{
		if (optarg[0] == '1' && optarg[1] >= '0' && optarg[1] <= '2')
		{
			return (optarg[0] - '0') * 10 + optarg[1] - '0';
		}
	}

	return -1;
}

void get_arg(int argc, char **argv, char **filename, int *m)
{
	int opt = getopt_long(argc, argv, "hf::m:", longopts, 0);

	do
	{
		switch (opt)
		{
			case 'h':
				help();
				exit(0);
				break;

			case 'f':
				*filename = optarg ? optarg : "temperature_small.csv";
				// printf("filename = %s\n", *filename);
				break;

			case 'm':
				*m = get_month(optarg);
				// printf("m = %d\n", *m);
				if (*m == -1)
				{
					puts("Error: m = 1..12");
				}
				break;

			case '?':
				help();
				break;

			default:
				break;
		}

		opt = getopt_long(argc, argv, "hf::m:", longopts, 0);
	}
	while (opt != -1);
}


int get_data(char *filename,
			 char *format,
			 struct data **log,
			 unsigned int *log_line_counter,
			 unsigned int **bad_str_arr,
			 unsigned int *bad_str_arr_len)
{
	unsigned int num_of_valid_args, line_counter = 1;
	struct data temp_data = {2000, 12, 31, 23, 59, -99};
	unsigned int *temp_arr = NULL;
	struct data *temp_log = NULL;

	FILE *f;
	f = fopen(filename, "r");

	if (f == NULL)
	{
		perror("Error opening file");
		return -1;
	}

	while (!feof(f))
	{
		num_of_valid_args = fscanf(f, format,
									&temp_data.year,
									&temp_data.month,
									&temp_data.day,
									&temp_data.hour,
									&temp_data.minute,
									&temp_data.temperature);

		if (num_of_valid_args != 6)
		{
			if (feof(f))
			{
				break;
			}

			temp_arr = realloc(*bad_str_arr, ++(*bad_str_arr_len) * sizeof(unsigned int));

			if (temp_arr == NULL)
			{
				perror("Memory reallocation error");
				return -1;
			}

				*bad_str_arr = temp_arr;
			(*bad_str_arr)[*bad_str_arr_len - 1] = line_counter;

			while (fgetc(f) != '\n') {}
		}
		else
		{
			temp_log = (struct data *) realloc(*log, ++(*log_line_counter) * sizeof(struct data));

			if (temp_log == NULL)
			{
				perror("Memory reallocation error");
				return -1;
			}

			*log = temp_log;
			(*log)[*log_line_counter - 1] = temp_data;
		}
		line_counter++;
	}
	if (fclose(f) == -1)
	{
		perror("Error closing file");
		return -1;
	}

	return 0;
}


void analyze_data(struct data *log,
				 unsigned int log_line_counter,
				 struct statistics *list_of_stat,
				 unsigned int list_of_stat_len)
{
	for (unsigned int i = 0; i < log_line_counter; i++)
	{
		list_of_stat[0].sum_of_temp += log[i].temperature;

		for (unsigned int j = 0; j < list_of_stat_len; j++)
		{
			if (list_of_stat[j].month == log[i].month)
			{
				list_of_stat[j].num_of_val++;
				list_of_stat[j].sum_of_temp += log[i].temperature;

				if (list_of_stat[j].min > log[i].temperature)
				{
					list_of_stat[j].min = log[i].temperature;
				}

				if (list_of_stat[j].max < log[i].temperature)
				{
					list_of_stat[j].max = log[i].temperature;
				}
			}
		}
	}

	for (unsigned int i = 1; i < list_of_stat_len; i++)
	{
		if (list_of_stat[0].min > list_of_stat[i].min)
		{
			list_of_stat[0].min = list_of_stat[i].min;
		}

		if (list_of_stat[0].max < list_of_stat[i].max)
		{
			list_of_stat[0].max = list_of_stat[i].max;
		}
	}
}

void print_bad_line_num(unsigned int *bad_str_arr, unsigned int bad_str_arr_len)
{
	if (bad_str_arr_len)
	{
		puts("\nIncorrect line numbers:");
		for (unsigned int i = 0; i < bad_str_arr_len; i++)
		{
			printf("%u ", *(bad_str_arr + i));
		}
		puts("");
	}
}


void print_month_stat(struct statistics *list_of_stat, unsigned int list_of_stat_len, int m)
{
	if (m != -1)
	{
		if (list_of_stat[m].num_of_val != 0)
		{
			puts("\nMonth statistics\nmonth\tmin\tmax\t mean");
			printf("%2d\t%3d\t%3d\t%6.2f\n", m, list_of_stat[m].min, list_of_stat[m].max, (double) list_of_stat[m].sum_of_temp / list_of_stat[m].num_of_val);
		}
		else
		{
			puts("\nNo data from this month");
		}
	}
	else
	{
		puts("\nMonth statistics\nmonth\tmin\tmax\t mean");
		for (unsigned int i = 1; i < list_of_stat_len; i++)
		{
			if (list_of_stat[i].num_of_val == 0)
			{
				continue;
			}
			else
			{
				printf("%2d\t%3d\t%3d\t%6.2f\n", i, list_of_stat[i].min, list_of_stat[i].max, (double) list_of_stat[i].sum_of_temp / list_of_stat[i].num_of_val);
			}
		}
	}
}
