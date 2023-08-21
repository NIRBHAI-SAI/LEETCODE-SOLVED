class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==1){
            return nums[0];
        }

        int a = nums[0];
        int b =0;
        int c;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take += b;
            int notake = a;
            c = max(take,notake);
            b =a;
            a =c; 
        }
        return a;
        
    }
};