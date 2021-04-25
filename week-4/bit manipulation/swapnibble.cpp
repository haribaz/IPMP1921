#include<bits/stdc++.h>
using namespace std;


unsigned int swap_nibbles(unsigned int c)
{
     unsigned int temp1, temp2;

     temp1 = c & 0x0f;
     temp2 = c & 0xf0;
     temp1=temp1 << 4;
     temp2=temp2 >> 4;

     return(temp2|temp1); 
}

int main() {
       unsigned int k = 15;
       cout<<swap_nibbles(k);
}