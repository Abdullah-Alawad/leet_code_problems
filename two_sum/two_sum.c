#include <stdio.h>
#include <stdlib.h>

int	*twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int	*res = malloc(sizeof(int) * 2);
	*returnSize = 2;

	int j;
	for(int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				res[0] = i;
				res[1] = j;
				return (res);
			}
		}
	}
	res[0] = 0;
	res[1] = 1;
	return (res);
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int returnSize;
    
    int* result = twoSum(nums, numsSize, target, &returnSize);
    printf("Indices to get %d: ", target);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
}