#include<bits/stdc++.h>
#include "Image.h"
#include "TempImage.h"

#ifndef Clip_H_
#define Clip_H_

using namespace std;

class Clip:public Image{
public:
	Clip();
	Clip(int w,int h);
	~Clip();
	//methods
	void combineimage(Image& input,TempImage& tempimage);
};

#endif
