/**
 * _strcat - concatenates two strings.
 *
 * @dest: base string
 *
 * @src: string to be appended
 *
 * Return: a pointer to the resulting string dest.
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (j = 0; dest[j] != '\0'; j++)
		;

	for (i = 0; src[i] != '\0'; i++)
	{
		*(dest + j + i) = src[i];
	}

	*(dest + j + i) = '\0';

	return (dest);
}
