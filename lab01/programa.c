#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MONTH_DAYS 30

int main()
{
    int inicial_users_number;
    int desired_users_number;

    scanf("%d", &inicial_users_number);
    scanf("%d", &desired_users_number);

    int first_month_users[MONTH_DAYS];
    int new_users_counter = 0;
    int number_of_days = 0;
    int exit = 0;

    int i = 0;
    for (i; i < MONTH_DAYS; i++)
    {
        scanf("%d", &first_month_users[i]);
        new_users_counter = new_users_counter + first_month_users[i];

        if (new_users_counter >= desired_users_number - inicial_users_number)
        {
            exit = 1;
            break;
        }
        number_of_days = i + 1;
    }

    if (exit == 0)
    {

        int mean = ceil(new_users_counter / MONTH_DAYS);

        while (new_users_counter <= desired_users_number - inicial_users_number)
        {

            int aux = first_month_users[0];
            int j = 0;
            for (j; j < MONTH_DAYS - 1; j++)
            {
                first_month_users[j] = first_month_users[j + 1];
            }

            first_month_users[MONTH_DAYS-1] = mean;

            new_users_counter = new_users_counter + mean;

            mean = ceil((new_users_counter - aux) / 30);

            i++;

            printf("media: %d\n", mean);
        }

        number_of_days = i + 1;
    }

    printf("%d\n", number_of_days);
}