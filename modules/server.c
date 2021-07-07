#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void worker(char plain_text[], char key_matrix[5][5], char ciphered_text[])		//Does the cipher using 3 rules
{
	int i, j, r1=0, r2=0, c1=0, c2=0;

	memset(ciphered_text, 0, 100);	//Clears the ciphered_text array, it fills up with characters in some systems.

	//=======================================================================
	//	outer loop:- Cycling through the variables in steps(letters) of 2.

	for (int k=0; k<strlen(plain_text);k+=2)
	{
		//=======================================================================
		//	This loop takes in the coordinates of the 2 characters.

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

		//=======================================================================


		//=======================================================================
		//	The 3 rules written here in "if" statements

		if (r1==r2)
		{
			if(c2==4)
			{
				strncat(ciphered_text, &key_matrix[r1][c1+1], 1);
				strncat(ciphered_text, &key_matrix[r2][0], 1);
			}
			else
			{
				strncat(ciphered_text, &key_matrix[r1][c1+1], 1);
				strncat(ciphered_text, &key_matrix[r2][c2+1], 1);
			}
		}
		if (c1==c2)
		{
			if (r2==4)
			{
				strncat(ciphered_text, &key_matrix[r1+1][c1], 1);
				strncat(ciphered_text, &key_matrix[0][c2], 1);
			}
			else
			{
				strncat(ciphered_text, &key_matrix[r1+1][c1], 1);
				strncat(ciphered_text, &key_matrix[r2+1][c2], 1);
			}
		}

		if (r1 != r2 && c1 != c2)
		{			
			strncat(ciphered_text, &key_matrix[r1][c2], 1);
			strncat(ciphered_text, &key_matrix[r2][c1], 1);
		}
		//=======================================================================
	}
}



void inducer(char plain_text[])		// Does the job of converting the plaintext into cipherable text by a set of rules.
{
	//=======================================================================
	//	This snippet is responsible for removing all spaces from the plain text

	int i1=0, j1=0;
	while (plain_text[i1])
    {
    	if (plain_text[i1] != ' ')
    		plain_text[j1++] = plain_text[i1];
    	i1++;
    }
    plain_text[j1] = '\0';

    //=======================================================================

    char temp[100];
    int a;
    int found = 0;
    a = strlen(plain_text);

    //=======================================================================
    //	Outer loop, to act as a pointer.

	for (int i=0; i<strlen(plain_text)-1; i++)
	{
		//=======================================================================
		//	2 "if" statements, same code block, this is because the code 
		//	shifts back the characters and the previous characters are
		//	overwritten, which makes the final plaintext wrong.

		if (found==0)
		{
			if (plain_text[i] == plain_text[i+1] && (i+1)%2 == 1)
			{
				//=======================================================================
				//	if the two adjecent characters are same, then copy all the characters
				//	before the index, add "x" and then copy all the remaining characters.

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

				//=======================================================================
			}
			
		}

		if (found == 1)
		{
			strcpy(plain_text, temp);	// Only difference in the two blocks.
			if (temp[i] == temp[i+1] && (i+1)%2 == 1)
			{
				//=======================================================================
				//	Exact same code.
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

	
	// If all the characters are unique, then just copy the plain text in temp.

	if (found == 0)
		strcpy(temp, plain_text);

	a = strlen(temp);
	char z = 'x';

	//	If the number of characters are odd, add a "x" in the end.
	if (a%2 != 0)
		strncat(temp, &z, 1);
		
	strcpy(plain_text, temp);

}



void key_matrix_maker(char key[100], char key_matrix[5][5])
{

	//=======================================================================
	//	This code snippet removes j if i is already present in the key string

	int found_i=0, found_j=0;
	char temp[100]="";

	for(int i=0; i<strlen(key); i++)
	{
		if (key[i] == 'i')
			found_i++;
		else if (key[i] == 'j')
			found_j++;
	}

	if (found_j > 0 && found_i > 0)
	{
		for (int i=0; i<strlen(key); i++)
		{
			if (key[i] != 'j')
			{
				//printf("%c", key[i]);
				strncat(temp, &key[i], 1);
			}
		}
	}
	else
	{
		strcpy(temp, key);
	}

	strcpy(key, temp);

	//=======================================================================
	//	Removes spaces from the key

	int i1=0, j1=0;
	while (key[i1])
    {
    	if (key[i1] != ' ')
    		key[j1++] = key[i1];
    	i1++;
    }
    key[j1] = '\0';

    //=======================================================================


	char alpha[100];
	char set1[100]= "abcdefghklmnopqrstuvwxyz", set2[100]="abcdefghiklmnopqrstuvwxyz";

	if (found_j>0 && found_i==0)
		strcpy(alpha, set1);
	else
		strcpy(alpha, set2);

    strcat(key, alpha);

    //=======================================================================
    //	this code snippet removes repeating characters, and appends to 1d array
    //	While loop is used here because if the characters repeat more than once,
    //	the loop tends to omit it.

    int i,j,k,size=0;
    
    while(size!=25)
    {
        for(i = 0; i < strlen(key); i++)
        {
            for(j = i + 1; key[j] != '\0'; j++)
            {
                if(key[j] == key[i])  
                {
                    for(k = j; key[k] != '\0'; k++)
                    {
                        key[k] = key[k + 1];
                    }
                }
            }
        }
        size = strlen(key);
    }

    //printf("%s\n", key);

    //=======================================================================

    i=0;
    j=0;
    k=0;

    //=======================================================================
    //	This code snippet converts the D key array into the 2D key matrix

    while(key[k])
    {
        if ((i+1)%5 ==0)
        {
            key_matrix[j][i] = key[k];
            //printf("%c\n", key_matrix[j][i]);
            //printf("[%d, %d]\n", j,i);
            j++;
            i = (i/5) - 1;
        }
        else
        {
            
            key_matrix[j][i] = key[k];
            //printf("%c  ", key_matrix[j][i]);
            //printf("[%d, %d],", j,i);
        }
        
        k++;
        i++;
    }

    //=======================================================================

}