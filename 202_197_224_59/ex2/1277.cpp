#include <cstdio>

int main() {
    char ch;
    while (~scanf("%c", &ch)) {
        for (int i = 0; i <= ch-'A'; i++) {
            for (int j = 1; j < 2*(ch-'A'+1)-i; j++) {
                printf(" ");
            }
            for (int j = 0; j < i; j++) {
                printf("%c", j+'A');
            }
            for (int j = i; j >= 0; j--) {
                printf("%c", j+'A');
            }
            puts("");
        }
        for (int i = 0; i <= ch-'A'; i++) {
            for (int j = 1; j < ch-'A'-i+1; j++) {
                printf(" ");
            }
            for (int j = 0; j < i; j++) {
                printf("%c", j+'A');
            }
            for (int j = i; j >= 0; j--) {
                printf("%c", j+'A');
            }

            for (int j = 2*(ch-'A'-i); j >= 0; j--) {
                printf(" ");
            }
            for (int j = 0; j < i; j++) {
                printf("%c", j+'A');
            }
            for (int j = i; j >= 0; j--) {
                printf("%c", j+'A');
            }

            puts("");
        }
    }
    return 0;
}