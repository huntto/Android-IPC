#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "123";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    memset(buffer, '\0', sizeof(buffer));
    
    if (pipe(file_pipes) == 0)
    {
        fork_result = fork();
        if (fork_result == -1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }
        if (fork_result == 0) {
            /* read */
            data_processed = read(file_pipes[0], buffer, BUFSIZ);
            printf("Child read %d bytes: %s\n", data_processed, buffer);

            /* write */
            buffer[0] = '0';
            data_processed = write(file_pipes[1], buffer, data_processed);
            printf("Child wrote %d bytes\n", data_processed);

            exit(EXIT_SUCCESS);
        } else {
            /* write */
            data_processed = write(file_pipes[1], some_data, strlen(some_data));
            printf("Parent wrote %d bytes\n", data_processed);

            /* read */
            data_processed = read(file_pipes[0], buffer, BUFSIZ);
            printf("Parent read %d bytes: %s\n", data_processed, buffer);

        }
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_SUCCESS);   
}