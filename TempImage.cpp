#include<bits/stdc++.h>
#include "TempImage.h"
using namespace std;


TempImage::TempImage(int w,int h):Image(w,h){
	centre_x=floor(width*0.5);
	centre_y=floor(height*0.5);
	radius=min(floor(width*0.125), floor(height*0.125));
}
bool TempImage::checkwithinradius(int x,int y,int xcent,int ycent){
	int distance=sqrt(pow(xcent-x,2)+pow(ycent-y,2));
	if(distance>radius)
		return false;
	else
		return true;
}

void TempImage::generateimage(){
	Pixel p;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			p.set_x(j);
			p.set_y(i);
			if(checkwithinradius(j,i,centre_x,centre_y)){
				p.set_color(255,255,255);
			}
			else{
				p.set_color(0,0,0);
			}
			ptr[i][j]=p;
		}
	}
}

void TempImage::addcircle(int x,int y){
	Color c(0,0,0); //indicates black color
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			if(checkwithinradius(j,i,x,y)){
				Color temp=ptr[i][j].get_color();
				if(temp==c)
					ptr[i][j].set_color(255,255,255);
			}
		}
	}
}

void TempImage::addcircles(){
	int temp_x=(0+centre_x)/2;
	int temp_y=(0+centre_y)/2;
	addcircle(temp_x,temp_y);
	temp_x=(width-1+centre_x)/2;
	temp_y=(0+centre_y)/2;
	addcircle(temp_x,temp_y);
	temp_x=(0+centre_x)/2;
	temp_y=(height-1+centre_y)/2;
	addcircle(temp_x,temp_y);
	temp_x=(width-1+centre_x)/2;
	temp_y=(height-1+centre_y)/2;
	addcircle(temp_x,temp_y);
}




