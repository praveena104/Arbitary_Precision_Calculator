/* Append a digit to the list */
#include<stdio.h>
#include<stdlib.h>
#include "apc.h"

/* Create a new node */
Dlist* create_node(data_t data) {
    Dlist *new_node = (Dlist*)malloc(sizeof(Dlist));
    if (!new_node) return NULL;
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

void append_digit(Dlist **head, Dlist **tail, data_t data)
{
    Dlist *new_node = create_node(data);
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(FAILURE);
    }
    if (!*head) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }
}

/* Display the result */
void display_result(Dlist *head) 
{
    while (head) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Free the list */
void free_list(Dlist *head) 
{
    while (head) {
        Dlist *temp = head;
        head = head->next;
        free(temp);
    }
}

/* Convert a string to a doubly linked list */
void string_to_dlist(char *str, Dlist **head, Dlist **tail) 
{
    while (*str) {
        append_digit(head, tail, *str - '0');  // Convert char to int
        str++;
    }
}
