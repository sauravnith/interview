# Circualar Printer
Write a program which takes four inputs (command line)

1. A string
2. char count (integer)
3. thread count - no of Threads(integer).
4. k: no of times each thread will print (integer) 
[The program should exit after all threads have printed exactly k number of times] 

Each thread then should start printing the chars in the string sequentially in the following format:
 eg:

 > myprinter ABCDEFGHIJ 3 4 2
 
Using 4 threads to print ABCDEFGHIJ alternatively in set of 3 chars

Thread1: ABC

Thread2: DEF

Thread3: GHI

Thread4: JAB

Thread1: CDE

Thread2: FGH

Thread3: IJA

Thread4: BCD 