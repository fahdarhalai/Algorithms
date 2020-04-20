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

## Recurrence Relation for Decreasing Functions :
**Example:**
``` C
void Test(int n){
  if(n>0){
    printf("%d", n);
    Test(n-1);
  }
}
```
The execution of **Test** function on input ```n = 3``` is as follows:
```
Test(3)             // T(3) time complexity
|__ 3               // One unit of time
|__ Test(2)         // T(2) time complexity
    |__ 2           // One unit of time
    |__ Test(1)     // T(1) time complexity
        |__ 1       // One unit of time
        |__ Test(0) // T(0) time complexity
```
The above example shows that each call of **printf** is executed in one unit of time, thus we obtain 3 calls of **printf**, whereas the number of calls of **Test** function is 4.
For this particular problem, the number of recursive calls given an integer **n** is:
```
f(n) = n + 1
```
which is of complexity ```O(n)```.
The time complexity of the example given defines the following recursive sequence:
```
        | 1           if n=0
 T(n) = |
        | T(n-1) + 1  if n>0
```
Solving the recursive sequence for n>0:
```
T(n) = T(n-1) + 1 
     = T(n-2) + 2
     = T(n-3) + 3
     = T(n-n) + n
     = T(0) + n
     = 1 + n
```
We conclude that the problem is linear in time, or ```T(n) ∈ Θ(n)```.

**Example:**
``` Cpp
void Test(int n){             // T(n) time complexity
  if(n>0){                    // One unit of time
    for(int i=0; i<n; i++){   // (n+1) * unit of time
      printf("%d", n);        // n * unit of time
    }
    Test(n-1);                // T(n-1) time complexity
  }
}
```
Number of recurise calls of **Test** function:
```
f(n) = n + 1
``` 
which is O(n).
The time complexity of the problem is given by the recursive sequence:
```
        | 1           if n=0
 T(n) = |
        | T(n-1) + n  if n>0
```
Solving the recursive sequence for n>0 gives:
```
T(n) = n(1+n)/2
``` 
which is O(n²).

**Summary:**
As the procedure of solving the time complexity of a recursive sequence become more clear, here is a summary of few of them (a,b are constant integers):
- T(n) = T(n-1) + 1 &emsp;&ensp;&emsp;&emsp;is O(n)
- T(n) = T(n-1) + logn &emsp;&emsp;is O(nlogn)
- T(n) = T(n-1) + n &emsp;&nbsp;&emsp;&emsp;is O(n²)
- T(n) = T(n-1) + n² &emsp;&emsp;&emsp;is O(n<sup>3</sup>)
- T(n) = 2T(n-1) + 1 &emsp;&emsp;&emsp;is O(2<sup>n</sup>)
- T(n) = 3T(n-1) + 1 &emsp;&emsp;&emsp;is O(3<sup>n</sup>)
- T(n) = 2T(n-1) + n &emsp;&emsp;&emsp;is O(n2<sup>n</sup>)

## Master Theorem for Decreasing Functions :
From the above summary, one can deduce a general formula for time complexity sequence as follows:
```
       | 1                if n=0
T(n) = |
       | aT(n-b) + f(n)   if n>0
```
where a,b are strictly positive real numbers, and **f(n)** is of order O(n<sup>k</sup>) where ```k≥0```.

**demystification:**

For ```n>0```, we have:<br>

&emsp;T(n) = aT(n-b) + f(n)<br>
&emsp;&emsp;&emsp;= a[aT(n-2b) + f(n)] + f(n)<br>
&emsp;&emsp;&emsp;= a²T(n-2b) + af(n) + f(n)<br>
&emsp;&emsp;&emsp;= a<sup>k</sup>T(n-kb) + a<sup>k-1</sup>f(n) + ... + af(n) + f(n) &emsp;&emsp;&emsp;&emsp;(for k>0)<br>

Let ```k=n/b```, hence:<br>
<p align="center"><b>T(n) = a<sup>n/b</sup> + a<sup>(n/b)-1</sup>f(n) + ... + af(n) + f(n)</b></p><br>

**Theorem:** 
- if ```a < 1```, then **T(n) ∈ O(f(n))**
- if ```a = 1```, then **T(n) ∈ O(nf(n))**
- if ```a > 1```, then **T(n) ∈ O(f(n)a<sup>n/b</sup>)**

## Recurrence relation for Dividing Functions :
**Example:**
``` C
void Test(int n){           // T(n) time complexity
  if(n>1){                  // One unit of time
    printf("%d", n);        // One unit of time
    T(n/2);                 // T(n/2) time complexity
  }
}
```
We conclude the following recursion sequence:
```
      | 1               if n=1
T(n) =| 
      | T(n/2) + 1      if n>1
```
For n>1, we can write after developing the equation: <br>
T(n) = T(n/2<sup>k</sup>) + k<br>
if k = logn, then: <br>
T(n) = T(1) + logn = 1 + logn<br>
which is O(logn)

**Example:**

Let us study the following recursion:
```
      | 1               if n=1
T(n) =| 
      | T(n/2) + n      if n>1
```
For n>1, we can write:<br>
T(n) = 1 + 2n(1-(0.5)<sup>logn</sup>)<br>
which is O(n).

**One more:**

Take a look at this last one:
```
      | 1               if n=1
T(n) =| 
      | 2T(n/2) + n      if n>1
```
For n>1, we can write:<br>
T(n) = n + nlogn<br>
which is O(nlogn).

## Master Theorem for Dividing Functions :
The general form of recurrence relation is:
```
      | 1                 if n=1
T(n) =|
      | aT(n/b) + f(n)    if n>1
```
where a≥1, b>1, and f(n) is of order O(n<sup>k</sup>log<sup>p</sup>n).

**Theorem:**

- if log<sub>b</sub>a > k, then O(n<sup>log<sub>b</sub>a</sup>)
- if log<sub>b</sub>a = k, then
  - if p > -1, then O(n<sup>k</sup>log<sup>p+1</sup>n)
  - if p = -1, then O(n<sup>k</sup>loglogn)
  - if p < -1, then O(n<sup>k</sup>)
- if log<sub>b</sub>a < k, then
  - if p ≥ 0, then O(n<sup>k</sup>log<sup>p</sup>n) 
  - if p < 0, then O(n<sup>k</sup>)

**Applying the theorem:**

- Case 1:
  - T(n) = 2T(n/2) + 1&nbsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;is O(n)
  - T(n) = 4T(n/2) + n&nbsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;is O(n²)
  - T(n) = 8T(n/2) + n²&nbsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;is O(n<sup>3</sup>)
- Case 2:
  - T(n) = T(n/2) + 1&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;&nbsp;&nbsp;&nbsp;is O(logn)
  - T(n) = 4T(n/2) + (nlogn)²&emsp;&emsp;&nbsp;&nbsp;is O(n²log<sup>3</sup>n)
  - T(n) = 2T(n/2) + n/log²n&emsp;&emsp;&nbsp;&nbsp;&nbsp;is O(n)
- Case 3:
  - T(n) = T(n/2) + n&nbsp;&nbsp;&nbsp;&emsp;&emsp;&emsp;&emsp;&emsp;is O(n)
  - T(n) = 4T(n/2) + n<sup>3</sup>log²n&emsp;&emsp;&nbsp;&nbsp;is O(n<sup>3</sup>log²n)
  - T(n) = 2T(n/2) + n²/logn&emsp;&emsp;&nbsp;&nbsp;is O(n²)
