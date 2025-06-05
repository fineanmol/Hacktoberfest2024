#Data visualization
# Import libraries
from matplotlib import pyplot as plt
import numpy as np


# Creating dataset
Btech_colleges = ['Galgotias', 'dtu', 'iit',
		'iiit', 'nsut']
data=np.array([90,87,95,78,80])
# Creating plot
fig = plt.figure(figsize =(10, 6))
plt.pie(data, labels = Btech_colleges, autopct='%1.1f%%', shadow=True, startangle=90)

# show plot
plt.axis('equal')
plt.title('Top btech colleges placement ratio')
plt.show()
