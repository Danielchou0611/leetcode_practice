void moveZeroes(int *nums, int numsSize)
{
    int wp = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
            nums[wp++] = nums[i];
    }
    for (int i = numsSize - 1; i >= wp; i--)
        nums[i] = 0;
}