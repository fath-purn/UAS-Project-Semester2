#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void reversed(string& s, int l, int r)
{
	while (l < r)
    {
		swap(s[l], s[r]);
		l++;
		r--;
	}
}

string reverseString(string str)
{
	str.insert(str.end(), ' ');
	int n = str.length();
	int j = 0;

	for (int i = 0; i < n; i++) 
    {
		if (str[i] == ' ') 
        {
			reversed(str, j, i - 1);
			j = i + 1;
		}
	}

	str.pop_back();
	reversed(str, 0, str.length() - 1);
	return str;
}

int main()
{
	string str;
	getline(cin, str);
	string rev = reverseString(str);
	cout << rev;
	return 0;
}