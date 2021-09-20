#include <stdio.h>
#include <string.h>
#include "Exercise1.h"

int main(void) 
{
    // To do code logic here.
    int x;
    PersonLinkedList p;
    CircularArrayQueue q;
    PersonDynamicArrayList DL;
    q=create_array_queue();
    init_array_queue(&q);
    x=get_queue_length(q);

    Person p1 = createPerson("Mark", 'M', "Cebu");
    Person p2 = createPerson("John", 'M', "Palawan");
    Person p3 = createPerson("Mary", 'F', "Bohol");
    Person p4 = createPerson("Alex", 'F', "Manila");
    
    enqueue(&q,p1);
    enqueue(&q,p2);
    enqueue(&q,p3);
    enqueue(&q,p4);
    displayqueue(q);
    x=get_queue_length(q);
    printf("\n%d\n",x);
    
//    p=get_all_females(q);
//    display_LL(p);
    DL=remove_all_males(&q);
//    display_DAL(DL);
    return 0;
}
