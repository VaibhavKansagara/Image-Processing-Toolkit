#include <iostream>
#include "Image.h"
#include "CompositeImage.h"

using namespace std;

CompositeImage::CompositeImage():
Image()
{

}
CompositeImage::CompositeImage(const Image &A, const Image &B, float alpha):
Image((1-alpha)*A + (alpha)*B)
{
	
}
CompositeImage::CompositeImage(const CompositeImage &c):
Image(c)
{

}
CompositeImage::~CompositeImage(){

}
