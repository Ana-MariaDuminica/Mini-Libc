// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

//https://man7.org/linux/man-pages/man3/malloc.3.html

void *malloc(size_t size)
{
	// /* TODO: Implement malloc(). */

    void *allocated_memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (mem_list_add(allocated_memory, size) != 0) {
        munmap(allocated_memory, size);
        return NULL;
    }

    return allocated_memory;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */

    size_t total_size = nmemb * size;

    void *allocated_memory = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    memset(allocated_memory, 0, total_size);

    if (mem_list_add(allocated_memory, total_size) != 0) {
        munmap(allocated_memory, total_size);
        return NULL;
    }

    return allocated_memory;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
        return;
    }

    struct mem_list *block = mem_list_find(ptr);

    munmap(ptr, block->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	// /* TODO: Implement realloc(). */
	if (size == 0) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL) {
        return malloc(size);
    }

    struct mem_list *region = mem_list_find(ptr);

    if (size > region->len) {
        void *new_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

        if (new_ptr == MAP_FAILED) {
            return NULL;
    	}

        memcpy(new_ptr, ptr, MIN(size, region->len));

        free(ptr);
        return new_ptr;
    } else {
        return ptr;
	}
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t new_size = nmemb * size;
    if (nmemb != 0 && new_size / nmemb != size) {
        return NULL;
    }

    if (ptr == NULL) {
        return malloc(new_size);
    }

    struct mem_list *region = mem_list_find(ptr);

    if (new_size > region->len) {
        void *new_ptr = mmap(NULL, new_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        memcpy(new_ptr, ptr, MIN(new_size, region->len));

        free(ptr);
        return new_ptr;

    } else {
        return ptr;
    }
}
