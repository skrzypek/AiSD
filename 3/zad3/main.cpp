// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
// https://www.youtube.com/watch?v=PHXAOKQk2dw
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

#define RESET "\033[0m"
#define SAPID "\033[32;1m"

using namespace std;


void construct_bad_match(map <char, int> &bad_match, string pattern) {
    int size = int(pattern.length());

    for (int i=0; i<size; i++){
        if (i == size-1) {
            map<char, int>::iterator it = bad_match.find(pattern[i]);

            if (it == bad_match.end()) {
                bad_match.insert(pair <char, int>(pattern[i], size));
            }
        } else {
            bad_match.insert(pair <char, int>(pattern[i], size-i-1));

            map<char, int>::iterator it = bad_match.find(pattern[i]);
            if (it != bad_match.end()) {
                it->second = size-i-1;
            }
        }
    }
    bad_match.insert(pair <char, int>('*', size));


    cout << "BAD MATCH TABLE:" << endl;
    for (auto i=bad_match.begin(); i != bad_match.end(); i++){
        cout << setw(6) << i -> first;
    }

    cout << endl;

    for (auto i=bad_match.begin(); i != bad_match.end(); i++){
        cout << setw(6) << i -> second;
    }
    cout << endl;
}


void bm(map <char, int> &bad_match, string pattern, string text) {
    int size = int(pattern.length());
    int full_size = int(text.length());

    char miss;
    int skip = 0;
    int stop_at = 0;
    int copy_size = int(size-1);

    map <int, int> found;

    while (stop_at <= int(text.length())) {

        copy_size = size-1;
        while (copy_size > -1) {

            if (pattern[copy_size] != text[stop_at+copy_size]) {
                miss = text[stop_at+copy_size];
                break;
            }
            if (copy_size == 0) {
                found.insert(pair <int, int>(stop_at, stop_at+size-1));
            }
            copy_size -= 1;
        }

        if (miss != ' ') {
            map<char, int>::iterator it = bad_match.find(miss);
            if (it != bad_match.end()) {
                skip = it->second;
            } else {
                map<char, int>::iterator it = bad_match.find('*');
                skip = it->second;
            }
        } else {
            skip = size;
        }

        stop_at += skip;
        miss = ' ';
    }

    for (auto i=found.begin(); i!=found.end(); i++){
        cout << "Found, start index: " << i->first << ", end index: " << i -> second << endl;
    }

    bool start = false;
    int start_at, end_at(0);
    for (int i=0; i<full_size; i++){
        map<int, int>::iterator it = found.find(i);
        if (it != found.end()) {
            start_at = it -> first;
            end_at = it -> second;
            start = true;
        }
        if (start) {
            if (i <= end_at){
                cout << SAPID << text[i] << RESET;
            } else {
                cout << text[i];
                start = false;
            }
        } else {
            cout << RESET << text[i];
        }
    }
    cout << endl;
}


int main() {
    string pattern, text;

	cout << "Set text: ";
	getline(cin, text);

    cout << "Set pattern: ";
    cin >> pattern;

    map<char, int> bad_match;
    construct_bad_match(bad_match, pattern);

    bm(bad_match, pattern, text);
}
