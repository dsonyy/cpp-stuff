#include <cstdio>

int function(const char);
int judge(int (*)(const char));

int main()
{
	printf("elo %c",judge(function));
	return 0;
}

int function(const char ch)
{
	return int (ch);
}

int judge(int (pf)(const char))
{
	return (pf)('X');
}