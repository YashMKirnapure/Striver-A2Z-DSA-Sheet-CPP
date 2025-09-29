#include <iostream>
using namespace std;

//Swap two numbers using bit manipulation
void swapTwoNums(int a,int b)
{
    cout<<"a: "<<a<<" b: "<<b<<endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<"a: "<<a<<" b: "<<b;
}

//Check if the ith bit is set or not
bool CheckiThBit(int n,int i)
{
    //Right Shift Method
    if((n>>i)&1 == 1)
        return true;
    else
        return false;

    //Left Shift Method
    if((1<<i)&n == 1)
        return true;
    else
        return false;
}

//Set the ith bit
int setIthBit(int n,int i)
{
    return n | (1<<i);
}

//Clear the ith bit
int ClearIthBit(int n,int i)
{
    return n & ~(1<<i);
}

//Toggle the ith bit
int toggleIthBit(int n,int i)
{
    return n ^ (1<<i);
}

//Remove the last set bit
int removeLastBit(int n)
{
    return n & (n-1);
}

//Check if the number is a power of 2
bool PowerOf2(int n)
{
    return n > 0 && (n & (n-1)) == 0;
}

//Count the number of set bits
int countSetBits(int n)
{
    int cnt = 0;
    while(n>0)
    {
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

int main()
{
    // swapTwoNums(5,6);
    // cout<<CheckiThBit(13,2);
    // cout<<setIthBit(9,2);
    // cout<<ClearIthBit(9,2);
    // cout<<toggleIthBit(8,1);
    // cout<<removeLastBit(7);
    // cout<<PowerOf2(128);
    // cout<<countSetBits(18);
}

/*
---

### **1. Swap two numbers using XOR**
```
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

* XOR has a magical property: `x ^ x = 0` and `x ^ 0 = x`.
* Using 3 XOR steps, we can swap values without needing a temporary variable.
* End result: values of `a` and `b` are exchanged.

---

### **2. Check if the i-th bit is set**
```
if ((n >> i) & 1 == 1) ...
```

* Right shift `n` by `i` → brings the i-th bit to the rightmost position.
* AND it with `1` → if result is `1`, that bit was set.

Alternative:
```
if ((1 << i) & n) ...
```

* Left shift `1` by `i` → makes a mask with only the i-th bit set.
* AND it with `n` → if result ≠ 0, that bit was set.

---

### **3. Set the i-th bit**
```
n | (1 << i)
```

* Left shift `1` by `i` to create a mask.
* OR with `n` → ensures that bit becomes `1` (set).

---

### **4. Clear the i-th bit**
```
n & ~(1 << i)
```

* `(1 << i)` sets only the i-th bit.
* `~(1 << i)` flips it, so all bits are `1` except the i-th.
* AND with `n` → clears that specific bit.

---

### **5. Toggle the i-th bit**
```
n ^ (1 << i)
```

* XOR with a mask flips that bit:

  * If it was `1`, becomes `0`.
  * If it was `0`, becomes `1`.

---

### **6. Remove the last set bit**
```
n & (n-1)
```

* Subtracting 1 flips all bits after the rightmost `1` (including it).
* ANDing with original clears that rightmost set bit.
* Example: `100100 → 100000`.

---

### **7. Check if number is power of 2**
```
(n > 0) && (n & (n-1)) == 0
```

* A power of 2 has exactly **one set bit**.
* `n & (n-1)` clears the last set bit → result is 0 only for powers of 2.

---

### **8. Count number of set bits**
```
while(n > 0) {
    n = n & (n-1);
    cnt++;
}
```

* Each step removes the rightmost set bit.
* Count how many times you can do that until `n = 0`.
* That gives total number of 1’s in the binary representation.

---

*/