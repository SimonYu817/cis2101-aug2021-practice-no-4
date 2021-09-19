#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIST 20
#define MAX_VSPACE 30

typedef char String[30];

typedef struct {
    String name;
    char sex;
    String city;
} Person;

typedef struct {
    Person data[MAX_LIST];
    int count;
} PersonStaticArrayList;

typedef struct {
    Person *data;
    int count;
    int max;
} PersonDynamicArrayList, *PersonDynamicArrayListPointer;

typedef struct node{
    Person elem;
    struct node *next;
} PersonNode, *PersonLinkedList;

typedef int Position;
typedef int PersonCusorBasedList;

typedef struct {
    Person elem;
    Position next;
} CNode;

typedef struct {
    CNode data[MAX_VSPACE];
    Position avail;
} VSpace;


Person createPerson(String name, char sex, String city);
void displayPersonInfo(Person p);

/* Static Array List*/
void init_SAL(PersonStaticArrayList *list){
	list->count=0;
}
void insert_first_SAL(PersonStaticArrayList *list, Person p){
	int x,i;
	if(list->count!=MAX_LIST){
		for(x=list->count;x>0;x--){
			list->data[x]=list->data[x-1];
		}
		list->data[x]=p;
		list->count++;
	}
}

void insert_last_SAL(PersonStaticArrayList *list, Person p){
	if(list->count!=MAX_LIST){
		list->data[list->count]=p;
		list->count++;
	}
}

void insert_at_SAL(PersonStaticArrayList *list, Person p, int index){
	int x;
	if(list->count!=MAX_LIST){
		if(index<=list->count){
			for(x=list->count;x>index;x--){
				list->data[x]=list->data[x-1];
			}
			list->data[x]=p;
		}
	}
}

void delete_first_SAL(PersonStaticArrayList *list){
	int x;
	for(x=0;x<list->count-1;x++){
		list->data[x]=list->data[x+1];
	}	
	list->count--;
}
void delete_last_SAL(PersonStaticArrayList *list){
	list->count--;
}
void delete_by_sex_SAL(PersonStaticArrayList *list, char sex){
	int x,i;
		for(x=0;x<list->count;x++){
			if(list->data[x].sex==sex){
			list->data[x]=list->data[x+1];
			i++;
			}
		}

	list->count-=i;
} // all ocurrences
void display_SAL(PersonStaticArrayList list){
	int x;
	for(x=0;x<list.count;x++){
	   printf("{%s | %c | %s}\n", list.data[x].name, list.data[x].sex, list.data[x].city);
	}
}

/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */
void init_DAL(PersonDynamicArrayList *list){
	list = (PersonDynamicArrayList *) malloc(sizeof(PersonDynamicArrayList));

    list->count = 0;
    list->max = MAX_LIST;
    list->data = (Person *) malloc(sizeof(Person)*list->max);
}
void insert_first_DAL(PersonDynamicArrayList *list, Person p){
	int i;
    if(list->count >= list->max) {
        list->max *= 2;
        list->data = (Person*)realloc(list->data, list->max);
    }

    for(i = list->count; i > 0; --i) {
        list->data[i] = list->data[i-1];
    }
    list->data[i] = p;
    list->count++;
}
void insert_last_DAL(PersonDynamicArrayList *list, Person p){
	if(list->count >= list->max) {
        list->max *= 2;
        list->data = (Person*)realloc(list->data, list->max);
    }

    list->data[list->count++] = p;
}
void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index);
void delete_first_DAL(PersonDynamicArrayList *list){
	    int i;
    if(list->count > 0) {
   
        for(i=0; i<list->count-1; ++i) {
            list->data[i] = list->data[i+1];
        }
        list->count--;
    }
}
void delete_last_DAL(PersonDynamicArrayList *list){
	if(list->count > 0) {
        list->count--;
	}
}
void delete_by_city_DAL(PersonDynamicArrayList *list, String city){
	int i, pos;

    for(i=0; i<list->count; ++i) {
        if(strcmp(list->data[i].city,city) ==0 ) {
            pos=i;
            break;
        }
    }

    if(i<list->count) {
        for(i=pos; i<list->count-1; ++i) {
            list->data[i] = list->data[i+1];
        }
        list->count--;

}
} // first ocurrence

void display_DAL(PersonDynamicArrayList list){

    int i;
    printf("{");
    for(i=0; i<list.count; ++i) {
         printf("{%s | %c | %s}\n", list.data[i].name, list.data[i].sex, list.data[i].city);
        if(list.count-1 > i) {
            printf(", ");
        }
    }
    printf("} Count: %d; Max: %d\n", list.count, list.max);
}
/* Dynamic Array List - v2 
 * Doubles the maximum size of the array when full.
 * The Dynamic Array List must also be created in the heap.
 */
void init_DAL_2(PersonDynamicArrayList **list);
void insert_first_DAL_2(PersonDynamicArrayList *list, Person p);
void insert_last_DAL_2(PersonDynamicArrayList *list, Person p);
void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index);
void delete_first_DAL_2(PersonDynamicArrayList *list);
void delete_last_DAL_2(PersonDynamicArrayList *list);
void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name); // last ocurrence
void display_DAL_2(PersonDynamicArrayList list);

/* Singly Linked List */
void insert_first_LL(PersonLinkedList *list, Person p){
	PersonLinkedList temp;
	temp = (PersonLinkedList)malloc(sizeof(PersonNode));
	if(temp!=NULL){
		temp->elem = p;
		temp->next = *list;
		*list = temp;
	}
}
void insert_last_LL(PersonLinkedList *list, Person p){
	PersonLinkedList temp;
	PersonLinkedList trav;
	temp = (PersonLinkedList)malloc(sizeof(PersonNode));

	for(trav = *list; trav!=NULL && trav->next != NULL; trav = trav->next){}
	temp->elem = p;
	temp->next = NULL;
	trav->next = temp;
	*list = trav;
}
void insert_after_LL(PersonLinkedList *list, Person p, String name);
void delete_first_LL(PersonLinkedList *list){
	PersonLinkedList trav;
	trav=*list;
	*list = trav->next;
	free(trav);
	
}
void delete_last_LL(PersonLinkedList *list){
	PersonLinkedList trav;
	for(trav = *list; trav!=NULL && trav->next != NULL; trav = trav->next){}
	free(trav);
}
void delete_by_city_LL(PersonLinkedList *list, String city){
	PersonLinkedList trav;
	for(trav = *list; trav!=NULL && trav->next != NULL; trav = trav->next){}
}
 // all ocurrences
void display_LL(PersonLinkedList list){
	PersonLinkedList temp;
	for(temp = list; temp != NULL; temp = temp->next){
         printf("{%s | %c | %s}\n", list->elem.name, list->elem.sex, list->elem.city);
	}
}

/* Implement all VSpace conncept and Cusor Based List*/
void init_vspace(VSpace *vs);
Position alloc_space(VSpace *vs){
	Position avail = vs->avail;

    if(avail != -1) {
        vs->avail = vs->data[avail].next;
    }

    return avail;
}
void free_space(VSpace *vs, Position index) {
	Person dummy={"xxxxx",'x',"xxxxx"};
    if(index != -1 && index < MAX_VSPACE) {
        vs->data[index].elem = dummy;
        vs->data[index].next = vs->avail;
        vs->avail = index;
    }
}
void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
	int avail;
	avail=alloc_space(vs);
	vs->data[avail].elem=p;
	vs->data[avail].next=*list;
	*list=avail;
}
void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
	int x,avail,i;
	for(x=*list;x!=-1;x=vs->data[x].next){
	i=x;
	}
	avail=alloc_space(vs);
	vs->data[avail].elem=p;
	vs->data[avail].next=vs->data[i].next;
	vs->data[x].next=avail;
	
}
void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index);
void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list);
void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list);
void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex); // all ocurrences
void display_CBL(VSpace vs, PersonCusorBasedList list);
#endif
