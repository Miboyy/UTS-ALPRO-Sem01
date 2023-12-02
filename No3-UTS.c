#include <stdio.h>

int main() {
    int num, fact = 1;

    printf("Masukan Nomer: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("The factorial of 0 is 1.\n");
    } else if (num > 0) {
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        printf("The factorial of %d is %d\n", num, fact);
    } else {
        printf("Invalid input. Please enter a non-negative number.\n");
    }

    return 0;
}