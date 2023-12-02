#include <stdio.h>

int isPrime(int number) {
  if (number <= 1) {
    return 0;
  }

  for (int i = 2; i <= number / 2; i++) {
    if (number % i == 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);

  if (isPrime(number)) {
    printf("%d Ini Bilangan Prima\n", number);
  } else {
    printf("%d Ini Bukan Bilangan Prima\n", number);
  }

  return 0;
}
