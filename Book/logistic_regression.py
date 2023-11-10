#%%
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import accuracy_score as ac

def sigmoid(x):
    return 1/(1+np.exp(-x))


def gd(X,y):
   
    X = np.insert(X,0,1,axis=1)
    weights = np.ones(X.shape[1])
    lr = 0.5
   
    for i in range(5000):
        y_hat = sigmoid(np.dot(X,weights))
        weights = weights + lr*(np.dot((y-y_hat),X)/X.shape[0])
       
    return weights[1:],weights[0]

def run():

    df = pd.read_csv('../a2.csv')

    X = np.array(df.iloc[:,0:-1])
    Y = np.array(df.iloc[:,-1])
    print(X.shape)
    weights,c = gd(X,Y)
#     x_input1 = np.linspace(-5,10,100)
#     y_input1 = weights*x_input1 + c
#     plt.figure(figsize=(5,5))
#     plt.plot(x_input1,y_input1,color='black',linewidth=1)
#     plt.scatter(X[:,0],Y)
#     plt.ylim(-5,5)
#     plt.xlim(0,12)
#     plt.show()
    print(weights)
    print(c)

run()
