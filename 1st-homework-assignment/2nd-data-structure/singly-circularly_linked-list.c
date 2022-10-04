#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node* next;
}
node; 

node* addtoEmpty(int value);
node* addtoBegin(node *tail, int data);
node* addtoEnd(node *tail, int data);
node* addtoMiddle(node *tail, int data);
int getMiddleIndex(node* tail);
void display(node* tail);


int main(){
  struct node* tail = addtoEmpty(5);
  tail = addtoBegin(tail, 15);
  tail = addtoEnd(tail, 3);
  tail = addtoMiddle(tail, 19);
  tail = addtoMiddle(tail, 12);

  display(tail);

}

node* addtoEmpty(int value){
  node* temp = (node *)malloc(sizeof(node));
  // Element pointer direct to itself 
  temp->value = value;
  temp->next = temp;

  return temp; 
}

int getMiddleIndex(node* tail) {
  int length = 0; 
  node* temp = tail->next; 
  do
  {
    length++; 
    temp = temp->next;
    
  } while (temp != tail->next);
  int middle = length % 2 == 0 ? length / 2 : (length + 1) / 2; 
  return middle; 
}

node* addtoBegin(node *tail, int data){
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

node* addtoMiddle(node *tail, int data){

  int middle = getMiddleIndex(tail);
  
  node *tempNode = (node *)malloc(sizeof(node));
  tempNode->value = data;

  // temp pointer to get the middle index
  node *p = tail->next;

  for (int i = 0; i < middle-1; i++)
  {
    p = p->next;
  }
  
  // arranging the connections between two nodes
  tempNode -> next = p -> next;
  p -> next = tempNode;

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