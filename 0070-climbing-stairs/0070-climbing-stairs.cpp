class Solution {
public:
    int climbStairs(int n) {
        int a = 0;
        int b = 1;
        int c;
        for(int i=0;i<n;i++){
            c = b+a;
            a = b;
            b = c;
            //cout<<c<<endl;
        }        
        return b;
    }
};