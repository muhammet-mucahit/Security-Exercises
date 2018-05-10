#include <stdio.h>
#include <unistd.h>

int vuln() {
    char buf[400];
    int r;
    register int i asm("rsp");
    register int j asm("rbp");
    printf("Welcome to the Proj 13 Server!\n\n");
    printf("$rsp = %#018x", i);
    printf("$rbp = %#018x\n\nEnter some text:\n", j);
    r = read(0, buf, 800);
    printf("You said: %s\n", buf);
    return 0;
}

int main(int argc, char *argv[]) {
    vuln();
    printf("Bye!\n");
    return 0;
}
