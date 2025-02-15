// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
    int mode = 0;
    va_list args;
    va_start(args, flags);

    int res = syscall(__NR_open, filename, flags, mode);

    va_end(args);

    if (res < 0) {
        errno = -res;
        return -1;
    }

    return res;
}
