#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int	comp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

bool containsDuplicate(int* nums, int numsSize) {
	int	i;
	qsort(nums, numsSize, sizeof(int), comp);

	i = 0;
	while (i < numsSize - 1)
	{
		if (nums[i] == nums[i + 1])
			return (true);
		i++;
	}
	return (false);
}

int	main(void)
{
	int	arr[] = {3,1,3};
	int	size = sizeof(arr) / sizeof(arr[0]);
	printf("size of arr: %d\n", size);
	if (containsDuplicate(arr, size))
		printf("there is duplicates!\n");
	else
		printf("NO duplicates\n");
}