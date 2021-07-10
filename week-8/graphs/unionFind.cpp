#include<bits/stdc++.h>
using namespace std;

int parent[1000];
int ranks[1000];

void makeSet(int n) {
    for(int i=1; i<=n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findPar(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = findPar(parent[x]);
}

void unionFind(int x, int y) {
    if(ranks[x] < ranks[y]) {
        parent[x] = y;
    } else if (ranks[x] > ranks[y]) {
        parent[y] = x;
    } else {
        parent[y] = x;
        ranks[x]++;
    }
}
int main() {
    makeSet(7);
    int m;
    unionFind(1, 2);
    cout<<findPar(2);
    unionFind(2, 3);
    cout<<findPar(3);
    unionFind(4, 5);
    cout<<findPar(5);
    unionFind(6, 7);
    cout<<findPar(7);
    unionFind(5, 6);
    cout<<findPar(6);
    unionFind(3, 7);
    cout<<findPar(7);
}