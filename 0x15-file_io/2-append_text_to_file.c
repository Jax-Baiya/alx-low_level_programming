#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: filename.
 * @text_content: added content.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd;
int nletters;
int rwr;

/* Check if filename is not null */
if (!filename)
return (-1);

/*
 * Open the file in write mode,
 * and move the file pointer to the end of the file
 */
fd = open(filename, O_WRONLY | O_APPEND);

if (fd == -1)
return (-1);

/* If the text_content is not null */
if (text_content)
{
for (nletters = 0; text_content[nletters]; nletters++)
;

/* Write the text_content to the file */
rwr = write(fd, text_content, nletters);

if (rwr == -1)
return (-1);
}

/* Close the file */
close(fd);

/* Return 1 to indicate success */
return (1);
}
