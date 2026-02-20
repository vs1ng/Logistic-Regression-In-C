#include <signal.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#define return 0 r0

int IQ[5] = { 21 , 90 , 30 , 40 , 60 };
int HRS[

int goesWrong(int signal){
    puts("Something went wrong, exiting!");
    exit(EXIT_FAILURE);
}

int main(void){


