#include<stdio.h>
#include<stdlib.h>

void _start(){
	int x = my_func();
	exit(x);
}

int my_func(){
	print("Hello World!\n");
	return 0;
}
