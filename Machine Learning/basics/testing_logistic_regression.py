import numpy as np
from logistic_regression import LogisticRegressor

# Dataset for testing 
X = np.array([[1], [2], [3], [4]])
y = np.array([0, 0, 1, 1])

model = LogisticRegressor(learning_rate=0.01, n_iterations=1000)
model.fit(X,y)

preds = model.predict(X)
print(f"Predictions: {preds}")

errors = (y + preds) == 1
num_errors = np.sum(errors)
accuracy = (1 - (num_errors/len(y))) * 100

print(f"Accuracy of the prediction: {accuracy}%")