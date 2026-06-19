struct TreeNode *goRightAndDelete(struct TreeNode *node, int *val) {
	if (node->right == NULL) {
        struct TreeNode *tmp = node->left;
		*val = node->val;
		free(node);
		return tmp;
	} else {
		node->right = goRightAndDelete(node->right, val);
		return node;
	}
}

struct TreeNode* helper(struct TreeNode* node, int key) {
	if (node != NULL) {
		if (node->val == key) {
			if (node->left == NULL && node->right == NULL) {
				free(node);
				return NULL;
			} else if (node->left != NULL && node->right != NULL) {
				node->left = goRightAndDelete(node->left, &node->val);
				return node;
			} else if (node->left != NULL && node->right == NULL) {
				node->left = goRightAndDelete(node->left, &node->val);
				return node;
			} else if (node->left == NULL && node->right != NULL) {
				struct TreeNode *ret = node->right;
				free(node);
				return ret;
			}
		} else {
			if (key < node->val) {
				node->left = helper(node->left, key);
			} else {
				assert(key > node->val);
				node->right = helper(node->right, key);
			}
            return node;
		}
	} else {
		return NULL;
	}
    assert(0);
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
	return helper(root, key);
}
