///\file singly_functions.h
///\brief C library for operations with singly linked lists.
///
///Implements operations as initialisation of an empty list, adding a value at
/// the beginning and at the end, inserting an item at a specified position,
///removing an item at a specified position, computing the length of a list
/// and appending two lists for singly linked lists.
#ifndef SINGLY_FUNCTIONS_H_INCLUDED
#define SINGLY_FUNCTIONS_H_INCLUDED

    typedef struct Singly Singly;

    void singly_print_list(Singly *head, FILE *f);
    int singly_pop_pos( Singly *head, int pos );
    Singly* singly_init_emptylist();
    void singly_push_first (Singly *head, int val);
    void singly_push_last(Singly *head, int val);
    void singly_push_pos(Singly *head, int pos, int val);
    void singly_delete_pos (Singly *head, int pos);
    int singly_length_list (Singly *head);
    void singly_append_lists (Singly *head_list1, Singly *head_list2);

#endif // SINGLY_FUNCTIONS_H_INCLUDED
