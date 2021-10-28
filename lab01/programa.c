
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *last = NULL;

void insert(int data)
{

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if (last == NULL)
    {
        temp->info = data;
        temp->next = temp;
        last = temp;
    }

    else
    {
        temp->info = data;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void update(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = last->next;
    temp->info = data;
    last = last->next;
}

void viewList()
{
    if (last == NULL)
        printf("\nList is empty\n");

    else
    {
        struct node *temp;
        temp = last;
        printf("ULTIMO: %d\n", temp->info);
        printf("PRIMEIRO: %d\n", temp->next->info);
        printf("SEGUNDO: %d\n", temp->next->next->info);
    }
}

int up(int sum)
{
    if (sum % 30 == 0)
    {
        return (sum / 30);
    }
    return (sum / 30) + 1;
}

int main()
{

    int inicial_users_number;
    int desired_users_number;

    scanf("%d", &inicial_users_number);
    scanf("%d", &desired_users_number);

    int new_users_counter = 0;
    int number_of_days = 0;
    int mean = 0;
    int estimated_users_counter;

    int i = 0;
    while (1)
    {
        int qtd_users;
        if (i < 30)
        {
            scanf("%d", &qtd_users);
            insert(qtd_users);
            new_users_counter = new_users_counter + qtd_users;
            // mean = up(new_users_counter);
            estimated_users_counter = new_users_counter;
        }

        else
        {
            int first = last->next->info;
            mean = up(estimated_users_counter);
            new_users_counter = new_users_counter + mean;
            update(mean);
            estimated_users_counter = estimated_users_counter + mean - first;
        }

        if (new_users_counter > desired_users_number - inicial_users_number)
        {
            break;
        }

        i++;
    }

    number_of_days = i;
    printf("\n%d", number_of_days);

    return 0;
}
