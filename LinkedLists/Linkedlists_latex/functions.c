///\file functions.c
///\brief C library implementation for operations with singly and doubly linked lists.
///
///Implements operations as initialisation of an empty list, adding a value at the beginning
///and at the end, inserting an item at a specified position, removing an item at a specified
///position, computing the length of a list and appending two lists for singly and
///doubly linked lists.
#include <stdio.h>
#include <stdlib.h>

#include "singly_functions.h"
#include "doubly_functions.h"

///\brief Singly type of linked list.
///
///Structure for singly type of linked lists.
struct Singly
{
    int data;///< An integer variable for storage the data in linked list.
    struct Singly *next;///< The link to next element.
};

///\brief Print a singly linked list.
///\param *head pointer to the first element of the list.
///\param *f pointer to the file for output results.
void singly_print_list( Singly *head, FILE *f )
{
    /// If the list is not empty, create a new node which will go through the list
    /// from the beginning.\n
    /// Print each element until the list ends.
    if ( head->next != NULL )
    {
        struct Singly *current;
        current = head;

        do
        {
            current = current->next;
            fprintf(f,"%d ", current->data);

        }while ( current->next != NULL );

        fprintf(f,"\n");
    }
    else
    {
        fprintf(f,"The list is empty\n");
    }
}

///\brief Return an element from a given position
///\param *head pointer to the first element of the list.
///\param pos represent the position from where displays the value.
///\return The value of element from position "pos".
int singly_pop_pos( Singly *head, int pos )
{
    /// With a "current" node go through the list to position "pos".\n
    /// Return the value of "current" node.
    int iterator;
    struct Singly *current;
    iterator = 0;
    current=head;

    while( iterator < pos )
    {
        current = current->next;
        iterator++;
    }
    return current->data;
}

///\brief Return a pointer of type singly linked list.
///\return Return a pointer of type singly linked list.
Singly* singly_init_emptylist()
{
    /// Creates and allocates memory for a new node.\n
    /// The list will be empty and the node will point to NULL.
    struct Singly* head;
    head = (Singly*)malloc(sizeof(Singly));
    head->data = NULL;
    head->next = NULL;

    return head;
}

///\brief Add a new element on the first position of list.
///\param *head pointer to the first element of the list.
///\param val represent the value that will be added.
void singly_push_first ( Singly *head, int val )
{
    /// Creates and allocates memory for a new node.\n
    /// Gives value to the new node.\n
    /// The new node will point to second element and the head of list
    /// will point to the new node.
    struct Singly *new_Singly;
    new_Singly = (Singly*) malloc(sizeof(Singly));
    new_Singly->data = val;
    new_Singly->next = head->next;
    head->next = new_Singly;
}

///\brief Add a new element on the last position of list.
///\param *head pointer to the first element of the list.
///\param val represent the value that will be added.
void singly_push_last( Singly *head, int val )
{
    /// Creates and allocates memory for a new node.\n
    /// Gives value to the new node.\n
    /// With a "current" node go through the list until the end.\n
    /// The "current" node will point to the new node.\n
    /// The new node will point to NULL.
    struct Singly *current;
    struct Singly *new_Singly;
    current = head;

    while( current->next != NULL )
    {
        current = current->next;
    }

    new_Singly = (Singly*) malloc(sizeof(Singly));
    current->next = new_Singly;
    new_Singly->data = val;
    new_Singly->next = NULL;
}

///\brief Add a new element on the specified position of list.
///\param *head pointer to the first element of the list.
///\param val represent the value that will be added.
///\param pos represent the position where the value will be added.
void singly_push_pos( Singly *head, int pos, int val )
{
    /// Creates and allocates memory for a new node.\n
    /// With a "current" node go through the list to position "pos".\n
    /// The new node will point to the "current" next element.\n
    /// The "current" node will point to the new node.
    /// Gives value to the new node.\n
    int iterator;
    struct Singly *current;
    struct Singly *added_Singly;
    iterator = 0;
    current=head;

    while( iterator < pos-1 )
    {
        current = current->next;
        iterator++;
    }

    added_Singly = (Singly*) malloc(sizeof(Singly));
    added_Singly->next = current->next;
    current->next = added_Singly;
    added_Singly->data = val;
}

///\brief Delete an element on the specified position of list.
///\param *head pointer to the first element of the list.
///\param pos represent the position where the value will be deleted.
void singly_delete_pos ( Singly *head, int pos )
{
    /// Creates and allocates memory for a deleted-node.\n
    /// With a "current" node go through the list to position "pos".\n
    /// The deleted-node will be "current" next element.\n
    /// "Current" node will point to deleted-node next element.\n
    /// Free the deleted-node memory.
    int iterator;
    struct Singly *current;
    struct Singly *deleted_node;
    iterator = 0;
    current = head;

    while( iterator < pos-1 )
    {
        current = current->next;
        iterator++;
    }

    deleted_node=current->next;
    current->next=deleted_node->next;
    free(deleted_node);

}

///\brief Return the length of list.
///\param *head pointer to the first element of the list.
///\return The length of the linked list.
int singly_length_list ( Singly *head )
{
    /// With a "current" node go through the list until the end.\n
    /// Count each element from list and return the number of elements.
    int length = 0;
    struct Singly *current;
    current = head;

    while ( current->next != NULL )
    {
        current = current->next;
        length++;
    }

    return length;
}

///\brief Append two singly lists.
///\param *head_list1 pointer to the first element of the list 1.
///\param *head_list2 pointer to the first element of the list 2.
void singly_append_lists ( Singly *head_list1, Singly *head_list2 )
{
    /// With a "current" node go to the end of list.\n
    /// The "current" node will point to the first element of second list.
    struct Singly *current;
    current = head_list1;

    while( current->next != NULL )
    {
        current = current->next;
    }

    current->next = head_list2->next;
}


///\brief Doubly type of linked list.
///
///Structure for doubly type of linked lists.
struct Doubly
{
    int data;///< An integer variable for storage the data in linked list.
    struct Doubly *next;///< The link to next element.
    struct Doubly *prev;///< The link to previous element.
};

///\brief Print a doubly linked list.
///\param *head pointer to the first element of the list.
///\param *f pointer to the file for output results.
void doubly_print_list( Doubly *head, FILE *f )
{
    /// If the list is not empty, create a new node which will go through the list
    /// from the beginning.\n
    /// Print each element until the list ends.
    if ( head->next != NULL )
    {
        struct Doubly *current;
        current = head;

        do
        {
            current = current->next;
            fprintf(f,"%d ", current->data);

        }while ( current->next != NULL );

        fprintf(f,"\n");
    }
    else
    {
        fprintf(f,"The list is empty\n");
    }
}

///\brief Return an element from a given position
///\param *head pointer to the first element of the list.
///\param pos represent the position where displays the value.
///\return The value of element from position "pos".
int doubly_pop_pos( Doubly *head, int pos )
{
    /// With a "current" node go through the list to position "pos".\n
    /// Return the value of "current" node.
    int iterator;
    struct Doubly *current;
    iterator = 0;
    current=head;

    while( iterator < pos )
    {
        current = current->next;
        iterator++;
    }
    return current->data;
}

///\brief Return a pointer of type doubly linked list.
///\return Return a pointer of type doubly linked list.
Doubly* doubly_init_emptylist()
{
    /// Creates and allocates memory for a new node.\n
    /// The list will be empty and the node will point to NULL.
    struct Doubly* head;
    head = (Doubly*) malloc(sizeof(Doubly));
    head->data = NULL;

    head->next = NULL;
    head->prev = NULL;

    return head;
}

///\brief Add a new element on the first position of list.
///\param *head pointer to the first element of the list.
///\param val represent the value that will be added.
void doubly_push_first ( Doubly *head, int val )
{
    /// Creates and allocates memory for a new node.\n
    /// Gives value to the new node.\n
    /// The new node will point to second element and to the head of list.\n
    /// The head of list will point to the new node.
    struct Doubly *new_Element;
    new_Element = (Doubly*) malloc(sizeof(Doubly));
    new_Element->data = val;
    new_Element->next = head->next;
    new_Element->prev = head;
    head->next = new_Element;
}

///\brief Add a new element on the last position of list.
///\param *head pointer to the first element of the list.
///\param val represent the value that will be added.
void doubly_push_last( Doubly *head, int val )
{
    /// Creates and allocates memory for a new node.\n
    /// Gives value to the new node.\n
    /// With a "current" node go through the list until the end.\n
    /// The "current" node will point to the new node.\n
    /// The new node will point to "current" node and to NULL.
    struct Doubly *current;
    struct Doubly *new_Element;
    current = head;

    while( current->next != NULL )
    {
        current = current->next;
    }

    new_Element = (Doubly*) malloc(sizeof(Doubly));
    current->next = new_Element;
    new_Element->data = val;
    new_Element->next = NULL;
    new_Element->prev = current;
}

///\brief Add a new element on the specified position of list.
///\param *head pointer to the first element of the list.
///\param val represent the value that will be added.
///\param pos represent the position where the value will be added.
void doubly_push_pos( Doubly *head, int pos, int val )
{
    /// Creates and allocates memory for a new node.\n
    /// With a "current" node go through the list to position "pos".\n
    /// The new node will point to the "current" next element and to "current" node.\n
    /// The "current" node will point to the new node.
    /// Gives value to the new node.\n
    int iterator;
    struct Doubly *current;
    struct Doubly *added_Element;
    iterator = 0;
    current=head;

    while( iterator < pos-1 )
    {
        current = current->next;
        iterator++;
    }

    added_Element = (Doubly*) malloc(sizeof(Doubly));
    added_Element->next = current->next;
    added_Element->prev = current;
    current->next = added_Element;
    added_Element->data = val;
}

///\brief Delete an element on the specified position of list.
///\param *head pointer to the first element of the list.
///\param pos represent the position where the value will be deleted.
void doubly_delete_pos ( Doubly *head, int pos )
{
    /// Creates and allocates memory for a deleted-node.\n
    /// With a "current" node go through the list to position "pos".\n
    /// The deleted-node will be "current" next element.\n
    /// "Current" node will point to deleted-node next element.\n
    /// The element after deleted-node will point to current.\n
    /// Free the deleted-node memory.
    int iterator;
    struct Doubly *current;
    struct Doubly *deleted_node;
    iterator = 0;
    current = head;

    while( iterator < pos-1 )
    {
        current = current->next;
        iterator++;
    }

    deleted_node=current->next;
    current->next=deleted_node->next;
    deleted_node->next->prev=current;
    free(deleted_node);

}

///\brief Return the length of list.
///\param *head pointer to the first element of the list.
///\return The length of the linked list
int doubly_length_list ( Doubly *head )
{
    /// With a "current" node go through the list until the end.\n
    /// Count each element from list and return the number of elements.
    int length = 0;
    struct Doubly *current;
    current = head;

    while ( current->next != NULL )
    {
        current = current->next;
        length++;
    }

    return length;
}

///\brief Append two doubly lists.
///\param *head_list1 pointer to the first element of the list 1.
///\param *head_list2 pointer to the first element of the list 2.
void doubly_append_lists ( Doubly *head_list1, Doubly *head_list2 )
{
    /// With a "current" node go the end of list.\n
    /// The "current" node will point to the first element of second list.\n
    /// The first element of second list will point to the last element of first list.
    struct Doubly *current;
    current = head_list1;

    while( current->next != NULL )
    {
        current = current->next;
    }

    current->next = head_list2->next;
    head_list2->next->prev = current;
}
