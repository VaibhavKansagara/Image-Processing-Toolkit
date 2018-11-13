#ifndef ScaledImage_H_
#define ScaledImage_H_
#include "Image.h"

class ScaledImage: public Image {
  public:
    ScaledImage();
    ScaledImage(int w,int h,Image a);
    ~ScaledImage();
    ScaledImage(const ScaledImage& other);
    void firstquad(Image a);
    void secondquad(Image a);
    void thirdquad(Image a);
    void fourthquad(Image a);
    void create_white(Image a);
};

#endif
