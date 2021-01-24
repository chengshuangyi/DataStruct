int Size(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + Size(root->left) + Size(root->right);
}

void _preorderTraversal(struct TreeNode* root, int *array, int *pi)
{
	if (root == NULL)
		return;

	array[*pi] = root->val;
	(*pi)++;
	_preorderTraversal(root->left, array, pi);
	_preorderTraversal(root->right, array, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	// if(root == NULL)
	//     return NULL;

	int size = Size(root);
	int *array = (int *)malloc(sizeof(int)*size);

	int i = 0;
	_preorderTraversal(root, array, &i);
	*returnSize = size;
	return array;
}