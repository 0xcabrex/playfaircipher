#include <stdio.h>
#include <string.h>

void worker(char plain_text[], char key_matrix[5][5], char ciphered_text[])		//Does the cipher using 3 rules
{
	//printf("%s\n", plain_text);
	int i, j, r1=0, r2=0, c1=0, c2=0;
	for (int k=0; k<strlen(plain_text);k+=2)
	{
		for (i=0; i<5; i++)
		{
			for (j=0; j<5; j++)
			{
				if (key_matrix[i][j] == plain_text[k])
				{
					r1=i;
					c1=j;
				}
				if (key_matrix[i][j] == plain_text[k+1])
				{
					r2=i;
					c2=j;
				}
			}
		}

		//printf("%d,%d,%d,%d\n", r1,c1,r2,c2);

		if (r1==r2)
		{
			if(c2==4)
			{
				//printf("Cipher Text: %c%c\n",key_matrix[r1][c1+1], key_matrix[r2][0]);
				strncat(ciphered_text, &key_matrix[r1][c1+1], 1);
				strncat(ciphered_text, &key_matrix[r2][0], 1);
			}
			else
			{
				//printf("Cipher Text: %c%c\n",key_matrix[r1][c1+1], key_matrix[r2][c2+1]);
				strncat(ciphered_text, &key_matrix[r1][c1+1], 1);
				strncat(ciphered_text, &key_matrix[r2][c2+1], 1);
			}
		}
		if (c1==c2)
		{
			if (r2==4)
			{
				//printf("Cipher Text: %c%c\n", key_matrix[r1+1][c1], key_matrix[0][c2]);
				strncat(ciphered_text, &key_matrix[r1+1][c1], 1);
				strncat(ciphered_text, &key_matrix[0][c2], 1);
			}
			else
			{
				//printf("Cipher Text: %c%c\n", key_matrix[r1+1][c1], key_matrix[r2+1][c2]);
				strncat(ciphered_text, &key_matrix[r1+1][c1], 1);
				strncat(ciphered_text, &key_matrix[r2+1][c2], 1);
			}
		}

		if (r1 != r2 && c1 != c2)
		{
			//printf("Cipher Text: %c%c\n", key_matrix[r1][c2], key_matrix[r2][c1]);	
			strncat(ciphered_text, &key_matrix[r1][c2], 1);
			strncat(ciphered_text, &key_matrix[r2][c1], 1);
		}
	}
}

void inducer(char plain_text[])		// Does the job of converting the plaintext into cipherable text by a set of rules.
{
	int i1=0, j1=0;
	while (plain_text[i1])
    {
    	if (plain_text[i1] != ' ')
    		plain_text[j1++] = plain_text[i1];
    	i1++;
    }
    plain_text[j1] = '\0';

    char temp[100];
    int a;
    int found = 0;
    a = strlen(plain_text);
	for (int i=0; i<strlen(plain_text)-1; i++)
	{
		if (found==0)
		{
			if (plain_text[i] == plain_text[i+1] && (i+1)%2 == 1)
			{
				for (int j=0; j<=i; j++)
				{						
					temp[j] = plain_text[j];
				}

				temp[i+1] = 'x';
				
				a = strlen(temp);
				
				for (int k=i+1; k<strlen(plain_text); k++)
				{					
					temp[k+1] = plain_text[k];
				}

				found = 1;
			}
			
		}

		if (found == 1)
		{
			strcpy(plain_text, temp);
			if (temp[i] == temp[i+1] && (i+1)%2 == 1)
			{
				for (int j=0; j<=i; j++)
				{						
					temp[j] = plain_text[j];
				}

				temp[i+1] = 'x';
				
				a = strlen(temp);				

				for (int k=i+1; k<strlen(plain_text); k++)
				{
					temp[k+1] = plain_text[k];
				}

				found = 1;
			}
			
		}		
		
	}

	
	if (found == 0)
		strcpy(temp, plain_text);
	a = strlen(temp);
	char z = 'x';
	if (a%2 != 0)
		strncat(temp, &z, 1);
		


	//printf("%s\n", temp);

	strcpy(plain_text, temp);

	//printf("%s\n", plain_text);
	
}



