#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	
	ifstream f;
	string s;
	s = "111.txt";	
	f.open(s);
	
	if (!f.is_open())
	{
		cout << "eror";
		return 0;
	}
	
	int n;
	int i;
	bool flag = true;
	int pos = 0;
	int neg = 0;

	while (!f.eof() && f >> n)
	{
		
		if (n > 0) pos++;
		else neg++;

	}

	fstream h("333.txt");
	ofstream g("222.txt");
	f.close();
	f.open(s);
	


			
	if (pos == neg)
	{


		f >> n;
		g << n << " ";
		if (n > 0) i = 1;
		else i = -1;

		while (!f.eof() && f >> n)
		{
			
			if ((n > 0) && (i == 1))
			{
				h << n << " ";
			}
			else if (n < 0 && i == 1)
			{
				g << n << " ";
				i = -1;
			}
			else if (n > 0 && i == -1)
			{
				g << n << " ";
				i = 1;
			}
			else
			{
				h << n << " ";
			}
		}

	}
	
	h.close();
	h.open("333.txt");

	while (!h.eof() && h >> n)
	{

		g << n << " ";

	}
	
}

