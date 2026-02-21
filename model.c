#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double alpha = 0.01;
int USR[20] = {21,7,5,15,30,8,12,25,18,6,22,9,14,28,11,19,4,16,23,10};
int IRR[20] = {0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,0,1};
int IST[20] = {0,1,0,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,0,1};
double Ps[20];
int n = sizeof(USR)/sizeof(USR[0]);
double s0,s1,s2;
int epLimit = 100000;

double sigmoid(double z){ return (1)/(1+exp(-z)); }

int main(int AC, char *ARG[]){
    double w0=0.1;double w1=0.1;double w2=0.1;
    double z,error;
    for(int ep = 1 ; ep < epLimit ; ep++){
        s0=0;s1=0;s2=0;
        for(int pos  = 0; pos < n ; pos++){
            z=w0+(w1)*(USR[pos])+(w2)*(IRR[pos]);
            Ps[pos]=sigmoid(z);
            error = (Ps[pos]-IST[pos]);
            s0 += error;
            s1 += (error)*(USR[pos]);
            s2 += (error)*(IRR[pos]);
        }
        double prev_w0 = w0,prev_w1 = w1,prev_w2 = w2;
        w0 = w0 - alpha*(s0/n) ;
        w1 = w1 - alpha*(s1/n) ;
        w2 = w2 - alpha*(s2/n) ;
        if ( fabs(w0-prev_w0) < 0.0001 && fabs(w1-prev_w1) < 0.0001 && fabs(w2-prev_w2) < 0.0001){
            z = w0 + (w1)*(atof(ARG[1])) + (w2)*(atof(ARG[2]));
            int prediction = sigmoid(z) > 0.5 ? 1 : 0 ;
            if(!prediction){putchar('1');exit(EXIT_SUCCESS);}
            else{putchar('0');exit(EXIT_SUCCESS);}
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}

