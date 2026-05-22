bool isSymmetricTree(struct TreeNode* p, struct TreeNode* q) {
    if (p != NULL && q != NULL && p->val == q->val) {
        return isSymmetricTree(p->left, q->right) && isSymmetricTree(p->right, q->left);
    } else {
        return p == q;
    }
}

bool isSymmetric(struct TreeNode* root) {
	if (root != NULL) {
		return isSymmetricTree(root->left, root->right);
	} else {
		return true;
	}
}
