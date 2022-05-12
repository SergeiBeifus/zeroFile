//
// Created by User on 05.05.2022.
//

#include "box.h"
#include <iostream>


namespace receptacle {
    box::box(int length, int wight, int height, double weight, int value) {
        if (length <= 0 || wight <= 0 || height <= 0 || weight <= 0 || value <= 0) {
            throw "Error input";
        } else {
            this->length = length;
            this->wight = wight;
            this->height = height;
            this->weight = weight;
            this->value = value;

        }
    }


    int box::getLength() const {
        return length;
    }

    void box::setLength(int length) {
        box::length = length;
    }

    int box::getWight() const {
        return wight;
    }

    void box::setWight(int wight) {
        box::wight = wight;
    }

    int box::getHeight() const {
        return height;
    }

    void box::setHeight(int height) {
        box::height = height;
    }

    double box::getWeight() const {
        return weight;
    }

    void box::setWeight(double weight) {
        box::weight = weight;
    }

    int box::getValue() const {
        return value;
    }

    void box::setValue(int value) {
        box::value = value;
    }

    bool box::Equals(box a) {
        if (this->length == a.length && this->wight == a.wight && this->height == a.height) {
            return true;
        } else {
            return false;
        }
    }


    std::ostream &operator<<(std::ostream &os, const box &p) {
        return os << "\nlength: " << p.length
                  << "\nwight:  " << p.wight
                  << " \nheight: " << p.height
                  << " \nweight: " << p.weight
                  << " \nvalue:  " << p.value;
    }

    std::istream &operator>>(std::istream &in, box &p) {
        in >> p.length >> p.wight >> p.height >> p.weight >> p.value;
        return in;
    }

    static int SumValue(box *arr, int size) {
        int res = 0;
        for (int i = 0; i < size; i++) {
            res = res + arr[i].getValue();
        }
        return res;
    }

    static bool TheSumOfTheLengthsOfAllStrings(box *arr, int size, int n) {
        bool res = true;
        for (int i = 0; i < size; i++) {
            if (arr[i].getLength() + arr[i].getWight() + arr[i].getHeight() > n) {
                res = false;
                break;
            }
        }
        return res;
    }

    static double SumWeightBox(box *arr, int size, int volume) {
        double res = 0;
        for (int i = 0; i < size; i++) {
            if (res < arr[i].getWeight() && arr[i].getLength() * arr[i].getWight() * arr[i].getHeight() <= volume) {
                res = arr[i].getWeight();
            }
        }
        return res;
    }

    static bool matryoshka(box *arr, int n) {

        int j = 0;
        box tmp = box(1, 1, 1, 1, 1);
        for (int i = 0; i < n; i++) {
            j = i;
            for (int k = i; k < n; k++) {
                if (arr[j].getLength() > arr[k].getLength()) {
                    j = k;
                }
            }
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }

        for (int i = 1; i < n; i++) {
            if (arr[i - 1].getLength() == arr[i].getLength() || arr[i - 1].getWight() >= arr[i].getWight() ||
                arr[i - 1].getHeight() >= arr[i].getHeight()) {
                return false;
            }
        }

        return true;
    }
}

