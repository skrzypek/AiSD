// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>

using namespace std;

const int tab_size = 5;


int main() {
    int tab[tab_size];
    int temp;

    for (int i=0; i<tab_size; i++){
        cout << "Set tab value (for " << i << " index): ";
        cin >> tab[i];
    }

    cout << "Your whole tab is: ";
    for (int i=0; i<tab_size; i++){
        cout << tab[i] << ", ";
    }
    cout << endl;

    for (int i=0; i<tab_size; i++){
        if (tab[i] > tab[i+1]) {
            temp = tab[i];

            tab[i] = tab[i+1];
            tab[i+1] = temp;

            i = -1;
        }
    }

    cout << "Your whole tab after bubble sort: ";
    for (int i=0; i<tab_size; i++){
        cout << tab[i] << ", ";
    }
    cout << endl;
}
