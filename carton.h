#ifndef CARTONS_H
#define CARTONS_H
#endif
#include <fstream>

class Carton{

public:
    Carton();
    Carton(float length, float width, float height);
    ~Carton() {};

    //getters
    float GetLength() const {return length_;};
    float GetWidth() const {return width_;};
    float GetHeight() const {return height_;};

    //setters
    void SetLength(float length);
    void SetWidth(float width);
    void SetHeight(float height);

    void WriteData(std::ostream &out) const;
    void WriteCarton(std::ostream &out) const;

    float Volume() const;

private:
    float length_;
    float width_;
    float height_;
};