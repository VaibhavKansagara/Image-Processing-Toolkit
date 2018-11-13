#ifndef Color_H_
#define Color_H_

#include <ostream>

using namespace std;

class Color {
  public:
    Color();
    Color(int r, int g, int b);
    ~Color();
    Color(const Color& other);
    void set_red(int x);
    void set_green(int x);
    void set_blue(int x);
    int get_red() const;
    int get_green() const;
    int get_blue() const;
    Color multiply(float alpha);
    friend Color operator+(Color const &color1, Color const &color2);
    friend ostream& operator<<(ostream &os,const Color &c);
    friend bool operator==(const Color &c1, const Color &c2);
    Color& operator=(Color const &other);
  private:
    int red, green, blue;
};

#endif
