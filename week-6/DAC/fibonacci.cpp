#include<bits/stdc++.h>
using namespace std;
void power(int K[2][2], int n);

void multiply(int K[2][2], int M[2][2]);

int fib(int n) {

    int K[2][2] = {{1, 1}, {1, 0}};

    if(n == 0) 
      return 0;

    power(K, n-1);
    return K[0][0];
}

void power(int K[2][2], int n) {

    if(n == 0 || n == 1)
       return;
    int M[2][2] = {{1, 1}, {1, 0}};
     
    power(K, n / 2);
    multiply(K, K);
     
    if (n % 2 != 0)
        multiply(K, M);
}

void multiply(int K[2][2], int M[2][2])
{
    int x = K[0][0] * M[0][0] + K[0][1] * M[1][0];
    int y = K[0][0] * M[0][1] + K[0][1] * M[1][1];
    int z = K[1][0] * M[0][0] + K[1][1] * M[1][0];
    int w = K[1][0] * M[0][1] + K[1][1] * M[1][1];
     
    K[0][0] = x;
    K[0][1] = y;
    K[1][0] = z;
    K[1][1] = w;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<fib(n);
}