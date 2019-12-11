#include <stdio.h>
#include <limits.h>

// using macros for binary conversion?

void printBinary (unsigned char byte) {
    int numBits = CHAR_BIT; 
    
    while(numBits--) { // is false when numBits = 0, i.e end of byte
    
        putchar('0' + ((byte >> numBits) & 1)); // '& 1' causes only the rightmost bit to be added
    }
}

unsigned char hamming13_8 (unsigned char byte) {
  // input is full 8 bits, as is
  // 0110 1011 - 107
  
  unsigned char D12 = 0x80;
  unsigned char C8 = 0xf0;
  printf("D12 is : ");
  printBinary(D12);
  putchar('\n'); 
  printf("C8 is : ");
  printBinary(C8);
  putchar('\n'); 
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

// matrices
// D12 = 1000 0000
// D11 = 0100 0000
// D10 = 0010 0000
// D9  = 0001 0000
// C8  = 1111 0000
// D7  = 0000 1000
// D6  = 0000 0100
// D5  = 0000 0010
// C4  = 1000 1110
// D3  = 0000 0001
// C2  = 0110 1101
// C1  = 0101 1011
// C0  = 0001 1111 1111 1110 (check entire result, which is 16 bit - 2 bytes)

// if 1 after adding, set to 1, if 0 after adding, set to 0


int main () {

  unsigned char byte; // size of char is 1 byte 
  
  // byte to matrix function?

  // adding bytes and storing into a short !!
  
  
  // (1 * 8) * (8 * 13) = 1 * 13
  // 1 byte * 13 bytes one by one, into a 16 bit short



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
      unsigned char test = 23;
      printBinary(test); // sets test to same value as 23 literal
      putchar('\n');
      printBinary(byte^53); // 53 as a literal is the same bit sequence as '5' <- char
      putchar('\n');
    }
  }
  
  
  int num = 2;
  num>>1;
  printf("does shift also assign?: %d\n", num);
  
  printf("inc a char by a literal: %c\n", '0' + 2); // %c is '2'

  printf("a char is %d byte(s) large\n", sizeof(char));
  printf("a short is %d byte(s) large\n", sizeof(unsigned short));


  printBinary(hamming13_8(107)); // prints 107 in binary - 0110 1011

  putchar('\n');

}
  
