/*
Rakshak Kumar
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void print_matrix(int **mat, int print_row, int print_col){

    printf("Printing Matrix...\n");

    int i, j;
    for (i = 0; i < print_row; i++) {
        for (j = 0; j < print_col; j++)
        {
            printf("%d   ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    printf("Begin transp...");

    int**matrix, **t_matrix;
    int i, j, t_rows, t_cols, rows, cols, block_size;

    printf("Enter rows, columns, and block size:\n");
    scanf("%d%d%d", &rows, &cols, &block_size);
    
    matrix = (int**)malloc(sizeof(float*)*rows);
    
    for (i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(sizeof(float)*cols);

        //matrix[i] = rand() % 10; 
    }

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            matrix[i][j] = i+j;
    
    printf("matrix: \n");
    print_matrix(matrix, rows, cols);

    t_rows = cols;
    t_cols = rows;

    t_matrix = (malloc(sizeof(float*) * t_rows));
    
    for (i = 0; i < t_rows; i++)
        t_matrix[i] = (malloc(sizeof(float) * t_cols));

    struct timeval t0, t1;
    gettimeofday(&t1, 0);


    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            t_matrix[j][i] = matrix[i][j];

    gettimeofday(&t1, 0);
    long elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;

    printf("%ld\n",elapsed);

    printf("transposed matrix: \n");
    print_matrix(t_matrix, t_rows, t_cols);

    return 0;
}