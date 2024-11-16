#include <sys/stat.h>
#include <errno.h>
#include "vendor/stm32f7xx.h"
#include "usart.h"

#undef errno
extern int errno;
// https://sourceware.org/newlib/libc.html#Syscalls

//  exit program without cleaning up files
void _exit(int exit_code)
{
    while (1)
    {
    };
}

// close a file
int _close(int file)
{
    return -1;
}

// pointer to list of environment variables and their values
char *__env[1] = {0};
char **environ = __env;

// transfer control to a new process by setting up a stack and pushign argc, argv, and envp.
int execve(char *name, char **argv, char **env)
{
    errno = ENOMEM;
    return -1;
}

// create a new process
int fork(void)
{
    errno = EAGAIN;
    return -1;
}

// status of open file
int _fstat(int file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

// get process ID
int _getpid(void)
{
    return 1;
}

// query whether output is a terminal
int _isatty(int file)
{
    return 1;
}

// send signal
int _kill(int pid, int sig)
{
    errno = EINVAL; // error invalid argument
    return -1;
}

// create new name for existing file
int link(char *old, char *new)
{
    errno = EMLINK; // too many links
    return -1;
}

// set position in a file
int _lseek(int file, int ptr, int dir)
{
    return 0;
}

// open a file
int open(const char *name, int flags, int mode)
{
    return -1;
}

// read a file
int _read(int file, char *ptr, int len)
{
    return 0;
}

// increase heap space
caddr_t *_sbrk(int incr)
{

    register char *stack_ptr asm("sp");

    extern char __bss_end__;
    static char *heap_end;
    char *prev_heap_end;
    // if no heap has been initialized, start it at the end of .bss
    if (heap_end == 0)
    {
        heap_end = &__bss_end__;
    }
    prev_heap_end = heap_end;
    // if the heap is now where stack is, wait
    if (heap_end + incr > stack_ptr)
    {
        while (1)
        {
            // heap/stack collision
        }
    }
    //increase heap size
    heap_end += incr;
    return (caddr_t *)prev_heap_end;
}

// get file status
int _stat(char *file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

// timing information for current process
int times(struct tms *buf)
{
    return -1;
}

// remove a file's directory entry
int unlink(char *name)
{
    errno = ENOENT;
    return -1;
}

// wait for child process
int wait(int *status)
{
    errno = ECHILD;
    return -1;
}
extern void blink();
void usart_write(USART_TypeDef *usart, char c);

// write to a file (including stdout, where debug printf will go)
int _write(int file, char *ptr, int len)
{
    (void)file;

    for (uint32_t i = 0; i < len; i++)
    {
        usart_write(USART3, *ptr++);
    }

    return len;
}