#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */

int create_file(const char *filename, char *text_content) {
  int opening, writing, len = 0;

  if (filename == NULL)
    return (-1);

  if (text_content != NULL) {
    for (len = 0; text_content[len];)
      len++;
  }
  opening = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
  writing = write(opening, text_content, len);

  if (opening == -1 || writing == -1)
    return (-1);

  close(opening);

  return (1);
}
