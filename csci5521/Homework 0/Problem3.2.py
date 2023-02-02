import numpy as np
from scipy.optimize import linprog
import scipy.io as sio
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
