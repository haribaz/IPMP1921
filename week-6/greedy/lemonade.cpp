class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int f = 0, t = 0;
    
    for(auto &i : bills){
      switch(i){
        case 5 : f++; break;
        case 10: f--, t++; break;
        default : if(t) t--, f--;
                  else f -= 3;
      }
      if(f < 0 || t < 0) return false;
    }
    
    return true; 
    }
};