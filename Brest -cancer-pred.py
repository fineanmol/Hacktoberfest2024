# Import necessary libraries
import numpy as np
import pandas as pd
from sklearn.preprocessing import LabelEncoder


#dataset
dataset = pd.read_csv('data.csv')
X = dataset.iloc[:, 2:32].values
y = dataset.iloc[:, 1].values
dataset.head()

#One Hot Encoding
#  M = malignant = 1, B = benign=0

labelencoder_y = LabelEncoder()
y = labelencoder_y.fit_transform(y)
y = y.tolist()

#KNN
# Run the KNN algorithm from sklearn module of python
from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier()
knn.fit(X,y)
y_knn = knn.predict(X)

#Confusion matrix

# Making the Confusion Matrix
from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y, y_knn)



from sklearn.metrics import accuracy_score
accuracy_score(y,y_knn)
