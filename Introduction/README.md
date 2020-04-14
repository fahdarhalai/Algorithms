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

## Characteristics of Algorihtms :
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
*Example (1):* Sum the elements of an array of size `n`
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
- [x] The time function is: `f(n) = 1+(n+1)+n+1 = 2n+3`, which is of order `n`.
- [x] The space complexity function: `S(n) = n+1+1+1 = n+3` which is of order `n`.

*Example (2):* Multiply two matrices of size `n`
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
- [x] The time function is: `f(n) = 2n<sup>3</sup> + 3n² + 2n + 1`, which is of order `n<sup>3</sup>`.
- [x] The space complexity function: `S(n) = 3n² + 4` which is of order `n²`.
