#include <stdio.h>
#include <string.h>
int value(char r) {
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}
int romanToDecimal(char *str) {
    int res = 0;
    for (int i = 0; i < strlen(str); i++) {
        int s1 = value(str[i]);
        if (i + 1 < strlen(str)) {
            int s2 = value(str[i + 1]);
            if (s1 >= s2) {
                res = res + s1;
            } else {
                res = res + s2 - s1;
                i++;
            }
        } else {
            res = res + s1;
            i++;
        }
    }
    return res;
}
void printBinary(int num) {
    char binary[32];
    int i = 0;
    while (num > 0) {
        binary[i] = (num % 2) + '0';
        num = num / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binary[j]);
    }
}
int main() {
    char romanNumeral[1000];

    scanf("%s", romanNumeral);
    int decimal = romanToDecimal(romanNumeral);
    printf("%s na base 2: ", romanNumeral);
    printBinary(decimal);
    printf("\n");
    printf("%s na base 10: %d\n", romanNumeral, decimal);
    printf("%s na base 16: %x\n", romanNumeral, decimal);
    return 0;
}
//CORRETO