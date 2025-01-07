#include <stdio.h>
#include <omp.h>

void process(int i) {
    printf("Processing Element %d by thread %d\n", i, omp_get_thread_num());
}

int main() {
    int n = 10;

    #pragma omp parallel
    {
        #pragma omp single
        {
            for (int i = 0; i < n; i++) {
                #pragma omp task firstprivate(i)
                {
                    process(i);
                }
            }
        }
        #pragma omp taskwait 
    }

    return 0;
}
