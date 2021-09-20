#ifndef CIRCULARARRAYQ_H
#define CIRCULARARRAYQ_H

#include <stdbool.h>
#include "Person.h"
#define MAX 10

typedef Person Type;

typedef struct {
    Type data[MAX];
    int front;
    int rear;
} CircularArrayQueue;

/** \fn CircularArrayQueue create_array_queue();
 *  \brief Create an empty circular array queue.
*/
CircularArrayQueue create_array_queue(){
	CircularArrayQueue A;
	return A;
}

/** \fn void init_array_queue(CircularArrayQueue *list);
 *  \brief Initialize as an empty circular array queue.
 *  \param list The queue that needs to be initialize.
*/
void init_array_queue(CircularArrayQueue *list){
	list->front=0;
	list->rear=MAX-1;
}

/** \fn bool is_empty(CircularArrayQueue list);
 *  \brief Return true if the current list is empty otherwise false.
 *  \param list The current queue.
*/
bool is_empty(CircularArrayQueue list){
	bool b=false;
	if(list.front==(list.rear+1)%MAX){
		b=true;
	}
	return b;
}

/** \fn bool is_full(CircularArrayQueue list);
 *  \brief Return true if the current list is full otherwise false.
 *  \param list The current queue.
*/
bool is_full(CircularArrayQueue list){
	bool b=false;
	if(list.front==(list.rear+2)%MAX){
		b=true;
	}
	return b;
}

/** \fn bool enqueue(CircularArrayQueue *list, Type p);
 *  \brief Adds a new person element into the last element available in the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
 *  \param p The person to be added in the queue.
*/
bool enqueue(CircularArrayQueue *list, Type p){
	if(!is_full(*list)){
		list->rear=(list->rear+1)%MAX;
		list->data[list->rear]=p;
	}
}

/** \fn bool dequeue(CircularArrayQueue *list);
 *  \brief Remove the first inserted element from the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
*/
bool dequeue(CircularArrayQueue *list){
	if(!is_empty(*list)){
		list->front=(list->front+1)%MAX;
}
}



/** \fn Type front(CircularArrayQueue list);
 *  \brief Return the person in the front without removing them.
 *  \param list The current queue.
*/
Type front(CircularArrayQueue list){
	Type p;
	p=list.data[list.front];
	return p;
}

void displayqueue(CircularArrayQueue list){
	int x;
	printf("%15s |%15s |%15s \n", "NAME","SEX","CITY");
	for(x=list.front;x!=(list.rear+1)%MAX;x=(x+1)%MAX){
         printf("{%15s | %15c | %15s}\n", list.data[x].name, list.data[x].sex, list.data[x].city);
	}
}
#endif
