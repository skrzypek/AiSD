// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>

using namespace std;


int main() {
    long unsigned int strong(1);
    int integer;

    cout << "Set integer: ";
    cin >> integer;

    for (int i=integer; i>1; i--) {
        strong *= i;
    }
    cout << integer << "! = "<< strong << endl;
}
