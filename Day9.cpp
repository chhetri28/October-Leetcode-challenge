//  Serialize and Deserialize BST
/*
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]

Example 2:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 104].
    0 <= Node.val <= 104
    The input tree is guaranteed to be a binary search tree.


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string getNextNode(string const& data, int& offset) {
        int end = data.find(',', offset);
        if(end == string::npos) {
            end = data.length();
        }
        string sNodeValue = data.substr(offset, end - offset);
        offset = end + 1;
        
        return sNodeValue;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if(!root) return result;
        queue <TreeNode*> Q;
        Q.push(root);
        result += to_string(root->val);
        result += ',';
        while(!Q.empty()) {
            TreeNode* node = Q.front();
            if(node->left) {
                result += to_string(node->left->val);
                result += ',';
                Q.push(node->left);
            } else {
                result += "#,";
            }
            if(node->right) {
                result += to_string(node->right->val);
                result += ',';
                Q.push(node->right);
            } else {
                result += "#,";
            }
            Q.pop();
        }
        // triming , and # from end
        int i = result.size() - 1;
        for(--i; i >= 0 and result[i] == '#'; i -= 2);
        return result.substr(0, i + 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        if(data.empty()) return root;
        queue<TreeNode*> Q;
        int offset = 0;
        int nodeValue = stoi(getNextNode(data, offset));
        root = new TreeNode(nodeValue);
        Q.push(root);
        while(!Q.empty()) {
            TreeNode* node = Q.front();
            if(offset < data.length()) {
                string sValue = getNextNode(data, offset);
                if(sValue != "#") {
                    int leftNodeValue = stoi(sValue);
                    node->left = new TreeNode(leftNodeValue);
                    Q.push(node->left);  
                }
            }
            if(offset < data.length()) {
                string sValue = getNextNode(data, offset);
                if(sValue != "#") {
                    int rightNodeValue = stoi(sValue);
                    node->right = new TreeNode(rightNodeValue);
                    Q.push(node->right);  
                }
            }
            Q.pop();
        }
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;