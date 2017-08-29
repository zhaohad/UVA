#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("data.in", "w", stdout);
    int cntCase = 1000000;
    printf("%d\n", cntCase);
    srand((unsigned) 0);
    for (int i = 0; i < cntCase; ++i) {
        int len = rand() % 80 / 3 + 1;
        for (int j = 0; j < len; ++j) {
                int isC = rand() % 4;
                switch (isC) {
                    case 0:
                        printf("C");
                    break;
                    case 1:
                        printf("H");
                    break;
                    case 2:
                        printf("N");
                    break;
                    case 3:
                        printf("O");
                    break;
                }
                isC = rand() % 99 + 1;
                if (isC > 1) {
                    printf("%d", isC);
                }
        }
        printf("\n");
    }
}
