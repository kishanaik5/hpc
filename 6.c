#include <stdio.h>
#include <omp.h>

void demonstrate_schedule(const char *schedule_type, omp_sched_t policy, int chunk_size) {
    printf("\nSchedule Type: %s (Chunk Size: %d)\n", schedule_type, chunk_size);
    omp_set_schedule(policy, chunk_size);

    #pragma omp parallel for schedule(runtime) num_threads(4)
    for (int i = 0; i < 16; i++) {
        printf("Iteration %d executed by thread %d\n", i, omp_get_thread_num());
    }
}

int main() {
    printf("Demonstrating Different OpenMP Scheduling Policies\n");

    // Demonstrating Dynamic Scheduling
    demonstrate_schedule("Dynamic", omp_sched_dynamic, 2);

    // Demonstrating Guided Scheduling
    demonstrate_schedule("Guided", omp_sched_guided, 2);

    // Demonstrating Auto Scheduling
    demonstrate_schedule("Auto", omp_sched_auto, 0);

    // Demonstrating Static Scheduling (for comparison)
    demonstrate_schedule("Static", omp_sched_static, 4);

    return 0;
}
