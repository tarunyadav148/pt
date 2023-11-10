import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = pd.read_csv('data.csv')

Data = data[['X', 'Y']].values

k = 3

np.random.seed(0)
centroids = Data[np.random.choice(Data.shape[0], k, replace=False)]

def euclidean_distance(x1, x2):
    return np.sqrt(np.sum((x1 - x2) ** 2))

max_iterations = 100
tolerance = 0.001
converged = False

for _ in range(max_iterations):
    cluster_assignments = []
    for point in Data:
        distances = [euclidean_distance(point, centroid) for centroid in centroids]
        cluster_assignment = np.argmin(distances)
        cluster_assignments.append(cluster_assignment)

    cluster_assignments = np.array(cluster_assignments)

    old_centroids = centroids.copy()

    for i in range(k):
        cluster_points = Data[cluster_assignments == i]
        if len(cluster_points) > 0:
            centroids[i] = np.mean(cluster_points, axis=0)

    if np.all(np.abs(centroids - old_centroids) < tolerance):
        converged = True
        break

data['Cluster'] = cluster_assignments

plt.scatter(data['X'], data['Y'], c=data['Cluster'], cmap='rainbow')
plt.scatter(centroids[:, 0], centroids[:, 1], s=100, c='black', label='Centroids')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('K-means Clustering (k=3)')
plt.legend()
plt.show()
