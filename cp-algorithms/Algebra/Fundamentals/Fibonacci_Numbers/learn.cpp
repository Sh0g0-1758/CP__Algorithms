#include<bits/stdc++.h>
using namespace std;

struct matrix {
    long long mat[2][2];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
              c.mat[i][j] = 0;
              for (int k = 0; k < 2; k++) {
                  c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
              }
          }
        }
        return c;
    }
};

int main() {
    matrix ans {
        1, 0,
        0, 1
    };
    matrix base {
        1, 1,
        1, 0
    };
    matrix xyz = ans * base;
    cout << xyz.mat[0][1] << endl;
}