///\file doubly_functions.h
///\brief C library for operations with doubly linked lists.
///
///Implements operations as initialisation of an empty list, adding a value at
/// the beginning and at the end, inserting an item at a specified position,
/// removing an item at a specified position, computing the length of a list
///and appending two lists for doubly linked lists.
#ifndef DOUBLY_FUNCTIONS_H_INCLUDED
#define DOUBLY_FUNCTIONS_H_INCLUDED

    typedef struct Doubly Doubly;

    void doubly_print_list(Doubly *head, FILE *f);
    int doubly_pop_pos( Doubly *head, int pos );
    Doubly* doubly_init_emptylist();
    void doubly_push_first (Doubly *head, int val);
    void doubly_push_last(Doubly *head, int val);
    void doubly_push_pos(Doubly *head, int pos, int val);
    void doubly_delete_pos (Doubly *head, int pos);
    int doubly_length_list (Doubly *head);
    void doubly_append_lists (Doubly *head_list1, Doubly *head_list2);


#endif // DOUBLY_FUNCTIONS_H_INCLUDED
