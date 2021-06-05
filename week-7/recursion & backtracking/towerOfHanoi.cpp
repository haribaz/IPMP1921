#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from, char to, char middle) {
    if(n == 1) {
        cout<<"Disk 1 from "<<from<<" to "<<to<<endl;
        return;
    }
    towerOfHanoi(n-1, from, middle, to);
    cout<<"Disk "<<n<<" from "<<from<<" to "<<to<<endl;
    towerOfHanoi(n-1, middle, to, from);
}

int main() {
    towerOfHanoi(2, 'A', 'C', 'B');
}