#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string in, out,s;

	cin >> in >> out;

	if (in.size() != out.size())
	{
		cout << "No";
		return 0;
	}

	s = out + "#" + in;
	vector <int> p(1 + s.size(), 0);
	int len = 0;

	for (int i = 1; i < s.size(); i++)
	{
		while (true)
		{
			if (s[i] == s[len])
			{
				len++;
				break;
			}

			if (len == 0)
				break;

			len = p[len];
		}

		p[i + 1] = len;
	}

	for (int i = 0; i < in.size() - len; i++)
	{
		if (in[i] != out[out.size() - 1 - i])
		{
			cout << "No";
			return 0;
		}
	}

	cout << "Yes" << endl << in.size() - len;

}