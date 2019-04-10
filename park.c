#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include<unistd.h>  
#include<sys/types.h>
#include<sys/stat.h>
//srand(time(0));
int num=0,c=0;
int x=0,y=0;
pthread_mutex_t lock;
/////////////////////////////////////////////////////////////////avas/////////////////////////////////////////////////////////

void Input()
{
printf("Enter no of passengers\n");
scanf("%d",&num);
}

/////////////////////////////////////////////////////////////////avas/////////////////////////////////////////////////////////

void leave(int xx)
{

y++;

if(y<num)
{
printf("passenger %d is left\n",y);
printf("%d car is free\n",xx);
}
}


/////////////////////////////////////////////////////////////////avas/////////////////////////////////////////////////////////
void ride(int y)
{
c++;
if(x<num)
{
x++;
printf("\npassenger %d is riding in %d car\n",x,y);
}
else if(c>num)
{
printf("%d car is waiting\n",y);
}
}
/////////////////////////////////////////////////////////////////avas/////////////////////////////////////////////////////////

void *Passenger1()
{
//printf("Passenger %d is riding in %d car",(p,c));
pthread_mutex_lock(&lock);
ride(1);
leave(1);
pthread_mutex_unlock(&lock);
}
/////////////////////////////////////////////////////////////////avas/////////////////////////////////////////////////////////

void *Passenger2()
{
//printf("Passenger %d is riding in %d car",(p,c));
pthread_mutex_lock(&lock);
sleep(2);
ride(2);
leave(2);
pthread_mutex_unlock(&lock);

}

/////////////////////////////////////////////////////////////////avas/////////////////////////////////////////////////////////

void *Passenger3()
{
//printf("Passenger %d is riding in %d car",(p,c));
pthread_mutex_lock(&lock);
sleep(3);
ride(3);
leave(3);
pthread_mutex_unlock(&lock);
}

/////////////////////////////////////////////////////////////////avas/////////////////////////////////////////////////////////

int main()
{
int xx;
Input();
pthread_t a,b,c;
pthread_mutex_init(&lock,NULL);
void *z;
for(int i=0;i<num;i++)
{
pthread_create(&a,NULL,Passenger1,NULL);
pthread_create(&b,NULL,Passenger2,NULL);
pthread_create(&c,NULL,Passenger3,NULL);
pthread_join(a,NULL);
pthread_join(b,NULL);
pthread_join(c,NULL);
}

}
