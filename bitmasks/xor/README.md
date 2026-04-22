# D. Exceptional Segments

**Time Limit:** 2 seconds  
**Memory Limit:** 512 MB  

## Problem Statement
You are given two integers **n** and **x**.  

Consider the sequence **[1, 2, 3, …, n]**. You need to find the number of its subsegments that contain **x** and have XOR equal to 0. In other words, count the number of pairs **(l, r)** such that **1 ≤ l ≤ x ≤ r ≤ n** and **l ⊕ (l+1) ⊕ ⋯ ⊕ r = 0**, where **⊕** denotes bitwise XOR.  

Since the answer can be very large, output it **modulo 998244353**.  

### Example
If **n=7** and **x=6**, suitable segments are:  
- (4,7): 4 ⊕ 5 ⊕ 6 ⊕ 7 = 0  
- (1,7): 1 ⊕ 2 ⊕ 3 ⊕ 4 ⊕ 5 ⊕ 6 ⊕ 7 = 0  

## Input
- First line: number of test cases **t** (1 ≤ t ≤ 2×10^5)  
- Each test case: two integers **n** and **x** (1 ≤ x ≤ n ≤ 10^18)  

## Output
For each test case, output one integer — the answer modulo 998244353.  

## Sample Input/Output

Input:
```
5
5 5
8 1
15 8
10 10
5989566119 1996588700
```

Output:
```
1
2
10
0
99996
```

## Approach
The XOR of numbers from 1 to n repeats every 4 numbers. Here's the pattern:
- If n divided by 4 leaves 0, XOR from 1 to n is n
- If n divided by 4 leaves 1, XOR is 1
- If n divided by 4 leaves 2, XOR is n+1
- If n divided by 4 leaves 3, XOR is 0

For a subsegment from l to r, if its XOR is zero, then the XOR from 1 to l-1 equals the XOR from 1 to r.

We need to count subsegments that include x and have XOR 0. Since n is up to 10^18, we can't check each one. We use math to count how many such segments exist for each test case.

## Solution Link
[Codeforces Contest 2225 Problem D](https://codeforces.com/contest/2225/problem/D)

## Code
[solution.cpp](solution.cpp)