#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main() {
	map<char, char> code = {
		{'A', '0'},
		{'E', '0'},
		{'H', '0'},
		{'I', '0'},
		{'O', '0'},
		{'U', '0'},
		{'W', '0'},
		{'Y', '0'},
		{'B', '1'},
		{'F', '1'},
		{'P', '1'},
		{'V', '1'},
		{'C', '2'},
		{'G', '2'},
		{'J', '2'},
		{'K', '2'},
		{'Q', '2'},
		{'S', '2'},
		{'X', '2'},
		{'Z', '2'},
		{'D', '3'},
		{'T', '3'},
		{'L', '4'},
		{'M', '5'},
		{'N', '5'},
		{'R', '6'}
	};

	char name[20], result[5], previous, current;
	int i, resultLen;

	printf("%9sNAME%21sSOUNDEX CODE\n", "", "");
	
	while(cin >> name) {
		result[0] = name[0];
		previous = code[name[0]];
		i = 1;
		resultLen = 1;
		while(name[i] != '\0') {
			if(resultLen < 4) {
				current = code[name[i]];
				if(current != '0' && current != previous) {
					result[resultLen++] = current;
				}
				previous = current;
			}
			i++;
		}
		for(int j = resultLen; j < 4; j++) {
			result[j] = '0';
		}
		printf("%9s%s%*s\n", "", name, 29-i,result);
	}
	printf("%19sEND OF OUTPUT\n", "");
	return 0;
}