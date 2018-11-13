#include "Reflection_Image.h"
#include<vector>
#include"Pixel.h"

Reflection_Image::Reflection_Image() {

}
Reflection_Image::~Reflection_Image() {

}

Reflection_Image::Reflection_Image(Image a) : Image(a.get_width(),a.get_height()) {
	// cout << "a wid : " << a.get_width() << " a hei : " << a.get_height() << endl;
	// cout << "r wid : " << get_width() << " r hei : " << get_height() << endl;
	for(int i=0;i<a.get_height();i++){
		for(int j=0;j<a.get_width();j++){
			int r,g,b;
			r=a.get_Color_x_y(a.get_height()-i-1,j).get_red();
			g=a.get_Color_x_y(a.get_height()-i-1,j).get_green();
			b=a.get_Color_x_y(a.get_height()-i-1,j).get_blue();
			setColor(i,j,r,g,b);
		}
	}
}
void Reflection_Image::createImage(Image a){
	for(int i=0;i<a.get_height();i++){
		for(int j=0;j<a.get_width();j++){
			setColor(i,j,a.get_Color_x_y(a.get_height()-i-1,j).get_red(),a.get_Color_x_y(a.get_height()-i-1,j).get_green(),a.get_Color_x_y(a.get_height()-i-1,j).get_blue());
		}
	}

}
