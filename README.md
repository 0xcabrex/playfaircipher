# Playfair cypher

Steps to create the playfair cypher text:

### Create a 5X5 matrix:

Note: I/J will not be in the same matrix together, if 'I' is there in the key, 'J' does not exist and vice versa

### Split the key word into sets of 2 letters with some rules:
	- If there are odd number of letters in the key, the last letter will be paired with 'z'.
	- If the paired letters are the same, then insert 'x' between the two letters.

### Rules for the cypher:
	- Rule 1: Row of the first letter (r0) and row of the second letter (r1) are equal, then take the adjecent character as the cyphered character
		l1 = [r0,c0] => c1 = [r0,c0+1]
		l2 = [r1,c1] => c2 = [r1,c1+1]

	- Rule 2: If both the letters are in the same column (c0 = c1), cypher character will be the character below it


	- Rule 3: Neither the row or the column are same , interchange the columns.
