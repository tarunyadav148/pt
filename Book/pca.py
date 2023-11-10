import numpy as np
import pandas as pd

df = pd.read_csv('b.csv')

from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()

df.iloc[:,0:2] = scaler.fit_transform(df.iloc[:,0:2])

covariance_matrix = np.cov([df.iloc[:,0],df.iloc[:,1]])
print('Covariance Matrix:\n', covariance_matrix)

eigen_values, eigen_vectors = np.linalg.eig(covariance_matrix)

print("eigen values :" ,eigen_values)
print("eigen vectors :" , eigen_vectors)

pc = eigen_vectors[0:1]
print("principal components: ", pc)

transformed_df = np.dot(df.iloc[:,0:2],pc.T)
new_df = pd.DataFrame(transformed_df,columns=['PC1'])

print("new dataframe : ",new_df)