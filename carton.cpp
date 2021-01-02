#include "carton.h"
#include <fstream>

using namespace std;

Carton::Carton() : length_(1.0), width_(1.0), height_(1.0) {}

Carton::Carton(float length, float width, float height) {
    SetLength(length);
    SetWidth(width);
    SetHeight(height);
}

void Carton::SetLength(float length){
    if (length <= 0){
        length_ = 1;
    }else{
        length_ = length;
    }
}
void Carton::SetWidth(float width){
    if(width <= 0){
        width_ = 1;
    }else{
        width_ = width;
    }
}
void Carton::SetHeight(float height){
    if(height <= 0){
        height_ = 1;
    }else{
        height_ = height;
    }
}

void Carton::WriteData(std::ostream &out) const {
    out << length_ << " "
        << width_ << " "
        << height_ << endl;
}

void Carton::WriteCarton(std::ostream &out) const {
    out << "A carton with length " << length_
        << ", width " << width_
        << ", and height " << height_ << ".";
}

float Carton::Volume() const {
    float volume = length_ * width_ * height_;
    return volume;
}
