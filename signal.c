#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// base function that gets called when SIGALRM is  triggered
// void handler(int signum) {
//     printf("Hello World!\n");
//     exit(1);  // Exit after printing
// }

// int main(int argc, char *argv[]) {
//     signal(SIGALRM, handler);  // Register handler to handle SIGALRM
//     alarm(5);  // Schedule a SIGALRM for 5 seconds
//     while (1);  // Busy wait for the signal to be delivered
//     return 0;
// }


//Modify to Print "Turing was right!" After Signal:
// int signal_received = 0;  // Global variable to track signal

// void handler(int signum) {
//     printf("Hello World!\n");
//     signal_received = 1;  // Mark that signal was received
// }

// int main(int argc, char *argv[]) {
//     signal(SIGALRM, handler);  // Register handler for SIGALRM
//     alarm(5);  // Schedule SIGALRM for 5 seconds

//     while (!signal_received);  // Busy wait until signal is received
//     printf("Turing was right!\n");

//     return 0;
// }


// (ii) Modify to Print Periodically:
void handler(int signum) {
    printf("Hello World!\n");
    alarm(5);  // Reset the alarm for another 5 seconds
}

int main(int argc, char *argv[]) {
    signal(SIGALRM, handler);  // Register handler for SIGALRM
    alarm(5);  // Schedule SIGALRM for 5 seconds

    while (1) {
        printf("Turing was right!\n");
        sleep(5);  // Sleep to avoid busy waiting
    }

    return 0;
}


