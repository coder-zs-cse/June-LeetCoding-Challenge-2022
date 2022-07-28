class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum<x) return -1;
        int k = sum - x;
        int left=0,right=0;
        int n = nums.size();
        sum=0;
        int output=-1;
        while(right<n){
            sum+= nums[right];
            while(sum>k && left<=right) sum-=nums[left++];
            if(sum==k)  output = max(output,right-left+1);
            right++;
        }
        return output<0 ? -1 : n - output;
    }
};