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

## Binary Search :
Binary Search is Divide & Conquer strategy which searches for a key in a given array of size **n**. We already know that the linear search is of order O(n) in worst case, and O(1) in best case, let's see how well Binary Search does.

**NOTE**:
Binary search requires the input array to be sorted. It has two approaches, the iterative approach, and the recursive approach.

#### 1. Iterative Binary Search :
Let's consider an input array of size ```n = 15```:<br>
A = {3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62}

 - First we set the lowest index to zero ```l = 1```, and the highest index to the size of the array ```h = n```.
 - Next, we calculate the mid index ```mid = (l + h)/2```.
 - We check if the key we are looking for, equals the element at index **mid**, if so, we return the **mid** index.
 - Else, we check if the the key is less than the element at index **mid**, if so, we set the new highest index as ```h = mid-1```.
 - Else, we set the new lowest index as ```l = mid+1```.
 - We repeat the process (from second step), until we find the key, or the lowest index crosses the highest, which means that the key doesn't exist in the given array.

Here is a simple implementation of the [Iterative Binary Search](https://github.com/fahdarhalai/Algorithms/blob/master/2-Divide%20and%20Conquer/BinarySearch.cpp#L5).

Now Let's analyse the time complexity of the Iterative Binary Search. For that we can make use of the Binary Search tree representation to get a better visualization and comprehension.

<p align="center">
  <img src="https://user-images.githubusercontent.com/41004675/80546180-85c2cf00-89a4-11ea-8731-e6dc50aa73fb.png" width="75%"/>
</p>

This image represents how the Binary Search algorithm travels aross the elements of the given array, it maps the **mid** index to a tree node. If you didn't see it yet, let's take the first iteration:
```
l = 1
h = 15
mid = (1+15)/2 = 8
```
The mid is then the first index the algorithm picks (or the root of the binary search tree). In the second iteration we have two possibilites depending on the searched key, either to teh left of the array like so:

```
l = 1
h = mid-1 = 8-1 = 7
mid = (1 + 7)/2 = 4 
```

Or to the right of the array like so:

```
l = mid+1 = 8+1 = 9
h = 15
mid = (9 + 15)/2 = 12
```

In both cases we successfully generate the second layer of the BST, which corresponds to two nodes, one with value 4, the other with value 12. Now you have a better understanding of how this works. Let's now continue the complexity analysis of the algorithm.

In case the searched key lays at the first calculated **mid** index (or the root of the BST), the algorithm is at its best case which is of complexity **O(1)**.

However in worst case, the algorithm will check all possible nodes (not all of them), that is for each time, it will choose to go to the left or to the right of the BST, until it reaches the bottom layer (AKA. the height of the tree).

At each layer of the BST, only one node is picked, which brings us to conclude that the worst case is when the algorithm passes all layers picking one node at each. Since the height of a BST of **n** nodes is ```log(n)```, we conclude the time complexity of the iterative binary search is **O(log(n))**.

#### 2. Recursive Binary Search :
Since Binary Search is a Divide & Conquer strategy, it is obvious that it can be solved using a recursive strategy, let's see how.

 - First we check if the given array is of length 1, that is if the lowest index equals the highest index, if so, we return the index if it holds the searched key.
 - If the array is not of length 1, we calculate the **mid** index ```mid = (l + h)/2```.
 - If the searched key is less than the element at the **mid** index, we update the highest index to ```h = mid-1```, then perform a recursive call again.
 - Else, we update the lowest index to ```l = mid+1```, then perform a recursive call again.

The algorithm will run until it finds the key, unless it doesn't exist. For this strategy, it is better to write down the algorithm, then we generate the recursion relation.
```
Algorithm RecursiveBinarySearch(Array, L, H, Key)     // Complexity T(n)
BEGIN
  if L=H:                                             // One unit of time
    if Array(L) = Key:                                // One unit of time
      return L
    else
      return -1
    end
  else
    MID <- (L + H)/2                                  // One unit of time
    if Key = Array(MID):                              // One unit of time
      return MID
    end
    if Key < Array(mid)                               // One unit of time
      H <- MID - 1
    else
      L <- MID + 1
    end
    return RecursiveBinarySearch(Array, L, H, Key)    // Complexity T(n/2)
  end
END
```
Here is a simple implementation of the [Recursive Binary Search](https://github.com/fahdarhalai/Algorithms/blob/master/2-Divide%20and%20Conquer/BinarySearch.cpp#L27).<br>
The recursion relation is given by:
```
       | 1             if n=1
T(n) = |
       | T(n/2) + 1    if n>1 
```
For ```n > 1```, we solve the recursion relation as we did before to eventually find ```T(n) = log(n)```.

## Merge Sort :
Having two sorted arrays, we wish to merge them into one sorted array. Let's write the algorithm for MergeSort of two input arrays:
```
Algorithm Merge(A, B, m, n)
BEGIN
  i=1, j=1, k=1
  
  while i<=m and j<=n:
    if A(i) < B(j):
      C(k++) = A(i++)
    else
      C(k++) = B(j++)
    end
  end
  
  while i<=m:
    C(k++) = A(i++)
  end
  
  while j<=n:
    C(k++) = B(j++)
  end
END
```
This algorithm is called Two-way MergeSort, since it merges two arrays. Generally, if we wish to merge **M** sorted arrays, we would use a M-way MergeSort.

The idea behind M-way MergeSort, is to merge arrays two by two to form one sorted array at the end.

The Merge algorithm merges two arrays of size **n** and **m**. The overall time complexity is **O(n+m)**.

**Example**:

We wish to sort the following array of integers:<br>
A = {9, 3, 7, 5, 6, 4, 8, 2}<br>
We can use 2-way MergeSort, by considering at first that each element of the array is a separate array. We then merge two elements at a time to get the following:
```
Merge({9}, {3}) => {3, 9}
Merge({7}, {5}) => {5, 7}
Merge({6}, {4}) => {4, 6}
Merge({8}, {2}) => {2, 8}
```
Next step, is to perform 2-way MergeSort on the new 4 arrays:
```
Merge({3, 9}, {5, 7}) => {3, 5, 7, 9}
Merge({4, 6}, {2, 8}) => {2, 4, 6, 8}
```
Last step, is to perform 2-way MergeSort on the new 2 arrays:
```
Merge({3, 5, 7, 9}, {2, 4, 6, 8}) = {2, 3, 4, 5, 6, 7, 8, 9}
```
Now we have a single sorted array by using 2-way MergeSort.

Given an array of size **n**, at each step of merging, we perform **n** merges. The number of steps is log<sub>2</sub>(n). Finally, the 2-way MergeSort algorithm has a time complexity of **O(nlog(n))**.

So far, we have seen how 2-way MergeSort works, it's time now to introduce the recursive algorithm of MergeSort which follows a Divide & Conquer strategy. We first write the algorithm and analyze it afterwards.
```
Algorithm MergeSort(low, high)  // T(n) time complexity
BEGIN
  if low < high:
    mid = (low+high)/2          // One unit of time 
    MergeSort(low, mid)         // T(n/2) time complexity
    MergeSort(mid+1, high)      // T(n/2) time complexity
    Merge(low, mid, high)       // n units of time 
  end
END
```
The MergeSort algorithm splits an array of size **n** into small arrays recursively, until it reaches one element in an array (low=high), then it starts 2-way MergeSort.
The recurrence relation is given by:
```
      | 1               if n = 1
T(n) =|
      | 2T(n/2) + n     if n > 1
```
Using Master's theorem for dividing functions, we get:
```
T(n) ∈ O(nlog(n))
```
**Pros:**

  - Large size list
  - Suited for linked lists
  - Stable in case of duplicates (Preserves the order)
  
**Cons:**

  - Space Complexity O(n)
  - Slower for small lists (Can be solved with the help of Insertion Sort for small problems)
  - Recursive (Uses stack memory) O(log(n))

