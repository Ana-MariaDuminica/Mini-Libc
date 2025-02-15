#include <unistd.h>
#include <time.h>

//https://copyprogramming.com/howto/use-the-nanosleep-function-in-c?utm_content=cmp-true

unsigned int sleep(unsigned int seconds) {
    /*TO DO: implement sleep function*/
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;

    if (nanosleep(&req, &rem) == -1) {
        return rem.tv_sec;
    }

    return 0;
}
