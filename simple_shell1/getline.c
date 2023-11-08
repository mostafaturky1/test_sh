#include "shell.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream) {

    char *new_ptr;
    size_t capacity = *n;
    size_t i = 0;
    int c;

    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1; // Invalid input
    }

    if (*lineptr == NULL) {
        *n = 0;  // Set the initial buffer size to zero
    }

    while (1) {
        if (i + 1 >= capacity) {
            capacity = (capacity == 0) ? 128 : capacity * 2; // Double the capacity or start with 128 if it's the first allocation
            new_ptr = (char *)realloc(*lineptr, capacity);
            if (new_ptr == NULL) {
                return -1; // Memory allocation error
            }
            *lineptr = new_ptr;
            *n = capacity;
        }

        c = fgetc(stream);
        if (c == EOF) {
            break;
        }

        (*lineptr)[i++] = (char)c;

        if (c == '\n') {
            break;
        }
    }

    if (i == 0 && c == EOF) {
        return -1; // No data read, EOF reached
    }

    (*lineptr)[i] = '\0';
    return i;
}

char** _getlines(FILE *stream, size_t *line_count, int mode) {
    char **lines = NULL;
    char **new_lines;
    char *line = NULL;
    size_t len = 0;
    ssize_t bytes_read;
    *line_count = 0;
    

    while (1) {
        bytes_read = getline(&line, &len, stream);
       

        if (bytes_read == -1) {
            break;
        }

        // Allocate memory for the new line and copy it into the array
        new_lines = (char **)realloc(lines, (*line_count + 1) * sizeof(char *));
        if (new_lines == NULL) {
            printf("Memory allocation error.\n");
            break;
        }
        lines = new_lines;

        lines[*line_count] = strdup(line);

        (*line_count)++;

        if (mode == INTERACTIVE) break;

    }

    free(line);
    return lines;
}
