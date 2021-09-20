#ifndef EXERCISE1_H
#define EXERCISE1_H
#include <stdlib.h>
#include "CircularArrayQ.h"

/** \fn int get_queue_length(CircularArrayQueue list);
 *  \brief Get the number of elements in the current queue.
 *  \param list The current queue.
*/
int get_queue_length(CircularArrayQueue list){
	int x,l;
	for(x=list.front,l=0;x!=(list.rear+1)%MAX;x=(x+1)%MAX){
		l++;
	}	
	return l;
}

/** \fn PersonLinkedList get_all_females(CircularArrayQueue list);
 *  \brief Returns all females as a linked list using the current list without removing them in the current list.
 *  \param list The current queue.
 *  Note: Use the queue basic operations (enqueue, dequeue, front)
*/
PersonLinkedList get_all_females(CircularArrayQueue list){
	PersonLinkedList plist;
	plist=NULL;
	Type p;
	while(!is_empty(list)){
		p=front(list);
		if(p.sex=='F' || p.sex=='f'){
			insert_first_LL(&plist,p);
		}
		dequeue(&list);
	}

	return plist;
}

/** \fn PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);
 *  \brief Remove all males in the current list and returns the removed males as a dynamic array list.
 *  \param list The current queue.
 *  Note: Use the concept of queue with out using the basic operations.
*/
PersonDynamicArrayList remove_all_males(CircularArrayQueue *list){
	PersonDynamicArrayList DL;
	
	CircularArrayQueue temp;
	init_array_queue(&temp);
	temp=*list;
	init_DAL(&DL);
	int x,i,cnt;
	for(i=0;list->front!=(list->rear+1)%MAX;){
		if(list->data[list->front].sex=='M'|| list->data[list->front].sex=='m'){
			insert_last_DAL(&DL,list->data[list->front]);
			cnt++;
			list->front=(list->front+1)%MAX;
		}else if(list->data[list->front].sex=='F'|| list->data[list->front].sex=='f'){
			temp.data[i]=list->data[x];
			list->front=(list->front+1)%MAX;
			temp.front=(temp.front+1)%MAX;
		}else{
			list->front=(list->front+1)%MAX;
			
		}
		
		}
		
//	list->rear-=cnt;
//	displayqueue(*list);
//	display_DAL(DL);
	return DL;

}

#endif
