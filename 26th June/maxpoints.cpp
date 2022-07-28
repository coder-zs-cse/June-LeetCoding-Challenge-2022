class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left=0;
        int n = cardPoints.size();
        int right = n-k-1;
        int sum=0;
        for(int i=0;i<n-k-1;i++) sum+=cardPoints[i]; 
        int minsum = sum;
        int total_sum=sum;
        while(right+1<n){
            sum-=cardPoints[left++];
            sum+=cardPoints[++right];
            total_sum+=cardPoints[right];
            minsum = min(minsum,sum);
        }
        
        return total_sum-minsum;
    }
};