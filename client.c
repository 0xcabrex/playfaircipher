#include<stdio.h>
#include<string.h>
#include "header.h"

void encrypt()
{
	//=======================================================================
	//	Initializing variables

	char key_matrix[5][5];
	char plain_text[100];
	char ciphered_text[100];
	char key[20];

	//=======================================================================

	printf("Enter the key: ");
	gets(key);

	key_matrix_maker(key, key_matrix);				//Creates the matrix with the specified key

	//=======================================================================
	//	Printing the Key matrix after forming them	
	
	printf("Key Matrix\n");

	for (int i=0; i<5; i++)
	{
		for (int j=0; j<5; j++)
		{
			printf("%c  ", key_matrix[i][j]);
		}
		printf("\n");
	}
	
	//=======================================================================

	//=======================================================================
	//	Getting text to be encrypted

	printf("Enter plain Text: ");
	scanf("%[^\n]s", plain_text);
	fflush(stdin);
	
	//=======================================================================

	inducer(plain_text);							// Does the appropriate conversions of the cipher

	//=======================================================================
	//	Outputting the plain text in the required manner

	printf("Modified plain Text: ");
	for (int k=0; k<strlen(plain_text); k++)		//groups the plain texts
	{
		if (k%2 == 1)
			printf("%c ", plain_text[k]);
		else
			printf("%c", plain_text[k]);
	}
	printf("\n");

	//=======================================================================

	worker(plain_text, key_matrix, ciphered_text);	// Calls the cipher function and does the cipher

	printf("ciphered text: %s\n", ciphered_text);
}


void decrypt()
{
	printf("Work under progress!\n");
}


int main(int argc, char const *argv[])
{

	printf("================Playfair cipher================\n");

	char choice;
	printf("Choose an option: \n");
	printf("a} Encryption\n");
	printf("b} Decryption\n");
	printf("=> ");
	choice = getchar();
	//fflush(stdin);
	int c;

	while ( (c = getchar()) != '\n' && c != EOF );

	switch(choice)
	{
		case 'a':
			encrypt();
			break;

		case 'b':
			decrypt();
			break;

		default:
			printf("Please choose an appropriate option!\n");
	}


	

	return 0;
}