#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 500
//creating record of students
struct student {
char name[50];
int regno;
};
//creating queue structure for shuttle
struct shuttle{
struct student queue[max];
int front;
int rear;
int size;
};
//globally calling shuttle as s
struct shuttle s;
//initializing queue
void init(){
s.front=0;
s.rear=-1;
s.size=0;
}
int isfull(){
return s.size==max;
}
int isempty(){
return s.size==0;
}
//function to add students to end of the shuttle queue(enqueue)
void join(){
if(isfull()){
printf("Waiting area is full.Wait for the next batch.\n");
return;
}
struct student st;
printf("Enter student name:");
scanf("%s",st.name);
printf("Enter registration number:");
scanf("%d",&st.regno);
s.rear=(s.rear+1)%max;
s.queue[s.rear]=st;
s.size++;
printf("%s has joined the queue.\n",st.name);
}
//allows students to board the bus from the front (dequeue) 
void board(){
if(isempty()){
printf("No students in queue. Bus is empty.\n");
return;
}
int seats,bcount=0;
printf("How many empty seats are available on the bus:\n");
scanf("%d",&seats);
printf("\nBOARDING PROCESS\n");
//continues boarding until seats are filled ie queue is empty 
while(!isempty() && bcount<seats){
printf("Passenger: %s %d",s.queue[s.front].name,s.queue[s.front].regno);
s.front=(s.front+1)%max;
s.size--;
bcount++;
}
printf("%d students boarded.\n",bcount);
if(!isempty()){
printf("There are still %d students waiting in queue.\n",s.size);
}
}
//function to display the students in queue 
void display(){
int current;
if(isempty()){
printf("Waiting area is empty.\n");
return;
}
current=s.front;
printf("Current queue: %d \n",s.size);
for(int i=0;i<s.size;i++){
printf("%d %s %d \n",i+1,s.queue[current].name,s.queue[current].regno);
current=(current+1)%max;
}
}
int main(){
init();
int choice;
while(1){
printf("\nCAMPUS SHUTTLE SYSTEM\n");
printf("1.) Join Queue\n");
printf("2.) Board Bus\n");
printf("3.) Display Queue\n");
printf("4.) Exit\n");
printf("Enter your choice:");
scanf("%d", &choice);
switch(choice){
case 1:
join();
break;
case 2:
board();
break;
case 3:
display();
break;
case 4:
printf("Exiting system.\n");
return 0;
break;
default:
printf("Invalid choice. Select choice 1 to 4.\n");}}}
