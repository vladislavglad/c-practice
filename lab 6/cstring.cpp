namespace mystring {
    
    int strlen(const char *str) {
        int counter = 0;
        while (*str) {
            counter++;
            str++;
        }
        return counter;
    }

    char *strcpy(char *dest, const char *src) {
        char *start = dest;

        while (*src) {
            *dest = *src;
            dest++;
            src++;
        }

        *dest = '\0';
        return start;
    }

    char *strcat(char *dest, const char *src) {
        char *start = dest;

        // Approach to the trailing value.
        while(*dest)
            dest++;

        while(*src) {
            *dest = *src;
            dest++;
            src++;
        }

        *dest = '\0';
        return start;
    }

    char *strchr(char *str, int c) {
        while (*str) {
            if (*str == c)
                return str;
            str++;
        }

        return nullptr;
    }

    // Utility function.
    char *last_char(char *str) {
        return &str[strlen(str)-1];
    }

    char *strrchr(char *str, int c) {

        // Get pointer to the last character.
        char *endc = last_char(str);

        // Approach from the end to beginning.
        while (*endc != *(str-1)) {
            if (*endc == c)
                return endc;
            endc--;
        }

        return nullptr;
    }

    int strcmp(const char *str1, const char *str2) {

        while (*str1) {
            if (*str1 != *str2)
                break;

            str1++;
            str2++;
        }

        if (*str1 < *str2) 
            return -1;
        else if (*str1 > *str2)
            return 1;
        else 
            return 0;
            
    }
}
