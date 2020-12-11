####EXPLANATION OF CODE
THe goal of this code is to print out a graph of a function along with its derivative graph and integral graph.
One example is shown in this code, but it can be edited for any function and the graphs could be reformatted for different purposes.
//
This code prints out 3 graphs, one of the original function, one of the derivative function and one of the integral function. 
This code starts by importing matplotlib, numpy, and scipy. 
Then, a function is defined. In this case the function is. 
Next, some variables are declared and defined. 
Upperlimit and lower limit is where the functions are being defined from, and step is how much x is changed by. For simplicity, the step is just 1. 
Then the range of the function is defined based on the upper and lower limit, and y is set equal to f(x). 
//
Now that the function is properly set, the x and y values are stored into a data frame adn then plotted based on every pair of x and y's. 
The plot is given a color denoted 'r', and given a title "function". Also, plt.subplot allows multiple subplots to be graphed. 
The three numbers represent in order, how many rows of plots, how many colums of plots, and what number plot. 
//
      Next, the derivative needs to be graphed. 
For this a new data frame is defined for the x and y values for this plot. 
The y values are calculated by taking the difference of two consecutive y's divided by the difference of two consecutive x's, and this is repeated for all the data. 
This gets the "slope" between two points. The x values are now just the average of every two consecutive original x values. 
Here, [:-1] is used to tell it to go through every value except the last, and [1:] to mean except the first. 
Then this plot is also graphed in the same manner as the first.
//
       finally, the integral graph.
First, an array is defined called integral and is given a magnitude of 30 
(becasue that is how many values we are going to define which is based on upperlimit-lowerlimit, with a step of 1). 
Then the code says, for each 'n' in the range of lowerlimit to upper limit with a step of 1, 
if n is less than the upper limit then the result is going to be the integral of the function (func) from 0 to n (quad is an integral finder from scipy). 
(the "err" calculates the error but that is not important for this program). 
Then each value of that integral is stored in the nth position in the array and n increases by 1. 
This goes on until the entire array is filled and n is now not less than the lower than the upper limit. 
In the same way as the other two graphs this graph is plotted. 
