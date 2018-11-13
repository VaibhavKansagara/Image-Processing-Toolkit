#ifndef Image_H_
#define Image_H_

#include "Pixel.h"
#include <fstream>

using namespace std;

class Image {
  public:
    Image();
    Image(int w, int h);
    ~Image();
    Image(const Image& other);
    int get_width() const;
    int get_height() const;
    Color get_Color_x_y(int x, int y) const;
    Pixel **get_ptr() const;
    void setptr();
    Pixel& get_pixel(int x,int y);
    void setColor(int i, int j, int r, int g, int b);
    Image &  binarize(Image & img,int t);
    Image& operator=(Image const &other);
    Image reflectionAboutY();
    Image reflectionAboutX();
    Image reflectionAboutXY();
    friend Image operator+(Image const &image1, Image const &image2);
    friend Image operator*(float const &f, Image const &image);
    friend istream& operator>>(istream &is, Image &image);
    friend ostream& operator<<(ostream &os, const Image &image);
  protected:
    int width, height,max_pixel;
    Pixel **ptr;
};

#endif
