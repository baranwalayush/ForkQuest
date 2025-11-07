import pandas as pd
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt

data = {
    'Feature1': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    'Feature2': [10, 8, 9, 7, 6, 5, 4, 3, 2, 1],
    'Target': [0, 0, 0, 0, 1, 1, 1, 1, 1, 1]  
}
df = pd.DataFrame(data)

X = df[['Feature1', 'Feature2']]
y = df['Target']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

dtree = DecisionTreeClassifier(random_state=42, max_depth=3) 
dtree.fit(X_train, y_train)

y_pred = dtree.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy: {accuracy:.2f}")

plt.figure(figsize=(10, 8))
plot_tree(dtree, feature_names=X.columns, class_names=['Class 0', 'Class 1'], filled=True)
plt.show()