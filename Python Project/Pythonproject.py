import matplotlib.pyplot as plt
import numpy as np
import scipy
from scipy.integrate import quad

#define function with range
def func(x):
    return ((1/20)*((x-3) ** 3) - (x ** 2))

upperlimit = 30
lowerlimit = 0
step = 1
x = np.array(range(lowerlimit, upperlimit, step))
y = func(x)


#storing x and y into data frame and plotting it
data = {
        'x': x,
        'y': y  
        }
plt.subplot(1,3,1)
plt.title('Function')
plt.plot(data['x'] , data['y'], 'r')


#finding the derivative and plotting it
data['yder'] = np.diff(data['y']) / np.diff(data['x'])
data['xder'] = (np.array(data['x'])[:-1] + np.array(data['x'])[1:]) / 2
plt.subplot(1,3,2)
plt.title('Derivative')
plt.plot(data['xder'], data['yder'], 'b')


#making array and inputing the integral of n into the array
integral = [0] * 30 

for n in range(lowerlimit, upperlimit, 1):
    if n <= upperlimit:
        res, err = quad(func, 0, n)
        integral[n] = res
        n += 1
plt.subplot(1,3,3)
plt.title('Integral')
plt.plot(x , integral, 'y')
