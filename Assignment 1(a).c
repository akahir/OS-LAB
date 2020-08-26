//Multithreaded program that generates the Fibonacci series.

#include <stdio.h>
#include<unistd.h>
#include <pthread.h>
#include <stdlib.h>
pthread_t tid;
pthread_t tid2;
int fibo[1000];
int top=-1;
void *printFibo(void *vargp){
  pthread_join(tid2,NULL);
  sleep(1);
  for(int i=0;i<=*(int*)vargp;i++)
{
    printf("%d",fibo[i]);
    printf(" ");
  }
}
void *calcFibo(void *vargp){
    int t1 = 0, t2 = 1, nextTerm = 0;
    fibo[0]=t1;
    fibo[1]=t2;
    top=1;
    int i=0;


    while(i <= *(int *)vargp)
    {
        nextTerm = t1 + t2;
        top++;
        fibo[top]=nextTerm;
        t1 = t2;
        t2 = nextTerm;
        i++;
    }
}
int main()
{
    int n;
    printf("Enter the number for which you generate fibo series");

    scanf("%d",&n);
    pthread_create(&tid,NULL,printFibo,(void*)&n);
    pthread_create(&tid2, NULL, calcFibo, (void*)&n);

    pthread_join(tid, NULL);
    exit(0);
}
