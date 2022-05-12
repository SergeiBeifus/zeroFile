//
// Created by User on 05.05.2022.
//

#ifndef UNTITLED2_BOX_H
#define UNTITLED2_BOX_H

#include <iostream>
namespace receptacle {
    class box {
        int length, wight, height;
        double weight;
        int value;

        bool Equals(box a);

        friend std::ostream &operator<<(std::ostream &os, const box &p);

        friend std::istream &operator>>(std::istream &in, box &p);

    public:
        int getLength() const;

        void setLength(int length);

        int getWight() const;

        void setWight(int wight);

        int getHeight() const;

        void setHeight(int height);

        double getWeight() const;

        void setWeight(double weight);

        int getValue() const;

        void setValue(int value);

        box(int length, int wight, int height, double weight, int value);
    };
}

#endif //UNTITLED2_BOX_H
