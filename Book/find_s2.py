import pandas as pd
import numpy as np
import os
data = pd.read_csv("a1.csv")
print(data,"\n")

d = np.array(data)[:,:-1]
print(d,"\n")

target = np.array(data)[:,-1]
print(target,"\n")

def train(c,t):
    specific_hypothesis = []
    for i, val in enumerate(t):
        if val == "yes":
            specific_hypothesis = c[i].copy()
            break

    for i, val in enumerate(c):
        if t[i] == "yes":
            for x in range(len(specific_hypothesis)):
                if val[x] != specific_hypothesis[x]:
                    specific_hypothesis[x] = '?'

    return specific_hypothesis

print("\n The final hypothesis is:",train(d,target))
