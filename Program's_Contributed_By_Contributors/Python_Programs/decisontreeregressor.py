import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeRegressor, plot_tree
import matplotlib.pyplot as plt

house = pd.read_csv('Salary_Data.csv')
x=house['YearsExperience'].values.reshape(-1,1)
y=house['Salary'].values.reshape(-1,1)

x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2,random_state=1)

regressor = DecisionTreeRegressor()
regressor.fit(x_train,y_train)

pred_val = regressor.predict(x_test)

plt.figure(figsize=(12,6))
plot_tree(regressor,filled=True, feature_names=['YearsExperience'])
plt.show()

plt.figure(figsize=(10,6))
plt.scatter(x_test,y_test,color='blue',label="Test")
plt.scatter(x_test,pred_val,color='red',label="predicted")
plt.xlabel('Years')
plt.ylabel('Salary')
plt.legend()
plt.show()
