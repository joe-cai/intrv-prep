#Convert Sorted Array to Binary Search Tree
```C++
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(nums, 0, nums.size() - 1);
    }
    TreeNode* arrayToBST(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = arrayToBST(nums, start, mid - 1);
        root->right = arrayToBST(nums, mid + 1, end);
        return root;
    }
};
```
