#include<bits/stdc++.h>
using namespace std;

void printList(vector<int> a) {
    for(int i=0; i<a.size(); i++) {
        cout<<a[i]<<" ";
    }
}

int getIndexToInsert(vector<int> v, int low, int high, int k){

    int start = low;
    int end = high - 1;

    while(start <= end){
        int mid = (start + (end-start)/2);

        if(v[mid] == k){
            return mid;
        }
        else if(v[mid] < k){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return start;

}

int main(){

    vector<int> a = {12,4,5,3,8,7};

    vector<double> medians;
    vector<int> numbers;
    int s;
    double med;
    
    numbers.push_back(a.front());
    medians.push_back(double(a.front()));

    for(auto i=a.begin()+1; i<a.end(); i++){
        s = numbers.size();
        int c = getIndexToInsert(numbers,0,s,*i);
        cout<<c<<endl;
        numbers.insert(numbers.begin()+c,*i);
        s++;
        if(s%2==1){
            med = numbers[(s/2)];
            medians.push_back(med);
        }
        else{
            med = (numbers[(s/2)]+numbers[(s-1)/2])/2.0;
            medians.push_back(med);
        }
    }
    cout<<endl<<endl;

    for(auto i=medians.begin(); i<medians.end(); i++){
        cout<<fixed<<setprecision(1)<<*i<<" ";
    }
    return 0;
}