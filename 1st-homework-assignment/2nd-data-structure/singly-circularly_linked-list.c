#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node* next;
}
node; 

node* addtoEmpty(int value);
node* addBegin(node *tail, int data);
node* addtoEnd(node *tail, int data);
void display(node* tail);


int main(){
  struct node* tail = addtoEmpty(5);
  tail = addBegin(tail, 15);
  tail = addtoEnd(tail, 3);
  display(tail);

}

node* addtoEmpty(int value){
  node* temp = (node *)malloc(sizeof(node));
  // Element pointer direct to itself 
  temp->value = value;
  temp->next = temp;

  return temp; 
}

node* addBegin(node *tail, int data){
  node *temp = (node *)malloc(sizeof(node));
  temp->value = data;
  
  // arranging the connections
  temp->next = tail->next;
  tail->next = temp;

  return tail;
}

node* addtoEnd(node *tail, int data){
  node *temp = (node *)malloc(sizeof(node));
  temp->value = data;

  // arranging the connections
  temp->next = tail->next;
  tail->next = temp;
  tail = temp;

  return tail;
}

void display(node* tail){
  node* temp = tail->next; 
  do
  {
    printf("%d ", temp->value);
    temp = temp->next;
    
  } while (temp != tail->next);
  
}