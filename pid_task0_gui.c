#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("The process ID is: %d\n", pid);
    printf("The parent process ID is: %d\n", ppid);

    return 0;
}
