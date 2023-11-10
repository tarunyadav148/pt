import pandas as pd
import math

data = pd.read_csv('a.csv')

def entropy(data):
    target_column = data.keys()[-1]
    entropy = 0
    values = data[target_column].unique()
    for value in values:
        probability = len(data[data[target_column] == value]) / len(data)
        entropy -= probability * math.log2(probability)
    return entropy

def information_gain(data, attribute):
    target_column = data.keys()[-1]
    target_values = data[target_column].unique()
    attribute_values = data[attribute].unique()
    entropy_total = entropy(data)
    entropy_attr = 0
    for value in attribute_values:
        entropy_subset = entropy(data[data[attribute] == value])
        proportion = len(data[data[attribute] == value]) / len(data)
        entropy_attr += proportion * entropy_subset
    return entropy_total - entropy_attr

def select_best_attribute(data):
    attributes = data.keys()[:-1]
    best_attribute = ""
    best_gain = -1
    for attribute in attributes:
        gain = information_gain(data, attribute)
        if gain > best_gain:
            best_gain = gain
            best_attribute = attribute
    return best_attribute

def id3(data, original_data, features):
    target_column = data.keys()[-1]

    if len(data[target_column].unique()) == 1:
        return data[target_column].unique()[0]

    if len(data) == 0 or len(features) == 0:
        return original_data[target_column].mode()[0]

    best_attribute = select_best_attribute(data)
    
    tree = {best_attribute: {}}
    
    features = [i for i in features if i != best_attribute]

    for value in data[best_attribute].unique():
        sub_data = data[data[best_attribute] == value]
        subtree = id3(sub_data, original_data, features)
        tree[best_attribute][value] = subtree

    return tree

def classify(tree, sample):
    for attribute, subtree in tree.items():
        value = sample[attribute]
        if value in subtree:
            if type(subtree[value]) is dict:
                return classify(subtree[value], sample)
            else:
                return subtree[value]

tree = id3(data, data, data.columns[:-1])

Sample1 = {'Outlook': 'Sunny', 'Temperature': 'Mild', 'Humidity': 'Normal', 'Wind': 'Strong'}
Sample2 = {'Outlook': 'Overcast', 'Temperature': 'Mild', 'Humidity': 'High', 'Wind': 'Weak'}
Sample3 = {'Outlook': 'Rain', 'Temperature': 'Cool', 'Humidity': 'High', 'Wind': 'Strong'}
Sample4 = {'Outlook': 'Sunny', 'Temperature': 'Hot', 'Humidity': 'High', 'Wind': 'Weak'}
Sample5 = {'Outlook': 'Rain', 'Temperature': 'Mild', 'Humidity': 'Normal', 'Wind': 'Weak'}

classification1 = classify(tree, Sample1)
classification2 = classify(tree, Sample2)
classification3 = classify(tree, Sample3)
classification4 = classify(tree, Sample4)
classification5 = classify(tree, Sample5)

print("Sample 1 is classified as:", classification1)
print("Sample 2 is classified as:", classification2)
print("Sample 3 is classified as:", classification3)
print("Sample 4 is classified as:", classification4)
print("Sample 5 is classified as:", classification5)
