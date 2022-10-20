// C++ program for Sparse Matrix Representation
// using Array
#include<stdio.h>

int main()
{   int r,c;
int sparseMatrix[100][100];
    printf("Enter The Rows and cols of Matrix");
 scanf("%d %d",&r,&c);
 printf("Enter The elements");
 for (int i = 0; i < r; i++)
 {
    for ( int j = 0; j <c; j++)
    {
        scanf("%d",&sparseMatrix[i][j]);
    }
 }
	int size = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (sparseMatrix[i][j] != 0)
				size++;


	int compactMatrix[3][size];

	
	int k = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (sparseMatrix[i][j] != 0)
			{
				compactMatrix[0][k] = i;
				compactMatrix[1][k] = j;
				compactMatrix[2][k] = sparseMatrix[i][j];
				k++;
			}
     printf("Row\nCol\nValue\n");
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<size; j++)
			printf("%d ", compactMatrix[i][j]);

		printf("\n");
	}
	return 0;
}
