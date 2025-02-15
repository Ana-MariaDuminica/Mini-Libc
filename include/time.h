//source: https://pubs.opengroup.org/onlinepubs/7908799/xsh/time.h.html
#ifndef _TIME_H
#define _TIME_H

typedef long time_t;
typedef long clock_t;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

time_t time(time_t *t);
double difftime(time_t time1, time_t time0);
time_t mktime(struct tm *tm);
struct tm *localtime_r(const time_t *timep);
struct tm *gmtime_r(const time_t *timep);
char *asctime_r(const struct tm *tm);
char *ctime_r(const time_t *timep);

clock_t clock(void);
#define CLOCKS_PER_SEC ((clock_t)1000000)

int nanosleep(const struct timespec *req, struct timespec *rem);

#endif
