# logistic reg, in C 
yes that's literally it.

## **92% Precision, 95% Accuracy**

<img width="447" height="258" alt="image" src="https://github.com/user-attachments/assets/2121abc2-8048-4416-b3b9-9ccc412f6f65" />

## Blazing Speed
optimized to respond to real-time inputs from sensor data

<img width="256" height="133" alt="image" src="https://github.com/user-attachments/assets/4e8b2681-6ac7-40ac-b75b-40572c6ef5f8" />

### Usage
1. compile using o3 optimizations and -ffast-math
```
gcc model.c -lm -O3 -ffast-math
```
2. run using arguements as inputs
```
./a.out <ultrasonic reading> <IR reading>
```
