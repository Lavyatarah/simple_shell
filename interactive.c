#include "shell.h"


int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

int is_delim(char b, char *delim)
{
	while (*delim)
		if (*delim++ == b)
			return (1);
	return (0);
}


int _isalpha(int b)
{
	if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
		return (1);
	else
		return (0);
}


int _atoi(char *s)
{
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0;  s[a] != '\0' && flag != 2; a++)
	{
		if (s[a] == '-')
			sign *= -1;

		if (s[a] >= '0' && s[a] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
