# Greedy Method
Just like Divide & Conquer strategy, Greedy Method is also a strategy or approach for solving a specific types of problems.

## General Approach :
The category of problems which require a Greedy strategy, are **optimization problems**, these are problems that require minimizing or maximizing a function.

<p align="center">
  <img src="https://user-images.githubusercontent.com/41004675/81754142-eeca3c80-94a4-11ea-8501-1cbb38d99b20.jpg" width="75%" />
</p>

Consider the problem **P** for traveling from a point **A** to **B**. One can say, the solution is to walk from A to B, or to ride a bike, or to drive a car, or to take the train ...etc.

However, add a constraint to the problem **P**, can make the set of solutions stricter. Such constraints can be on the duration of travel which will most likely exclude traveling by walking or riding the bike. However, traveling by flight or train, are reasonable solutions, those solutions are said to be **Feasible**.

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
