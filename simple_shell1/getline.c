#include "shell.h"

/* str_cmd _getline(void) {
    size_t i;
    str_cmd command;
    size_t remaining;
    static char input_buffer[BUFFER_SIZE];
    static size_t input_buffer_pos = 0;
    ssize_t bytes_read;

    while (1) {
        if (input_buffer_pos == 0) {
            bytes_read = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
            if (bytes_read < 0) {
                perror("read");
                exit(1);
            } else if (bytes_read == 0) {
                _printchar('\n');
                exit(0);
            }
            input_buffer_pos = (size_t)bytes_read;
        }
        for (i = 0; i < input_buffer_pos; i++) {
            if (input_buffer[i] == '\n') {
                input_buffer[i] = '\0';
                command.input = _strdup(input_buffer);
                remaining = input_buffer_pos - i - 1;
                _memmove(input_buffer, input_buffer + i + 1, remaining);
                input_buffer_pos = remaining;
                return (command);
            }
        }
        remaining = input_buffer_pos;
        _memmove(input_buffer, input_buffer + input_buffer_pos, remaining);
        input_buffer_pos = remaining;
    }
} */
