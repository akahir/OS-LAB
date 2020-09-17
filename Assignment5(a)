#include <stdio.h> 
#include <stdlib.h>    
#include <pthread.h>
#include <limits.h>

struct fib{
    int n;
    int arr[100000];
};

void* myThread(void *a){
	
	printf("Calculation in thread\n");
	 struct fib *obj = ((struct fib *) a);

	
	if(obj->n==1)
	{
	    obj->arr[0]=0;
	}
	if(obj->n==2)
	{
	    obj->arr[0]=0;
	    obj->arr[1]=1;
	}
	else{
	   obj->arr[0]=0;
	   obj->arr[1]=1;  
	   int i;
	for ( i=2; i<obj->n; i++){
		obj->arr[i]=obj->arr[i-1]+obj->arr[i-2];
	  }
	}
}


int main()
{
    struct fib obj;
    scanf("%d" , &obj.n);
    pthread_t thread;
    printf("Before thread\n");
    pthread_create(&thread, NULL, myThread, &obj);
    pthread_join(thread, NULL); 
    printf("After thread\n");
    for(int i =0;i<obj.n;i++)
    {
        printf("%d ", obj.arr[i]);
    }
    printf("\n");
    return 0;
}
