
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

long compute_sum() {
    long sum = 0;
    for (long i = 1; i <= 1000000; i++) sum += i;
    return sum;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <num_processes>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    for (int i = 0; i < N; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            long sum = compute_sum();
            printf("Child PID %d: Sum = %ld\n", getpid(), sum);
            exit(0);
        }
    }

    for (int i = 0; i < N; i++) wait(NULL);
    return 0;
}
