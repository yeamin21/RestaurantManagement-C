#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CAPACITY 100

typedef struct node
{
    int data;
    struct node * next;
} Queue;


unsigned int size = 0;
int completed=0;



int enqueue(Queue ** rear, Queue ** front, int data);
int dequeue(Queue ** front);
int isEmpty();
int isFull();


int main()
{
    int ch, data;
    Queue *rear, *front;
    system("color 5f");

    rear  = NULL;
    front = NULL;

    while (1)
    {

        printf("--------------------------------------------\n");
        printf("  Ultra Instinct Kachchi House  \n");
        printf("--------------------------------------------\n");
        printf("1. Receive Order\n");
        printf("2. Deliver Order(Only for Cooks!)\n");
        printf("3. Waiting\n");
        printf("4. Orders Completed\n");
        printf("5. Total Order\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n\n");



        printf("Select an option:");

        scanf("%d", &ch);
        system("cls");
        switch (ch)
        {
            case 1:

                printf("--------------------------------------------\n");
                printf("\nFOOD CODES\n");
                printf("--------------------------------------------\n");
                printf("1:Kachchi Biriyani\n");
                printf("2:Bhuna Khichuri\n");
                printf("3:Patla Khichuri\n");
                printf("4:Morog Polao\n");
                printf("5:Doi\n");
                printf("--------------------------------------------\n\n");



                printf("\nEnter Food Code: ");

                scanf("%d", &data);


                if (enqueue(&rear, &front, data))

                    printf("order added to queue.");
                else
                    printf("cant proceed order.");

                break;


            case 2:
                data = dequeue(&front);

                if (data == INT_MIN)
                    printf("No Order Remains.");
                else if(data==1)
                    printf("Kachchi Biriyani Served");
                else if(data==2)
                    printf("Bhuna Khichuri Served");
                else if(data==3)
                    printf("Patla Khichuri Served");
                else if(data==4)
                    printf("Morog Polao Served");
                else if(data==5)
                    printf("Doi Served");


                break;

            case 3:

                if (isEmpty())
                    printf("No Order Remains.");
                else
                    printf("Waiting to be served= %d person(s)", size);
                break;

            case 4:

                printf("Number of order(s) completed= %d\n",completed);

                break;
            case 5:

                printf("Number of Total Order(s)= %d\n",completed+size);

                break;

            case 0:
                printf("Exiting from app.\n");
                exit(0);


            default:

                printf("Invalid choice, please input number between (0-4).");
                break;

        }

        printf("\n\n");
    }
}

int enqueue(Queue ** rear, Queue ** front, int data)
{
    Queue * newNode = NULL;


    if (isFull())
    {
        return 0;
    }

    newNode = (Queue *) malloc (sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;
    if ( (*rear) )
    {
        (*rear)->next = newNode;
    }

    *rear = newNode;
    if ( !(*front) )
    {
        *front = *rear;
    }

    size++;

    return 1;
}

int dequeue(Queue ** front)
{
    Queue *toDequque = NULL;
    int data = INT_MIN;


    if (isEmpty())
    {
        return INT_MIN;
    }

    toDequque = *front;
    data = toDequque->data;
    *front = (*front)->next;

    size--;
    completed++;
    free(toDequque);

    return data;
}


int isEmpty()
{
    return (size <= 0);
}

int isFull()
{
    return (size > CAPACITY);
}
