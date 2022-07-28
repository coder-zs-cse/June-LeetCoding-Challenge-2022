class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> ladder_diff;
        int bricks_diff=0;
        int i;
        for(i=1;i<heights.size();i++){
            int diff = heights[i] - heights[i-1];
            if(diff<=0) continue;
            if(ladder_diff.size()<ladders)  ladder_diff.push(diff);
            else{
                if(ladders && ladder_diff.top()<diff){
                    if(bricks_diff + ladder_diff.top()<=bricks){
                        bricks_diff+=ladder_diff.top();
                        ladder_diff.pop();
                        ladder_diff.push(diff);
                    }
                    else   break;
                }
                else{
                    if(bricks_diff + diff <=bricks)  bricks_diff+=diff;
                    else break;
                }
            }
        }
        return i-1;
    }
};