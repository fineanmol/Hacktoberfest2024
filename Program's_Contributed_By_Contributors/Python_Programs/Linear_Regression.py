'''
file nume: Linear_Regression.py
author: Chirag Ingle, National Institute Of Technology Karnataka, Surathkal, Mangaluru
'''
import numpy as np
import pandas as pd
import math
import time
b_init = 785.1811367994083
w_init = np.array([ 0.39133535, 18.75376741, -53.36032453, -26.42131618])
print(f"w_init shape: {w_init.shape}, b_init type: {type(b_init)}")

#x_train,y_train are input data
def compute_cost(x,y,w,b):
    '''
    This function calculates the mean square loss for Multiple Input Linear Regression Machine Learning Model.
    Input-X-Training Input
    y=Training Output
    w,b=Parameters
    '''
    tic=time.time_ns()
    cost=0
    m=x.shape[0]
    for i in range(m):
        f_wb=x[i].dot((w))+b
        cost+=(f_wb-y[i])**2/(2*m)
    
    return cost
    
# Compute and display cost using our pre-chosen optimal parameters. 
cost = compute_cost(X_train, y_train, w_init, b_init)
print(f'Cost at optimal w : {cost}')
def compute_gradient(x,y,w,b):
    m=x.shape[0]
    for i in range(m):
        dJ_dw=
tic=time.time_ns()
f_wb=np.multiply(X_train,w_init)
a=np.sum(f_wb,axis=1,keepdims=1)
y_train=y_train.reshape(3,1)
cost=np.square(a+b_init-y_train)
cost/=2*X_train.shape[0]
print(np.sum(cost))
tac=time.time_ns()
print(tac-tic)