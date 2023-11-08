#include "shell.h"

char * _getline(FILE *stream) {

    size_t i;
    char * command;
    size_t remaining;
    static char input_buffer[BUFFER_SIZE];
    static size_t input_buffer_pos = 0;
    ssize_t bytes_read;

    if (stream == NULL) {
        return NULL; // Invalid input
    }

    while (1) {
        if (input_buffer_pos == 0) {
            bytes_read = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
            if (bytes_read < 0) {
                perror("read");
                exit(1);
            } else if (bytes_read == 0) {
                /* End of input */
                _printchar('\n');
               return NULL; 
            }
            input_buffer_pos = (size_t)bytes_read;
        }
        /* Search for a newline character in the buffer */
        for (i = 0; i < input_buffer_pos; i++) {
            if (input_buffer[i] == '\n') {
                /* Null-terminate the line */
                input_buffer[i] = '\0';
                /* Create a copy of the line */
                command = _strdup(input_buffer);
                /* Move the remaining data to the beginning of the buffer */
                remaining = input_buffer_pos - i - 1;
                _memmove(input_buffer, input_buffer + i + 1, remaining);
                input_buffer_pos = remaining;
                return (command);
            }
        }
        /* No newline found, move the remaining data to the beginning of the buffer */
        remaining = input_buffer_pos;
        _memmove(input_buffer, input_buffer + input_buffer_pos, remaining);
        input_buffer_pos = remaining;
    }
}

char** _getlines(size_t *line_count, int mode) {
    char **lines = NULL;
    char **new_lines;
    char *line = NULL;
    *line_count = 0;
    

    while (1) {
        line = _getline(stdin);

        if (line == NULL){
            line_count--;
            return lines;
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

