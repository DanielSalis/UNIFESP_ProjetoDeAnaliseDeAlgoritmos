#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arrays;
    int iterations;

    scanf("%d", &arrays);
    scanf("%d", &iterations);

    int **arrays_matrix = (int **)malloc(arrays * sizeof(int *));

    int arrays_sizes[arrays];

    int i;
    for (i=0; i < arrays; i++)
    {
        int current_array_size;
        scanf("%d", &current_array_size);

        arrays_sizes[i]=current_array_size;

        arrays_matrix[i] = (int *)malloc(current_array_size * sizeof(int));

        int j = 0;
        for (j; j < current_array_size; j++)
        {
            int number;
            scanf("%d", &number);
            arrays_matrix[i][j] = number;
        }
    }

    printf("\n");
    int k, l;
    for (k = 0; k < arrays; k++)
    {
        for (l = 0; l < arrays_sizes[k]; l++)
        {
            printf("%d ", arrays_matrix[k][l]);
        }
        printf("\n");
    }

    return 0;
}
