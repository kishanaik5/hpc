#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        #pragma omp single
	        { for(int i =0;i<5;i++){
            #pragma omp task
            {
                printf("Task %d executed by thread %d\n", i, omp_get_thread_num());
	    }}}}

    return 0;
}
