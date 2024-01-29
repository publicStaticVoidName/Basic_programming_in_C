#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "defines.h"
#include "temp_function.h"

int main(int argc, char **argv)
{
	char *filename = "temperature_small.csv";
	int m = -1;

	char *format = "%u;%u;%u;%u;%u;%d";

	struct data *log = NULL;
	unsigned int log_line_counter = 0;

	unsigned int *bad_str_arr = NULL, bad_str_arr_len = 0;

	unsigned int list_of_stat_len = 13;
	struct statistics list_of_stat[list_of_stat_len];

	for (unsigned int i = 0; i < list_of_stat_len; i++)
	{
		list_of_stat[i].month = i;
		list_of_stat[i].min = 100;
		list_of_stat[i].max = -100;
		list_of_stat[i].num_of_val = 0;
		list_of_stat[i].sum_of_temp = 0;
	}

	get_arg(argc, argv, &filename, &m);
	get_data(filename, format, &log, &log_line_counter, &bad_str_arr, &bad_str_arr_len);

	if (!log_line_counter)
	{
		puts("No data to analyzing");
		return 0;
	}

	list_of_stat[0].num_of_val = log_line_counter;

	analyze_data(log, log_line_counter, list_of_stat, list_of_stat_len);

	print_bad_line_num(bad_str_arr, bad_str_arr_len);

	print_month_stat(list_of_stat, list_of_stat_len, m);

	printf("\nAnnual statistics: min is %d, max is %d, mean is %.2f\n",
			list_of_stat[0].min,
			list_of_stat[0].max,
			(double) list_of_stat[0].sum_of_temp / list_of_stat[0].num_of_val);

	return 0;
}
