// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>

using namespace std;


long unsigned int strong(long unsigned int integer) {
    if (integer==0) {
        return 1;
    }
    return integer*strong(integer-1);
}


int main() {
    long unsigned int integer;

    cout << "Set integer: ";
    cin >> integer;

    cout << integer << "! = " << strong(integer) << endl;
}
