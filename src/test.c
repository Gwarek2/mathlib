#include <stdio.h>
#include <stdlib.h>
char *toBinary(int n, int len);
int main() {
    int a = 60;
    int b = 255;
    char *abinary = toBinary(a, 8);
    printf("a = %s\n", abinary);
    char *bbinary = toBinary(b, 8);
    printf("b = %s\n", bbinary);
    char *binary = toBinary(a & b, 8);
    printf("r = %s", binary);

    free(abinary);
    free(bbinary);
    free(binary);
    return 0;
}

char *toBinary(int n, int len) {
    char *binary = (char *)malloc(sizeof(char) * len);
    int k = 0;
    for (unsigned i = (1 << (len - 1)); i > 0; i = i / 2) {
        binary[k++] = (n & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}
