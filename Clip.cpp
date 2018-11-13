#include<bits/stdc++.h>
#include "Clip.h"
using namespace std;

Clip::Clip(){}

Clip::Clip(int w,int h):Image(w,h){
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			ptr[i][j].set_color(255,255,255);
		}
	}
}
//methods
void Clip::combineimage(Image& input,TempImage& tempimage){
	Color c(255,255,255);
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			if(tempimage.get_Color_x_y(i,j)==c){
				ptr[i][j]=input.get_ptr()[i][j];
			}
		}
	}
}

Clip::~Clip(){}
