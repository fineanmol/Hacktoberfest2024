import numpy as np

# Define a sigmoid activation function
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# Define the derivative of the sigmoid function
def sigmoid_derivative(x):
    return x * (1 - x)

# Define the neural network class
class NeuralNetwork:
    def __init__(self, input_size, hidden_size, output_size):
        # Initialize the weights with random values
        self.weights_input_hidden = np.random.uniform(-1, 1, (input_size, hidden_size))
        self.weights_hidden_output = np.random.uniform(-1, 1, (hidden_size, output_size))

    def forward(self, inputs):
        # Perform forward propagation
        self.hidden_layer_input = np.dot(inputs, self.weights_input_hidden)
        self.hidden_layer_output = sigmoid(self.hidden_layer_input)
        self.output_layer_input = np.dot(self.hidden_layer_output, self.weights_hidden_output)
        self.output_layer_output = sigmoid(self.output_layer_input)
        return self.output_layer_output

    def backward(self, inputs, targets, learning_rate):
        # Calculate the error
        output_error = targets - self.output_layer_output

        # Calculate the deltas and update the weights
        delta_output = output_error * sigmoid_derivative(self.output_layer_output)
        output_adjustment = np.dot(self.hidden_layer_output.T, delta_output)
        delta_hidden = np.dot(delta_output, self.weights_hidden_output.T) * sigmoid_derivative(self.hidden_layer_output)
        hidden_adjustment = np.dot(inputs.T, delta_hidden)

        self.weights_hidden_output += learning_rate * output_adjustment
        self.weights_input_hidden += learning_rate * hidden_adjustment

    def train(self, inputs, targets, learning_rate, epochs):
        for _ in range(epochs):
            for i in range(len(inputs)):
                input_data = np.array(inputs[i])
                target_data = np.array([targets[i]])
                self.forward(input_data)
                self.backward(input_data, target_data, learning_rate)

    def predict(self, inputs):
        predictions = []
        for i in range(len(inputs)):
            input_data = np.array(inputs[i])
            output = self.forward(input_data)
            predictions.append(output)
        return predictions

# Example usage
if __name__ == "__main__":
    # Define the training data
    inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    targets = np.array([0, 1, 1, 0])

    # Create and train the neural network
    input_size = 2
    hidden_size = 4
    output_size = 1
    learning_rate = 0.1
    epochs = 10000

    nn = NeuralNetwork(input_size, hidden_size, output_size)
    nn.train(inputs, targets, learning_rate, epochs)

    # Make predictions
    test_inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    predictions = nn.predict(test_inputs)

    # Print the predictions
    for i in range(len(test_inputs)):
        print(f"Input: {test_inputs[i]}, Prediction: {predictions[i][0]:.2f}")
