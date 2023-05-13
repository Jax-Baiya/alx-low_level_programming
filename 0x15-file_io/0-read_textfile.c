#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t nrd, nwr;
char *buf;

/* Check if filename is null */
if (!filename)
return (0);

/* Open the file with Read-Only mode */
fd = open(filename, O_RDONLY);

/* Check if open() failed*/
if (fd == -1)
return (0);

/* Allocate memory for the buffer */
buf = malloc(sizeof(char) * (letters));
if (!buf)
return (0);

/* Read data from the file into the buffer */
nrd = read(fd, buf, letters);

/* Write the data from the buffer to standard output */
nwr = write(STDOUT_FILENO, buf, nrd);

/* Close the file descriptor and free the buffer */
close(fd);
free(buf);

/* Return the number of bytes written */
return (nwr);
}
