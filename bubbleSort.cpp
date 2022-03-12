#include <iostream>
#include <list>
#include <iterator>

using namespace std;


bool sort(int* list, int size) {
    // copy list
    int *copyList = new int[size];
    for (int i = 0; i < size; i++) {
        copyList[i] = list[i];
    }

    for (int i = 0; i < size - 1; i++) {
        int pole = list[i];
        int pole2 = list[i + 1];
        if (pole2 < pole) {
            list[i] = pole2;
            list[i + 1] = pole;
        }
    }

    for (int i = 0; i < size; i++) {
        if (copyList[i] != list[i]) return false;
    }

    return true;
}


void bubbleSort(int *list, int size)
{
    while (!sort(list, size));
}

int main()
{
    int pole[] = { 5,2,10,4,1 };
    int size = sizeof(pole) / sizeof(pole[0]);
    bubbleSort(pole, size);


    for (int i = 0; i < size; i++) {
        cout << pole[i] << endl;
    }
    return 0;
}