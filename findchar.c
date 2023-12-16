/**
 * findchar - checks whether a string contains a character
 *
 * @str: string to be checked
 * @c: character to check for
 *
 * Return: 0 if not found or index if found
 */

int findchar(char *str, char c)
{
	int i, j = -2;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == c)
			return (i);
	}
	return (j);
}
