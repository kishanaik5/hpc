1. OpenMp parallel programs on using #pragma directive using work sharing constructs in C

2. OpenMp programs using sections like omp for and omp single.

3. OpenMp programs on parallel constructs.

4. OpenMp programs on task construct.

5. OpenMp programs using thread private directives.

6. OpenMp programs on threads scheduling.

7. Programs for Point to Point MPI calls.

8. CUDA programs on broadcasting

OpenMP 
Compile : gcc -fopenmp filename.c
Exec : ./a.out

Cuda 
Compile : nvcc filename.c
Exec : ./a.out

MPI Programs
Compile : mpicc filename.c
Exec : mpirun ./a.out
