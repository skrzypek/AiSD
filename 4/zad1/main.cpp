// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>
#include <iomanip>

using namespace std;


// global variables
const int tab_size = 8, index_order_size = 6, space = 6;


void display_by_pointer(int age_values[], int index[]) {
    cout << "Sorted:";

    int pointer = index[0];  // start from first element
    while (pointer != -1){
        cout << setw(space) << age_values[pointer];  // display by pointer

        for (int i=0; i<tab_size; i++){
            if (age_values[pointer] == age_values[i]){
                pointer = index[i];  // point to the next element
                break;
            }
        }
    }
}


void display_tab_with_pointer(int age_values[], int index[]) {
    cout << "Next:  ";
    for (int i=0; i<tab_size; i++) {
        if (index[i] == 0){
            cout << setw(space) << "-";
        } else {
            cout << setw(space) << index[i];
        }
    }
    cout << endl;

    cout << "Value: ";
    for (int i=0; i<tab_size; i++) {
        if (index[i] == 0){
            cout << setw(space) << "-";
        } else if (age_values[i] == 0) {
            cout << setw(space) << " ";
        } else {
            cout << setw(space) << age_values[i];
        }
    }
    cout << endl;

    cout << "--" << endl;
    display_by_pointer(age_values, index);
}


void delete_last_element(int age_values[], int index[]) {
    cout << endl << endl;

    int new_last, temp;
    for (int i=0; i<tab_size; i++) {
        if (index[i] == -1){
            cout << "Prepare to remove: " << age_values[i] << endl;
            new_last = i;

            // assing new last index to the element
            for (int s=0; s<tab_size; s++) {
                if (index[s] == new_last) {
                    index[s] = -1;
                    break;
                }
            }

            // move all index to the left (to avoid empty hole in the middle of the list)
            for (int m=i+1; m<tab_size; m++) {
                index[m-1] = index[m];
                age_values[m-1] = age_values[m];

            }

            // switch selected index into new tab size after moving elements
            for (int l=0; l<tab_size; l++) {
                if (index[l] > i) {
                    temp = index[l];
                    index[l] = temp-1;
                }
            }

            break;
        }
    }
    display_tab_with_pointer(age_values, index);
    cout << endl;
}


void add_first_element(int age_values[], int index[]) {
    cout << endl;

    int temp = index[0];
    for (int i=0; i<tab_size; i++) {
        if (index[i] == 0) {  // looking for empty slot
            cout << "Set age for index: " << i << ": ";
            cin >> age_values[i];

            index[i] = temp;
            index[0] = i;

            break;
        }
    }
    display_tab_with_pointer(age_values, index);
    cout << endl;
}


int main() {
    int age_values[tab_size],
        index[tab_size] = {0, 0, 0, 0, 0, 0, 0, 0},
        index_order[index_order_size] = {4, 1, 3, 6, 2, 5};

    cout << "Index order: ";
    for (int i=0; i<index_order_size; i++) {
        cout << index_order[i] << ", ";
    }
    cout << endl;

    // order input values: 7, 8, 9, 11, 12, 15
    for (int i=0; i<index_order_size; i++) {
        cout << "Set age for index: " << index_order[i] << ": ";
        cin >> age_values[index_order[i]];

        if (i == 0) {
            index[i] = index_order[i];
        } else {
            index[index_order[i-1]] = index_order[i];
        }
        index[index_order[i]] = -1;
    }

    display_tab_with_pointer(age_values, index);
    delete_last_element(age_values, index);
    add_first_element(age_values, index);

    return 0;
}
