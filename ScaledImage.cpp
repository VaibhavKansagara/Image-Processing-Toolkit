#include <iostream>
#include "ScaledImage.h"
using namespace std;
ScaledImage::ScaledImage() {

}

ScaledImage::ScaledImage(int w , int h , Image p)
{
    width = w;
    height = h;
    ptr = new Pixel*[height];
    for(int i=0;i<height;i++) {
      ptr[i] = new Pixel[width];
    }
    Color c(255 , 255 ,255);
    for(int i=0;i<height;i++) {
      for(int j=0;j<width;j++) {
        ptr[i][j].set_color(c);
      }
    }
    firstquad(p);
    thirdquad(p);
    fourthquad(p);
    secondquad(p);
    create_white(p);
}

ScaledImage::~ScaledImage() {

}

ScaledImage::ScaledImage(const ScaledImage& other):
  Image(other.get_width(), other.get_height()) {
    for(int i=0;i<height;i++) {
      for(int j=0;j<width;j++) {
        ptr[i][j] = other.ptr[i][j];
      }
    }
}
void ScaledImage::firstquad(Image a){
    for (int i = 0; i < a.get_height()/2; i++) {
        for (int j = 0; j < a.get_width()/2; j++) {
            ptr[i][j].set_color(a.get_Color_x_y(2*i , 2*j));
        }
    }
}
void ScaledImage::thirdquad(Image a){
    for (int i = 0; i < a.get_width()/2; i++) {
        for (int j = 0; j < a.get_height()/2; j++) {
            ptr[a.get_height() - j - 1][a.get_width() - i - 1].set_color(a.get_Color_x_y(2*j , 2*i));
        }
    }
}
void ScaledImage::fourthquad(Image a){
    for (int i = 0; i < a.get_width()/2; i++) {
        for (int j = 0; j < a.get_height()/2; j++) {
            ptr[a.get_height() - j - 1][i].set_color(a.get_Color_x_y(2*j , 2*i));
        }
    }
}
void ScaledImage::secondquad(Image a){
    for (int i = 0; i < a.get_width()/2; i++) {
        for (int j = 0; j < a.get_height()/2; j++) {
            ptr[j][a.get_width() - i - 1].set_color(a.get_Color_x_y(2*j , 2*i));
        }
    }
}
void ScaledImage::create_white(Image a){
    Color c(255,255,255);
    for (int i = 0; i < a.get_width()/4; i++) {
        for (int j = 0; j < a.get_height(); j++) {
            ptr[j][i].set_color(c);
        }
    }
    for (int i = 0; i < a.get_width(); i++) {
        for (int j = 0; j < a.get_height()/4; j++) {
            ptr[j][i].set_color(c);
        }
    }
    for (int i = 3*a.get_width()/4; i < a.get_width(); i++) {
        for (int j = 0; j < a.get_height(); j++) {
            ptr[j][i].set_color(c);
        }
    }
    for (int i = 0; i < a.get_width(); i++) {
        for (int j = 3*a.get_height()/4; j < a.get_height(); j++) {
            ptr[j][i].set_color(c);
        }
    }
}
