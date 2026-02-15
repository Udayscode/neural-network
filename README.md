# XOR Neural Network in C++

---

**Overview**

This project implements a small feedforward neural network in C++.
The network is trained to learn the XOR function using backpropagation.

No external machine learning libraries are used.
All computations are written manually using standard C++.

---

**Problem Description**

The XOR function produces the following outputs:

| Input A | Input B | Output |
|---------|---------|--------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

XOR is not linearly separable.
A single-layer perceptron cannot represent this function.
At least one hidden layer with nonlinear activation is required.

---

**Network Architecture**

- **2 input neurons**
- **2 hidden neurons**
- **1 output neuron**

Each hidden and output neuron applies the **sigmoid activation function**.

Bias terms are included in both hidden and output layers.
Bias shifts the activation function and allows non-zero decision boundaries.

---

**Training Method**

The network is trained using gradient descent.

- Forward propagation computes activations.
- Error is calculated as the difference between predicted and target values.
- Backpropagation computes gradients using the chain rule.
- Weights and biases are updated after each training example.

Default parameters:

- Epochs: `50000`
- Learning rate: `0.5`

---

**Compilation**

```bash
g++ xor_nn.cpp -o xor_nn -std=c++17
```

**Execution**
```bash
./xor_nn
```
---
**Expected Output**

After training, the outputs should approximate:
```bash
0 XOR 0 => raw: ~0.02 | predicted: 0
0 XOR 1 => raw: ~0.98 | predicted: 1
1 XOR 0 => raw: ~0.97 | predicted: 1
1 XOR 1 => raw: ~0.03 | predicted: 0
```
Exact values may vary due to random initialization.
---
**Implementation Notes**

Forward propagation computes weighted sums followed by sigmoid activation.

- Backpropagation computes output error first.
- The error is propagated to the hidden layer.
- Weights are updated using the gradient of the sigmoid function.
- Bias values are updated in the same way as weights.
- Random initialization uses values in the range [-1, 1].
- This improves convergence compared to only positive initialization.
