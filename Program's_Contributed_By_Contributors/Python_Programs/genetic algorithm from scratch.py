#!/usr/bin/env python
# coding: utf-8

# In[12]:


import pandas as pd
import numpy as np


# In[25]:


N = 3
q = 3


# In[20]:


themap = np.zeros((N,N))
themap
        
        
        


# In[21]:


themap[0][2]


# In[23]:


for i in range(0,N):
    for j in range(0,i):
        print(themap[i][j])
        


# In[31]:


i = 0
j = 0

while (i<N):
    
    while(j<i):
        print(themap[i][j])
            


# In[17]:


themap


# In[ ]:




