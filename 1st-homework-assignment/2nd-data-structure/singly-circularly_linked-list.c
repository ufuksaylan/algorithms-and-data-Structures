#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node{
  int value;
  struct node* next;
}
node; 

node* addtoEmpty(int value);
node* addtoBegin(node *tail, int data);
node* addtoEnd(node *tail, int data);
node* addtoMiddle(node *tail, int data);
node* deleteBegin(node *tail);
node* deleteEnd(node *tail);
node* deleteMiddle(node *tail);

//return the index
int search(node *tail, int data);

bool isEmpty(node* tail);
int getLength(node* tail);
void display(node* tail);
void displayMenu();



int main(){
  
  displayMenu();
  struct node* tail = addtoEmpty(5);
  tail = addtoBegin(tail, 15);
  tail = addtoEnd(tail, 3);
  tail = addtoMiddle(tail, 19);
  tail = addtoMiddle(tail, 12);
  tail = deleteBegin(tail);
  tail = deleteEnd(tail);
  tail = addtoBegin(tail, 15);
  tail = addtoBegin(tail, 99);
  tail = deleteMiddle(tail);
  


  display(tail);
  printf("\n%d", search(tail, 15));
}

node* addtoEmpty(int value){
  node* temp = (node *)malloc(sizeof(node));
  // Element pointer direct to itself 
  temp->value = value;
  temp->next = temp;

  return temp; 
}

int getLength(node* tail) {
  int length = 0; 
  node* temp = tail->next; 
  do
  {
    length++; 
    temp = temp->next;
    
  } while (temp != tail->next);
  return length; 
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

  int length =  getLength(tail);
  int middle = length % 2 == 0 ? length / 2 : (length + 1) / 2; 
  
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

node* deleteBegin(node *tail){
  if (tail->next == tail)
  {
    free(tail);
    tail = NULL;
    return tail;
  }

  // arranging the connections
  node* temp = tail->next;
  tail->next = temp->next;
  free(temp);

  return tail; 
}

node* deleteEnd(node *tail){

  if (tail->next == tail)
  {
    free(tail);
    tail = NULL;
    return tail;
  }

  node* temp = tail->next;

  while (temp->next != tail)
  {
    temp = temp->next;
  }  

  // arranging the connections
  temp->next = tail->next;
  free(tail);
  tail = temp;  

  return tail;  
}

node* deleteMiddle(node *tail){
  if (tail->next == tail)
  {
    free(tail);
    tail = NULL;
    return tail;
  }

  int middle = round(getLength(tail) / 2.0);
  printf("middle:%d\n", middle);
  //temp pointer to reach to the middle index
  node *p = tail->next;

  for (int i = 0; i < middle - 2; i++)
  {
    p = p->next;
  }

  node *temp = p->next;
  p->next = temp->next;
  free(temp);
  return tail; 
}

bool isEmpty(node* tail) {
  return tail->next == NULL;
}

int search(node *tail, int data) {

  if(isEmpty(tail))
    return -1; 

  node *temp = tail->next; 
  int i = 0;
  do
  {
    if(temp->value == data)
      return i;
    temp = temp->next;
    i++;
  } while (temp != tail->next);

  return -1;
}

void displayMenu(){
  printf("=============================================="); 
"======================";
  printf("\nMenu:\n");
  printf("1. Insert At Front\n");
  printf("2. Insert At End\n");
  printf("3. Insert at middle\n");
  printf("4. Delete From Front\n");
  printf("5. Delete From End\n");
  printf("6. Delete From Middle\n");
  printf("7. Search for a element\n(Index of element will be printed, if exists)\n");
  printf("8. Reverse the list\n");
  printf("9. Display the list\n");
  printf("====================================================================\n");

}
 