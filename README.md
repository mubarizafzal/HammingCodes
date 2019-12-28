# A learning project for C programming.

<strong>Project concept taken from [Nifty Assignments](http://nifty.stanford.edu/2011/hansen-hamming-codes/).</strong>


<strong>Relevant topics:</strong>

  - Error correcting codes that use parity bits
    - Single Error Correction bits (SEC) and Double Error Detection Bits (DED)
  - Binary representation and manipulation of data
  - Matrix multiplication
  - Binary I/O
  - Bitwise operators and macros


<strong>What are parity bits and how are they used?</strong>

  - Parity bits are used to detect if some byte(s) of data contain an error
    - an error being a bit within the data being flipped, the original value of the data is thus lost
  - The parity bit covers certain data bits and is set to 1 or 0 such that all the bits it covers (including itself) have an even number of 1s
    - ex. if the bits being covered had the values of 1, 0, 1, 1 then the parity bit would be set to 1
  - Thus if the data gets and error, it can be noticed that there are an odd number of 1s
  - Parity bits (SEC) have some issues
    - they can detect that there was an error, but not on which bit within the byte, so a correction can't be made
    - if multiple errors occur on the same byte, the number of 1s might become even again and despite an error occuring, it would not be noticed
    - this can be solved through double error correction bits (DED), which cover all of the data bits and the parity bits as well


<strong>How to run:</strong>

  - Type "make" in the terminal to compile
  - Then "./out < testfile1" to take the test file bytes as input
  - Also "./out" by itself to enter custom input
