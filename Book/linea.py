import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('LR.csv')

income = data['Income'].values
food_expenditure = data['Food Expenditure'].values

X = income
y = food_expenditure

X_mean = sum(X) / len(X)
y_mean = sum(y) / len(y)

numerator = sum((X[i] - X_mean) * (y[i] - y_mean) for i in range(len(X)))
denominator = sum((X[i] - X_mean) ** 2 for i in range(len(X)))
slope = numerator / denominator

intercept = y_mean - slope * X_mean

predicted_food_expenditure = [slope * x + intercept for x in X]


plt.scatter(income, food_expenditure, label='Data Points')
plt.plot(X, predicted_food_expenditure, color='red', label='Best-Fit Line')
plt.xlabel('Income')
plt.ylabel('Food Expenditure')
plt.title('Linear Regression')
plt.legend()
plt.show()

print(
    f"Best-fit line equation: Food Expenditure = {slope:.2f} * Income + {intercept:.2f}")