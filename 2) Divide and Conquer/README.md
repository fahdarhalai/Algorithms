# Divide & Conquer
Divide & Conquer algorithms follow a strategy which consist of a certain approach or design to solve a computational problem.

## General Approach :
Let **P** b a problem of ```size = n```, we can divide the problem into **k** independant sub-problems, each of which gives a solution **S<sub>i</sub>** for ```1 ≤ i ≤ k```. We can combine all the **k** solutions into one solution **S** which would be the solution for the entire problem **P**.

<p align="center">
  <img src="https://user-images.githubusercontent.com/41004675/79476095-789afd00-8000-11ea-8952-3b8f8e18c6c4.png" width="75%" />
</p>

For each divide & conquer problem, there must exist a method for breaking the problem into a number of sub-problems, as well as a method for combining them back to the original.

**IMPORTANT:**
Each sub-problem **P<sub>i</sub>** is of the same nature as the original, for instance, if the problem **P** performs certain tasks on an input data of ```size = n```, then all sub-problems must perform the same exact tasks but on a small portion of the input data.

**Example:**
```
Algorithm Divide_And_Conquer(P)
BEGIN
  if(small(P))
    return solve(P);
  else
    P1, P2, P3, ... , Pk <-- divide(P);
    sub_solutions <-- Divide_And_Conquer(P1), Divide_And_Conquer(P2), ... , Divide_And_Conquer(Pk);
    solution <-- combine(solutions);
    return solution;
END
```
**Major Divide & Conquer algorithms:**
1. Binary Search
2. Finding Maximum & Minimum
3. MergeSort
4. QuickSort
5. Strassem's Matrix Multiplication
