#include "shell.h"

int _isspace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

char* readLine(void) {
    char buffer[1024];
    ssize_t bytesRead;
    size_t totalSize = 0;
    char* input = NULL;
    char* newlinePos;

    while ((bytesRead = read(0, buffer, sizeof(buffer))) > 0) {
        char* temp = (char*)_realloc(input, totalSize + bytesRead + 1);
        if (temp == NULL) {
            perror("Memory allocation error");
            free(input);
            return NULL;
        }
        input = temp;
        _memcpy(input + totalSize, buffer, bytesRead);
        totalSize += bytesRead;
        input[totalSize] = '\0';

        newlinePos = _strchr(input, '\n');
        if (newlinePos != NULL) {
            newlinePos = "\0";  /* Replace newline with null terminator */ 
            break;
        }
    }

    return input;
}

char* readAll(void) {
    char buffer[BUFFER_SIZE];
    char* result = NULL;
    size_t totalSize = 0;
    ssize_t i = 0;
    ssize_t bytesRead;
    
    while ((bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        /*  Allocate memory for the result buffer */
        result = realloc(result, totalSize + bytesRead + 1); /* need to be a buildin */
        if (result == NULL) {
            exit(EXIT_FAILURE);
        }

        /*  Copy the current buffer to the result buffer */
        for (i = 0; i < bytesRead; ++i) {
            result[totalSize + i] = buffer[i];
        }
        
        /* // Update the total size */
        totalSize += bytesRead;
    }

    /* // Check for read errors */
    if (bytesRead == -1) {
        exit(EXIT_FAILURE);
    }

    /* // Null-terminate the result string */
    result[totalSize] = '\0';
    
    return result;
}

void finalizeLines(char** lines, size_t* lineCount, const char* input) {
    const char* start = input + _strlen(input) - 1;

    if (*start != '\n') {
        size_t length = _strlen(input);
        lines[*lineCount] = malloc((length + 1) * sizeof(char));
        if (lines[*lineCount] == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        strncpy(lines[*lineCount], start, length);
        lines[*lineCount][length] = '\0'; /* Null-terminate the last line */

        (*lineCount)++;
    }
}

char** splitLines(const char* input, size_t* lineCount) {
    size_t bufferSize = 1; /* Initial buffer size for storing pointers to lines */
    size_t count = 0; /* Number of lines found */
    const char* start = input;
    const char* end;

    char** lines = malloc(bufferSize * sizeof(char*));
    if (lines == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    
    while ((end = _strchr(start, '\n')) != NULL) 
    {
        size_t length = end - start;
        if (length == 0){
            start = end + 1;
            continue;
        }

        lines[count] = malloc((length + 1) * sizeof(char)); /* +1 for the null terminator */
        if (lines[count] == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        strncpy(lines[count], start, length);
        lines[count][length] = '\0'; /* Null-terminate the line */

        count++;

        if (count == bufferSize) {
            bufferSize++;
            lines = _realloc(lines, bufferSize * sizeof(char*));
            if (lines == NULL) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }
        }
        start = end + 1;
    }

    *lineCount = count;

    return lines;
}

char* trimSpaces(const char* input) {
    size_t length = _strlen(input);
    size_t endIndex=0;
    size_t trimmedLength=0;
    char* trimmedString;
    size_t startIndex = 0;
    while (startIndex < length && _isspace(input[startIndex])) {
        startIndex++;
    }

    /* // Find the end index of non-space character */
    endIndex = length - 1;
    while (endIndex > startIndex && _isspace(input[endIndex])) {
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
        _strncpy(trimmedString, input + startIndex, trimmedLength);
    }

    /* // Null-terminate the trimmed string */
    trimmedString[trimmedLength] = '\0';

    return trimmedString;
}

char** _getAll(size_t *lineCount)
{
    char* input, **lines;
    size_t i;
    char* timmedLine;

    input = readAll();
    lines = splitLines(input, lineCount);
    for ( i = 0; i < *lineCount; ++i) {
        timmedLine = lines[i];
        lines[i] = trimSpaces(timmedLine);
        free(timmedLine);
    }

    free(input);
    return(lines);
}


char** _getline(size_t *lineCount)
{
    char* input, **lines;
    size_t i;
    char* timmedLine;

    input = readLine();
    if (input == NULL)
        return NULL;

    lines = splitLines(input, lineCount);
    for ( i = 0; i < *lineCount; ++i) {
        timmedLine = lines[i];
        lines[i] = trimSpaces(timmedLine);
        free(timmedLine);
    }

    free(input);
    return(lines);
}

char* getCommand(const char* path) {
    /* // Find the last occurrence of the directory separator */
    const char* lastSeparator = _strrchr(path, '/');
    
    /* // If the separator is found, return the substring after it */
    if (lastSeparator != NULL) {
        return _strdup(lastSeparator + 1);
    } else {
        /* // If no separator is found, the whole path is the last part */
        return _strdup(path);
    }
}
