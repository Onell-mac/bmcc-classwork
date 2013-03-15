#include "giglio_proj2_1.h"

// print a welcome message when program launches
void printWelcome() {
  printf("\nWelcome to Dominic's Circular Doubly Linked List example!\n\
Use the menu below to experimemt with all the different ways\n\
to create, alter and destroy linked lists. You will be able\n\
to continue using this menu until you choose to leave.\n\n"
  );
}

// print the menu used by the user to interact with the list
int printMenu() {
  int choice = 0;

  printf("\nPlease choose from the following options:\n\n\
1.) Print the list\n\
2.) Insert a single element into the list\n\
3.) Check if the list is empty\n\
4.) Exit\n\n\
choice: "
  );

  // get the users choice
  scanf("%d", &choice);
  return choice;
}

// determine if the list is empty
int isEmpty(node *n) {
  int count = 1;
  node *cursor = n->next;

  while (cursor != n) {
    count++;
    cursor = cursor->next;
  }

  if (count > 2)
    return 0;
  else
    return 1;
}

// insert one element into the list
void insertOne(elem e, node *n) {
  node *rightElem = n->next;  

  // if this is a new list with nothing in head, put e there
  // else, if this is a new list with nothing in tail, put e there
  // otherwise, create a new node and insert it into the list
  if (n->data == NULL) {
    n->data = (elem) e;
  } else if (n->prev->data == NULL) {
    n->prev->data = (elem) e;
  } else {
    node *newElem = (node *) malloc(sizeof(node));

    if (newElem == NULL) {
      printf("Error allocating memory!\n");
      return EXIT_FAILURE;
    }

    newElem->data = (elem) e;
    newElem->next = rightElem;
    newElem->prev = n;
    n->next = newElem;
    rightElem->prev = newElem;
  }

}

