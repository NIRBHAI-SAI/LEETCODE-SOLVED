class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0;
        int j= height.size() - 1;
        int w = 0;

        while(i<j){
            if(height[i] > height[j]){
                w = max (w, (j-i) * height[j]);
                j--;
            }
            else{
                w = max (w, (j-i) * height[i]);
                i++;
            }
        }
        return w;
        
    }
};