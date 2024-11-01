#include <sys/stat.h>
#include <errno.h>
#undef errno
extern int errno;

void _exit(int exit_code)
{
    while (1)
    {
    };
}

int _close(int file)
{
    return -1;
}

char *__env[1] = {0};
char **environ = __env;

int execve(char *name, char **argv, char **env)
{
    errno = ENOMEM;
    return -1;
}

int fork(void)
{
    errno = EAGAIN;
    return -1;
}

int fstat(int file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

int getpid(void)
{
    return 1;
}

int isatty(int file)
{
    return 1;
}

int kill(int pid, int sig)
{
    errno = EINVAL;
    return -1;
}

int link(char *old, char *new)
{
    errno = EMLINK;
    return -1;
}

int _lseek(int file, int ptr, int dir)
{
    return 0;
}

int open(const char *name, int flags, int mode)
{
    return -1;
}

int _read(int file, char *ptr, int len)
{
    return 0;
}

char *_sbrk(int incr)
{

    register char *stack_ptr asm("sp");

    extern char __bss_end__;
    static char *heap_end;
    char *prev_heap_end;

    if (heap_end == 0)
    {
        heap_end = &__bss_end__;
    }
    prev_heap_end = heap_end;
    if (heap_end + incr > stack_ptr)
    {
        while (1)
        {
            // heap/stack collision
        }
    }
    heap_end += incr;
    return (char *)prev_heap_end;
}

int _stat(char *file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

int times(struct tms *buf)
{
    return -1;
}

int unlink(char *name)
{
    errno = ENOENT;
    return -1;
}

int wait(int *status)
{
    errno = ECHILD;
    return -1;
}

int _write(int file, char *ptr, int len)
{
    return 0;
}