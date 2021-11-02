import matplotlib.pyplot as plt
Partition = 'Holidays', 'Eating_Out', 'Shopping', 'Groceries'
sizes = [200, 150, 260, 24s0]
fig1, ax1 = plt.subplots()
ax1.pie(sizes, labels=Partition, autopct='%1.1f%%', shadow=True, startangle=90)         
ax1.axis('equal')
plt.show()