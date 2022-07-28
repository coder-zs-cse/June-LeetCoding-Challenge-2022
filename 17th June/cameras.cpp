/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 0 : with camera 
    // 1 : without camera, but covered
    // 2: without camera and uncovered
    enum node_states { BHAGWAAN_BHAROSE, WITHOUT_BULB_COVERED, WITH_BULB };
    
    int postorder(TreeNode *root,int &camera){
        if(!root) return WITHOUT_BULB_COVERED;
        
        int left = postorder(root->left,camera);
        int right = postorder(root->right,camera);
        
        if(left== BHAGWAAN_BHAROSE || right== BHAGWAAN_BHAROSE){
            camera++;
            return WITH_BULB;
        }
        
        if(left== WITH_BULB && right== WITH_BULB)  return WITHOUT_BULB_COVERED;
        
        if(left==WITHOUT_BULB_COVERED && right == WITHOUT_BULB_COVERED) return BHAGWAAN_BHAROSE;
        
        return WITHOUT_BULB_COVERED;
    }
    int minCameraCover(TreeNode* root) {
        int camera =0;
        if(postorder(root,camera)== BHAGWAAN_BHAROSE) camera++;
        return camera;
    }
};