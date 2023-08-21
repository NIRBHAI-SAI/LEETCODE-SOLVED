class Solution {
    int rob2(vector<int>& nums) {
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
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];

        vector<int> temp1,temp2;

        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        return max(rob2(temp1),rob2(temp2));
        
        
    }
};