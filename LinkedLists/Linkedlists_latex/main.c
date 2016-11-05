/// \file main.c
/// \brief Libraries 2. : A library for linked lists.

#include <stdio.h> /*for prinf().*/
#include <stdlib.h>
#include <time.h> /* for using function time (get current time) and macro constant NULL.*/

#include "singly_functions.h" /* the header file containing singly linked list functions.*/
#include "doubly_functions.h" /* the header file containing doubly linked list functions.*/

///\brief Singly type of linked list.
///
///Structure for singly type of linked lists.
struct Singly
{
    int data;///< An integer variable for storage the data in linked list.
    struct Singly *next;///< The link to next element.
};

///\brief Doubly type of linked list.
///
///Structure for doubly type of linked lists.
struct Doubly
{
    int data;///< An integer variable for storage the data in linked list.
    struct Doubly *next;///< The link to next element.
    struct Doubly *prev;///< The link to previous element.
};

///\brief Test generator for singly type structure.
///\param *f pointer to the file for output results.
///\return The test results.
void singly_test(FILE *f)
{
    int i;
    int length=2000; /// length : a variable for length of list, default at 2000 elements.\n
    int val; /// val : a variable to enter values in list.\n
    int pos; /// pos : a variable for positions in lists.\n

    struct Singly *head_first;
    head_first = singly_init_emptylist();

    struct Singly *head_second;
    head_second = singly_init_emptylist();

    /// Create two lists using singly_push_last and singly_push_first functions
    /// with length value of "length".\n
     for(i=1;i<=length;i++)
    {
        val = rand();
        singly_push_last(head_first, val);

        val = rand();
        singly_push_first(head_second, val);
    }

    pos = rand()%2000+1;

    /// Print the initial list and the list after we delete the element.\n
    /// Print the element from position "pos" (generated with C random function),
    /// before and after we delete the element.
    fprintf(f,"Initial singly linked list : \n");
    singly_print_list(head_first, f);
    fprintf(f,"\nThe %d-th element that will be deleted : %d\n", pos, singly_pop_pos(head_first, pos));
    singly_delete_pos(head_first, pos);
    fprintf(f,"The new element from position %d : %d\n\n", pos, singly_pop_pos(head_first,pos));
    fprintf(f,"List : \n");
    singly_print_list(head_first, f);

    fprintf(f,"------------------------------------------------\n");

    pos = rand()%2000+1;
    val = rand();

    /// Add the a new element "val" on position "pos", both generated with C random function.\n
    /// Print the element from position "pos".
    singly_push_pos(head_first, pos, val);
    fprintf(f,"Element %d added on position %d\n", val,pos);
    fprintf(f,"The element from position %d : %d\n",pos, singly_pop_pos(head_first, pos));

    /// Print the length of the list and the list.\n
    fprintf(f,"Length of list : %d\n\n", singly_length_list(head_first));
    fprintf(f,"List : \n");
    singly_print_list(head_first, f);
    fprintf(f,"------------------------------------------------\n");

    /// Append the two list, print the result and lengh of appended lists.\n
    singly_append_lists(head_first, head_second);
    fprintf(f,"Length of the appended lists : %d\n\n", singly_length_list(head_first));
    fprintf(f,"Appended Lists : \n");
    singly_print_list(head_first, f);

}

///\brief Test generator for doubly type structure.
///\param *f pointer to the file for output results.
///\return The test results.
void doubly_test(FILE *f)
{
    int i;
    int length=2000; /// length : a variable for length of list, default at 2000 elements.\n
    int val; /// val : a variable to enter values in list.\n
    int pos; /// pos : a variable for positions in lists.\n

    struct Doubly *head_first;
    head_first = doubly_init_emptylist();

    struct Doubly *head_second;
    head_second = doubly_init_emptylist();

     /// Create two lists using doubly_push_last and doubly_push_first functions
     /// with length value of "length".\n
     for(i=1;i<=length;i++)
    {
        val = rand();
        doubly_push_last(head_first, val);

        val = rand();
        doubly_push_first(head_second, val);
    }

    pos = rand()%2000+1;

    /// Print the initial list and the list after we delete the element.\n
    /// Print the element from position "pos" (generated with C random function),
    /// before and after we delete the element.
    fprintf(f,"Initial doubly linked list : \n");
    doubly_print_list(head_first, f);
    fprintf(f,"\nThe %d-th element that will be deleted : %d\n", pos, doubly_pop_pos(head_first, pos));
    doubly_delete_pos(head_first, pos);
    fprintf(f,"The new element from position %d : %d\n\n", pos, doubly_pop_pos(head_first,pos));
    fprintf(f,"List : \n");
    doubly_print_list(head_first, f);

    fprintf(f,"------------------------------------------------\n");

    pos = rand()%2000+1;
    val = rand();
    /// Add the a new element "val" on position "pos", both generated with C random function.\n
    /// Print the element from position "pos".
    doubly_push_pos(head_first, pos, val);
    fprintf(f,"Element %d added on position %d\n", val, pos);
    fprintf(f,"The element from position %d : %d\n",pos, doubly_pop_pos(head_first, pos));

    /// Print the length of the list and the list.\n
    fprintf(f,"Length of list : %d\n\n", doubly_length_list(head_first));
    fprintf(f,"List : \n");
    doubly_print_list(head_first, f);
    fprintf(f,"------------------------------------------------\n");

    /// Append the two list, print the result and lengh of appended lists.\n
    doubly_append_lists(head_first, head_second);
    fprintf(f,"Length of the appended lists : %d\n\n", doubly_length_list(head_first));
    fprintf(f,"Appended Lists : \n");
    doubly_print_list(head_first, f);

}

///\brief Main function.
///
///Function call tests generator for singly and doubly linked lists giving tests
/// with operation imported from "singly_functions.h" and "doubly_functions.h".\n
int main()
{
    /// Opens a text file for writing in appending mode. If it does not exist, then a new
    ///file is created. The program will start appending content in the existing file content.\n
    FILE *f = fopen("LinkedLists_output.txt","w");

    /// Intializes random number generator.\n
    srand(time(NULL));

    /// Uses the singly_test and doubly_test, tests generator function.\n
    singly_test(f);
    fprintf(f,"\n---------------------------------------------------------\n---------------------------------------------------------\n\n");
    doubly_test(f);
    return 0;
}
