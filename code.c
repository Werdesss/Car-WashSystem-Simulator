#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "head.h"
int i=1;


void car_to_wash_simulator(Node** q1,Node** q2){
	int priority,vip,car=rand()%2;							// new car or not
	if (car==1){
		vip=rand()%2;										// has a membership or not 
		if ((*q1)->size>(*q2)->size){
			if (vip==1){
				priority=rand()%30;
				push(q2,i,priority);
			}
			else 
				push(q2,i,0);
		}
		else if ((*q1)->size<(*q2)->size){
			if (vip==1){
				priority=rand()%30;
				push(q1,i,priority);
			}
			else 
				push(q1,i,0);
		} 
		else{
			if (vip==1){
				priority=rand()%30;
				push(q1,i,priority);
			}
			else 
				push(q1,i,0);
			}
		}
		i++;
}

void run_simulator(int hour,int max_time,Node** q1,Node** q2){
	hour*=60;
	while (hour>0){
		car_to_wash_simulator(q1,q2);
		//process_car_wash();
		//start_washing_next_car();
		hour--;
	}
}






int main(){
    int hour,max_time,number_wm;
    printf("The length time in hours for simulation:");
    scanf("%d",&hour);
    printf("The maximum time it takes for a washing machine to wash a car(minutes):");
    scanf("%d",&max_time);
    printf("The number of washing machines(min 2):");
    scanf("%d",&number_wm);
    while(number_wm<2){ 											// it will be 2 anyway for my code(both are priority queues)
		printf("The number of washing machines(min 2):");
        scanf("%d",&number_wm);
    }
    srand(time(NULL));
	Node* q1=newNode(0,0);		
    Node* q2=newNode(0,0);
    run_simulator(hour,max_time,&q1,&q2);
    
    return 0;
}

