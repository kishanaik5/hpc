#include <stdio.h>
#include <mpi.h>
#define BUFFER_SIZE 32
int main(int argc, char *argv[]) {
    int rank, size;
    char message[BUFFER_SIZE] = "Hello India";
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Process %d: Sending message...\n", rank);
        for (int i = 1; i < size; i++) {
            MPI_Send(message, BUFFER_SIZE, MPI_CHAR, i, 0, MPI_COMM_WORLD);
        }
    } else {
        MPI_Recv(message, BUFFER_SIZE, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        printf("Process %d: Received message '%s' from process 0\n", rank, message);
    }
    MPI_Finalize();
    return 0;
}
