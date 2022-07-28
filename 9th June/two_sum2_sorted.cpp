class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,e=nums.size()-1;
        while(i<e){
            if(nums[i]+nums[e]>target)e--;
            else if(nums[i]+nums[e]<target) i++;
            else return {i+1,e+1};
        }
        return {};
    }
};
