#include <stdio.h>
#include <string.h>


int isPalindrome(char buf[]);
int isMirrored(char buf[]);

int MIRROR_MAP[10000];

int main() {
    freopen("data.in", "r", stdin);
    char buf[1000000];
    MIRROR_MAP['A'] = 'A';
    MIRROR_MAP['E'] = '3';
    MIRROR_MAP['H'] = 'H';
    MIRROR_MAP['I'] = 'I';
    MIRROR_MAP['J'] = 'L';
    MIRROR_MAP['L'] = 'J';
    MIRROR_MAP['M'] = 'M';
    MIRROR_MAP['O'] = 'O';
    MIRROR_MAP['S'] = '2';
    MIRROR_MAP['T'] = 'T';
    MIRROR_MAP['U'] = 'U';
    MIRROR_MAP['V'] = 'V';
    MIRROR_MAP['W'] = 'W';
    MIRROR_MAP['X'] = 'X';
    MIRROR_MAP['Y'] = 'Y';
    MIRROR_MAP['Z'] = '5';
    MIRROR_MAP['1'] = '1';
    MIRROR_MAP['2'] = 'S';
    MIRROR_MAP['3'] = 'E';
    MIRROR_MAP['5'] = 'Z';
    MIRROR_MAP['8'] = '8';
    while (scanf("%s", buf) > 0) {
        int isP = isPalindrome(buf);
        int isM = isMirrored(buf);
        printf("%s", buf);
        if (isP && isM) {
            printf(" -- is a mirrored palindrome.\n");
        } else if (isP) {
            printf(" -- is a regular palindrome.\n");
        } else if (isM) {
            printf(" -- is a mirrored string.\n");
        } else {
            printf(" -- is not a palindrome.\n");
        }
        printf("\n");
    }
}

int isPalindrome(char buf[]) {
    int len = strlen(buf);
    int isP = 1;
    for (int i = 0; i < len / 2; ++i) {
        if (buf[i] != buf[len - 1 -i]) {
            isP = 0;
            break;
        }
    }
    return isP;
}

int isMirrored(char buf[]) {
    int len = strlen(buf);
    int isM = 1;
    for (int i = 0; i < len / 2 + 1; ++i) {
        if (MIRROR_MAP[buf[i]] != buf[len - i - 1]) {
            isM = 0;
            break;
        }
    }
    return isM;
}
