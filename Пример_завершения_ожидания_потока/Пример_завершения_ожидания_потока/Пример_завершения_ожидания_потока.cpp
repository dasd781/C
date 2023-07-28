#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void* print_b(void* args)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%c", 'b');
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t thread;
    int result;
    result = pthread_create(&thread, NULL, &print_b, NULL);
    if (result != 0)
    {
        printf("%s\n", "Error");
        return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%c", 'a');
        sleep(1);
    }
    if (pthread_join(thread, NULL) != 0)
    {
        printf("%s\n", "Join Error");
        return 1;
    }
    printf("%c", 'd');
    return 0;
}