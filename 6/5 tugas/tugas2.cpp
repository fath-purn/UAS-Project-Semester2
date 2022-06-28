// Nama : Fatkhurrohman Purnomo
// NIM : 21102125

#include <bits/stdc++.h>
using namespace std;

// Fungsi untuk mengembalikan satuan operator
int back(char satuan)
{
	if (satuan == '^')
		return 3;
	else if (satuan == '/' || satuan == '*')
		return 2;
	else if (satuan == '+' || satuan == '-')
		return 1;
	else
		return -1;
}

// Fungsi utama untuk mengubah ekspresi infiks
// ke ekspresi postfix
void mengubah(string data)
{
	stack<char> st; // Stack untuk menampung operator
	string result; // Hasil akhir

	for (int i = 0; i < data.length(); i++) {
		char c = data[i];

		// Jika karakter yang dipindai adalah
        // sebuah operan, tambahkan ke string output.
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;

        // Jika karakter yang dipindai adalah sebuah kurung buka, maka:
		else if (c == '(')
			st.push('(');
        
        // Jika karakter yang dipindai adalah sebuah kurung tutup, maka:
		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			while (!st.empty()
				&& back(data[i]) <= back(st.top())) {
				if (c == '^' && st.top() == '^')
					break;
				else {
					result += st.top();
					st.pop();
				}
			}
			st.push(c);
		}
	}

	// Tambahkan semua karakter yang ada di stack ke output
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}

// Fungsi utama
int main()
{
	string exp;
	cout << " Infix     : ";
	cin >> exp;
	
	cout << " Postfix   : ";
	mengubah(exp);
	return 0;
}
