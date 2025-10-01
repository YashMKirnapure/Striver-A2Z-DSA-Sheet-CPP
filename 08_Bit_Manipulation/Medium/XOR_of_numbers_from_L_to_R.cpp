#include <iostream>
using namespace std;

int func(int num)
{
    if (num % 4 == 0)
        return num;
    if (num % 4 == 1)
        return 1;
    if (num % 4 == 2)
        return num + 1;
    if (num % 4 == 3)
        return 0;
}

int findXOR(int l, int r)
{
    return func(l - 1) ^ func(r);
}

/*

### **1. `func(int num)`**
This function gives the XOR of all numbers from `0` to `num`.
It works because the XOR sequence has a repeating pattern every **4 numbers**:

* If `num % 4 == 0 → XOR = num`
* If `num % 4 == 1 → XOR = 1`
* If `num % 4 == 2 → XOR = num + 1`
* If `num % 4 == 3 → XOR = 0`

This comes from observing XORs:

0 ^ 1 = 1
0 ^ 1 ^ 2 = 3
0 ^ 1 ^ 2 ^ 3 = 0
0 ^ 1 ^ 2 ^ 3 ^ 4 = 4
...
So it cycles every 4 steps.

### **2. `findXOR(int l, int r)`**
We want XOR of numbers from **L to R**.
* Trick:
  XOR(L..R) = XOR(0..R) ^ XOR(0..L-1)

* Why? Because the prefix XOR cancels out:
  (0 ^ 1 ^ ... ^ (L-1)) ^ (0 ^ 1 ^ ... ^ R) 
  = L ^ (L+1) ^ ... ^ R

* So:
  return func(l-1) ^ func(r);
  
### **Example**
Find XOR from `L = 3` to `R = 9`:
* `XOR(0..9) = func(9) = 1` (since 9 % 4 = 1)
* `XOR(0..2) = func(2) = 3` (since 2 % 4 = 2 → num+1)
* Result = `1 ^ 3 = 2`

Think of it like tracking goals scored up to match `R` minus goals scored up to match `L-1`. The overlapping early goals cancel out, leaving just the goals scored between matches `L` and `R`.

*/