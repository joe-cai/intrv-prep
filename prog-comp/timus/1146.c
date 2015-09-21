#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100

int matrix[MAXN][MAXN];
int row[MAXN];
int main(int argc, char* argv[]) {
    int N;
    scanf("%d", &N);
    int i, j, k;
    for (i = 0; i < N; i++)
	for (j = 0; j < N; j++)
	    scanf("%d", &matrix[i][j]);

    int subsum, maxsum = matrix[0][0];
    for (i = 0; i < N; i++) {
	memset(row, 0, sizeof(row));
	for (j = i; j < N; j++) {
	    for (k = 0; k < N; k++)
		row[k] += matrix[j][k];
	    subsum = 0;
	    for (k = 0; k < N; k++) {
		subsum += row[k];
		if (maxsum < subsum) 
		    maxsum = subsum;
		if (subsum < 0)
		    subsum = 0;
	    }
	}
    }
    printf("%d\n", maxsum);
    return 0;
}
