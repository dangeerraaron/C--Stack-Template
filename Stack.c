//Stack Data Structure and Operations 
// All Credit to Portfolio Courses Channel on YouTube!!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct //define new type called stack
{
    int *collection; //pointer to dynamic array
    int capacity; // size of the array, memory value of int
    int size; // number of elements in array
    

}Stack;

Stack *create_stack(int capacity); //use of heap memory
void destroy_stack (Stack *stack);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool pop(Stack *stack, int *item); //pass by pointer to pop item
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *item); //peeks at item on top of stack

int main (void)
{
    Stack *stack = create_stack(5);
    
    if(stack == NULL)
    {
        printf("Error creating stack.\n");
        return 1; // signals shell/terminal ar error
    }
    
    if(is_empty(stack)) printf("Stack is empty.\n");
    
    push(stack, 2);
    printf("Stack size: %d\n", stack->size);
    
    push(stack,9);
    push(stack,4);
    push(stack,7);
    push(stack,8);
    
    if(is_full(stack)) printf("Stack is full.\n");
    printf("Stacksize: %d\n", stack->size);
    
    bool try_push = push(stack, 5); 
    if(try_push == false) printf("Push failed.\n");
    
    int peek_val = 0;
    peek(stack, &peek_val);
    
    printf("Peek Val: %d \n", peek_val);
    
    int pop_val = 0;
    
    for(int i=0; i < 5; i++)
    {
       pop(stack, &pop_val);
       printf("Popped Value: %d\n", pop_val);
    }
    
    bool try_pop = pop(stack, &pop_val);
    if(try_pop == false) printf("Pop Failed.\n");
    
    bool try_peek = peek(stack, &peek_val);
    if(try_peek == false) printf("Peek Failed.\n");
    
    destroy_stack(stack);

    return 0;
}

Stack *create_stack(int capacity)
{
    if(capacity <= 0) return NULL;
    
    Stack *stack = malloc(sizeof(Stack)); //dynamically allocate space for stack in memory amd store memory address in *stack
    if(stack == NULL) return NULL;
    
    stack->collection = malloc(sizeof(int) * capacity); // allocate array memory based on capacity given, store in address of collection
    if(stack->collection == NULL) // if collection fails to create stack
    {
        free(stack); //free up memory, for safety
        return NULL;
    }
    
    stack->capacity = capacity;
    stack->size = 0; // initially nothing in stack
    
    return stack;
    
}

void destroy_stack (Stack *stack)
{
   free(stack->collection); //destroy dynamically allocated array memory
   free(stack); //destroy stack
}

bool is_full(Stack *stack)
{
    return stack->capacity == stack->size; //if stack capacity = size, then true
}

bool is_empty(Stack *stack)
{
    return stack->size == 0; //return true if stack size is 0, meaning it is empty
}

bool push(Stack *stack, int item)
{
    if(is_full(stack)) return false; // if full cannot push item
    
    stack->collection[stack->size] = item; // pushes item on top of stack
    stack->size++; // pushes stack on to next element on array
    
    return true;
}

bool peek(Stack *stack, int *item)
{
    if(is_empty(stack)) return false;
    
    *item = stack->collection[stack->size - 1]; // peeks at the current top of stack by derefencing the address, pass by pointer
    
    return true;
}

bool pop(Stack *stack, int *item)
{
    if(is_empty(stack)) return false;
    
    stack->size--; //decrement size to modify where top of stack is
    
    *item = stack->collection[stack->size]; //pass by pointer to address of val
    
    return true;
}
