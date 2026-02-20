# Model:

1. Initialize weights (w0, w1, w2, w3) to small random values

2. For each iteration:
   
   z = w0 + w1*(IRreading) + w2*(USisThere) + w3*(USdistance)
   
   p = 1 / (1 + e^(-z))  // Sigmoid function
   
3. Update weights using gradient descent:
   
   - w0 = w0 - α * sum(p - isThere)
   - w1 = w1 - α * sum((p - isThere) * IRreading)
   - w2 = w2 - α * sum((p - isThere) * USisThere)
   - w3 = w3 - α * sum((p - isThere) * USdistance)
   
   where α = learning rate (e.g., 0.01)

4. Prediction:
   
   - z = w0 + w1*(IR) + w2*(US) + w3*(distance)
   - probability = 1 / (1 + e^(-z))
   - prediction = probability > 0.5 ? 1 : 0

# Example:

**Data:**
```
IRreading | USisThere | USdistance | isThere
    1     |     1     |     5      |    1
    0     |     1     |    15      |    0  
    1     |     0     |    10      |    1
```

**One Iteration:**

1. Start: w0=0.1, w1=0.1, w2=0.1, w3=0.01

2. Process all rows:
   - Row 1: z = 0.1 + 0.1(1) + 0.1(1) + 0.01(5) = 0.35, p = 0.59
   - Row 2: z = 0.1 + 0.1(0) + 0.1(1) + 0.01(15) = 0.35, p = 0.59  
   - Row 3: z = 0.1 + 0.1(1) + 0.1(0) + 0.01(10) = 0.30, p = 0.57

3. Sum gradients:
   - w0 gradient: (0.59-1) + (0.59-0) + (0.57-1) = -0.25
   - w1 gradient: (0.59-1)(1) + (0.59-0)(0) + (0.57-1)(1) = -0.84
   - w2 gradient: (0.59-1)(1) + (0.59-0)(1) + (0.57-1)(0) = 0.18
   - w3 gradient: (0.59-1)(5) + (0.59-0)(15) + (0.57-1)(10) = 4.55

4. Update weights (α=0.1):
   - w0 = 0.1 - 0.1(-0.25) = 0.125
   - w1 = 0.1 - 0.1(-0.84) = 0.184
   - w2 = 0.1 - 0.1(0.18) = 0.082
   - w3 = 0.01 - 0.1(4.55) = -0.445

That's one complete iteration. Repeat until weights converge.

# Eval:

Accuracy = (correct predictions) / (total predictions)
Log-loss = -sum(y*log(p) + (1-y)*log(1-p)) / n
