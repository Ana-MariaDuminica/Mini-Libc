#include <stdio.h>
#include <internal/syscall.h>
#include <errno.h>
#include <unistd.h>

int puts(const char* str) {
    /* TODO: Implement puts(). */
    const char* current = str;

    while (*current != '\0') {
        write(1, current, 1);
        current++;
    }

    char newline = '\n';
    write(1, &newline, 1);

    return 1;
}
