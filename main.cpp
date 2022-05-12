#include <iostream>
#include <gtest/gtest.h>
#include "cmake-build-debug/box.h"
#include "cmake-build-debug/Container3D.h"

using namespace receptacle;
using namespace std;
int main() {
    box a = box(1, 1, 1, 1.0, 2);
    box b = box(1, 2, 2, 1.0, 1);
    vector<box> arr = {box(1, 1, 1, 1, 1),
                       box(6, 6, 6, 6, 6)};

    Container3D c = Container3D(arr, 10, 10, 10, 10);
    std::cout << "\n number of boxes in a container: " << c.getSize() << "\n";


    c.setBox(a);
    std::cout << "\n number of boxes in a container after adding a box: " << c.getSize();
    //c.deleteByIndex(0);
    std::cout << "\n the total weight of the contents of the container: " <<c.sumWeight();
    std::cout << "\n the total cost of the contents of the container: " <<c.sumValue();
    std::cout<< "\n" << c.getBox(0);
    arr[0] = a;
    std::cout << "\n"<< c.getBox(0);
    cout << c;
    c[0] = b;
    cout << c;

    cin >> c;
    cout << c;
    return 0;
}

