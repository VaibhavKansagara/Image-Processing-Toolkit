#include "Pixel.h"

Pixel::Pixel() {

}

Pixel::Pixel(int p, int q, Color col) {
  x = p;
  y = q;
  c = col;
}

Pixel::~Pixel() {

}

void Pixel::set_x(int x){
  this->x=x;
}

void Pixel::set_y(int y){
  this->y=y;
}

Pixel::Pixel(const Pixel& other) {
  x = other.x;
  y = other.y;
  c = other.c;
}

Color Pixel::get_color() const{
  return c;
}

void Pixel::set_color(int x, int y, int z) {
  c.set_red(x);
  c.set_green(y);
  c.set_blue(z);
}

void Pixel::set_color(Color c1) {
  c = c1;
}

int Pixel::get_x() const{
  return x;
}

int Pixel::get_y() const{
  return y;
}

Pixel operator+(Pixel const &pixel1, Pixel const &pixel2) {
  if(pixel1.get_x() == pixel2.get_x() && pixel1.get_y() == pixel2.get_y()) {
    Color tmp_color = pixel1.get_color() + pixel2.get_color();
    Pixel p(pixel1.get_x(), pixel1.get_y(), tmp_color);
    return p;
  }
}

Pixel& Pixel::operator=(Pixel const &other) {
  x = other.x;
  y = other.y;
  c = other.c;
  return (*(this));
}

ostream& operator<<(ostream &os,const Pixel &p) {
  os<<p.c;
  return os;
}
