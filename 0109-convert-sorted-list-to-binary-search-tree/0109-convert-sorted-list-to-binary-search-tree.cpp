/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* _curr = nullptr;
    TreeNode* buildTree(int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* left_child = buildTree(left, mid - 1);
        TreeNode* _root = new TreeNode(_curr->val);
        _root->left = left_child;
        _curr = _curr->next;
        _root->right = buildTree(mid + 1, right);

        return _root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;

        auto get_len = [](ListNode* head) -> int {
            int len = 0;
            while (head) {
                len++;
                head = head->next;
            }
            return len;
        };

        int node_count = get_len(head);
        _curr = head;

        return buildTree(0, node_count - 1);
    }
};