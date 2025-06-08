/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) 
{
    Dlist *ptr1 = *tail1, *ptr2 = *tail2;
    int carry = 0;

    while (ptr1 || ptr2 || carry) 
    {
        int sum = carry;
        if (ptr1) {
            sum += ptr1->data;
            ptr1 = ptr1->prev;
        }
        if (ptr2) {
            sum += ptr2->data;
            ptr2 = ptr2->prev;
        }
        carry = sum / 10;
        append_digit(headR, tailR, sum % 10);
    }

    // Reverse the result list to display it in correct order
    Dlist *temp = NULL, *current = *headR;
    while (current) 
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp) *headR = temp->prev;
    
    return SUCCESS;
}
