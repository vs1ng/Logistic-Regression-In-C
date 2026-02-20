#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    int a = atoi(argv[1]);
    double p = (1)/(1+pow(M_E,-a));
    printf("P = %f\n",p);
    return 0;
}
