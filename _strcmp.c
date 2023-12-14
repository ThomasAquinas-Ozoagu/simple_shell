/**
 * _strcmp - checks two strings for equal number of bytes
 *
 * @s1: string 1
 *
 * @s2: string 2
 *
 * Return: integer 0 if equal, +15 if 1 > 2 and -15 if 2 > 1.
 */

int _strcmp(char *s1, char *s2)
{
	int j, k;
	int c1 = 0;
	int c2 = 0;

	for (j = 0; s1[j]; j++)
	{
		c1 = c1 + (int)s1[j];
	}
	for (k = 0; s2[k]; k++)
	{
		c2 = c2 + (int)s2[k];
	}

	if (c1 > c2)
		return (15);
	else if (c1 < c2)
		return (-15);
	else
		return (0);
}
