#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(
    int node,
    int **graph,
    int graphSize,
    int *graphColSize,
    int *path,
    int pathSize,
    int ***result,
    int *returnSize,
    int **returnColumnSizes
) {
    path[pathSize++] = node;

    if (node == graphSize - 1) {
        (*result)[*returnSize] = malloc(pathSize * sizeof(int));
        memcpy((*result)[*returnSize], path, pathSize * sizeof(int));

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < graphColSize[node]; i++) {
        dfs(graph[node][i],
            graph,
            graphSize,
            graphColSize,
            path,
            pathSize,
            result,
            returnSize,
            returnColumnSizes);
    }
}

int** allPathsSourceTarget(
    int **graph,
    int graphSize,
    int *graphColSize,
    int *returnSize,
    int **returnColumnSizes
) {
    // Maximum possible number of paths for graphSize <= 15
    int capacity = 10000;

    int **result = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    *returnSize = 0;

    int path[graphSize];

    dfs(
        0,
        graph,
        graphSize,
        graphColSize,
        path,
        0,
        &result,
        returnSize,
        returnColumnSizes
    );

    return result;
}

int main() {
    int row0[] = {1, 2};
    int row1[] = {3};
    int row2[] = {3};
    int *row3 = NULL;   // No outgoing edges

    int *graph[] = {
        row0,
        row1,
        row2,
        row3
    };

    int graphColSize[] = {2, 1, 1, 0};
    int graphSize = 4;

    int returnSize = 0;
    int *returnColumnSizes = NULL;

    int **result = allPathsSourceTarget(
        graph,
        graphSize,
        graphColSize,
        &returnSize,
        &returnColumnSizes
    );

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    return 0;
}