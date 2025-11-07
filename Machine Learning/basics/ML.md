kmeans.py — K-Means Clustering from Scratch
- K-Means is an unsupervised learning algorithm used to partition data into k clusters based on similarity.

Class: KMeans
__init__(self, n_clusters=3, n_iterations=100)
--Initializes the clustering model.

Parameters:
n_clusters: Number of clusters to form.
n_iterations: Maximum number of iterations for convergence.

Attributes:
centroids: Stores the coordinates of cluster centers.

fit(self, X): Trains the model by finding optimal centroids.

Steps:
Randomly selects centroids from the dataset.

Iteratively:
Assigns each point to the nearest centroid.
Updates centroids based on the mean of assigned points.
Stops if centroids do not change (convergence).

predict(self, X)
--Assigns new data points to the nearest cluster.
Returns: Array of cluster labels.

_assign_clusters(self, X)
--Computes Euclidean distance from each point to each centroid.
Returns: Index of the closest centroid for each point.

linear_regression.py — Linear Regression from Scratch
- Linear Regression models the relationship between input features and a continuous target variable using a straight line.

Class: LinearRegressor
__init__(self, learning_rate, n_iterations)
--Initializes the model.

Parameters:
learning_rate: Step size for gradient descent.
n_iterations: Number of training iterations.

Attributes:
weights: Coefficients for input features.
Intercept term.

fit(self, X, y)
--Trains the model using gradient descent.

Steps:
Initializes weights and bias to zero.

Iteratively:
Predicts output using current weights and bias.
Computes gradients of loss w.r.t. weights and bias.
Updates weights and bias using gradients.

predict(self, X)
-- Predicts target values for input data.
Returns: Array of predicted values.

logistic_regression.py — Logistic Regression from Scratch
Overview
Logistic Regression is a classification algorithm that models the probability of a binary outcome using the sigmoid function.

Class: LogisticRegressor
__init__(self, learning_rate=0.01, n_iterations=1000)
Purpose: Initializes the model.

Parameters:
learning_rate: Step size for gradient descent.
n_iterations: Number of training iterations.

Attributes:
weights: Coefficients for input features.
bias: Intercept term.

fit(self, X, y)
--Trains the model using gradient descent.

Steps:
Initializes weights and bias to zero.

Iteratively:
Computes linear combination of inputs and weights.
Applies sigmoid.
Computes gradients of loss w.r.t. weights and bias.
Updates weights and bias.

predict(self, X)
Purpose: Predicts binary class labels.

Steps:
Applies sigmoid to linear model output.
Converts probabilities to class labels (0 or 1).


