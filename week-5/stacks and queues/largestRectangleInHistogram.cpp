class Solution {
public:
    
    void helper1(vector<int> &heights, vector<int> &smallestLeft, int n) {
         stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty()) {
                smallestLeft[i] = -1;
            } else {
                smallestLeft[i] = st.top();
            }
            st.push(i);
        }
    }
    
    void helper2(vector<int> &heights, vector<int> &smallestRight, int n) {
         stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty()) {
                smallestRight[i] = n;
            } else {
                smallestRight[i] = st.top();
            }
            st.push(i);
        }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> smallestLeft(n);
        vector<int> smallestRight(n);
        int ans = INT_MIN;
        helper1(heights, smallestLeft, n);
        helper2(heights, smallestRight, n);
        
        for(int i=0; i<n; i++) {
            int a = smallestLeft[i]+1;
            int b = smallestRight[i]-1;

            int temp = heights[i]*(b-a+1);
            ans = max(ans, temp);
        }
        return ans;
    }
};