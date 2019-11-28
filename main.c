#include <stdio.h>
#include <limits.h>

// using macros for binary conversion?

void printBinary (unsigned char byte) {
    int numBits = CHAR_BIT; 
    
    while(numBits--) { // is false when numBits = 0, i.e end of byte
    
        putchar('0' + ((byte >> numBits) & 1)); // '& 1' causes only the rightmost bit to be added
    }
}

unsigned char hamming_13_8 (unsigned char byte) {
  // input in form 0000xxxx
  
  // binary or hexadecimal literals?
  
  unsigned char temp = 0x00;
    
  
  return byte;
}
// D12 D11 D10 D9 C8 D7 D6 D5 C4 D3 C2 C1 C0
// C0 - DED parity bit - covers all
// C1 - SEC parity bit - covers 1, 3, 5, 7, 9, 11
// C2 - SEC parity bit - covers 2, 3, 6, 7, 10, 11
// C4 - SEC parity bit - covers 4, 5, 6, 7, 12
// C8 - SEC parity bit - covers 8, 9, 10, 11, 12  


int main () {

  unsigned char byte; // size of char is 1 byte 
  // to what degree is the byte used through the program
  // byte to matrix function?

  // matrix = [[1, 2], [3, 4]]
  // 1 2
  // 3 4

  while (scanf("%c", &byte) != EOF) {
    if (byte != '\n') {
      printf("%X\n", byte); // as hexadecimal
      printBinary(byte); // as binary
      putchar('\n');
      printBinary(byte<<1);
      putchar('\n');
      printBinary(byte>>1);
      putchar('\n');
      printBinary(0x00);
      putchar('\n');
      printBinary(0xff);
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
  
