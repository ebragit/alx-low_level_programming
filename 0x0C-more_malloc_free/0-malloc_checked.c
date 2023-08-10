#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc
 * @b: amount of bytes
 * Return: pointer to our new allocated memory exit with 98 if malloc fails
*/

void *malloc_checked(unsigned int b)
{
	void *new_memo;

	new_memo = malloc(b);
	if (new_memo == NULL)
		exit(98);
	return (new_memo);
}
