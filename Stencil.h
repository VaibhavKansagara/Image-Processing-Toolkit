#include<bits/stdc++.h>
#include "Image.h"
#include "TempImage.h"

#ifndef Stencil_H_
#define Stencil_H_

using namespace std;

class Stencil:public Image{
public:
	Stencil();
	Stencil(Image& input,int w,int h);
	~Stencil();

	void combineimage(TempImage& tempimage);

};

#endif