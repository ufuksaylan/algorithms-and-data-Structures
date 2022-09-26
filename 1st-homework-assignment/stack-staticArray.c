#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 4 

typedef struct stack
{
  int array[CAPACITY];
  int top; 
}
stack;

bool isEmpty(stack* s); 
bool isFull(stack* s);
int peek(stack* s);
void push(stack* s, int x);
void pop(stack* s);
void clear(stack* s);
void display(stack s);
void reverse(stack* s);
void insertFromBottom(stack* s, int x);


int main(){

  stack stack1;
  stack1.top = -1;  

  push(&stack1, 1);
  push(&stack1, 2);
  push(&stack1, 3);
  push(&stack1, 4);

  display(stack1);


  printf("\n");

  reverse(&stack1);

  printf("\n");
  display(stack1);
  // printf(isFull(&stack1) ? "true": "false");
}

bool isEmpty(stack* s) {
  return s->top == -1; 
}

bool isFull(stack* s) {
  return (s->top + 1) == CAPACITY; 
}

int peek(stack* s) {
  if (isEmpty(s))
    printf("nothing to see here\n");
  else
  {
    printf("%d\n", s->array[s->top]);
    return s->array[s->top]; 
  }  
}

void push(stack* s, int x) {
  if (isFull(s))
    printf("\nThe stack is full.");
  else
  {
    s->top += 1; 
    s->array[s->top] = x; 
  }
}

void pop(stack* s) {
  if (isEmpty(s))
    printf("\nThe stack is empty.");
  else
    s->top -= 1; 
}

void clear(stack* s) {
  s->top = -1; 
}

void display(stack s) {
  if (isEmpty(&s))
    printf("Nothing to display.");
  else 
  {
    while (s.top != -1)
    { 
      peek(&s);
      s.top -= 1;
    }
  }
}

void reverse(stack* s) {  
  if (!isEmpty(s)) {  
    int temp = peek(s);
    pop(s); 

    reverse(s);
    insertFromBottom(s, temp);
  }
}

void insertFromBottom(stack* s, int x) {
  if (isEmpty(s))
    push(s, x);
  else {
    int topElement = peek(s);
    pop(s);

    insertFromBottom(s, x);

    push(s, topElement); 
  }
  
}