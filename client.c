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
	//fgets(key, 20, stdin);

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
	//fgets(plain_text, 100, stdin);
	
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

	int choice;
	printf("Choose an option: \n");
	printf("1} Encryption\n");
	printf("2} Decryption\n");
	printf("=> ");
	//choice = getchar();
	scanf("%d", &choice);

	fflush(stdin);

	char c;

	#ifdef __linux__
		while ( (c = getchar() ) != '\n');
	#endif


	switch(choice)
	{
		case 1:
			encrypt();
			break;

		case 2:
			decrypt();
			break;

		default:
			printf("Please choose an appropriate option!\n");
	}


	

	return 0;
}