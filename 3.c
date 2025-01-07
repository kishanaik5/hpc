#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main() {
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("Section 1 starting, thread %d\n", omp_get_thread_num());
            for (int i = 0; i < 3; i++) {
                sleep(1);
                printf("Section 1: Iteration %d, Thread %d\n", i, omp_get_thread_num());
            }
            printf("Section 1 finished, thread %d\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            printf("Section 2 starting, thread %d\n", omp_get_thread_num());
            for (int j = 0; j < 2; j++) {
                sleep(1); // Simulate some work
                printf("Section 2: Iteration %d, Thread %d\n", j, omp_get_thread_num());
            }
            printf("Section 2 finished, thread %d\n", omp_get_thread_num());
        }
    }

    printf("Outside parallel region.\n");

    return 0;
}
