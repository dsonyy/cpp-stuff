#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> arg;

	cout << "Podawaj slowa, kiedy skonczysz napisz 'gotowe'.\n";
	
	char buf;
	arg.push_back("");
	int i = 0;
	
	do
	{
		buf = cin.get();
		if (isgraph(buf))
		{
			arg.at(i) += buf;
		}
		else
		{
			arg.push_back("");
			++i;
		}
		
	} while (buf !='\n');
	
	for (int y = 0; y<arg.size();++y)
		cout << arg[y];
	
	return 0;
}