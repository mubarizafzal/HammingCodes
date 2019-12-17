#include <stdio.h>
#include <limits.h>

// macro for printing values in binary
#define binary(value) \
  int numBits = sizeof(value)*8; \
  while (numBits--) { \
    if ((numBits + 1) % 4 == 0 && numBits != 0 && numBits != sizeof(value)*8 - 1) { \
      putchar(' '); \
    } \
    putchar('0' + ((value >> numBits) & 1)); \
  } \
  putchar('\n')
  

unsigned short hamming13_8 (unsigned char byte) {

  // matrix of length 12, starting from D12 until C1
  
  unsigned char matrix[12] = {
    0x80, // D12 = 1000 0000
    0x40, // D11 = 0100 0000    
    0x20, // D10 = 0010 0000
    0x10, // D9  = 0001 0000
    0xf0, // C8  = 1111 0000
    0x08, // D7  = 0000 1000
    0x04, // D6  = 0000 0100
    0x02, // D5  = 0000 0010
    0x8e, // C4  = 1000 1110
    0x01, // D3  = 0000 0001
    0x6d, // C2  = 0110 1101
    0x5b, // C1  = 0101 1011

  
  };
  
  unsigned short C0 = 0x1ffe; // C0  = 0001 1111 1111 1110 (checks entire result, which is 16 bits)

  
  unsigned short result = 0;
  int length = 12;
  
  unsigned short setBit;
  int charBits;
  
  printf("In binary: ");
  binary(byte);
  
  while (length--) {
    
    
    charBits = sizeof(unsigned char)*8;
    setBit = 0;
    
    
    while (charBits--) {
      
      setBit = setBit ^ (((byte >> charBits) & 1) & ((matrix[length] >> charBits) & 1));
    }
    
    printf("Bit val at pos %d is %d\n", 12 - length, setBit);
    
    result = result | (setBit << (12 - length));
    
    
  }
  
  setBit = 0;
  int shortBits = sizeof(unsigned short)*8;
  
  while (shortBits--) {
  
    setBit = setBit ^ (((result >> shortBits) & 1) & ((C0 >> shortBits) & 1));
  }
  
  printf("Bit val at pos 0 is %d\n", setBit);
  
  result = result | setBit;
  
  return result;
}


// C0 - DED parity bit - covers all
// C1 - SEC parity bit - covers 1, 3, 5, 7, 9, 11
// C2 - SEC parity bit - covers 2, 3, 6, 7, 10, 11
// C4 - SEC parity bit - covers 4, 5, 6, 7, 12
// C8 - SEC parity bit - covers 8, 9, 10, 11, 12  


int main () {

  unsigned char byte; // size of char is 1 byte 
  unsigned short result;
  
  printf("This program scans characters byte by byte and converts each into its hamming(13, 8) representation.\n");
  printf("8 bits are represented in 13 bits with 4 SEC parity bits and 1 DED parity bit.\n");
  printf("Result is in the form: 0 0 0 D12 D11 D10 D9 C8 D7 D6 D5 C4 D3 C2 C1 C0.\n");
  printf("D12 D11 D10 D9 D7 D6 D5 D3 are bits holding the binary values of the byte.\n");
  printf("The parity bits cover different data bits, and is set to 1 or 0 so that there are an even number of 1s among its group (which includes itself).\n");
  printf("Type 'q' to exit\n");
  printf("----------------------------------------------------------------------------------\n");
  
  while (scanf("%c", &byte) != EOF) {
    if (byte != '\n') {
      
      if (byte == 'q') {
        break;
      }
      
      printf("You entered '%c' which is %X in hexadecimal.\n", byte, byte); // as hexadecimal
      
      result = hamming13_8(byte);
  
      printf("Result: ");
      binary(result);          
      
    }
  }
  
  /*  testing code
  byte = 0xb3;
  result = hamming13_8(byte);
  printf("Result: ");
  binary(result);
  */
}
  
