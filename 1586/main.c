#include <stdio.h>
#include <ctype.h>

#define DEBUG 0

double WEIGHT[] = {12.01f, 1.008, 16.00f, 14.01f};

int main() {
    freopen("data.in", "r", stdin);
    if (!DEBUG) {
        freopen("data.out", "w", stdout);
    }
    int cntCase;
    scanf("%d\n", &cntCase);
    for (int i = 0; i < cntCase; ++i) {
        int cntAtom[4] = {0, 0, 0, 0};
        int lastIndex = -1;
        int lastNum = 0;
        char c = 0;
        while (c != '\n') {
            if (scanf("%c", &c) <= 0) {
                c = '\n';
            }
            if (c >= '0' && c <= '9') {
                int num = c - '0';
                lastNum = lastNum * 10 + num;
            } else {
                if (lastIndex != -1) {
                    if (lastNum == 0) {
                        lastNum = 1;
                    }
                    cntAtom[lastIndex] += lastNum;
                }
                switch (c) {
                    case 'C':
                        lastIndex = 0;
                        break;
                    case 'H':
                        lastIndex = 1;
                        break;
                    case 'O':
                        lastIndex = 2;
                        break;
                    case 'N':
                        lastIndex = 3;
                        break;
                }
                lastNum = 0;
            }
        }
        double sum = 0;
        for (int i = 0; i < 4; ++i) {
            sum += cntAtom[i] * WEIGHT[i];
        }
        if (DEBUG) {
            printf("C: %d, H: %d, O: %d, N: %d\n", cntAtom[0], cntAtom[1], cntAtom[2], cntAtom[3]);
        }
        printf("%.3f\n", sum);
    }
}
