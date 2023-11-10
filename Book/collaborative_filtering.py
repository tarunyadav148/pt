6. collaborativeFiltering.py
import pandas as pd
import numpy as np 
from sklearn.metrics.pairwise import cosine_similarity

ratings_data = pd.read_csv("rating.csv")
user_movie_matrix = ratings_data.pivot(index="userId",columns="movieId",values="rating")
user_movie_matrix = user_movie_matrix.fillna(0)
user_similarity = cosine_similarity(user_movie_matrix)
user_similarity_df = pd.DataFrame(user_similarity,index=user_movie_matrix.index, columns = user_movie_matrix.index)

def findNeighbors (userId, k = 7):
    similar_users = user_similarity_df.loc[userId]
    similar_users = similar_users.sort_values(ascending = False)
    similar_users = similar_users.iloc[1:k+1]
    return similar_users

def predictRating (userId, movieId):
    similar_users = findNeighbors(userId)
    movie_rating = user_movie_matrix.loc[similar_users.index,movieId]
    weighted_rating = similar_users*movie_rating
    predictRating = weighted_rating.sum()/similar_users.sum()
    return predictRating

user_Id = 1
missing_movies = user_movie_matrix.loc[user_Id][user_movie_matrix.loc[user_Id]==0]
predictedRatings = missing_movies.index.to_series().apply(lambda movie_Id:predictRating(user_Id, movie_Id))
print (predictedRatings)