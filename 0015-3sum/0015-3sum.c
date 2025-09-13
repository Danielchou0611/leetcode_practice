/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// find three number of sum equal to 0

// O(n^2)
#include <stdio.h>
#include <stdlib.h>
void swap(int *num1, int *num2) // c沒有&參照
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

// 因為回傳值已經有其他用意,而caller(leetcode test)不知道有多少解答跟解答的size所以需要returnSize跟returnColumnSizes
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) // returnSize告訴caller有多少組triplets解答, returnColumnSizes告訴caller每組解答的長度
{
    for (int i = 0; i < numsSize; i++) // sort
        for (int j = i; j < numsSize; j++)
            if (nums[i] > nums[j]) // 小到大
                swap(&nums[i], &nums[j]);

    *returnSize = 0;                                                         // 總共幾組先初始化
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * numsSize * numsSize); // 配置n行,但每行也只存一個(記錄每行有幾個空間)
    int **ret = (int **)malloc(sizeof(int *) * numsSize * numsSize);         // 先配置n*n空間(避免overflow)
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i == 0 || nums[i] != nums[i - 1]) // 避免重複算到一樣的數值
        {
            int left = i + 1, right = numsSize - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) // 右邊大
                    right--;
                else if (sum < 0)
                    left++;
                else
                {
                    ret[(*returnSize)] = (int *)malloc(sizeof(int) * 3); // 將每一行配置三個空間
                    (*returnColumnSizes)[(*returnSize)] = 3;             // 記錄此行長度為3
                    ret[(*returnSize)][0] = nums[i];
                    ret[(*returnSize)][1] = nums[left];
                    ret[(*returnSize)][2] = nums[right];
                    (*returnSize)++;
                    left++;
                    while (left != right && nums[left] == nums[left - 1]) // 一樣的跳過, 避免重複加入
                        left++;
                }
            }
        }
    }
    return ret;
}
