#include <iostream>

using namespace std;

void displayRun(int values[], int size) {
    bool inRun = false;
    for (int i = 0; i < size; i++) {
        if (i > 0 && values[i] == values[i - 1]) {
            if (!inRun) {
                cout << "(";
                inRun = true;
            }
        }
        else {
            if (inRun) {
                cout << values[i - 1] << ") ";
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

bool hasRun(int values[], int size) {
    for (int i = 1; i < size; i++) {
        if (values[i] == values[i - 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int values[20];

    while (true) {
        for (int i = 0; i < 20; i++) {
            values[i] = rand() % 6 + 1;
        }

        if (hasRun(values, 20)) {
            cout << "has run: ";
        }
        else {
            cout << "no run: ";
        }

        displayRun(values, 20);

        if (hasRun(values, 20)) {
            break;
        }
    }

    return 0;
}