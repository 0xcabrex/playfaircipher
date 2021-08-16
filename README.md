# Playfair cipher

The Playfair cipher or Playfair square or Wheatstone–Playfair cipher is a manual symmetric encryption technique and was the first literal digram substitution cipher.

Steps to cipher a text using the playfair cipher:

### Create a 5X5 matrix table:
	- A 'key' is needed to make the cipher, The key must be stripped off any repeating characters
	- The elements of the matrix will be filled up with the newly formatted key and will be unique.

Note: I/J will not be in the same matrix together, if 'I' is there in the key, 'J' does not exist and vice versa.

### Split the to-be-ciphered text into pairs of 2 letters with some rules:
	- if any pair has the same letters, insert 'x' between the two letters and regroup.
	- If there are odd number of letters in the text, the last letter will be paired with 'x'.

### Rules for the cypher:
	- Rule 1: If row of the first letter `r0` and row of the second letter `r1` are equal `r0=r1`, then cipher character will be the one below.
		l1 = [r0,c0] => c1 = [r0,c0+1]
		l2 = [r1,c1] => c2 = [r1,c1+1]

	- Rule 2: If both the letters are in the same column `c0 = c1`, cypher character will be the character on the right.
		l1 = [r0,c0] => c1 = [r0+1,c0]
		l2 = [r1,c1] => c2 = [r1+1,c1]

	- Rule 3: Neither the row or the column are same, interchange the columns.
		l1 = [r0,c0] => c1 = [r0,c1]
		l2 = [r1,c1] => c2 = [r1,c0]

### Rules for decrypting the cypher:
	- Rule 1: If Row of the first letter (r0) and row of the second letter (r1) are equal `r0=r1`, then the above character is the cipher text.
		l1 = [r0,c0] => c1 = [r0, c0-1]
		l2 = [r1,c1] => c2 = [r1, c1-1]

	- Rule 2: If bothe the letters are in the same column `c0=c1`, the deciphered character will be then one above.
		l1 = [r0,c0] => c1 = [r0-1,c0]
		l2 = [r1,c1] => c2 = [r1-1,c1]

	- Rule 3: If neither the row nor column are same, interchange the columns.
		l1 = [r0,c0] => c1 = [r0,c1]
		l2 = [r1,c1] => c2 = [r1,c0]

## Compiling the program

The program can be compiled using the makefile as
```bash
make -f makefile.mk
```

Or you can also do it manually:
```bash
gcc -c client.c
gcc -c modules/server.c

gcc client.o server.o header.h -o mainfile

```
