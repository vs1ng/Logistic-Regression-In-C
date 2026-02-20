#include <complex.h>
#include <stdio.h>
#include <math.h>

int USR[20] = {21,7,5,15,30,8,12,25,18,6,22,9,14,28,11,19,4,16,23,10};
int IRR[20] = {0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,0,1};
int IST[20] = {0,1,0,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,0,1};
double Ps[20];
int n = sizeof(USR)/sizeof(USR[0]);

double sigmoid(double z){
    double p = (1)/(1+exp(-z));
    return p;
}

int main(void){
    double w0=0.1;
    double w1=0.1;
    double w2=0.1;
    double z;
    for(int pos  = 0; pos < n ; pos++){
        z=w0+(w1)*(USR[pos])+(w2)*(IRR[pos]);
        Ps[pos]=sigmoid(z);
        printf("z = %f\tsigmoid = %f\n",z,Ps[pos]);
    }
    return 0;
}

