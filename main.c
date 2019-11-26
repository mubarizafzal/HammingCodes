#include <stdio.h>
#include <limits.h>

// using macros for binary conversion?

void printBinary (unsigned char byte)
{
    int numBits = CHAR_BIT; 
    
    while(numBits--) { // is false when i = 0, i.e end of byte
    
        putchar('0' + ((byte >> numBits) & 1));
    }
}

unsigned char hamming_13_8 (unsigned char byte) {
  // input in form 0000xxxx
  
  // binary or hexadecimal literals?
    
  
  return byte;
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
      printBinary(byte^53); // 53 as a literal is the same bit sequence as '5'
      putchar('\n');
    }
  }
  
  int num = 2;
  num>>1;
  printf("does shift also assign?: %d\n", num);
  
  printf("inc a char by a literal: %c\n", '0' + 2); // %c is '2'

  printf("a char is %d byte(s) large\n", sizeof(char));

}
  
