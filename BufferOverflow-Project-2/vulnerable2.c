#include <stdio.h>
#include <string.h>

void func() {
    char buf[100];
    gets(buf);
    printf("You entered: %s\n", buf);
}

int main(int argc, char *argv[]) {
    func();
    return 0;
}