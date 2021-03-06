#include<stdio.h>
#include<string.h>
#include "header.h"

int show_process;

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
	//gets(key);
	//printf("%s\n", key);
	scanf("%[^\n]s", key);
	fflush(stdin);
	
	#ifdef __linux__
		char c;
		while ( (c = getchar()) != '\n');
	#endif
		
	//fgets(key, 20, stdin);

	key_matrix_maker(key, key_matrix);				//Creates the matrix with the specified key

	//=======================================================================
	//	Printing the Key matrix after forming them, if the process is 'y'
	
	if (show_process == 1)
	{
		printf("Key Matrix\n");

		for (int i=0; i<5; i++)
		{
			for (int j=0; j<5; j++)
			{
				printf("%c  ", key_matrix[i][j]);
			}
			printf("\n");
		}
	}
	
	//=======================================================================

	//=======================================================================
	//	Getting text to be encrypted

	printf("Enter plain Text: ");
	scanf("%[^\n]s", plain_text);
	fflush(stdin);

	#ifdef __linux__
		while ( (c = getchar()) != '\n');
	#endif
	//fgets(plain_text, 100, stdin);
	
	//=======================================================================

	inducer(plain_text);							// Does the appropriate conversions of the cipher

	//=======================================================================
	//	Outputting the plain text in the required manner

	if (show_process == 1)
	{
		printf("Modified plain Text: ");
		for (int k=0; k<strlen(plain_text); k++)		//groups the plain texts
		{
			if (k%2 == 1)
				printf("%c ", plain_text[k]);
			else
				printf("%c", plain_text[k]);
		}
		printf("\n");
	}

	//=======================================================================

	worker(plain_text, key_matrix, ciphered_text, show_process);	// Calls the cipher function and does the cipher

	printf("ciphered text: %s\n", ciphered_text);
}


void decrypt()
{
	//=======================================================================
	//	Initializing variables

	char key_matrix[5][5];
	char plain_text[100];
	char ciphered_text[100];
	char key[20];

	//=======================================================================

	printf("Enter the key: ");
	
	scanf("%[^\n]s", key);
	fflush(stdin);
	
	#ifdef __linux__
		char c;
		while ( (c = getchar()) != '\n');
	#endif
		
	//fgets(key, 20, stdin);

	key_matrix_maker(key, key_matrix);				//Creates the matrix with the specified key

	//=======================================================================
	//	Printing the Key matrix after forming them	

	if(show_process == 1)	
	{
		printf("Key Matrix\n");

		for (int i=0; i<5; i++)
		{
			for (int j=0; j<5; j++)
			{
				printf("%c  ", key_matrix[i][j]);
			}
			printf("\n");
		}
	}
	
	//=======================================================================

	//=======================================================================
	//	Getting text to be encrypted

	printf("Enter cipher Text: ");
	scanf("%[^\n]s", plain_text);
	fflush(stdin);
	//fgets(plain_text, 100, stdin);
	
	//=======================================================================

	inducer(plain_text);							// Does the appropriate conversions of the cipher

	//=======================================================================
	//	Outputting the plain text in the required manner

	if (show_process == 1)
	{
		printf("Modified ciphered Text: ");
		for (int k=0; k<strlen(plain_text); k++)		//groups the plain texts
		{
			if (k%2 == 1)
				printf("%c ", plain_text[k]);
			else
				printf("%c", plain_text[k]);
		}
		printf("\n");
	}

	//=======================================================================

	upside_down_worker(plain_text, key_matrix, ciphered_text, show_process);	// Calls the cipher function and does the cipher

	printf("deciphered text: %s\n", ciphered_text);
}


int main(int argc, char const *argv[])
{

	printf("================Playfair cipher================\n");

	int choice;
	printf("Choose an option: \n");
	printf("1} Encryption\n");
	printf("2} Decryption\n");
	int flag=1;
	while(flag)
	{
		printf("=> ");
		//choice = getchar();
		scanf("%d", &choice);
		fflush(stdin);

		char c;

		#ifdef __linux__
			while ( (c = getchar() ) != '\n');
		#endif

		int another_flag=1;
		char ch;

		switch(choice)
		{
			case 1:

				
				while(another_flag)
				{
					printf("Do you want to see the process?(y/n): ");
					scanf("%c", &ch);
					fflush(stdin);

					#ifdef __linux__
						while ( (c = getchar() ) != '\n');
					#endif

					switch(ch)
					{
						case 'y':
							show_process = 1;
							printf("Okay, process of cipher will be shown\n\n");
							another_flag = 0;
							break;

						case 'n':
							show_process = 0;
							printf("Okay, process will not be shown\n\n");
							another_flag = 0;
							break;

						default:
							printf("Please enter only y or n\n");
					}
				}

				encrypt();
				flag = 0;
				break;

			case 2:

				
				while(another_flag)
				{
					printf("Do you want to see the process?(y/n): ");
					scanf("%c", &ch);
					fflush(stdin);

					#ifdef __linux__
						while ( (c = getchar() ) != '\n');
					#endif

					switch(ch)
					{
						case 'y':
							show_process = 1;
							printf("Okay, process of cipher will be shown\n\n");
							another_flag = 0;
							break;

						case 'n':
							show_process = 0;
							printf("Okay, process will not be shown\n\n");
							another_flag = 0;
							break;

						default:
							printf("Please enter only y or n\n");
					}
				}

				decrypt();
				flag = 0;
				break;

			default:
				printf("Please choose an appropriate option!\n");
		}	
	}
	return 0;
}