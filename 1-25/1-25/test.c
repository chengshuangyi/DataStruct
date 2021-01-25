bool isSameTree(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL && t == NULL)
		return true;

	if (s == NULL || t == NULL)
		return false;

	if (s->val != t->val)
		return false;

	return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (s == NULL)
		return false;

	if (isSameTree(s, t))
		return true;

	return isSubtree(s->left, t) || isSubtree(s->right, t);
}