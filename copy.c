#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUF_SIZE
#define BUF_SIZE 5*1024 
#endif
#ifndef ERRORS_H
#include "errors.h"
#endif

void main(int argc, char **argv)
{
    int first_file, second_file, openflags;
    mode_t file_perms;
    size_t num_read;
    char buf[BUF_SIZE];

    openflags = O_CREAT | O_WRONLY | O_TRUNC;
    file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    if ((first_file = open(argv[1], O_RDONLY)) == -1)
        err_exit("open source");
    if ((second_file = open(argv[2], openflags, file_perms)) == -1)
        err_exit("open target");
    while ((num_read = read(first_file, buf, BUF_SIZE)) > 0)
    {
        if (write(second_file, buf, num_read) == -1)
            err_exit("write");
    }
    if (num_read == -1)
        err_exit("read");

    close(first_file);
    close(second_file);
}
