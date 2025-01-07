#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(int argc, char *argv[]) {
    int nthreads, i, id;
    int a[N], b[N], c[N];
    for (i = 0; i < N; i++) {
        a[i] = b[i] = i * 1.0;
    }

    #pragma omp parallel shared(a, b, c) private(id, i)
    {
        id = omp_get_thread_num();
        if (id == 0) {
            nthreads = omp_get_num_threads();
            printf("Total threads are %d\n", nthreads);
        }
        printf("Thread %d started\n", id);

        #pragma omp for
        for (i = 0; i < N; i++) {
            c[i] = a[i] + b[i];
            printf("Thread %d: c[%d] = %d\n", id, i, c[i]);
        }
    }
    return 0;
}
