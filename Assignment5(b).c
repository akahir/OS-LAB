#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int a= 0; //global
void *myThreadFun(void *vargp)
{
    int *tid = (int *)vargp;
    static int b = 0; //static
    int c=0; //local
    ++b;
    ++a;
    ++c;
    printf("Thread ID: %d,Values of Static: %d, Global: %d, Local: %d\n", *tid, ++b, ++a,++c);
}

int main()
{
    pthread_t id;
    for (int i = 0; i < 3; i++)
        pthread_create(&id, NULL, myThreadFun, (void *)&id);

    pthread_exit(NULL);
    return 0;
}
