//
//  STACK_ADT.c
//  stackADT
//
//  Created by 조팝개발자by_ju on 2021/05/06.
//

#include <stdio.h>
#include <stdlib.h>
#include "STACK_ADT.h"

#define INIT_CAPACITY 100
void reallocate(Stack s);

struct stack_type{
    Item *contents;
    int top;
    int size;
};


static void terminate(const char *message){
    printf("%s\n", message);
    exit(1);
}

Stack create(void){
    
    Stack s = (Stack)malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: stack could not be created.");
    s->contents = (Item *)malloc(INIT_CAPACITY * sizeof(Item));
    if (s->contents == NULL) {
        free(s);
        terminate("Error in create: stack could not be created.");
    }
    s->top = -1;
    s->size = INIT_CAPACITY;
    return s;
}

void destroy(Stack s) {
    
    free(s->contents);
    free(s);
}

void make_empty(Stack s){
    s->top = -1;
}

int is_empty(Stack s){
    
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int is_full(Stack s){
    if (s->top == s->size -1)
        return 1;
    else
        return 0;
} 

void push(Stack s, Item i){
    if (is_full(s))
        reallocate(s);
    s->top++;
    s->contents[s->top] = i;
}

Item pop(Stack s){
    
    if (is_empty(s))
        terminate("Error in pop: stack is empty.");
    s->top--;
    return s->contents[s->top+1];
}

Item peek(Stack s){
    
    if (is_empty(s))
        terminate("Error in peek: stack is empty.");
    return s->contents[s->top];
}

void reallocate(Stack s)
{
    Item *tmp = (Item *)malloc(2 * s->size * sizeof(Item));
    if (tmp == NULL) {
        terminate("Error in create: stack could not be created.");
    }
    for (int i = 0; i<s->size; i++)
        tmp[i] = s->contents[i];
    free(s->contents);
    s->contents = tmp;
    s->size *= 2;
}

