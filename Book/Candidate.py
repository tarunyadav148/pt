import numpy as np

import pandas as pd

 

data = pd.read_csv('a1.csv')

ip = np.array(data.iloc[:,0:-1])

lbls = np.array(data.iloc[:,-1])

 

def find_hypotheses(ip, labels):

    specific_hypothesis = ip[0].copy()

    print("\nInitialization of specific_hypothesis and general_hypothesis")

    print("\nSpecific Boundary: ", specific_hypothesis)

    general_hypothesis = [["?" for i in range(len(specific_hypothesis))] for i in range(len(specific_hypothesis))]

    print("\nGeneric Boundary: ", general_hypothesis)  

 

    for i, instance in enumerate(ip):

        if lbls[i] == "yes":

            for x in range(len(specific_hypothesis)):

                if instance[x] != specific_hypothesis[x]:                    

                    specific_hypothesis[x] = '?'                    

                    general_hypothesis[x][x] = '?'

                   

        if lbls[i] == "no":            

            for x in range(len(specific_hypothesis)):

                if instance[x] != specific_hypothesis[x]:                    

                    general_hypothesis[x][x] = specific_hypothesis[x]                

                else:                    

                    general_hypothesis[x][x] = '?'        

       

        print("Specific Boundary after ", i+1, "Instance is ", specific_hypothesis)        

        print("Generic Boundary after ", i+1, "Instance is ", general_hypothesis)

        print("\n")

 

    indices = [i for i, val in enumerate(general_hypothesis) if val == ['?', '?', '?', '?', '?', '?']]    

    for i in indices:  

        general_hypothesis.remove(['?', '?', '?', '?', '?', '?'])

    return specific_hypothesis, general_hypothesis

 

final_specific_h, final_general_h = find_hypotheses(ip, labels)

 

print("Final Specific Hypothesis: ", final_specific_h, sep="\n")

print("Final General Hypothesis: ", final_general_h, sep="\n")