class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> record;
        long long int total_sum=0;
        for(auto it:target) {
            record.push(it);
            total_sum+=it;
        }
        
        int n = target.size();
        if(n==1){
            return target[0]==1;
        }
        while(record.top()!=1){
		    total_sum-=record.top();
            if(total_sum==0 || total_sum>=record.top()) return false;
            int new_value = record.top()%(total_sum);
            if(total_sum!=1 && new_value==0) return false;
            record.pop();
            record.push(new_value);
            total_sum +=new_value;
            
        }
        return true;
    }
};