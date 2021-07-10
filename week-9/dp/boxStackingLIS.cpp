struct box {
        int h, l, w;
    };
    
    static bool comp(struct box a, struct box b) {
        if(a.l*a.w > b.l*b.w) {
            return true;
        } else {
            return false;
        }
        
    }
    
    int maxHeight(int height[],int width[],int length[],int n)
    {
        int size = 3*n;
        box arr[size];
        int k=0;
        for(int i=0; i<n; i++) {
            arr[k].h = height[i];
            arr[k].l = max(length[i], width[i]);
            arr[k].w = min(length[i], width[i]);
            k++;
            
            arr[k].h = width[i];
            arr[k].l = max(length[i], height[i]);
            arr[k].w = min(length[i], height[i]);
            k++;
            
            arr[k].h = length[i];
            arr[k].l = max(height[i], width[i]);
            arr[k].w = min(height[i], width[i]);
            k++;
        }
            
            sort(arr, arr+size, comp);
            
            int dp[size];
            for(int i=0; i<size; i++) {
                dp[i] = arr[i].h;
            }
            
            for(int i=1; i<size; i++) {
                for(int j=0; j<i; j++) {
                    if(arr[j].l > arr[i].l && arr[j].w > arr[i].w) {
                        dp[i] = max(dp[i], dp[j] + arr[i].h);
                    }
                }
            }
            int ans = 0;
            for(int i=0; i<size; i++) {
                ans = max(ans, dp[i]);
            }
            return ans;
        }
        
};