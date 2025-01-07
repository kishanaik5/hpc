#include <stdio.h>
#include <omp.h>

int main(){
    int n= 16;
    #pragma omp parallel for schedule(static,4)
    for (int i=0;i<n;i++){
        printf("Thread %d working on the iteration %d\n",omp_get_thread_num(),i);
    }
    #pragma omp parallel for schedule(dynamic,4)
    for (int i=0;i<n;i++){
        printf("Thread %d working on the iteration %d\n",omp_get_thread_num(),i);
    }
    #pragma omp parallel for schedule(guided,4)
    for (int i=0;i<n;i++){
        printf("Thread %d working on the iteration %d\n",omp_get_thread_num(),i);
    }
    return 0;
}
