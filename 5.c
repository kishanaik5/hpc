#include <stdio.h>
#include <omp.h>

int counter = 0;

#pragma omp threadprivate(counter)

int main() {
    #pragma omp parallel
    {
        counter++;
        printf("Thread %d counter = %d \n",omp_get_thread_num(),counter);
    }
    return 0;
}
