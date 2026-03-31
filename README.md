# Logistic Regression Classifier for Sensor-Based Proximity Detection

A lightweight, high-performance binary classification model implemented in C using logistic regression. Designed for real-time sensor data processing with minimal latency.

## Overview

This project implements a logistic regression model trained to classify proximity events based on dual-sensor input (ultrasonic and IR readings). The model achieves high accuracy while maintaining deterministic inference latency suitable for embedded or real-time systems.

## Performance Metrics

| Metric       | Value  |
|--------------|--------|
| Precision    | 92%    |
| Accuracy     | 95%    |


## **92% Precision, 95% Accuracy**

<img width="447" height="258" alt="image" src="https://github.com/user-attachments/assets/2121abc2-8048-4416-b3b9-9ccc412f6f65" />

## Blazing Speed
optimized to respond to real-time inputs from sensor data

<img width="256" height="133" alt="image" src="https://github.com/user-attachments/assets/4e8b2681-6ac7-40ac-b75b-40572c6ef5f8" />


## Technical Specifications

- **Language**: C (ISO C99)
- **Training Algorithm**: Gradient descent with batch update
- **Decision Function**: Sigmoid activation with 0.5 threshold
- **Input Features**: Ultrasonic sensor reading, IR sensor reading
- **Training Dataset**: 20 labeled samples
- **Convergence Criteria**: Maximum 100,000 epochs or weight change < 1e-4

## Key Features

- **Deterministic Inference**: Fixed execution path with no runtime branching variability
- **Optimized for Latency**: Single inference pass with O(1) complexity
- **Minimal Dependencies**: Only standard C libraries (`stdio.h`, `math.h`, `stdlib.h`)
- **Small Memory Footprint**: No dynamic allocation during inference

## Build Instructions

Compile with optimization flags for maximum inference performance:

```bash
gcc model.c -lm -O3 -ffast-math -o classifier
```

## Usage

Execute the classifier with ultrasonic and IR sensor readings as arguments:

```bash
./classifier <ultrasonic_reading> <ir_reading>
```

### Output
- `1` : Event detected (positive classification)
- `0` : No event detected (negative classification)

### Example

```bash
./classifier 25 1
1
```

## Training Data Summary

The model was trained on 20 labeled samples with the following feature distributions:

- **Ultrasonic Range**: 4–30 (arbitrary units)
- **IR Readings**: Binary (0 or 1)
- **Target Labels**: Binary classification (IST array)

## Implementation Notes

- Weights are initialized to 0.1 for all coefficients
- Learning rate (α) = 0.01
- Batch gradient descent with normalization by sample count
- Sigmoid function implemented via `exp(-z)` for numerical stability

## Limitations and Future Work

- Training set currently limited to 20 samples; performance may improve with larger datasets
- No cross-validation implemented in current version
- Binary features only; IR sensor assumed to output thresholded values
- Potential for L2 regularization to reduce overfitting

