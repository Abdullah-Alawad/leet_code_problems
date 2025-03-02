#include <stdlib.h>
#include <stdio.h>


int	*smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize)
{
	int	*res;
	int num;
	int count;

	res = malloc(sizeof(int) * numsSize);
	*returnSize = numsSize;
	for (int i = 0; i < numsSize; i++)
	{
		num = nums[i];
		count = 0;
		for (int i = 0; i < numsSize; i++)
		{
			if (num > nums[i])
				count++;
		}
		res[i] = count;
	}
	return (res);
}

int main() {
    int nums[] = {8, 1, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int* result = smallerNumbersThanCurrent(nums, numsSize, &returnSize);
    printf("Num of smaller nums: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
}