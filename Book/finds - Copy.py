import pandas as pd

data = pd.read_csv("a1.csv")
hypothesis = None

for index, row in data.iterrows():
    color, toughness, fungus, appearance, poisonous = row

    if poisonous == "Yes":
        if hypothesis is None:
            hypothesis = row
        else:
            for i in range(len(row)):
                if row[i] != hypothesis[i]:
                    hypothesis[i] = '?'

print("Most Specific Hypothesis:")
print(hypothesis.values)
