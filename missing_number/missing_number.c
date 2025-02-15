#include <stdio.h>
#include <stdlib.h>

int	comp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	missingNumber(int* nums, int numsSize)
{
	int	i;

	i = 0;
	qsort(nums, numsSize, sizeof(int), comp);
	while (i < numsSize - 1)
	{
		if ((nums[i + 1] - nums[i]) > 1)
			return (nums[i] + 1);
		i++;
	}
	if (nums[0] == 0)
		return (nums[i] + 1);
	else
		return (nums[0] - 1);
}

int	main(void)
{
	int	nums[] = {0,1};
	int	size = sizeof(nums) / sizeof(nums[0]);
	printf("missing number: %d\n", missingNumber(nums, size));
}