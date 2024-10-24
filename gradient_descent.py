import numpy as np
def gradient_descent(x,y):
    w_curr=b_curr=0
    iterations=10000
    n=len(x)
    learning_rate=0.16
    for i in range(iterations):
        y_predicted=w_curr*x+b_curr
        cost=(1/2*n)*sum([val**2 for val in (y_predicted-y)])
        dw=(1/n)*sum(x*(y_predicted-y))
        db=(1/n)*sum(y_predicted-y)
        w_curr-=learning_rate*dw
        b_curr-=learning_rate*db
        print(f'w:{w_curr} b:{b_curr} cost:{cost} iterations:{i+1}')

x=np.array([1,2,3,4,5])
y=np.array([5,7,9,11,13])
gradient_descent(x,y) 
