#include<stdio.h>
#include<string.h>
#include "header.h"


int main(int argc, char const *argv[])
{
	char key_matrix[5][5] = {"ocure","nabdf","ghikl","mpqst","vwxyz"};
	char plain_text[100];
	char ciphered_text[100];

	
	printf("Key Matrix\n");							//outputs the key matrix, in the form of a matrix

	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5; j++)
		{
			printf("%c\t", key_matrix[i][j]);
		}
		printf("\n");
	}

	printf("Enter plain Text: \n");
	scanf("%[^\n]s", plain_text);
	inducer(plain_text);							// Does the appropriate conversions of the cipher
	printf("Plain Text: ");
	for (int k=0; k<strlen(plain_text); k++)		//groups the plain texts
	{
		if (k%2 == 1)
			printf("%c ", plain_text[k]);
		else
			printf("%c", plain_text[k]);
	}
	printf("\n");

	worker(plain_text, key_matrix, ciphered_text);	// Calls the cipher function and does the cipher

	printf("ciphered text: %s\n", ciphered_text);

	return 0;
}