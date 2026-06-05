#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 100;  // initial capacity
    int count = 0;

    int **res = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    qsort(nums, numsSize, sizeof(int), compare);
    
    for (int i = 0; i < numsSize; ++i) {
        if ((i > 0) && (nums[i] == nums[i-1]))
            continue;

        int j = i + 1;
        int k = numsSize - 1;
        
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum > 0)
                --k;
            else if (sum < 0)
                ++j;
            else {
                if (count == capacity) {
                    capacity *= 2;

                    res = realloc(res, capacity * sizeof(int *));
                    *returnColumnSizes =
                        realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                res[count] = malloc(3 * sizeof(int));

                res[count][0] = nums[i];
                res[count][1] = nums[j];
                res[count][2] = nums[k];

                (*returnColumnSizes)[count] = 3;

                count++;
                ++j;

                while ((j < k) && (nums[j] == nums[j-1])) {
                    ++j;
                }
            }
        }
    }   

    *returnSize = count;
    return res;
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize = 0;
    int *returnColumnSizes = NULL;

    int **result = threeSum(
        nums,
        numsSize,
        &returnSize,
        &returnColumnSizes
    );

    printf("Found %d triplets:\n", returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("[");

        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);

            if (j < returnColumnSizes[i] - 1)
                printf(", ");
        }

        printf("]\n");
    }

    // Free memory allocated by threeSum
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    return 0;
}