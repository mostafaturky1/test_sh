#include "shell.h"


char* readInput(int mode) {
    char buffer[BUFFER_SIZE];
    char* result = NULL;
    size_t totalSize = 0;
    ssize_t i = 0;

    ssize_t bytesRead;
    printf("read\n");
    while ((bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        printf("read\n");
        /*  Allocate memory for the result buffer */
        result = realloc(result, totalSize + bytesRead + 1);
        if (result == NULL) {
            exit(EXIT_FAILURE);
        }

        /*  Copy the current buffer to the result buffer */
        for (i = 0; i < bytesRead; ++i) {
            result[totalSize + i] = buffer[i];
        }
        
        /* // Update the total size */
        totalSize += bytesRead;

        if (mode == INTERACTIVE && buffer[i-1] == '\n') break;
    }

    /* // Check for read errors */
    if (bytesRead == -1) {
        exit(EXIT_FAILURE);
    }

    /* // Null-terminate the result string */
    result[totalSize] = '\0';
    
    return result;
}

char** splitLines(const char* input, size_t* lineCount) {
    size_t bufferSize = 1; /* // Initial buffer size for storing pointers to lines */
    size_t count = 0; /* // Number of lines found */
    const char* start = input;
    const char* end;


    char** lines = malloc(bufferSize * sizeof(char*));
    if (lines == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    
    while ((end = strchr(start, '\n')) != NULL || (end = strchr(start, '\0'))) {
        /* // Calculate the length of the line */
        size_t length = end - start;
        /* // Allocate memory for the line */
        lines[count] = malloc((length + 1) * sizeof(char));/*  // +1 for the null terminator */
        if (lines[count] == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        /* // Copy the line to the allocated memory */
        strncpy(lines[count], start, length);
        lines[count][length] = '\0'; /* // Null-terminate the line */

        count++;

        /* // Resize the buffer if needed */
        if (count == bufferSize) {
            bufferSize++;
            lines = realloc(lines, bufferSize * sizeof(char*));
            if (lines == NULL) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }
        }

        /* // Move to the next line */
        start = end + 1;
    }

    /* // Check for the last line (no newline at the end) */
    if (start < input + strlen(input)) {
        size_t length = input + strlen(input) - start;

        /* // Allocate memory for the last line */
        lines[count] = malloc((length + 1) * sizeof(char));
        if (lines[count] == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        /* // Copy the last line to the allocated memory */
        strncpy(lines[count], start, length);
        lines[count][length] = '\0'; /* // Null-terminate the last line */

        count++;
    }

    /* // Set the final line count */
    *lineCount = count;

    return lines;
}


char* trimSpaces(const char* input) {
    size_t length = strlen(input);
    size_t endIndex=0;
    size_t trimmedLength=0;
    char* trimmedString;

    /* // Find the start index of non-space character */
    size_t startIndex = 0;
    while (startIndex < length && isspace(input[startIndex])) {
        startIndex++;
    }

    /* // Find the end index of non-space character */
    endIndex = length - 1;
    while (endIndex > startIndex && isspace(input[endIndex])) {
        endIndex--;
    }

    /* // Calculate the size of the trimmed string */
    trimmedLength = (startIndex <= endIndex) ? (endIndex - startIndex + 1) : 0;

    /* // Allocate memory for the trimmed string */
    trimmedString = malloc(trimmedLength + 1); /* // +1 for the null terminator */
    if (trimmedString == NULL) {
        perror("Memory allocation error");
        return trimmedString;
    }

    /* // Copy the trimmed part to the new string */
    if (trimmedLength > 0) {
        strncpy(trimmedString, input + startIndex, trimmedLength);
    }

    /* // Null-terminate the trimmed string */
    trimmedString[trimmedLength] = '\0';

    return trimmedString;
}

char** _getlines(size_t *lineCount, int mode)
{
    char* input, **lines;
    size_t i;
    char* timmedLine;

    input = readInput(mode);
    printf("input: %s\n", input);
    lines = splitLines(input, lineCount);
    printf("line count: %lu\n", *lineCount); 
    for ( i = 0; i < *lineCount; ++i) {
        timmedLine = lines[i];
        lines[i] = trimSpaces(timmedLine);
        printf("lines[%lu] = %s\n", i, lines[i]);
        free(timmedLine);
    }

    free(input);
    return(lines);
}
