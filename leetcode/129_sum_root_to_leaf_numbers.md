#Sum Root to Leaf Numbers
##Recursive solution
```C++
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        work(ans, root, 0);
        return ans;
    }
    void work(int& ans, TreeNode* root, int partSum) {
        if (root == NULL) return;
        partSum = 10 * partSum + root->val;
        if (root->left == NULL && root->right == NULL) {
            ans += partSum;
            return;
        }
        work(ans, root->left, partSum);
        work(ans, root->right, partSum);
    }
};
```

##Iterative solution
```C++
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        queue<int> nums;
        nums.push(root->val);

        int ans = 0;
        while (!nodes.empty() && !nums.empty()) {
            TreeNode* currNode = nodes.front();
            int currNum = nums.front();
            if (currNode->left == NULL && currNode->right == NULL)
                ans += currNum;
            if (currNode->left != NULL) {
                nodes.push(currNode->left);
                nums.push(currNum * 10 + currNode->left->val);
            }
            if (currNode->right != NULL) {
                nodes.push(currNode->right);
                nums.push(currNum * 10 + currNode->right->val);
            }
            nodes.pop();
            nums.pop();
        }
        return ans;
    }
};
```