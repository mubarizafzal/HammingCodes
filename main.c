#include <stdio.h>


int main () {

  char byte;

  while (scanf("%c", &byte) != EOF) {
    if (byte != '\n') {
      printf("%c\n", byte);
    }
  }

  printf("Hellow \n");

}
