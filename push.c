#include <stdio.h>
#include "monty.h"
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack* next;
} stack_t;

// Function to push a value onto the stack
void f_push(stack_t** head, int value) {
    stack_t* new_node = (stack_t*)malloc(sizeof(stack_t));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}
