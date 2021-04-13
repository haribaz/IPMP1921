class Solution {
public:
    string reverseWords(string s) {
        vector<string> tmp;
        string str="";
        string out="";
        for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ')
        {
            tmp.push_back(str);
            str = "";
        } else {
            str += s[i];
    }
        }
   
    tmp.push_back(str);
 
    int i;
    for (i = tmp.size() - 1; i > 0; i--) {
        out += tmp[i];
        out += " ";
    }
        out += tmp[0];
        return out;
}
    
};