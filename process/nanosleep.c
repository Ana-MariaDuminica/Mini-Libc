#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    /*TO DO: implement nanosleep function*/
    int result = syscall(__NR_nanosleep, req, rem);

    if (result == -1) {
        return -1;
    }
    return 0;
}
