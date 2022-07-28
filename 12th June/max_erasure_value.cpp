

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> record;
        int max_sum=0;
        int sum=0;
        int left = 0;
        for(int i=0;i<nums.size();i++){
            auto check = record.find(nums[i]);
            if(check!=record.end()){
                while(left<=record[nums[i]]){
                    record.erase(nums[left]);
                    sum-=nums[left++];
                }  
            }
            sum+=nums[i];
            record[nums[i]] = i;
            max_sum = max(max_sum,sum);
        }
        return max_sum;
    }
};