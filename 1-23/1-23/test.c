int Depth(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	int leftDepth = Depth(root->left);
	int rightDepth = Depth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	int gap = Depth(root->left) - Depth(root->right);
	if (abs(gap) > 1)
		return false;
	return isBalanced(root->left) && isBalanced(root->right);
}