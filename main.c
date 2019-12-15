#include <stdio.h>
#include <limits.h>

// using macros for binary conversion?
// typeof can make macros type independant


void printBinary (void* data, size_t numBytes) {
        
    int numBits = numBytes * 8;    
    
    
    if (numBytes == sizeof(unsigned char)) {
    
      unsigned char temp_data = *((unsigned char*) data);
      while (numBits--) {
      
        if ((numBits + 1) % 4 == 0 && numBits != 0 && numBits != numBytes*8 - 1) {
          putchar(' ');
        }
        
        putchar('0' + ((temp_data >> numBits) & 1));
      
      }
    }
    
    if (numBytes == sizeof(unsigned short)) {
      
      unsigned short temp_data = *((unsigned short*) data);
      while (numBits--) {
        
        if ((numBits + 1) % 4 == 0 && numBits != 0 && numBits != numBytes*8 - 1) {
          putchar(' ');
        }
        
        putchar('0' + ((temp_data >> numBits) & 1));
      
      }
    }
    
    if (numBytes == sizeof(unsigned int)) {
      
      unsigned int temp_data = *((unsigned int*) data);
      while (numBits--) {
 
        if ((numBits + 1) % 4 == 0 && numBits != 0 && numBits != numBytes*8 - 1) {
          putchar(' ');
        }
        
        putchar('0' + ((temp_data >> numBits) & 1));
      
      }
    }    
}








unsigned short hamming13_8 (unsigned char byte) {
  // input is full 8 bits, as is
  // 0110 1011 - 107
  
  
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
  
  unsigned short C0 = 0x1ffe; // C0  = 0001 1111 1111 1110 (checks entire result, which is 16 bit - 2 bytes)

  
  unsigned short result = 0;
  int length = 12;
  
  unsigned short setBit;
  int charBits;
  
  
  printBinary(&byte, sizeof(byte));
  putchar('\n');
  
  while (length--) {
    
    
    charBits = sizeof(unsigned char)*8;
    setBit = 0;
    
    
    while (charBits--) {
      
  
      setBit = setBit ^ (((byte >> charBits) & 1) & ((matrix[length] >> charBits) & 1));
    }
    
    printf("bit val at pos: %d is  ", 12 - length);
    printBinary(&setBit, sizeof(setBit)); // odd or even
    putchar('\n'); 
    
    result = result | (setBit << (12 - length));
    
    // saving into result 00
    
    
  }
  
  setBit = 0;
  int shortBits = sizeof(unsigned short)*8;
  
  while (shortBits--) {
  
    setBit = setBit ^ (((result >> shortBits) & 1) & ((C0 >> shortBits) & 1));
  }
  
  printf("bit val at pos: 0 is  ");
  printBinary(&setBit, sizeof(setBit)); // odd or even
  putchar('\n'); 
  
  result = result | setBit;
  
  
  
  return result;
}









// D12 D11 D10 D9 C8 D7 D6 D5 C4 D3 C2 C1 C0
// C0 - DED parity bit - covers all
// C1 - SEC parity bit - covers 1, 3, 5, 7, 9, 11
// C2 - SEC parity bit - covers 2, 3, 6, 7, 10, 11
// C4 - SEC parity bit - covers 4, 5, 6, 7, 12
// C8 - SEC parity bit - covers 8, 9, 10, 11, 12  
 
// matrices


// if 1 after adding, set to 1, if 0 after adding, set to 0


int main () {

  unsigned char byte; // size of char is 1 byte 
  
  
  while (scanf("%c", &byte) != EOF) {
    if (byte != '\n') {
      
      printf("%X\n", byte); // as hexadecimal
      
      printBinary(&byte, sizeof(byte)); // as binary
      putchar('\n');
      
      unsigned short test1 = 0xffff;
      
      printBinary(&test1, sizeof(test1)); // sets test to same value as 23 literal
      putchar('\n');
      
      byte = byte^53;
      printBinary(&byte, sizeof(byte)); // 53 as a literal is the same bit sequence as '5' <- char
      putchar('\n');
    }
  }
  
  
  int num = 2;
  num>>1;
  printf("does shift also assign?: %d\n", num);
  
  printf("inc a char by a literal: %c\n", '0' + 2); // %c is '2'

  printf("a char is %d byte(s) large\n", sizeof(char));
  printf("a short is %d byte(s) large\n", sizeof(unsigned short));

  unsigned short value = hamming13_8(0xff);
  printBinary(&value, sizeof(value)); // prints 107 in binary - 0110 1011
  // fix address


  putchar('\n');

}
  
