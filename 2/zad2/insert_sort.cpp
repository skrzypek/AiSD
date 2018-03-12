// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>

using namespace std;

const int tab_size = 5;


int main() {
    int tab[tab_size];
    int temp, j;

    for (int i=0; i<tab_size; i++){
        cout << "Set tab value (for " << i << " index): ";
        cin >> tab[i];
    }

    cout << "Your whole tab is: ";
    for (int i=0; i<tab_size; i++) {
        cout << tab[i] << ", ";
    }
    cout << endl;

    for (int i=(tab_size-2); i>=0; i--) {
        temp = tab[i];

        j = i+1;
        while (j<tab_size && temp>tab[j]) {
            tab[j-1] = tab[j];
            j++;
		}

        tab[j-1] = temp;
    }

    cout << "Your whole tab after insertion sort: ";
    for (int i=0; i<tab_size; i++) {
        cout << tab[i] << ", ";
    }
    cout << endl;
}
