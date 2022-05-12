//
// Created by User on 10.05.2022.
//

#ifndef UNTITLED2_CONTAINER3D_H
#define UNTITLED2_CONTAINER3D_H


#include <vector>
#include "box.h"

using namespace std;
namespace receptacle {
    class Container3D {

        int length, wight, height;
        double maximumWeightLimit;
        vector<box> container3D;
    public:
        Container3D(vector<box> &container3D, int length, int wight, int height, double maximumWeightLimit);

        friend std::ostream &operator<<(std::ostream &os, const Container3D &p);

        friend std::istream &operator>>(std::istream &in, Container3D &p);

        box &operator[](int index);

        size_t getSize() const;

        double sumWeight();

        double sumValue();

        box &getBox(int n);

        int setBox(box o);

        void deleteByIndex(int i);
    };
}

#endif //UNTITLED2_CONTAINER3D_H
