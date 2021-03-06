# Introduction to Algorithms
Introductory ideas, concepts and principles of Algorithms: `First design, then implement` :sunglasses:

## What is the difference between Algorithm & Program ?
- Algorithm:
  - When is written: in design phase
  - Who: Domain knowledge (Medecine, Math, Civil engineering ...)
  - Languages : Human language, math notations, diagrams ..
  - Dependancy: Hardware/Software independant
  - What after: Analysis

- Program: 
  - When is written: in implementation phase
  - Who: Programmer
  - Languages: Programming languages Java, C/C++, Python ..
  - Dependancy: Hardware/Software dependant
  - What after: Testing

## Priori Analysis & Posteriori Testing :
- Priori Analysis:
  - For Algorithms:
  - Language independant
  - Hardware independant
  - Time & Space Function

- Posteriori Testing:
  - For Programs
  - Language dependant
  - Hardware dependant
  - Watch time & memory in bytes

## Characteristics of Algorithms :
1. Input: 0 or more
2. Output: at least 1
3. Definiteness: Every statement should have one definite meaning(known steps)
4. Finiteness: It must stop, should have finite number of statements
5. Effectiveness: Should not have unnecessary statements

## How to analyse an Algorithm ?
1. Time: How much time it takes to return a result
2. Space: How much memory it consumes during the life time
3. Network consumption (Case of cloud applications, programs that run over network ...)
4. Power consumption
5. CPU registers consumption

Example:
```
Algorithm Swap(a, b)
BEGIN
	temp <- a;
	a <- b;
	b <- temp;
END
```
The time & space complexity functions are constants:
- [x] Time complexity: O(1)
- [x] Space complexity: O(1)

## Frequency Count Method :
**Example (1):** Sum the elements of an array of size `n`
```
Algorithm Sum(A, n)
{
	S = 0;			// Time: 1
	for(i=0; i<n; i++)	// Time: n+1
	{
		S = S + A[i];	// Time: n
	}
	return S;		// Time: 1
}
```
- [x] The time function is: **f(n) = 2n+3**, which is of order n.
- [x] The space complexity function: **S(n) = n+3** which is of order n.

**Example (2):** Multiply two matrices of size `n`
```
Algorithm Multiply(A,B,n)
{
	for(i=0; i<n; i++)					// Time: n+1
	{
		for(j=0; j<n; j++)				// Time: n*(n+1)
		{
			C[i,j] = 0;				// Time: n*n
			for(k=0; k<n; k++)			// Time: n*n*(n+1)
			{
				C[i,j] = C[i,j] + A[i,k]*B[k,j];// Time: n*n*n
			}
		}
	}
}
```
- [x] The time function is: **f(n) = 2n<sup>3</sup> + 3n² + 2n + 1**, which is of order n<sup>3</sup>.
- [x] The space complexity function: **S(n) = 3n² + 4** which is of order n².

## Classes of functions :
**Types of Time functions:**
1. O(1)		constant
2. O(log n)	Logarithemic
3. O(n)		Linear
4. O(n²)	Quadratic
5. O(n<sup>3</sup>)	Cubic
6. O(2<sup>n</sup>)	Exponential

**1 < log n < sqrt(n) < n < nlog n < n² < n<sup>3</sup> < 2<sup>n</sup> < n! < n<sup>n</sup>**
<p align="center">
	<img src="https://vaxxxa.github.io/talks/introduction.to.algorithms-computational.complexity/static/images/big-o-complexity.png" width="75%" />
</p>

## Asymptotic Notations :
**Theorem: Big-Oh Notation**<br>Let **f** be a real or complex function, **g** a real function. We write: <br>
```f(x) = O(g(x)) as x ---> oo```<br>
if and only if there exists a real number M>0, and a real number x0 such that:<br>
```|f(x)| ≤ Mg(x) for all x ≥ x0```<br>
Big-Oh notation represents the upper bound of the function.

	- Example: f(n) = 2n+3
	f(n) = O(n), but also:
	f(n) = O(nlogn)
	f(n) = O(n²)

**Theorem: Big Omega Notation**<br>Let **f** be a real or complex function, **g** a real function. We write: <br>
```f(x) = Ω(g(x)) as x ---> oo```<br>
if and only if there exists a real number C>0, and a real number x0 such that:<br>
```|f(x)| => Cg(x) for all x ≥ x0```<br>
Big Omega notation represents the lower bound of the function.

	- Example: f(n) = 2n+3
	f(n) = Ω(n), but also:
	f(n) = Ω(logn)
	f(n) = Ω(1)


**Theorem: Theta Notation**<br>Let **f** be a real or complex function, **g** a real function. We write: <br>
```f(x) = Θ(g(x)) as x ---> oo```<br>
if and only if there exists constants C1, C2>0, and a real number x0 such that:<br>
```C1g(x) ≤ f(x) ≤ C2g(x) for all x ≥ x0```<br>
Theta notation represents the average bound of the function.

	-Example: f(n) = 2n+3
	f(n) = Θ(n) is the only answer.
