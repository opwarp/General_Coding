// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

// https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Solution 1:
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        
        vector<TreeNode*> v1;
        v1.push_back(root);
        
        while(!v1.empty())
        {
            vector<TreeNode*> temp;
            vector<int> v2;
            for(int i=0; i<v1.size(); i++)
            {
                if(v1[i]->left)
                    temp.push_back(v1[i]->left);
                if(v1[i]->right)
                    temp.push_back(v1[i]->right);

                v2.push_back(v1[i]->val);
            }
            ret.push_back(v2);
            v1 = temp;
        }
        
        return ret;
    }
};

// Solution 2:
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q1;
        vector<int> vec;
        vector<vector<int>> ret;
        
        if(!root)
            return ret;
        
        q1.push(root);
        int l1 = 1;         // Number of nodes in current level
        int l2 = 0;         // Count for number of nodes in next level 
        while(!q1.empty())
        {
            while(l1--)
            {
                TreeNode* curr = q1.front();
                q1.pop();
                if(curr->left)
                {
                    q1.push(curr->left);
                    l2++;
                }
                if(curr->right)
                {
                    q1.push(curr->right);
                    l2++;
                }
                vec.push_back(curr->val);
            }
            if(vec.size())
            {
                ret.push_back(vec);
                vec.clear();
            }        
            l1 = l2;
            l2 = 0;
        }
        return ret;
    }
};
