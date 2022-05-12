//
// Created by User on 10.05.2022.
//

#include "Container3D.h"
#include "box.h"

namespace receptacle {


    Container3D::Container3D(vector<box> &container3D, int length, int wight, int height, double maximumWeightLimit) {

        if (length <= 0 || wight <= 0 || height <= 0 || maximumWeightLimit <= 0) {
            throw std::exception();
        } else {
            this->container3D = container3D;
            this->length = length;
            this->wight = wight;
            this->height = height;
            this->maximumWeightLimit = maximumWeightLimit;
        }
    }

    size_t Container3D::getSize() const {
        return container3D.size();
    }

    double Container3D::sumWeight() {
        double res = 0.0;
        for (const auto &i: container3D) {
            res += i.getWeight();
        }
        return res;
    }

    double Container3D::sumValue() {
        double res = 0.0;
        for (const auto &i: container3D) {
            res += i.getValue();
        }
        return res;
    }

    box &Container3D::getBox(int i) {
        return container3D[i];
    }

    int Container3D::setBox(box a) {
        if (maximumWeightLimit - sumWeight() >= a.getWeight()) {
            container3D.push_back(a);
            return container3D.size() - 1;
        } else {
            throw "Container is full";
        }
    }

    void Container3D::deleteByIndex(int index) {
        if (!container3D.empty()) {
            for (int i = index; i < container3D.size() - 1; i++) {
                container3D[i] = container3D[i + 1];
            }
            container3D.pop_back();
        } else {
            throw "array is void";
        }

    }

    std::ostream &operator<<(std::ostream &os, const Container3D &p) {
        os << "length: " << p.length << " wight: " << p.wight << " height: " << p.height << " weight: "
           << p.maximumWeightLimit << std::endl;
        for (box i: p.container3D) {
            os << i << "\n";
        }
        return os;
    }

    std::istream &operator>>(std::istream &in, Container3D &p) {
        in >> p.length >> p.wight >> p.height >> p.maximumWeightLimit;
        for (box i: p.container3D) {
            in >> i;
        }
        return in;
    }

    box &Container3D::operator[](const int index) { return container3D[index]; }
}