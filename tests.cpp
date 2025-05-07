#include <iostream>
#include <vector>

using namespace std;

void load (vector <int> &lista, vector <int> listb) {
    for ( int i=0; i < listb.size(); i++) {
        lista[i] = listb[i];
    }

}

void print ( vector <int> list) {
    for (int i=0; i < list.size(); i++) {
        cout << list[i] <<" ";
    }
    cout<<"\n";
}

int main () {
    vector <int> list1 = {1, 2, 3, 4, 5};
    vector <int> list2 = {6, 6, 6, 6, 6};
    print(list1);
    print(list2);
    load(list1, list2);
    print(list1);
    print(list2);


    return 0;

}