// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>

#define RESET "\033[0m"
#define LEFT "\033[32m"
#define RIGHT "\033[31m"
#define PIVOT "\033[32;1m"

using namespace std;

const int tab_size = 7;


void display(int tab[], int left, int right, int pivot) {
    for (int i=0; i<tab_size; i++) {
        if (tab[i] == pivot){
            cout << PIVOT << tab[i] << RESET << ", ";
        } else if (i == left) {
            cout << LEFT << tab[i] << RESET << ", ";
        } else if (i == right) {
            cout << RIGHT << tab[i] << RESET << ", ";
        } else {
            cout << tab[i] << ", ";
        }
    }
}


int sort(int tab[], int left, int right, int pivot) {
    int temp;
    int point_left = left;
    int point_right = right-1;

    cout << "Pivot: "<< pivot << endl;
    display(tab, point_left, point_right, pivot);
    cout << endl;

    while (true) {

        // move right
        while (tab[point_left] < pivot) {
            display(tab, point_left, point_right, pivot);
            cout << endl;
            point_left++;
        }

        // move left
        while (point_right > 0 && tab[point_right] > pivot) {
            display(tab, point_left, point_right, pivot);
            cout << endl;
            point_right--;
        }

        if (point_left >= point_right) {
            break;
        } else {
            swap(tab[point_left], tab[point_right]);

            display(tab, point_left, point_right, pivot);
            cout << "  --  Swap: "<< tab[point_left] << ", " << tab[point_right] << endl;
        }
    }

    if (tab[point_left] > pivot){
        swap(tab[point_left], tab[right]);

        display(tab, point_left, right, pivot);
        cout << "  -- Swap pivot: "<< tab[point_left] << ", " << tab[right] << endl;
    }

    cout << endl;
    return point_left;
}


void quick_sort(int tab[], int left, int right) {
    if (right-left <= 0) {
        return;
    }

    int pivot = tab[right];
    int partition = sort(tab, left, right, pivot);

    // sort left
    quick_sort(tab, left, partition-1);

    // sort right
    quick_sort(tab, partition+1, right);
}


int main() {
    int tab[tab_size] = {25, 11, 42, 31, 54, 14, 19};

    cout << "Your whole tab before quick sort: ";
    for (int i=0; i<tab_size; i++) {
        cout << tab[i] << ", ";
    }
    cout << endl;

    quick_sort(tab, 0, tab_size-1);

    cout << "Your whole tab after quick sort: ";
    for (int i=0; i<tab_size; i++) {
        cout << tab[i] << ", ";
    }
    cout << endl;
}
