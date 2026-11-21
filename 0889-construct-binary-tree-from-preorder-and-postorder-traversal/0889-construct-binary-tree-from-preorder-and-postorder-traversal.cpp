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

    TreeNode *solve(int preStart, int preEnd, int postStart, vector<int> &preorder, unordered_map<int,int> &m)
    {
        if(preStart>preEnd) return NULL;

        int val = preorder[preStart];
        TreeNode *root = new TreeNode(val);

        if(preStart==preEnd) return root;

        int leftRoot = preorder[preStart+1];
        int index = m[leftRoot];
        int numSize = index - postStart + 1;

        root->left = solve(preStart+1, preStart+numSize, postStart, preorder, m);
        root->right = solve(preStart+numSize+1,preEnd,index+1,preorder,m);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();

        unordered_map<int,int>m;
        for(int i=0;i<n;i++) m[postorder[i]] = i;

        return solve(0,n-1,0,preorder,m);
    }
};