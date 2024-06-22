#include<bits/stdc++.h>
using namespace std;

int main(){
    int dividend = -2147483648;
    int divisor = -1;
    long long a = (long long)abs(dividend);
    long long b = (long long)abs(divisor);
    long long cnt = 0;
    while(a > 0) {
        a -= b;
        if(a>=0) cnt++;
    }
    cout<<cnt<<endl;
}
