#include <stdio.h>
#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
	int	*res;
	int	pos;

	*returnSize = 0;
	for(int i = 0; i < numsSize; i++)
	{
		pos = abs(nums[i]) - 1;
		if (nums[pos] > 0)
		{
			nums[pos] = -nums[pos];
			(*returnSize)++;
		}
	}
	*returnSize = numsSize - *returnSize;
	res = malloc(sizeof(int) * (*returnSize));
	int	j = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] > 0)
		{
			res[j] = i + 1;
			j++;
		}
	}
	return (res);
}

int main() {
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int* disappearedNumbers = findDisappearedNumbers(nums, numsSize, &returnSize);
    printf("Disappeared numbers: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", disappearedNumbers[i]);
    }
    printf("\n");
    free(disappearedNumbers);
}