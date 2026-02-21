#include <complex.h>
#include <stdio.h>
#include <math.h>

const double alpha = 0.01;
int USR[20] = {21,7,5,15,30,8,12,25,18,6,22,9,14,28,11,19,4,16,23,10};
int IRR[20] = {0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,0,1};
int IST[20] = {0,1,0,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,0,1};
double Ps[20];
int n = sizeof(USR)/sizeof(USR[0]);
double s0,s1,s2;
int epLimit = 10;

double sigmoid(double z){
    double p = (1)/(1+exp(-z));
    return p;
}

int main(void){
    double w0=0.1;double w1=0.1;double w2=0.1;
    double z;
    for(int ep = 1 ; ep < epLimit ; ep++){
        s0=0;s1=0;s2=0;
        for(int pos  = 0; pos < n ; pos++){
            z=w0+(w1)*(USR[pos])+(w2)*(IRR[pos]);
            Ps[pos]=sigmoid(z);
            //printf("z = %f\tsigmoid = %f\n",z,Ps[pos]);
            s0 += (Ps[pos]-IST[pos]);
            s1 += (Ps[pos]-IST[pos])*(USR[pos]);
            s2 += (Ps[pos]-IST[pos])*(IRR[pos]);
        }
        w0 = w0 - alpha*(s0/n) ;
        w1 = w1 - alpha*(s1/n) ;
        w2 = w2 - alpha*(s2/n) ;
        printf("Epoch: %d\nAdjusted Weights:\n\tw0\t:\t%f\n\tw1\t:\t%f\n\tw2\t:\t%f\n",ep,w0,w1,w2);
    }
    return 0;
}

