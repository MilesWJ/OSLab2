#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile sig_atomic_t seconds = 0;

void alarm_handler(int signum) {
    seconds++;
    printf("Tick... %d seconds elapsed\n", seconds);
    alarm(1);  // schedule next tick
}

void sigint_handler(int signum) {
    printf("\nProgram terminated after %d seconds.\n", seconds);
    exit(0);
}

int main() {
    signal(SIGALRM, alarm_handler);
    signal(SIGINT,  sigint_handler); // handle Ctrl-C

    alarm(1); // start ticking every second

    while (1) {
        pause(); // sleep until signal arrives
    }

    return 0;
}
