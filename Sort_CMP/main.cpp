#include "bits/stdc++.h"
#include "Function.h"
#include "SortAlgorithm.h"
#include "ArrayGenerator.h"


int main() {
    srand(time(NULL));
    system("mode 100, 25");
    int keyIn;

    while(true) {
        system("cls");
        setTextColor(15);

        cout<< "--------| MENU |--------\n";
        cout<< "1. Array Generation\n";
        cout<< "2. Sorting Comparison\n";
        cout<< "3. Print Result\n";
        cout<< "4. Exit\n\n";
        cout<< "--> "; cin >> keyIn;

        switch(keyIn) {
            case 1: ArrayGenerator(); break;
            case 2: showCompareResult(); break;
            case 3: printOutput(); break;
            case 4: return 0;
            default: break;
        }
    }




    return 0;
}
