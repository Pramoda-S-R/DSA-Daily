#include <stdio.h>
#include <stdlib.h>

int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize) {
    int *out = calloc(n + 1, sizeof(int));

    for (int i = 0; i < bookingsSize; ++i) {
        int seats = bookings[i][2];
        out[bookings[i][0] - 1] += seats;
        out[bookings[i][1]] -= seats;
    }

    for (int i = 1; i < n; ++i) {
        out[i] += out[i - 1];
    }

    *returnSize = n;
    return out;
}

int main() {
    int row0[] = {1,2,10};
    int row1[] = {2,3,20};
    int row2[] = {2,5,25};

    int* bookings[] = {row0, row1, row2};
    int colSizes[] = {3,3,3};

    int arr_size = 0;
    int *res = corpFlightBookings(bookings, 3, colSizes, 5, &arr_size);

    for (int i = 0; i < arr_size; ++i) {
        printf("%d, ", res[i]);
    }
    free(res);
    return 0;
}