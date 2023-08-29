// Write a program in C (WAPic) to increment values at each location of any given integer value. Eg: Input: 1347 Output: 4557
#include <stdio.h>

int incrementDigits(int num) {
    int result = 0;
    int multiplier = 1;
    int i=0;

    while (num > 0) {
        int digit = num % 10;
        digit = (digit + i) % 10;  // Increment the digit by i

        result += digit * multiplier;
        multiplier *= 10;
        num /= 10;
        i++;
    }

    return result;
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    int result = incrementDigits(num);
    printf("Output: %d\n", result);

    return 0;
}