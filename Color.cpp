#include "Color.h"

Color::Color() {

}

Color::Color(int r, int g, int b) {
  red = r;
  green = g;
  blue = b;
}

Color::~Color() {

}

Color::Color(const Color& other) {
  red = other.red;
  green = other.green;
  blue = other.blue;
}

void Color::set_red(int x) {
  red = x;
}

void Color::set_green(int x) {
  green = x;
}

void Color::set_blue(int x) {
  blue = x;
}

int Color::get_red() const{
  return red;
}

int Color::get_green() const{
  return green;
}

int Color::get_blue() const{
  return blue;
}

Color operator+(Color const &color1, Color const &color2) {
  int r = color1.get_red() + color2.get_red();
  int g = color1.get_green() + color2.get_green();
  int b = color1.get_blue() + color2.get_blue();
  Color new_c(r, g, b);
  return new_c;
}

Color& Color::operator=(Color const &other) {
  red = other.red;
  green = other.green;
  blue = other.blue;
  return (*(this));
}

bool operator==(const Color &c1, const Color &c2){
  if(c1.get_red()==c2.get_red() && c1.get_green()==c2.get_green() && c1.get_blue()==c2.get_blue())
    return true;
  return false;
}

ostream& operator<<(ostream &os,const Color &c) {
  os<<c.get_red()<<" "<<c.get_green()<<" "<<c.get_blue()<<" ";
  return os;
}
Color Color::multiply(float alpha){
    Color c;
    c.red = red * alpha;
    c.green = green * alpha;
    c.blue = blue * alpha;
    return c;
}
