#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* func_sqr(void* args)
{
    int value = *((int*)args);
    return (void*)(value * value);
}

int main()
{
    pthread_t thread;
    int val = 10;
    int res_thread = pthread_create(&thread, NULL, &func_sqr, &val);
    if (res_thread != 0)
    {
        printf("%s\n", "Error");
        return 1;
    }
    void* res_value;
    if (pthread_join(thread, &res_value) != 0)
    {
        printf("%s\n", "Join Error");
        return 1;
    }
    int ival = *((int*)&res_value);
    printf("Result = %d\n", ival);
    return 0;
}