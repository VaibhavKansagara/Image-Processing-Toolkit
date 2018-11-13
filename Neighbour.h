
#ifndef Neighbour_H_
#define Neighbour_H_
#include "Image.h"
#include<vector>
using namespace std;
class Neighbour{
	public:
		Neighbour(int width,int height);
		Neighbour(Image a);
		~Neighbour();

		float** RGB_to_HSV(Image a);
		float maxima(float a,float b,float c);
		float minima(float a,float b,float c);
		vector<Pixel> maxneighbour(Image p);
		Image maxImage(vector<Pixel> L,Image p);
		Image Gaussian(vector<Pixel> L,Image img);
		bool Is_valid(int x,int y,Image a);
		bool Is_max(Image p,int x,int y);

	private:
		float** SS;

};
#endif
