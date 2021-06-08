# Playfair cypher

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
	- Rule 1: Row of the first letter (r0) and row of the second letter (r1) are equal, then take the adjecent character as the cyphered character
		l1 = [r0,c0] => c1 = [r0,c0+1]
		l2 = [r1,c1] => c2 = [r1,c1+1]

	- Rule 2: If both the letters are in the same column (c0 = c1), cypher character will be the character below it


	- Rule 3: Neither the row or the column are same , interchange the columns.
