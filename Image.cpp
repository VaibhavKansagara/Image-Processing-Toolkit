#include "Image.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Image::Image() {

}

Image::Image(int w, int h) {
  width = w;
  height = h;
  ptr = new Pixel*[height];
  for(int i=0;i<height;i++) {
    ptr[i] = new Pixel[width]();
  }
}

Image::~Image() {

}

Image::Image(const Image& other) {
  width = other.width;
  height = other.height;
  ptr = new Pixel*[height];
  for(int i=0;i<height;i++) {
    ptr[i] = new Pixel[width];
  }
  for(int i=0;i<height;i++) {
    for(int j=0;j<width;j++) {
      ptr[i][j] = other.ptr[i][j];
    }
  }
}

void Image::setptr() {
    ptr = new Pixel*[height];
    for(int i = 0; i < height; i++) {
        ptr[i] = new Pixel[width];
    }
}

int Image::get_width() const{
  return width;
}

int Image::get_height() const{
  return height;
}

Color Image::get_Color_x_y(int x, int y) const{
  return ptr[x][y].get_color();
}

Pixel** Image::get_ptr() const{
  return ptr;
}

Pixel& Image::get_pixel(int x,int y){
  return ptr[x][y];
}

void Image::setColor(int i, int j, int r, int g, int b) {
  ptr[i][j].set_color(r, g, b);
}

Image& Image::operator=(Image const &other) {
  height = other.height;
  width = other.width;
  for(int i=0;i<height;i++) {
    for(int j=0;j<width;j++) {
      ptr[i][j] = other.ptr[i][j];
    }
  }
  return *(this);
}

Image operator+(Image const &image1, Image const &image2) {
  if(image1.get_width() == image2.get_width() && image1.get_height() == image2.get_height()) {
    int w1 = image1.get_width();
    int h1 = image1.get_height();
    Image result(w1, h1);
    for(int i=0;i<result.get_height();i++) {
      for(int j=0;j<result.get_width();j++) {
        int new_r = image1.get_Color_x_y(i, j).get_red() + image2.get_Color_x_y(i, j).get_red();
        int new_g = image1.get_Color_x_y(i, j).get_green() + image2.get_Color_x_y(i, j).get_green();
        int new_b = image1.get_Color_x_y(i, j).get_blue() + image2.get_Color_x_y(i, j).get_blue();
        result.setColor(i, j, new_r, new_g, new_b);
      }
    }
    return result;
  }
}

Image operator*(float const &f, Image const &image) {
  Image tmp_image(image.get_width(), image.get_height());
  for(int i=0;i<image.get_height();i++) {
    for(int j=0;j<image.get_width();j++) {
      int new_red = f*(image.ptr[i][j].get_color().get_red());
      int new_green = f*(image.ptr[i][j].get_color().get_green());
      int new_blue = f*(image.ptr[i][j].get_color().get_blue());
      tmp_image.setColor(i, j, new_red, new_green, new_blue);
    }
  }
  return tmp_image;
}

istream& operator>>(istream &is, Image &image) {
  is >> image.width >> image.height >> image.max_pixel;
  image.setptr();
  for(int i=0;i<image.height;i++) {
    for(int j=0;j<image.width;j++) {
      int r, g, b;
      is>>r>>g>>b;
      image.ptr[i][j].set_color(r, g, b);
    //   image.ptr[i][j].set_x(j);
    //   image.ptr[i][j].set_y(i);
    }
  }
  return is;
}

ostream& operator<<(ostream &os,const Image &image) {
  os << "P3" << endl;
  os << image.width << " " << image.height << endl;
  os << "255" << endl;
  Pixel **p = image.get_ptr();
  for(int i=0;i<image.height;i++) {
    for(int j=0;j<image.width;j++) {
      os<<p[i][j]<<" ";
    }
    os<<endl;
  }
  return os;
}
Image Image::reflectionAboutY(){
  Image answer = *this;
  for(int i = 0 ; i < answer.height ; i++){
    int start=0,end=width-1;
    while(start < end)
    {
      Pixel temp = answer.ptr[i][start];
      answer.ptr[i][start] = answer.ptr[i][end];
      answer.ptr[i][end] = temp;
      start++;
      end--;
    }
  }
  return answer;
}

Image Image::reflectionAboutX(){
  Image answer = *this;
  for(int i = 0 ; i < answer.width ; i++){
    int start=0,end=height-1;
    while(start < end)
    {
      Pixel temp = answer.ptr[start][i];
      answer.ptr[start][i] = answer.ptr[end][i];
      answer.ptr[end][i] = temp;
      start++;
      end--;
    }
  }
  return answer;
}

Image Image::reflectionAboutXY(){
  reflectionAboutX();
  reflectionAboutY();
}

Image & Image::binarize(Image & img,int t){
  int h = img.get_height();
  int w = img.get_width();
  Image * binary = new Image(w,h);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
    {
      Pixel * temp = new Pixel();
      if((img.get_ptr()[i][j].get_color().get_red()+img.get_ptr()[i][j].get_color().get_green()+img.get_ptr()[i][j].get_color().get_blue())/3<t)
      {
        (*temp).set_color(0,0,0);
      }
      else
      {
        (*temp).set_color(255,255,255);
      }
      (*binary).setColor(i,j,(*temp).get_color().get_red(),(*temp).get_color().get_green(),(*temp).get_color().get_blue());
    }
  }
  return *binary;
}
