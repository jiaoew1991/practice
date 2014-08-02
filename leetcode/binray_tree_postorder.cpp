#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        stack<TreeNode*> waitingStack;
        waitingStack.push(root);
        while (!waitingStack.empty()) {
            TreeNode* node = waitingStack.top();
            if (node->) {
                
            }
        }
    }
};
int main(int argc, const char *argv[])
{
    return 0;
}
