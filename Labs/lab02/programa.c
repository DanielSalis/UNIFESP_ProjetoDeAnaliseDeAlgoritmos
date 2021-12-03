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


    int sum = 0;
    for(i=0; i < iterations; i++)
    {
        sum =  0;
        int minimal_value = arrays_matrix[0][0];
        int array_sizes_position=0;
        int j;
        for(j=0;j < arrays; j++){
            if(minimal_value < arrays_matrix[j][i]){
                minimal_value = arrays_matrix[j][i];
                array_sizes_position = j;
            }
            sum = sum + arrays_matrix[j][i];
        }

        for(j = 0; j < arrays_sizes[array_sizes_position] - 1; i++){
            arrays_matrix[array_sizes_position][i] = arrays_matrix[array_sizes_position][i + 1];
        }
    }

    printf("\nSOMA: %d", sum);

    // printf("\n");
    // int k, l;
    // for (k = 0; k < arrays; k++)
    // {
    //     for (l = 0; l < arrays_sizes[k]; l++)
    //     {
    //         printf("%d ", arrays_matrix[k][l]);
    //     }
    //     printf("\n");
    // }

    return 0;
}
