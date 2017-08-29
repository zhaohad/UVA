#include <stdio.h>

int MAX_N = 10000;
int RESULT[10001][10];

int main() {
    for (int i = 1; i <= MAX_N; ++i) {
        for (int j = 0; j < 10; ++j) {
            RESULT[i][j] = RESULT[i - 1][j];
        }
        int t = i;
        while (t) {
            int n = t % 10;
            RESULT[i][n] += 1;
            t /= 10;
        }
    }

    int cntCase;
    scanf("%d", &cntCase);
    for (int i = 0; i < cntCase; ++i) {
        int d;
        scanf("%d", &d);
        for (int j = 0; j < 10; ++j) {
            if (j != 0) {
                printf(" ");
            }
            printf("%d", RESULT[d][j]);
        }
        printf("\n");
    }

    return 0;
}
