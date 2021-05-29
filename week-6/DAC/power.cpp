class Solution {
public:
    
    double helper(double x, long long int n) {
        if(n == 0)
            return 1;
        double temp = helper(x, n/2);
        if(n%2 == 0)
            return temp * temp;
        else
            return temp * temp * x;
    }
    
    
    double myPow(double x, int n) {
        long long int k = n;
        if(n >= 0) 
            return helper(x, k);
        else 
            return 1/helper(x, -k);
    }
};