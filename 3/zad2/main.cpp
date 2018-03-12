// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>

using namespace std;


int main() {
    const int pattern_size = 3, char_list_size = 10;
	int from(0), to(0);

	char pattern[pattern_size];
	char char_list[char_list_size] = {'a', 'a', 'p', 'a', 't', 'e', 's', 'a', 's', 's'};

	cout << "Set characters for pattern (max_length=3): " ;
	cin >> pattern;

	cout << "Your patterns is: ";
	for (int a=0; a<pattern_size; a++){
		cout << pattern[a];
	}
	cout << endl;

	cout << "Start for search your pattern at list: ";
	for (int a=0; a<char_list_size; a++){
		cout << char_list[a];
	}
	cout << endl;

	for (int a=0; a<char_list_size-2; a++){
		if (char_list[a]==pattern[0] && char_list[a+1]==pattern[1] && char_list[a+2]==pattern[2]){
			from = a;
			to = a + 2;
			break;
		}
	}

	if (from || to) {
		cout << "Found from: " << from << " to " << to << endl;
	} else {
		cout << "Pattern not found" << endl;
	}

	return 0;
}
