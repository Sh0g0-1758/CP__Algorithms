// Problem : 

/*
From Euclid it is known that for any positive integers A and B there exist such integers X and Y that
AX + BY = D, where D is the greatest common divisor of A and B. The problem is to find for given
A and B corresponding X, Y and D.
Input
The input will consist of a set of lines with the integer numbers A and B, separated with space
(A, B < 1000000001).
Output
For each input line the output line should consist of three integers X, Y and D, separated with space.
If there are several such X and Y , you should output that pair for which |X| + |Y| is the minimal. If
there are several X and Y satisfying the minimal criteria, output the pair for which X ≤ Y .
Sample Input
4 6
17 17
Sample Output
-1 1 2
0 1 17
*/

// Solution : 

#include<bits/stdc++.h>
using namespace std;

int gcd_pair(int a, int b,int &x,int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int d = gcd_pair(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    int a,b;
    cout << gcd_pair(3,-2,a,b) << endl;
    cout << a << "  " << b << endl;
}