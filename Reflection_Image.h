#ifndef Reflection_Image_H_
#define Reflection_Image_H_
#include "CompositeImage.h"
#include "Image.h"
#include<vector>
class Reflection_Image : public Image {
	public:
	Reflection_Image();
	Reflection_Image(Image a);
	~Reflection_Image();
	void createImage(Image a);
};
#endif
