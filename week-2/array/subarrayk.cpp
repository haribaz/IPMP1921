#include<bits/stdc++.h>
using namespace std;

pair<int, int> subarraySum(vector<int>& nums) {
    int count=0, sum=0;
    unordered_map<int, int> m;
    m[0] = 0;
	for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(m.find(sum) != m.end())
            return {m[sum], i};
        m[sum] = i+1;
    }
    return {-1, -1};
}

int main()
{
    vector<int> arr{-3, 2, -3, 1, 6};
    pair<int, int> p = subarraySum(arr);
    cout<<p.first<<" "<<p.second;
    
}