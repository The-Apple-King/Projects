import numpy as np
import matplotlib.pyplot as plt
from scipy.io import loadmat
import scipy.optimize as op

def perceptron(X, y, w0):
    w = w0
    converged = False
    steps = 0
    while not converged:
        mistakes = 0
        for i in range(X.shape[0]):
            if y[i] * np.dot(w, X[i]) <= 0:
                w += y[i] * X[i]
                mistakes += 1
        steps +=1
        if mistakes == 0:
            converged = True
    return w, steps

data = loadmat('data1.mat')
X = data['X']
y = data['y']
w0 = np.array([1.0, -1.0])
w, steps = perceptron(X, y, w0)

def graph():
    # plot the samples with different colors for different classes
    for i in range(X.shape[0]):
        if y[i] == 1:
            plt.scatter(X[i, 0], X[i, 1], c='r')
        else:
            plt.scatter(X[i, 0], X[i, 1], c='b')

    # plot the decision boundary defined by the initial w
    x1 = np.linspace(X[:,0].min(), X[:,0].max(), 100)
    x2 = -(w0[0]/w0[1])*x1
    plt.plot(x1, x2, 'g--')

    # plot the decision boundary defined by the final w
    x2 = -(w[0]/w[1])*x1
    print(steps)
    plt.show()

graph()