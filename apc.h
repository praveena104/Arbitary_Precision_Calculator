#ifndef APC_H
#define APC_H

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, int *isNegative);
/*int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
*/
/*create node */

Dlist* create_node(data_t data);
void append_digit(Dlist **head, Dlist **tail, data_t data);
void display_result(Dlist *head);
void free_list(Dlist *head);
void string_to_dlist(char *str, Dlist **head, Dlist **tail);

#endif
