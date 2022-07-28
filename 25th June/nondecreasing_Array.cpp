class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int prev;
        int i;
        int n = nums.size();
        for(i=0;i<nums.size();i++){
            if(i<n-1 && nums[i]>nums[i+1]){
                if(i>0 && nums[i+1]<nums[i-1]){
                    prev = nums[i];
                }
                else{
                    prev = nums[i+1];
                    
                }
                i+=2;
                break;
            }
        }
        for(;i<n;i++){
            if(prev>nums[i]) return false;
            prev = nums[i];
        }
        
        return true;
    }
};