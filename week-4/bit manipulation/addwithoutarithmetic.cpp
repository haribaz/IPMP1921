#include <bits/stdc++.h>
using namespace std;
 
int add(int x, int y)
{
    while (y != 0) {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}
 
// Driver code
int main()
{
    cout << add(7, 12);
    return 0;
}