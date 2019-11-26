A work in progress. Learning project for C programming.

- what are haming codes?
  - what are parity bits?
  - history
- complexity/features?
  - single error correction, double error detection (SECDED)
    - Hamming (13, 8)
  - target data size?
- functionality demonstration
- key topics

Project concept taken from [Nifty Assignments](http://nifty.stanford.edu/2011/hansen-hamming-codes/).


Hamming Codes:

- parity bits are used to detect if the byte contains an error
- when the byte is set to a certain value, the parity bit is set to 1 or 0 such that all the 5 bits have an even number of 1s
- thus if the byte gets and error, it can be noticed that there are an odd number of 1s

- parity bits have some issues
  - they can detect that there was an error, but not on which bit within the byte, so a correction can't be made
  - if multiple errors occur on the same byte, the number of 1s might become even again and despite an error occuring, it would not be noticed
  

