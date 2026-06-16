#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFFSET 100001
#define MAX_VAL (2 * OFFSET)
#define MAX_SIZE 100001

static int adj[MAX_VAL][2];
static int adj_count[MAX_VAL];
static int result[MAX_SIZE];

// NOLINTNEXTLINE(readability-identifier-naming)
int* restoreArray(int** adjacent_pairs, int adjacent_pairs_size,
                  int* adjacent_pairs_col_size, int* return_size) {
    (void)adjacent_pairs_col_size;

    memset(adj_count, 0, sizeof(adj_count));

    // Build adjacency list
    for (int i = 0; i < adjacent_pairs_size; i++) {
        int idx0 = adjacent_pairs[i][0] + OFFSET;
        int idx1 = adjacent_pairs[i][1] + OFFSET;
        adj[idx0][adj_count[idx0]++] = idx1;
        adj[idx1][adj_count[idx1]++] = idx0;
    }

    // Find starting element (endpoint with only 1 neighbor)
    int start = -1;
    for (int i = 0; i < adjacent_pairs_size; i++) {
        int idx0 = adjacent_pairs[i][0] + OFFSET;
        if (adj_count[idx0] == 1) {
            start = idx0;
            break;
        }
        int idx1 = adjacent_pairs[i][1] + OFFSET;
        if (adj_count[idx1] == 1) {
            start = idx1;
            break;
        }
    }

    // Walk the graph
    int n = adjacent_pairs_size + 1;
    result[0] = start - OFFSET;
    int prev = -1;
    int curr = start;

    for (int i = 1; i < n; i++) {
        int next = adj[curr][0];
        if (next == prev) {
            next = adj[curr][1];
        }
        result[i] = next - OFFSET;
        prev = curr;
        curr = next;
    }

    *return_size = n;
    return result;
}

int main(void) {
    int **pairs = calloc(3, sizeof(int *));

    for (int i = 0; i < 3; i++) {
        pairs[i] = calloc(2, sizeof(int));
    }

    pairs[0][0] = 2;
    pairs[0][1] = 1;

    pairs[1][0] = 3;
    pairs[1][1] = 4;

    pairs[2][0] = 3;
    pairs[2][1] = 2;

    int pairs_size = 3;
    int pairs_col_size = 2;
    int return_size;

    int *res = restoreArray(
        pairs,
        pairs_size,
        &pairs_col_size,
        &return_size
    );

    for (int i = 0; i < return_size; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    for (int i = 0; i < pairs_size; i++) {
        free(pairs[i]);
    }
    free(pairs);

    return 0;
}