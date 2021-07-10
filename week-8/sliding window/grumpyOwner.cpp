class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        
        for(int i=0;i<customers.size();i++){
            
            if(grumpy[i]==0){
                ans+=customers[i];
                customers[i]=0;
            }
        }
        
        
        int slide=0;
        
        for(int i=0;i<minutes;i++){
            slide+=customers[i];
        }
        
        int finalanstoadd=slide;
        
        
        for(int i=minutes;i<customers.size();i++){
            
            slide+=customers[i];
            slide-=customers[i- minutes];
            finalanstoadd=max(slide,finalanstoadd);
        }
        
        
        return finalanstoadd +  ans ;
    }
};