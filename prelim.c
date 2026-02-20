#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    double a = atof(argv[1]);
    double p = (1)/(double)(1+(double)pow(M_E,-a));
    printf("P = %f\n",p);
    int prediction = p > 0.5 ? 1 : 0;
    printf("Prediction = %d\n",prediction);
    return 0;
}
