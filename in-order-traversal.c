/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traverse(struct TreeNode *node, int *arr, int *len) {
    if (node == NULL) {
        return;
    }
    traverse(node->left, arr, len);
    if (arr != NULL) {
        arr[*len] = node->val;
    }
    *len += 1;
    traverse(node->right, arr, len);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    traverse(root, NULL, returnSize);
    int *out = malloc(sizeof(int) * *returnSize);
    *returnSize = 0;
    traverse(root, out, returnSize);
    return out;
}
