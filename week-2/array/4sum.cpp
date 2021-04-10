#include<bits/stdc++.h>
using namespace std;

void fourSum(vector<int> arr, int target) {
    unordered_map<int, pair<int, int>> map;
    int size = arr.size();
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            map[arr[i] + arr[j]] = {i, j};
        }
    }

    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            int sum = target - (arr[i] + arr[j]);
            if(map.find(sum) != map.end()) {
                pair<int, int> temp = map[sum];
                if(temp.first != i && temp.first != j && temp.second != i && temp.second != j) {
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[temp.first]<<" "<<arr[temp.second];
                    return;
                }
            }
        }
    }

}

int main() {
    
    vector<int> arr{1, 2, 3, 4, 5, 6};
    int target = 14;
    fourSum(arr, target);
}