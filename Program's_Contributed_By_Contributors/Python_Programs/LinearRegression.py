import numpy as np
from sklearn.linear_model import LinearRegression

# Load the training data
X, y = np.loadtxt('train.csv', delimiter=',')

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25)

# Create the linear regression model
model = LinearRegression()


# Fit the model to the training data
model.fit(X_train, y_train)

# Make predictions on the testing data
predictions = model.predict(X_test)

# Evaluate the model performance
mse = np.mean((predictions - y_test)**2)
print('Mean squared error:', mse)

# Save the model to a file
model.save('model.pkl')

# Load the model from a file
model = joblib.load('model.pkl')

# Make predictions on new data
new_data = np.array([[10, 20, 30]])
predictions = model.predict(new_data)

# Print the predictions
print('Predictions:', predictions)
