#include "shell.h"

void* _memmove(void* dest, const void* src, size_t n)
{
    char* d = dest;
    const char* s = src;
    size_t i;

    if (d > s) {
        /* Copy from the end to the beginning to handle overlapping regions. */
        for (i = n; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    } else if (d < s) {
        /* Copy from the beginning to the end to handle non-overlapping regions. */
        for (i = 0; i < n; i++) {
            d[i] = s[i];
        }
    }

    return dest;
}

void *_realloc(void *ptr, size_t size) {
    size_t i;
    size_t copy_size;
    void *new_ptr;

    if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    new_ptr = malloc(size);

    if (new_ptr != NULL) {
        copy_size = size;
        if (size > sizeof(size_t)) {
            copy_size = size - sizeof(size_t);
        }

        for (i = 0; i < copy_size; i++) {
            ((char *)new_ptr)[i] = ((char *)ptr)[i];
        }

        free(ptr);
    }

    return new_ptr;
}

void free_struct(str_cmd *command)
{
    int i = 0;
    
    while (command->arg[i])
    {
        if(command->arg[i] != NULL)
        {
        free(command->arg[i]);
        }
        i++;
    }
    if(command->arg != NULL)
    free(command->arg);
    if(command->input != NULL)
    free(command->input);
    if(command->executablePath != NULL)
    {
        free(command->executablePath);
    }
}

void *_memcpy(void *dest, const void *src, size_t n) {
    char *dest_ptr = (char *)dest;
    const char *src_ptr = (const char *)src;
    size_t i;

    for (i = 0; i < n; i++) {
        dest_ptr[i] = src_ptr[i];
    }

    return dest;
}
