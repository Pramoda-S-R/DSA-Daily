#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void print_arr(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size - 1; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size - 1]);
}

int maxSumRangeQuery(int* nums, int numsSize, int** requests, int requestsSize, int* requestsColSize) {
    int *diff = calloc(numsSize + 1, sizeof(int));
    for (int i = 0; i < requestsSize; ++i) {
        diff[requests[i][0]]++;
        diff[requests[i][1] + 1]--;
    }
    
    for (int i = 1; i < numsSize + 1; ++i) {
        diff[i] += diff[i - 1];
    }
    
    qsort(diff, numsSize + 1, sizeof(int), compare);
    qsort(nums, numsSize, sizeof(int), compare);
    
    long long sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum = (sum + 1LL * nums[i] * diff[i + 1]) % 1000000007;
    }

    free(diff);

    return sum;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 10};

    int request0[] = {0, 2};
    int request1[] = {1, 3};
    int request2[] = {1, 1};

    int *requests[] = {
        request0,
        request1,
        request2
    };

    int requestsColSize[] = {2, 2, 2};
    
    int sum = maxSumRangeQuery(nums, 6, requests, 3, requestsColSize);

    printf("%d\n", sum);
    return 0;
}