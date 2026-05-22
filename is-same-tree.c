bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p != NULL && q != NULL && p->val == q->val) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    } else {
        return p == q;
    }
}
