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
    for (i = 0; i < arrays; i++)
    {
        int current_array_size;
        scanf("%d", &current_array_size);

        arrays_sizes[i] = current_array_size;

        arrays_matrix[i] = (int *)malloc(current_array_size * sizeof(int));

        int j = 0;
        for (j; j < current_array_size; j++)
        {
            int number;
            scanf("%d", &number);
            arrays_matrix[i][j] = number;
        }
    }

    int sum;
    for (i = 0; i < iterations; i++)
    {
        sum = 0;
        int minimal_value = arrays_matrix[0][0];
        int array_sizes_position = 0;
        int j;
        for (j = 0; j < arrays; j++)
        {
            if (arrays_sizes[j] > 0 && minimal_value > arrays_matrix[j][0])
            {
                minimal_value = arrays_matrix[j][0];
                array_sizes_position = j;
            }

            sum = sum;

            if (arrays_sizes[j] > 0)
            {
                sum = sum + arrays_matrix[j][0];
            }
        }

        for (j = 0; j < arrays_sizes[array_sizes_position] - 1; j++)
        {
            arrays_matrix[array_sizes_position][j] = arrays_matrix[array_sizes_position][j + 1];
        }
        arrays_sizes[array_sizes_position]--;
    }

    printf("%d", sum);

    return 0;
}
