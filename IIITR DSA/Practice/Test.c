#include <stdio.h>

int incrementValue(int num) {
    int result = 0;
    int multiplier = 1;
    
    while (num > 0) {
        int digit = num % 10;
        result += (digit + 1) * multiplier;
        num /= 10;
        multiplier *= 10;
    }
    
    return result;
}

int main() {
    int num;
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    int incremented = incrementValue(num);
    
    printf("Incremented value: %d\n", incremented);
    
    return 0;
}
