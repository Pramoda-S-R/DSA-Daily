#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static inline double dmax(double a, double b) { return a > b ? a : b; }
static inline double dmin(double a, double b) { return a < b ? a : b; }

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *arr1, *arr2;
    int m, n;
    if (nums1Size <= nums2Size) {
        arr1 = nums1;
        arr2 = nums2;
        m = nums1Size;
        n = nums2Size;
    } else {
        arr1 = nums2;
        arr2 = nums1;
        m = nums2Size;
        n = nums1Size;
    }

    int left = 0;
    int right = m;

    
    while (left <= right) {
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;

        double left1  = (i == 0) ? -INFINITY : arr1[i - 1];
        double right1 = (i == m) ?  INFINITY : arr1[i];

        double left2  = (j == 0) ? -INFINITY : arr2[j - 1];
        double right2 = (j == n) ?  INFINITY : arr2[j];

        if ((left1 <= right2) && (left2 <= right1)) {
            if (((m + n) % 2) == 1) 
                return dmax(left1, left2);
            return (dmax(left1, left2) + dmin(right1, right2)) / 2.0;
        }
        else if (left1 > right2)
            right = i - 1;
        else
            left = i + 1;
    }

    return 0.0;
}

int main() {
    int nums1[] = {1, 2, 3};
    int nums2[] = {-1, 0, 2};

    printf("%lf", findMedianSortedArrays(nums1, 3, nums2, 3));

    return 0;
}