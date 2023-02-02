import numpy as np
from scipy.optimize import linprog
import scipy.io as sio
import matplotlib.pyplot as plt
mat_contents = sio.loadmat("data1.mat")
x1 = np.arange(-1, 1, 0.1) #generate x between -1 to 1 by stepsize 0.1 
x2 = -w0[0]*x1/w0[1] #calculate x2 by w and x1.

plt.plot(x1, x2, color='black', linewidth=2.0)
plt.show


