#include <iostream>

using namespace std;

void displayRun(int values[], int size) {
    bool inRun = false;
    for (int i = 0; i < size; i++) {
        if (i > 0 && values[i] == values[i - 1]) {
            if (!inRun) {
                cout << " (";
                inRun = true;
            }
        }
        else {
            if (inRun) {
                cout << values[i - 1] << " ) ";
                inRun = false;
            }
        }
        if (i == size - 1 && inRun) {
            cout << values[i] << ") ";
        }
        else if (!inRun) {
            cout << values[i] << " ";
        }
        else {
            cout << values[i];
        }
    }
    if (!inRun) {
        cout << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    const int size = 20;
    int dieValues[size];

    for (int i = 0; i < size; i++) {
        dieValues[i] = rand() % 6 + 1;
    }

    cout << "Die values: ";
    displayRun(dieValues, size);

    return 0;
}
