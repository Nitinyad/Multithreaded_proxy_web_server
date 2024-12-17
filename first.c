#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <unistd.h>
void* myturn(void *arg){
    for(int i = 0; i < 6; i ++){
        sleep(1);
        printf("my turn , %d" , i);
    }
    return NULL;
}

void yourturn(){
    while(1){
        printf("your turn ");
        sleep(2);
    }
}

int main(){
    pthread_t newthread;

    pthread_create(&newthread , NULL , myturn , NULL);
    yourturn();
    pthread_join(newthread , NULL);
    return 0;
}