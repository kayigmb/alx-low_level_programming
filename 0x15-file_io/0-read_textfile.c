#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters) {
  ssize_t opening, reading, writing;
  char *buffer;

  if (filename == NULL)
    return (0);

  buffer = malloc(sizeof(char) * letters);
  if (buffer == NULL)
    return (0);

  opening = open(filename, O_RDONLY);
  reading = read(opening, buffer, letters);
  writing = write(STDOUT_FILENO, buffer, reading);

  if (opening == -1 || reading == -1 || writing == -1 || writing != reading) {
    free(buffer);
    return (0);
  }

  free(buffer);
  close(opening);

  return (writing);
};
