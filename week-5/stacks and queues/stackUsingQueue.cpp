#include<bits/stdc++.h>
using namespace std;

class stackQueue {
    queue<int> q1, q2;

    public:

    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        q1.pop();
    }

    int top() {
        return q1.front();
    }

};

int main() {
    stackQueue s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

}