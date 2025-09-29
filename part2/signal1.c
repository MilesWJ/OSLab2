#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t flag = 0; // communicate between handler and main

void handler(int signum) {
    printf("Hello World!\n");
    flag = 1; // set flag instead of exiting
}

int main() {
    signal(SIGALRM, handler);
    alarm(5);

    while (!flag);  // wait until handler sets flag

    printf("Turing was right!\n");
    return 0;
}
