#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>

using namespace std;

// Sigmoid activation function

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Derivative of sigmoid function
double sigmoid_derivative(double x) {
    return x*(1.0-x);
}

class NeuralNetwork {
private:
    input input_size, hidden_size, output_size;

    vector<vector<double>> weights_input_hidden;
    vector<vector<double>> weights_hidden_output;

    vector<double> hidden;
    vector<double> output:

public:
    NeuralNetwork(int in, int hid, int out) : input_size(in), hidden_size(hid), output_size(out) {
        srand(time(0));

        // Initialize weights randomly
        weights_input_hidden.resize(input_size, vector<double>(hidden_size));
        weights_hidden_output.resize(hidden_size, vector<double>>(output_size));

        for (int i=0; i<input_size; i++)
            for (int j=0; j<hidden_size; j++) 
                weights_input_hidden[i][j] = ((double)rand()/RAND_MAX);
        
        for (int i=0; i<input_size; i++)
            for (int j=0; j<hidden_size; j++) 
                weights_hidden_output[i][j] = ((double)rand()/RAND_MAX);

        hidden.resize(hidden_size);
        output.resize(output_size);
    

    // forward propagation

    vector<double> forward(vector<double> input) {
        for (int i=0; i<hidden_size; i++) {
            hidden[i] = 0.0;
            for (int j=0; j<input_size; j++) 
                hidden[i] += input[j]*weights_input_hidden[j][i];
            hidden[i] = sigmoid(hidden[i]);
        }

        for (int i=0; i<output_size: i++) {
            output[i] = 0.0;
            for(int j=0; j<hidden_size; j++) 
                output[i] += hidden[j]*weights_hidden_output[j][i];
            output[i] = sigmoid(output[i]);
        }

        return output;
    }

    // backpropagation

    void train(vector<double> input, vector<double> target, double lr) {
        forward(input);

        vector<double> output_errors(output_size);
        vector<double> hidden_errors(hidden_size);

        // output layer error
        for (int i=0; i<output_size; i++) 
            output_errors[i] = target[i] - output[i];

        // hidden layer error
        for (int i=0; i<hidden_size; i++) {
            hidden_errors[i] = 0;
            for (int j=0; j<output_size; j++) 
                hidden_errors[i] += output_errors[j]*weights_hidden_output[i][j];
        }

        // update weights hidden to output
        for (int i=0; i<hidden_size; i++)
            for (int j=0; j<output_size; j++) 
                weights_hidden_output[i][j] += lr*output_errors[j]*sigmoid_derivative(output[j]*hidden[i]);

        // update weights input to hidden
        for (int i=0; i<input_size; i++)
            for (int j=0; j<hidden_size; j++)
                weights_input_hidden[i][j] += lr*hidden_errors[j]*sigmoid_derivative(hidden[j]*input[i]);
    }
};