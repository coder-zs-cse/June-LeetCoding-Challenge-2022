class Solution {
public:
   #define pi pair<int,int>
    int findKthLargest(vector<int>& nums, int k) {
        //priority_queue<int> record; // max heap
        priority_queue<int,vector<int>, greater<int>> record;
        for(int i=0;i<nums.size();i++){
            if(record.size()<k) record.push(nums[i]);
            else if(nums[i]>record.top()){
                record.pop();
                record.push(nums[i]);
            }
        }
        // N = 10, K = 10
        return record.top();
    }
};
// 2 3 4 5 6 
// priority is max heap 
// 5 10 45 23
// min priority queue
//     3 2 3 1 2 4 5 5 6
//     k = 4
// set of max      4 5 5 6
//     6 3 5 10 2 3 4
//     k = 4
//     pq  = 4 5 6 10 
