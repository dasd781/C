#include <iostream>
#include <string>
using namespace std;
void computeLPS(string pat, int* lps) {
	int8_t j = 0;
	lps[0] = 0;
	int8_t i = 1;
	while (i < pat.size()) {
		if (pat[i] == pat[j]) {//èäåì ïî öèêëó, åñëè ó íàñ ñèìâîëû ðàâíû, òî ìû èíêðåìåíòèðóåì è j è i
			j++;
			lps[i] = j;
			i++;
		}
		else {//åñëè ó íàñ ñèìâîëû íå ðàâíû, è ïðè ýòîì j íå ðàâíî íóëþ, òî ïðèñâàèâàåì j
			if (j != 0) {
				j = lps[j - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}
void KMPSearch(const string& pat, const string txt) {
	int* lps = new int[pat.size()];
	computeLPS(pat, lps);

	int i = 0;
	int j = 0;
	while (i < txt.size()) {
		if (pat[j] == pat[i]) {
			j++;
			i++;
		}
		if (j == pat.size()) {
			cout << "Found Pattern at index" << i - j << endl;
			j = lps[j - 1];//???
		}
		else if (i < txt.size() && pat[j] != txt[i])
		{
			if (j != 0) {
				j = lps[j - 1];//???
			}
			else {
				i = i + 1;
			}
		}
	}
}
int main() {
	string txt = "AABAACAABAA";
	string pat = "ABABA";
	KMPSearch(txt, pat);
	return 0;
}