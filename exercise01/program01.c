#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signal_number) {
    // Write your code here.
}

int main() {
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);

	printf("%d\n", getpid());
	while (1);
}
