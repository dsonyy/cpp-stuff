// functions.cpp 
// definitions of all global functions used in the program

#include "headers.h"
#include "functions.h"

/*
void Message(message_type type, char * str, ...)
{
	va_list arg;
	va_start(arg, str);
	int argc = 0;

	switch (type)
	{
	case Info:		printf("[  i  ] "); break;
	case Warning:	printf("[  !  ] "); break;
	case Error:		printf("[ERROR] "); break;
	}

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == 's')
				printf("%s", va_arg(arg, char*));
			else if (str[i + 1] == 'i')
				printf("%i", va_arg(arg, int));
			else if (str[i + 1] == '#')
				putchar('#');
			i++;
		}
		else
			putchar(str[i]);
	}
}
*/


void Help()
{

}
