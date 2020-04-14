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
The time as well as space complexity functions are constants:
- [x] Time complexity: O(1)
- [x] Space complexity: O(1)

## Frequency Count Method :
Example:
```
Algorithm Sum(A, n)
{
	S = 0;
	for(i=0; i<n; i++)
	{
		S = S + A[i];
	}
	return S;
}
```
For an array of size `n`, the initialization `S=0` is only executed once, the condition `i<n` in the `for loop` is evaluated to true `n` times, the `n+1` iteration is evaluated to false, thus the condition is evaluated `n+1` times. The statement within the for loop is executed `n` times, and finally the return statement is executed once.
We conclude the time function: <br>`f(n) = 1+(n+1)+n+1 = 2n+3`, which is of order `n`.<br>
Since the array is of size `n`, with the addition of 3 more variable used within the function, we conclude the space complexity function:<br>
`S(n) = n+1+1+1 = n+3` which is of order `n`.
