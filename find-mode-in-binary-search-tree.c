int findOutSize(struct TreeNode* node) {
	if (node == NULL) {
		return 0;
	}
	return 1 + findOutSize(node->left) + findOutSize(node->right);
}

void helper(struct TreeNode* node, int *res, int *len, int *gstreak, int *cstreak, int *cstreakVal) {
	if (node != NULL) {
		helper(node->left, res, len, gstreak, cstreak, cstreakVal);
		
		if (node->val == *cstreakVal) {
			*cstreak += 1;
		} else {
			*cstreakVal = node->val;
			*cstreak = 1;
		}
		if (*cstreak > *gstreak) {
			*gstreak = *cstreak;
			*len = 0;
		}
		if (*cstreak == *gstreak) {
			res[*len] = node->val;
			*len += 1;
		}

		helper(node->right, res, len, gstreak, cstreak, cstreakVal);
	}
}

int* findMode(struct TreeNode* root, int* returnSize) {
	int resSize = findOutSize(root);
	int *res = malloc(resSize * sizeof(int));

    int cstreak = 0;
    int gstreak = 0;
    int cstreakVal = 0;

    *returnSize = 0;
	helper(root, res, returnSize, &cstreak, &gstreak, &cstreakVal);

	return res;
}
