#ifndef Pixel_H_
#define Pixel_H_

#include "Color.h"
#include <fstream>

class Pixel {
  public:
    Pixel();
    Pixel(int p, int q, Color col);
    ~Pixel();
    Pixel(const Pixel& other);
    Color get_color() const;
    void set_color(int x, int y, int z);
    void set_color(Color c1) ;
    int get_x() const;
    int get_y() const;
    void set_x(int x);
    void set_y(int y);
    friend Pixel operator+(Pixel const &pixel1, Pixel const &pixel2);
    Pixel& operator=(Pixel const &other);
    friend ostream& operator<<(ostream &os,const Pixel &c);
  private:
    int x, y;
    Color c;
};

#endif
