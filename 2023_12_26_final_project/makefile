temp: main.o temp_function.o
	cc -Wall -o temp.out main.o temp_function.o
	rm *.o

main: main.c defines.h temp_function.h
	cc -c -Wall main.c

temp_function: temp_function.c defines.h temp_function.h
	cc -c -Wall temp_function.c

clean:
	rm *.o
