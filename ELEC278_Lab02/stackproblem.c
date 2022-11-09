// stackproblem.c - Lab 02 - Jake Moffat
// Created by Jake Moffat on 2021-09-28.
//

// libraries
#include <stdio.h>
#include <stdlib.h>


// define structs, node and linked lists
// Handy manifests
#define	EXIT_OK		0
#define	EXIT_ERROR	-1
#define	SIZE_STACK 80

// Definition of stack node - this version implements stack of integers
//typedef struct _sn {
//    struct _sn	*next;
//    int			nodval;
//} StkNode;

// Now do a version that implements stack of chars
typedef struct _sn {
    struct _sn  *next;
    char        nodchar;
} StkNode;

// This implementation has only one stack
StkNode		*head = NULL;

// push function for chars
char push (char c)
// Top of stack is front of linked list.  Create node to hold data and
// place it at front of list. Returns 0 if no node created; 1 for success.
{
    StkNode *p = (StkNode *)malloc(SIZE_STACK);
    if (p == NULL)	return 0;
    p->nodchar = c;
    p->next = head;
    head = p;
    return  1;
}//push()

// pop function for chars
char  pop (char *pchar)
// Top of stack is front of linked list. Check if list empty; if not,
// remove first node on list and copy value to supplied location.
{
    int	rslt = 0; //check if pop function works
    if (pchar != NULL)	{
        StkNode *p = head;
        if (p != NULL)	{
            head = p->next;
            *pchar = p->nodchar;
            free (p);
            rslt = 1; // works if 1
        }//endif stack not empty
    }//endif result location available
    return rslt;
}// pop()

// void main function
void main (void)
{
    char	ch;
    int		going;

    printf ("Please insert characters: \n");

    going = 1;
    while (going)	{
        // very specific format !!
        scanf ("%c", &ch);			// get the letter in the first position
        printf ("Received %c \n", ch);

        if (ch == "\n") {
            going = 0; //same as break;
            //break;

            // insert char into stack
        }}