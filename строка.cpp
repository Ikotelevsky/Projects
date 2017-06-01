#include <iostream>
#include <string>


using namespace std;

void add(string &str, int size = 1) {
	int temp = str.size() - size;
	if (temp < 0) {
		str.insert(0, "1");
		return;
	}
	int ascii = str[str.size() - size];	
	if (ascii < 57) {
		str[str.size() - size] = char(ascii + 1);
	}
	else if (ascii = 57) {
		str[str.size() - size] = char(48);
		size++;
		add(str,size);
	}
}


int main() {
	
	string str;
	getline(cin, str);
	add(str);
	cout << str;
	return 0;
}

