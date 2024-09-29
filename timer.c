#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

time_t start_time;  // Track the start time

void alarm_handler(int signum) {
    printf("Hello World!\n");
    alarm(5);  // Reset the alarm for another 5 seconds
}

void sigint_handler(int signum) {
    time_t end_time = time(NULL);
    printf("\nProgram ran for %ld seconds.\n", end_time - start_time);
    exit(0);  // Exit after printing the runtime
}

int main(int argc, char *argv[]) {
    start_time = time(NULL);  // Get the current time

    signal(SIGALRM, alarm_handler);  // Handle SIGALRM
    signal(SIGINT, sigint_handler);  // Handle SIGINT (Ctrl + C)
    
    alarm(5);  // Schedule SIGALRM for 5 seconds

    while (1) {
        printf("Turing was right!\n");
        sleep(5);  // Sleep to avoid busy waiting
    }

    return 0;
}

