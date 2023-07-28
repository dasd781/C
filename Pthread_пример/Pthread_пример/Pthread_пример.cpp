#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* func_hello(void* args)
{
    printf("%s\n", "Hello, world!");
    sleep(3);
    return NULL;
}


int main()
{
    pthread_t thread;
    int result;
    result = pthread_create(&thread, NULL, &func_hello, NULL);
    if (result != 0)
    {
        printf("%s\n", "Error");
        return 1;
    }
    printf("%s\n", "Bye, world!");
    sleep(1);
    return 0;
}
// Под линуксовые оболочки