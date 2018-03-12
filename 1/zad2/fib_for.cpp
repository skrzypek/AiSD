// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>

using namespace std;


int main() {
    long unsigned int number(0), a(0), b(0);

    cout << "Set number (which one element from fibonacci numbers): ";
    cin >> number;

    if (number > 0) {
        b = 1;
        for(int i=0; i<(number-1); i++) {
            b += a;  // or b = b + a;
            a = b - a;
        }
    }
    cout << "And your number is: " << b << endl;
}
