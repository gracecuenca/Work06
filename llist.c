#include <stdio.h>
#include <stdlib.h>

//da node
struct node {
  int i;
  struct node *next;
};

//printing the list
void print_list(struct node * bob){
  printf("HEAD->");
  while(bob){
    printf("%d->", bob->i);
    //going through the list bob
    bob = bob->next;
  }
  printf("NULL\n");
}

struct node * insert_front(struct node * bob, int x){
  struct node * frntptr;
  //memory allocated for new node of list
  frntptr = malloc(sizeof(struct node));
  frntptr->i = x;
  frntptr->next = bob;
  return frntptr;
}

struct node * free_list(struct node * bob ){
  while(bob){
    //utilizing temp node to take each node
    struct node * temp = bob;
    bob = bob-> next;
    free(temp);
    //setting to null
    temp = NULL;
  }
  return bob;
}

int main(){
  struct node * chum = 0;
  printf("chum before any chums:\n");
  print_list(chum);
  int i = 10;
  while(i){
    chum = insert_front(chum,i);
    i--;
  }
  printf("chum after chums added:\n");
  print_list(chum);
  chum = free_list(chum);
  printf("chum after freeing chums:\n");
  print_list(chum);
}
