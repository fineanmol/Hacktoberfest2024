import numpy as np
X_train = np.array([
    [1, 1, 0, 1], [0, 1, 0, 1], [1, 0, 1, 0], [0, 0, 1, 1], [0, 1, 0, 0], [0, 0, 1, 0], [1, 1, 0, 1], [1, 0, 1, 0]
])
y_train = np.array([1, 1, 0, 0, 1, 0, 1, 0])
X_test = np.array([
    [1, 0, 0, 1], [0, 1, 1, 1], [1, 0, 1, 1], [0, 0, 0, 1], [1, 1, 0, 0]
])
y_test = np.array([1, 1, 0, 0, 1])
alpha = 0.01
X_train = np.c_[np.ones((X_train.shape[0], 1)), X_train]  
X_train_T = np.transpose(X_train)
X_train_T_X_train = np.dot(X_train_T, X_train)
X_train_T_X_train_regularized = X_train_T_X_train + alpha * np.identity(X_train.shape[1])
X_train_T_X_train_inv = np.linalg.inv(X_train_T_X_train_regularized)
X_train_T_y_train = np.dot(X_train_T, y_train)
beta = np.dot(X_train_T_X_train_inv, X_train_T_y_train)
X_test = np.c_[np.ones((X_test.shape[0], 1)), X_test]
y_pred = np.dot(X_test, beta)
error = y_test - y_pred
mse = np.mean(error ** 2)
print("Mean Squared Error (MSE):", mse)