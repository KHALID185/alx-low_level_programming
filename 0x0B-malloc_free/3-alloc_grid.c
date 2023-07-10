#include "main.h"

/**
 * **alloc_grid - a function that returns a pointer to a 2 dimensional array
 * @width: integer
 * @height: integer
 * Return: 2 dim array
*/

int **alloc_grid(int width, int height)
{
int **ptr, i, j;
ptr = malloc(sizeof(int) * height);
if (width <= 0 || height <= 0 || ptr == 0)
	return (NULL);
else
{
	for (i = 0; i < height; i++)
	{
		ptr[i] = malloc(sizeof(**ptr) * width);
		if (ptr[i] == 0)
		{
		while (i--)
			free(ptr[i]);
		free(ptr);
		return (NULL);
		}
		for (j = 0; j < width; j++)
			ptr[i][j] = 0;


	}
}
return (ptr);
}
