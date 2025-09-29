#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t flag = 0;

void handler(int signum) {
    printf("Hello World!\n");
    flag = 1;
    alarm(5); // schedule next alarm
}

int main() {
    signal(SIGALRM, handler);
    alarm(5);

    while (1) {
        if (flag) {
            printf("Turing was right!\n");
            flag = 0;     // reset flag
        }
        pause();          // sleep until next signal
    }

    return 0;
}
