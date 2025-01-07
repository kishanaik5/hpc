#include <stdio.h>
#include <omp.h>

#define N 1000

int main() {
    int i, num_threads;
    double a[N], b[N], sum[N];
    #pragma omp parallel shared(a, b, sum, num_threads) private(i)
    {
        #pragma omp single
        {
            num_threads = omp_get_num_threads();
            printf("Number of threads: %d\n", num_threads);
        }

        #pragma omp for
        for (i = 0; i < N; i++) {
            a[i] = i * 2.0;
            b[i] = i * 3.0;
        }

        #pragma omp for
        for (i = 0; i < N; i++) {
            sum[i] = a[i] + b[i];
        }
    }

    printf("First few sums:\n");
    for (i = 0; i < 5; i++) {
        printf("sum[%d] = %f\n", i, sum[i]);
    }

    return 0;
}
