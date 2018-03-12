//nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>

#define RESET "\033[0m"
#define SAPID "\033[32;1m"

using namespace std;


int main() {
    const int characters_tab_size = 20;
    int count = 0;
	char sapid, characters[characters_tab_size];

	srand(time(0));
	for (int i=0; i<characters_tab_size; i++){
		characters[i] = 'a' + rand()%26;
	}

	cout << "Set character: (char <1>): ";
	cin >> sapid;

	cout << "Start search for: " << SAPID << sapid << RESET << " at: ";
    for (int i=0; i<characters_tab_size; i++){
        cout << characters[i];
    }
    cout << endl;

	for (int i=0; i<characters_tab_size; i++){
		if (sapid == characters[i]){
			count++;
			cout << "Found: " << SAPID << sapid << RESET << " and their position is " << i << endl;
		}
	}

	cout << "At: ";
    for (int i=0; i<characters_tab_size; i++){
        if (characters[i] == sapid){
            cout << SAPID << characters[i] << RESET;
        } else {
            cout << characters[i];
        }
    }
    cout << " your char (" << SAPID << sapid << RESET << ")" << " was " << count << " times" << endl;

	return 0;
}
