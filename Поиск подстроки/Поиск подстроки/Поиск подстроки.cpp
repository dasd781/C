
/*
bool search(int arr[], int size, int x, int& foundIndex)
{
	foundIndex = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			foundIndex = i;
			return true;
		}
	}
	return false;
}
*/
void search(const string& pat, const string& txt)
{
	int M = pat.size();
	int N = txt.size();
	int j;
	for (int i = 0; i <= N - M; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (txt[i + j] != pat[j]) break;
		}
		if (j == M)
			cout << "Pattern found at index" << i << endl;
	}
}