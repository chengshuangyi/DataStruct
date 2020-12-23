int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;
	int pre = 0;
	int cur = 1;
	while (cur < numsSize)
	{
		if (nums[pre] != nums[cur])
		{
			pre++;
			nums[pre] = nums[cur];
			cur++;
		}
		else
		{
			cur++;
		}
	}
	return pre + 1;

}