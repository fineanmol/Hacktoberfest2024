# Import
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

# Generate some sample data
X = np.random.rand(100, 1)  # Features (independent variable)
y = 2 * X + 1 + 0.1 * np.random.rand(100, 1)  # Target (dependent variable)

# Split the data into a training and test set
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create a model
model = LinearRegression()

# Train the model
model.fit(X_train, y_train)

# Make predictions
y_pred = model.predict(X_test)

# Calculate
# Measures the mean squared the difference between the actual value (y_test) and the value predicted by the model (y_pred).
mse = mean_squared_error(y_test, y_pred)
print(f"Mean Squared Error: {mse}")

# Trained model to make predictions on new data
new_data = np.array([[0.8]])
predicted_value = model.predict(new_data)
print(f"Predicted value for new data: {predicted_value[0][0]}")

# yak finsisns
