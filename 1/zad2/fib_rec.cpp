// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>

#include <iostream>

using namespace std;


long unsigned int fib(long unsigned int number) {
    if (number == 0) {
        return 0;
    } else if (number == 1) {
        return 1;
    }
    return fib(number-1) + fib(number-2);
}


int main() {
    long unsigned int number;
    cout << "Set number (which one element from fibonacci numbers): ";
    cin >> number;

    cout << "And your number is: " << fib(number) << endl;
}
