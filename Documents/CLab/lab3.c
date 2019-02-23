/*
  Finish this code so that it:

  * Builds a doubly-linked list of pte structures, with random integer ages from 1 to 100
  * Prints the ages, in order from left to right, in the list
  * Bubble sort the doubly-linked list, by age
  * Print them again, so we can see they're sorted.

  Starter code is below

  ------------------------------

  Bubble Sort a doubly-linked list
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct pte{
  int pageID;
  struct pte *prev;
  struct pte *next;
  int age;
} pte;

#define N 100 /* Number of pages */
int main(){
  int i; /* counter */
  pte *first; /* "first" entry in the ring */
  pte *iter; /* Iterator around the ring */
  srand(time(NULL));
  first = (pte*)malloc(sizeof(pte));
  first->pageID = 0;
  first->age = 0;

  // Build the doubly-linked list of ptes
  iter = first;
  for(i = 0; i < N; i++){
    pte *p = (pte*)malloc(sizeof(pte));

    if(i<N-1){
      iter->next = p;
      p->prev = iter;
      p->pageID = iter->pageID + 1;
      p->age = random()%100 + 1;  //randomly generate ages
      iter = p;
    
    } else {
      iter->next = first;
      p->pageID = iter->pageID + 1;
      p->age = random()%100 + 1;  //randomly generate ages...
      first->prev = first;
    }

  }

  // Print the ages, in order, in the list
  struct pte *p = first;
  printf("Start sort!\n");
  for(int i = 0; i<N; i++){
    printf("%d\n",p->age);
    p = p->next;
  }
  // Bubble sort the list
  
  struct pte *f = first;
  for(int i = 0; i<N; i++){
    pte *s = first;
    for(int j = 0; j<N; j++){
      if(f->age > s->age){
	
	struct pte x = *f;
	struct pte y = *s;

	x.next = s->next;
	y.next = f->next;
	x.prev = s->prev;
	y.prev = f->prev;

	*f->prev->next = y;
	*s->prev->next = x;

      }
      s = s->next;
     
    }
    f = f->next;
    
  }

  printf("Sort complete!\n");
  // Print sorted list
  struct pte *l = first;
  for(int i = 0; i<N; i++){
    printf("%d\n",l->age);
    l = l->next;
  }
  
  
  return 0;
}
