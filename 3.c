#include <omp.h>
#include <stdio.h>

int main(){
    #pragma omp parallel
{
    int thread_id = omp_get_thread_num();
    printf("hello from the thread %d", thread_id);
}return 0;
}
