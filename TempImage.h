#include<bits/stdc++.h>
#include "Image.h"

#ifndef TempImage_H_
#define TempImage_H_

using namespace std;

class TempImage:public Image{
private:
	int centre_x,centre_y;
	int radius;
public:
	TempImage(int w,int h);
	bool checkwithinradius(int x,int y,int xcent,int ycent);

	void generateimage();

	void addcircle(int x,int y);

	void addcircles();
};

#endif
