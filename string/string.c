// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
//source: https://www.scaler.com/topics/string-h-in-c/

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *ptr;
	for (ptr = destination; *source != '\0'; source++, ptr++) {
		*ptr = *source;
	}
	*ptr = *source;
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *ptr = destination;
	while (*source && len > 0) {
		*ptr = *source;
		ptr++;
		source++;
		len--;
	}
	while (len > 0) {
		*ptr = '\0';
		ptr++;
		len--;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *ptr = destination;
	while (*ptr != '\0') {
		ptr++;
	}
	while (*source != '\0') {
		*ptr++ = *source++;
	}
	*ptr = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *ptr = destination;
	while (*ptr != '\0') {
		ptr++;
	}
	for (size_t i = 0; i < len; i++) {
		*ptr++ = *source++;
	}
	*ptr = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    if (*str1 == *str2) {
        return 0;
    } else if (*str1 > *str2) {
        return 1;
    }
	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	while (*str1 == *str2 && len > 1) {
        str1++;
        str2++;
		len--;
    }
	if (*str1 == *str2) {
		return 0;
	} else if (*str1 > *str2) {
		return 1;
	}
	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *last_occur = NULL;
	while (*str != '\0') {
		if (*str == (char)c) {
			last_occur = str;
		}
		str++;
	}
	if (last_occur != NULL) {
		return (char *)last_occur;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (*needle == '\0') {
        return (char *)haystack;
    }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack;
        }

        haystack++;
    }
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if (*needle == '\0') {
        return (char *)(haystack + strlen(haystack));
    }

    const char *last = NULL;
    const char *found;

    while ((found = strstr(haystack, needle)) != NULL) {
        last = found;
        haystack = found + 1;
	}

    if (last != NULL) {
        return (char *)last;
    }
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *src = (char *)source;
	char *dest = (char *)destination;

	for (size_t i = 0; i < num; i++)
    	dest[i] = src[i];

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dst = (char *)destination;
    const char *src = (const char *)source;

    if (dst == src || num == 0) {
        return destination;
    }

    if (dst < src) {
        while (num--) {
            *dst++ = *src++;
        }
    } else {
        dst += num;
        src += num;
        while (num--) {
            *(--dst) = *(--src);
        }
    }
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *byte_ptr1 = (const unsigned char *)ptr1;
    const unsigned char *byte_ptr2 = (const unsigned char *)ptr2;

    for (size_t i = 0; i < num; i++) {
        if (byte_ptr1[i] == byte_ptr2[i]) {
            return 0;
        } else if (byte_ptr1[i] > byte_ptr2[i]) {
            return 1;
        }
    }

	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *byte_ptr = (unsigned char *)source;
    unsigned char byte_value = (unsigned char)value;

    for (size_t i = 0; i < num; i++) {
        byte_ptr[i] = byte_value;
    }
	return source;
}
