#include<string>
#include<iostream>
using namespace std;
# define NO_OF_CHARS 256

void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
	int i;
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}
void search(string txt, string pat)
{
	int m = pat.size();
	int n = txt.size();

	int badchar[NO_OF_CHARS];
	badCharHeuristic(pat, m, badchar);

	int s = 0;
	while (s <= (n - m))
	{
		int j = m - 1;

		while (j >= 0 && pat[j] == txt[s + j])
			j--;

		if (j < 0)
		{
			cout << " pattern occurs at shift =  " << s << endl;
		}
		else
		{
			int bc = badchar[txt[s + j]];
			s += max(1, j - bc);
		}

	}
}

	int main()
	{
		string txt = "METADDDATASADF";
		string pat = "DATA";
		//int badchar[NO_OF_CHARS];
		//int size = pat.size() / sizeof(pat[0]);
		//badCharHeuristic(pat,size,badchar);
		search(txt, pat);
		return 0;
	}
