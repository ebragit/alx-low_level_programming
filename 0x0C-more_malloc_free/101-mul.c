#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string consists of only digits
int isNumber(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to multiply two strings representing positive integers
char *multiplyStrings(const char *num1, const char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len3 = len1 + len2;
    
    char *result = (char *)malloc(sizeof(char) * (len3 + 1));
    if (!result) {
        perror("Memory allocation error");
        exit(1);
    }
    memset(result, '0', len3);
    result[len3] = '\0';
    
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0') + carry + (result[i + j + 1] - '0');
            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry;
    }
    
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 98;
    }

    if (!isNumber(argv[1]) || !isNumber(argv[2])) {
        printf("Error\n");
        return 98;
    }

    char *num1 = argv[1];
    char *num2 = argv[2];

    // Remove leading zeros
    while (*num1 == '0') {
        num1++;
    }
    while (*num2 == '0') {
        num2++;
    }

    if (*num1 == '\0' || *num2 == '\0') {
        printf("0\n");
        return 0;
    }

    char *result = multiplyStrings(num1, num2);
    printf("%s\n", result);
    
    free(result);
    
    return 0;
}
