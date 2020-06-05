# Greedy Method
Just like Divide & Conquer strategy, Greedy Method is also a strategy or approach for solving a specific types of problems.

## General Approach :
The category of problems which require a Greedy strategy, are **optimization problems**, these are problems that require minimizing or maximizing a function.

<p align="center">
  <img src="https://user-images.githubusercontent.com/41004675/81754142-eeca3c80-94a4-11ea-8501-1cbb38d99b20.jpg" width="75%" />
</p>

Consider the problem **P** for traveling from a point **A** to **B**. One can say, the solution is to walk from A to B, or to ride a bike, or to drive a car, or to take the train ...etc.

However, adding a constraint to the problem **P**, can make the set of solutions stricter. Such constraints can be on the duration of travel which will most likely exclude traveling by walking or riding the bike. However, traveling by flight or train, are reasonable solutions, those solutions are said to be **Feasible**.

Now let's say, we wish to travel with minimum cost. From the set of feasible solutions, there will be always one solution which satisfies all the constraints and the additional minimization condition, this solution is said to be **Optimal**.

Our problem **P** is now a minimization problem that consist of finding an Optimal solution which satisfies all the constraints and achieves minimum cost. Similarly we may define **P** such that it requires finding a maximum of ```something```, it is called a maximization problem. In both cases, **P** is an **Optimization problem**.

The general approach to optimization problems using Greedy Method is described by the following algorithm:
```
Algorithm Greedy(A)
BEGIN
  S <- empty set of solutions
  for each element e of A:
    if Feasible(e)
      Add(S, e);
END
```
where **A** is an input of size **n**.

## Knapsack Problem :
The problem consist of a knapsack of total capacity W (total weight), and **N** objects, each one is having a profit and a weight as follows:
<table>
  <tr>
    <td>objects</td>
    <td>1</td>
    <td>2</td>
    <td>3</td>
    <td>4</td>
    <td>5</td>
    <td>6</td>
    <td>7</td>
    <td>8</td>
    <td>9</td>
    <td>10</td>
  </tr>
  <tr>
    <td>profits</td>
    <td>p1</td>
    <td>p2</td>
    <td>p3</td>
    <td>p4</td>
    <td>p5</td>
    <td>p6</td>
    <td>p7</td>
    <td>p8</td>
    <td>p9</td>
    <td>p10</td>
  </tr>
  <tr>
    <td>weights</td>
    <td>w1</td>
    <td>w2</td>
    <td>w3</td>
    <td>w4</td>
    <td>w5</td>
    <td>w6</td>
    <td>w7</td>
    <td>w8</td>
    <td>w9</td>
    <td>w10</td>
  </tr>
</table>

We wish to find the perfect combination of objects, so that the total profit is maximized while the total weight doesn't exceed a certain value being the constraint.

**NOTE:** There are two types of Knapsack Problem:</br>
  * 0-1 Knapsack: The object should either be taken as whole, or left (eg. 1Kg ingot gold).
  * Fractional Knapsack: A small portion of the object can be selected (eg. Vegetables).

The 0-1 Knapsack cannot be solved using Greedy Method, so we are going to focus on Fractional Knapsack.

The formulation of the problem is as follows:

Maximize ∑p<sub>i</sub>x<sub>i</sub><br>
Subject to ∑p<sub>i</sub>x<sub>i</sub> ≤ W

To solve the problem we must add a new row to the table with additional information being the profit per unit weight of each object. We obtain the following results:
<table>
  <tr>
    <td>Object</td>
    <td>1</td>
    <td>2</td>
    <td>3</td>
    <td>4</td>
    <td>5</td>
    <td>6</td>
    <td>7</td>
    <td>8</td>
    <td>9</td>
    <td>10</td>
  </tr>
  <tr>
    <td>Profit</td>
    <td>p1</td>
    <td>p2</td>
    <td>p3</td>
    <td>p4</td>
    <td>p5</td>
    <td>p6</td>
    <td>p7</td>
    <td>p8</td>
    <td>p9</td>
    <td>p10</td>
  </tr>
  <tr>
    <td>Weight</td>
    <td>w1</td>
    <td>w2</td>
    <td>w3</td>
    <td>w4</td>
    <td>w5</td>
    <td>w6</td>
    <td>w7</td>
    <td>w8</td>
    <td>w9</td>
    <td>w10</td>
  </tr>
  <tr>
    <td>P/W</td>
    <td>p1/w1</td>
    <td>p2/w2</td>
    <td>p3/w3</td>
    <td>p4/w4</td>
    <td>p5/w5</td>
    <td>p6/w6</td>
    <td>p7/w7</td>
    <td>p8/w8</td>
    <td>p9/w9</td>
    <td>p10/w10</td>
  </tr>
</table>

Next, we begin by adding to the knapsack, objects with higher **P/W** values until there is no more, we keep selecting in decreasing order until we reach the total capacity of the knapsack. This method ensures that the total profit is going to be optimal.

Here is the algorithm for the Fractional Knapsack:
```
Algorithm FractionalKnapsack(A, P, W, n, capacity):
  initialize T of size n
  
  for i ≤ n:
    T[i] := P[i]/W[i]
    i := i + 1
  end
   
  sort T in decreasing order and reflect changes to A, P and W
 
  total_weight := 0
  for i ≤ n:
    w := 0
    while(w < W[i]):
      if(total < capacity):
        total_weight := total_weight + 1
        w := w + 1
      else:
        break
      end
    end
    if(total_weight < capacity):
      break
    end
  end
  
  return total_weight
```
Here is an implementation for the [Fractional Knapsack Problem](https://github.com/fahdarhalai/Algorithms/blob/master/3-Greedy%20Method/FractionalKnapsack.cpp#L22).

## Job Sequencing with Deadlines:
Let's look at the following jobs :
<table>
  <tr>
    <td>Jobs</td>
    <td>J1</td>
    <td>J2</td>
    <td>J3</td>
    <td>J4</td>
    <td>J5</td>
  </tr>
  <tr>
    <td>Profits</td>
    <td>20</td>
    <td>15</td>
    <td>10</td>
    <td>5</td>
    <td>1</td>
  </tr>
  <tr>
    <td>Deadlines</td>
    <td>2</td>
    <td>2</td>
    <td>1</td>
    <td>3</td>
    <td>3</td>
  </tr>
</table>

Assuming our machine, executes each job in **1 unit** of time. The deadline gives information about the maximum time we can wait before completing the job.

In order to solve the problem using Greedy Method, we need to define the function to be optimized, as well as the constraints. For this one, the function to optimize is the total profits function (needs to be maximized). The total time **T** needed for processing all possible jobs is directly related to the maximum deadline M in our list of jobs, and the relationships is expressed as ```T ≤ M```.

In our example, **T** is unknown, but **M**=4, this means all the jobs that could be executed, should be executed within the time interval **[0,4]**:
```
0 ------ 1 ------ 2 ------ 3 ------ 4
```
(For instance, if we execute **J1** first, then it should go between **[0,1]** time slot.)

Solving the problem is done in the following steps:
1. Sort the jobs by profit in decreasing order
2. Select first job (with deadline d1) and insert it in the time slot **[d1-1,d1]**
3. Select next job (with deadline d), insert it in time slot **[d-1,d]** if it's empty, otherwise insert it in the first empty time slot found before **[d-1,d]** (if found).
4. Repeat step (3) for all time slots in the order mentioned.

The above steps can also be written as a general algorithm as follows:
```
Algorithm JobSequencing(J, P, D, n):
  R <- Empty sequence solution list of 
  Sort(P) and reflect the new order onto J and D
  foreach (j, p, d) in (J, P, D):
    if R[d-1] is empty:
      Add j in R at position (d-1)
    else:
      i <- (d-2)
      while i ≥	0:
        if R[i] is empty:
          Add j in R at position i
          break
        decrement(i)
      end
    end
  end
end
```
Here is and implementation of the [Job Sequencing Algorithm]().
