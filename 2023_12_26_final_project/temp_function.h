void print_data(struct data log);

void help(void);

int get_month(const char * optarg);

void get_arg(int argc, char **argv, char **filename, int *m);

int get_data(char *filename,
			 char *format,
			 struct data **log,
			 unsigned int *log_line_counter,
			 unsigned int **bad_str_arr,
			 unsigned int *bad_str_arr_len);

void analyze_data(struct data *log,
				 unsigned int log_line_counter,
				 struct statistics *list_of_stat,
				 unsigned int list_of_stat_len);

void print_bad_line_num(unsigned int *bad_str_arr, unsigned int bad_str_arr_len);

void print_month_stat(struct statistics *list_of_stat, unsigned int list_of_stat_len, int m);
