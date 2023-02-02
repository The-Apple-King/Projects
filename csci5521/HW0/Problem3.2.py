import numpy as np
from scipy.optimize import linprog
import scipy.io as sio

def perceptron(X, y, w0):
    w = w0
    converged = False
    steps = 0
    while not converged:
        mistakes = 0
        for i in range(X.shape[0]):
            if y[i] * np.dot(w, X[i]) <= .5:
                w += y[i] * X[i]
                mistakes += 1
        steps +=1
        if mistakes == 0:
            converged = True
    return w, steps
    
mat_contents = sio.loadmat("data2.mat")
X = mat_contents["X"]
y = np.squeeze(mat_contents["y"])
m, n = np.shape(X)
X = np.hstack((X, np.ones((m, 1 ))))
n = n + 1
f = np.append(np.zeros(n), np.ones(m))
A1 = np.hstack((X*np.tile(y,(n,1)).T,np.eye(m)))
A2 = np.hstack((np.zeros((m,n)), np.eye(m)))
A =-np.vstack((A1,A2))
b = np.append(-np.ones(m), np.zeros(m))
x = linprog(f, A, b)
w = x['x'][0:n]
w = perceptron(X, y, w)