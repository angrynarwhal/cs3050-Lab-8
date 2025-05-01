
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* compute_sum(void* arg) {
    long sum = 0;
    for (long i = 1; i <= 1000000; i++) sum += i;
    printf("Thread %ld: Sum = %ld\n", pthread_self(), sum);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <num_threads>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    pthread_t threads[N];

    for (int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, compute_sum, NULL);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
