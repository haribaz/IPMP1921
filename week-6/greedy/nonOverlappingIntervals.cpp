bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
class Solution {
public:
    
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int i=0, j, ans=0;
        for(j=1; j<intervals.size(); j++) {
            int currEnd = intervals[i][1];
            int nextStart = intervals[j][0];
            int nextEnd = intervals[j][1];
            if(currEnd > nextStart) {
                ans++;
                if(currEnd > nextEnd) {
                    i=j;
                }
            } else {
                i=j;
            }
        }
        return ans;
    }
};