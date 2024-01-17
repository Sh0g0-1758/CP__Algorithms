// Problem :
/*
Once upon a time, an elderly man and an elderly woman lived. One day, the elderly man went to a
mountain for hang gliding, and the elderly woman went to a river for shooting rapids in a canoe.
The elderly man looked around from the sky, he found the elderly woman enjoying shooting rapids. So
he called her in a loud voice, she noticed him. They like acrobatic feats. So they decided to touch each
other’s hand by hand.
He can stretch his hand to her periodically. Moreover, she also can stretch her hand to him periodically.
Because they are busy on their work.
Strictly speaking, she stretches her hand on time n and after that she stretches every m unit times. On the
other hand, he stretches his hand every a unit times after he approaches to her. And it takes k unit times
to approach her. Therefore, he stretches his hand at first on time k + a.
Your job is to write a program to calculate the time when they mutually touch a hand by hand first.
For example, the following table shows the first input of sample inputs. They mutually touch a hand by
hand on 8.
Time 1 2 3 4 5 6 7 8
The elderly woman - - Stretch - - - - Stretch
The elderly man - Approach - Stretch - Stretch - Stretch
Input
Input consists of multiple test cases. Each test case consists of a line which contains four non-negative
integers n, m, a, and k separated by a space character. Input is terminated by a case of n = m = a = k = 0,
and it should not to be processed.
You can assume that input integers are less than 2^31
.
Output
For each test case, you should output the time when they mutually touch a hand by hand if possible.
Otherwise, you should output “Impossible”.
Sample Input
3 5 2 2
0 0 0 0
Output for the Sample Input
8
*/

// Solution :

#include <bits/stdc++.h>
using namespace std;

int helper(int a, int b,int &x,int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int d = helper(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    int n, m, a, k;
    while (true)
    {
        // cin >> n >> m >> a >> k;
        n = 7;
        m = 6;
        a = 5;
        k = 2;
        if (n == 0 && m == 0 && a == 0 && k == 0)
            break;
        if (abs(m-k)%__gcd(a,n) != 0)
        {
            cout << "Impossible" << endl;
            continue;
        }
        int u,v;
        int gcd = helper(a,n,u,v);
        int t = max(floor(((k-m) * u) / n) + 1 , floor(((k-m) * v) / a));
        int x = (t * (n) / gcd) + ((m - k) * u / gcd);
        cout << k + x * a << endl;
    }
}