#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#include <string>


int main()
{
	vector<string> vec;
	string word;
	while (cin >> word)
	{
		vec.push_back(word);
	}
		vector<string>::reverse_iterator it;
		for (it = vec.rbegin(); it != vec.rend(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	
	system("pause");
		
}