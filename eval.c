#include <stdio.h>
#include <math.h>

const double alpha = 0.01;
int USR[20] = {21,7,5,15,30,8,12,25,18,6,22,9,14,28,11,19,4,16,23,10};
int IRR[20] = {0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,0,1};
int IST[20] = {0,1,0,1,0,1,1,0,1,1,0,1,1,0,1,0,1,1,0,1};
int n = sizeof(USR)/sizeof(USR[0]);

double sigmoid(double z){
    return (1)/(1+exp(-z));
}

int main(void){
    double w0=0.1, w1=0.1, w2=0.1;
    double s0, s1, s2;
    
    // Train model
    for(int ep = 1; ep < 100000; ep++){
        s0=0; s1=0; s2=0;
        for(int pos = 0; pos < n; pos++){
            double z = w0 + w1*USR[pos] + w2*IRR[pos];
            double pred = sigmoid(z);
            double error = pred - IST[pos];
            s0 += error;
            s1 += error * USR[pos];
            s2 += error * IRR[pos];
        }
        double prev_w0 = w0, prev_w1 = w1, prev_w2 = w2;
        w0 -= alpha * s0/n;
        w1 -= alpha * s1/n;
        w2 -= alpha * s2/n;
        
        if(fabs(w0-prev_w0) < 0.0001 && fabs(w1-prev_w1) < 0.0001 && fabs(w2-prev_w2) < 0.0001){
            printf("Converged at epoch %d\n", ep);
            break;
        }
    }
    
    int correct = 0;
    int tp=0, fp=0, tn=0, fn=0;
    
    printf("\nPredictions vs Actual:\n");
    for(int i = 0; i < n; i++){
        double z = w0 + w1*USR[i] + w2*IRR[i];
        double prob = sigmoid(z);
        int pred = prob > 0.5 ? 1 : 0;
        
        printf("USR:%2d IRR:%d -> Pred:%d Actual:%d (%.3f)\n", 
               USR[i], IRR[i], pred, IST[i], prob);
        
        if(pred == IST[i]) correct++;
        
        if(pred == 1 && IST[i] == 1) tp++;
        else if(pred == 1 && IST[i] == 0) fp++;
        else if(pred == 0 && IST[i] == 0) tn++;
        else fn++;
    }
    
    double accuracy = (double)correct / n;
    double precision = tp > 0 ? (double)tp / (tp + fp) : 0;
    double recall = tp > 0 ? (double)tp / (tp + fn) : 0;
    
    printf("\nPerformance Metrics:\n");
    printf("Accuracy:  %.1f%% (%d/%d)\n", accuracy*100, correct, n);
    printf("Precision: %.1f%%\n", precision*100);
    printf("Recall:    %.1f%%\n", recall*100);
    printf("\nConfusion Matrix:\n");
    printf("       Pred\n");
    printf("     0   1\n");
    printf("A 0 %2d  %2d\n", tn, fp);
    printf("c 1 %2d  %2d\n", fn, tp);
    
    return 0;
}
