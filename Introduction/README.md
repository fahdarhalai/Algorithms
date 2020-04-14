# Introduction to Algorithms
Introductory ideas, concepts and princples of Algorithms.
`First design, then implement`

## What is the difference between Algorithm & Program ?
- Algorithm:
+ When is written: in design phase
+ Who: Domain knowledge (Medecine, Math, Civil engineering ...)
+ Languages : Human language, math notations, diagrams ..
+ Dependancy: Hardware/Software independant
+ What after: Analysis

- Program:
+ When is written: in implementation phase
+ Who: Programmer
+ Languages: Programming languages Java, C/C++, Python ..
+ Dependancy: Hardware/Software dependant
+ What after: Testing

## Priori Analysis and Posteriori Testing :
- Priori Analysis:
+ For Algorithms
+ Language independant
+ Hardware independant
+ Time & Space Function

- Posteriori Testing:
+ For Programs
+ Language dependant
+ Hardware dependant
+ Watch time & memory in bytes

## Characteristics of Algorihtms :
1- Input: 0 or more
2- Output: at least 1
3- Definiteness: Every statement should have one definite meaning(known steps)
4- Finiteness: It must stop; should have finite number of statements
5- Effectiveness: Should not have unnecessary statements

## How to analyse an Algorithm ?
1- Time: How much time it takes to return a result
2- Space: How much memory it consumes during the life time
3- Network consumption (Case of cloud applications)
4- Power consumption
5- CPU registers consumption

Example:
```
Algorithm Swap(a, b)
BEGIN
	temp <- a;
	a <- b;
	b <- temp;
END
```
