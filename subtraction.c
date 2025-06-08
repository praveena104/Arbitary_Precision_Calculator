/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stddef.h>
#include <stdio.h>
	
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, int *isNegative)
{
    Dlist *ptr1 = *head1, *ptr2 = *head2;
    *isNegative = 0;

    // Check which number is larger without a separate comparison function
    while (ptr1 && ptr2) {
        if (ptr1->data < ptr2->data) {
            *isNegative = 1;  // Number 1 is smaller, so result should be negative
            break;
        } else if (ptr1->data > ptr2->data) {
            *isNegative = 0;  // Number 1 is larger, so result will be positive
            break;
        }
        // Move to the next most significant digit
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Reset pointers to start subtraction from least significant digit
    ptr1 = *isNegative ? *tail2 : *tail1;
    ptr2 = *isNegative ? *tail1 : *tail2;

    int borrow = 0;

    while (ptr1 || ptr2 || borrow) {
        int diff = borrow;
        if (ptr1) {
            diff += ptr1->data;
            ptr1 = ptr1->prev;
        }
        if (ptr2) {
            diff -= ptr2->data;
            ptr2 = ptr2->prev;
        }

        if (diff < 0) {
            diff += 10;  // Adjust if the result is negative
            borrow = -1; // Set borrow for the next iteration
        } else {
            borrow = 0;  // Reset borrow if no need to borrow
        }

        append_digit(headR, tailR, diff % 10);
    }

    // Reverse the result list to display it in correct order
    Dlist *temp = NULL, *current = *headR;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp) *headR = temp->prev;

    return SUCCESS;
}
