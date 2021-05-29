class Solution {
public:
    string removeKdigits(string str, int k) {
        if(str.length() <= k)
            return "0";
        if(k == 0)
            return str;
        
        stack <char> s;
        
        s.push(str[0]);
        
        for(int i = 1; i<str.length(); i++){
            while(k>0 && !s.empty() && str[i]<s.top()){
                k--;
                s.pop();
            }
            s.push(str[i]);
            
        }
        
        while(k && !s.empty()){
            k--;
            s.pop();
        }
        string res = "";
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        cout<<res<<endl;
        int i=0;
        while(res[i] == '0') {
            res.erase(0, 1);
        }
        if(res.size() == 0)
            return "0";
        else
        return res;
    }
};