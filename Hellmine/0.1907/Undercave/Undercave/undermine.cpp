#include "undermine.h"

int main()
{

}

bool prob(int prob)
{
	uniform_int_distribution<> range(0, 100);
	if (range(gen) <= prob) return true;
	else return false;
}