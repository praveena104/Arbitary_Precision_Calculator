/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "apc.h"

int main() {
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;
    char option, operator;

    do {
        /* Read input as a string */
        char input[256], num1[128], num2[128];
        printf("Enter the input: ");
        scanf("%s", input);

        /* Extract operator and split numbers */
        sscanf(input, "%[^+-*/]%c%s", num1, &operator, num2);

        /* Convert strings to doubly linked lists */
        string_to_dlist(num1, &head1, &tail1);
        string_to_dlist(num2, &head2, &tail2);
        int isNegative=0;

        /* Perform the operation based on operator */
        switch (operator) {
            case '+':
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                printf("Addition Result: ");
                display_result(headR);
                break;
            case '-':
                subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR, &isNegative);
                printf("Subtraction Result: ");
                if (isNegative) 
                {
                    printf("-");
                }
                display_result(headR);
                break;
           /* case '*':
                multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                printf("Multiplication Result: ");
                display_result(headR);
                break;
            case '/':
                division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                printf("Division Result (Quotient): ");
                display_result(headR);
                break;*/
            default:
                printf("Invalid Input. Try again...\n");
        }

        /* Free all lists */
        free_list(head1);
        free_list(head2);
        free_list(headR);
        head1 = head2 = headR = NULL;
        tail1 = tail2 = tailR = NULL;

        /* Prompt user to continue */
        printf("Want to continue? Press [yY | nN]: ");
        scanf(" %c", &option);
    } while (option == 'y' || option == 'Y');

    return 0;
}