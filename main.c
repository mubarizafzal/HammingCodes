#include <stdio.h>
#include <limits.h>

void printBinary(unsigned char byte)
{
    int bCount = CHAR_BIT; 
    
    while(bCount--) { // is false when i = 0, i.e end of byte
    
        putchar('0' + ((byte >> bCount) & 1)); // different way to loop?
    }
}

int main () {

  unsigned char byte; // size of char is 1 byte 


  while (scanf("%c", &byte) != EOF) {
    if (byte != '\n') {
      printf("%X\n", byte); // as hexadecimal
      printBinary(byte); // as binary
      putchar('\n');
      printBinary(byte<<1);
      putchar('\n');
      printBinary(byte>>1);
      putchar('\n');
      printBinary(~byte);
      putchar('\n');
      printBinary(byte^5); // 5 as a literal is 4 bits, so only first 4 bits are affected
      putchar('\n');
    }
  }

  printf("a char is %d byte(s) large\n", sizeof(char));

}
  
