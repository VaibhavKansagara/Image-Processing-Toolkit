#include"Neighbour.h"
#include<vector>
#include"Pixel.h"
#include<iostream>
using namespace std;
Neighbour::Neighbour(int width,int height){
	SS = new float*[height];
  for(int i=0;i<height;i++) {
    SS[i] = new float[width]();
  }
}
Neighbour::~Neighbour(){

}
//
//Neighbour::Neighbour(Image a){
//	p=a;
//}
float Neighbour::maxima(float a,float b,float c){
	float max=a;
	if(max<b){
		max=b;
	}
	 if(max<c){
		max=c;
	}
	return max;
}
float Neighbour::minima(float a,float b,float c){
	float min=a;
	if(min>b){
		min=b;
	}
	 if(min>c){
		min=c;
	}
	return min;
}
float** Neighbour::RGB_to_HSV(Image a){
	// float HSV[a.get_height()][a.get_width()][3];
	//cout<<"hkh"<<endl;
	SS = new float*[a.get_height()];
	  for(int i=0;i<a.get_height();i++) {
    	SS[i] = new float[a.get_width()];
  }
	//[a.get_height()][a.get_width()];
	float H,S,V,max,min,delta;
	for(int i=0;i<a.get_height();i++){
		for(int j=0;j<a.get_width();j++){
			max=maxima((float)a.get_Color_x_y(i,j).get_red()/255,(float)a.get_Color_x_y(i,j).get_green()/255,(float)a.get_Color_x_y(i,j).get_blue()/255);
			min=minima((float)a.get_Color_x_y(i,j).get_red()/255,(float)a.get_Color_x_y(i,j).get_green()/255,(float)a.get_Color_x_y(i,j).get_blue()/255);
			delta=max-min;
			V=max;
			if(max==0){
				S=0;
			}
			else{
				S=delta/max;
			}
//			if(delta==0){
//				H=0;
//			}
//			if(max==(float)a.get_Color_x_y(i,j).get_red()/255){
//				H=60*((((a.get_Color_x_y(i,j).get_green()/255)-(a.get_Color_x_y(i,j).get_blue()/255))/(int)delta)%6);
//			}
//			if(max==(float)a.get_Color_x_y(i,j).get_green()/255){
//				H=60*((((float)a.get_Color_x_y(i,j).get_blue()/255-(float)a.get_Color_x_y(i,j).get_red()/255)/delta)+2);
//			}
//			if(max==a.get_Color_x_y(i,j).get_blue()/255){
//				H=60*((((float)a.get_Color_x_y(i,j).get_red()/255-(float)a.get_Color_x_y(i,j).get_green()/255)/delta)+4);
//			}
//			HSV[i][j][0]=H;
//			HSV[i][j][1]=S;
//			HSV[i][j][2]=V;
			SS[i][j]=S;
		}
	}
	return SS;
}
bool Neighbour::Is_valid(int x,int y,Image a ){
	if(x>0 &&x>a.get_height()){
		if(y>0 && y>a.get_width()){
			return true;
		}
		return false;
	}
	return false;


}
bool Neighbour::Is_max(Image p,int y,int x ){
	  for(int i=-1;i<=1;i++) {
    for(int j=-1;j<=1;j++) {
      if(!(i==0 && j==0)){
        if(Is_valid(x+j,y+i,p)) {
          if((SS[y+i][x+j])>=(SS[y][x]))
            return false;
          }
        }
      }
    }
  return true;
}

vector<Pixel> Neighbour::maxneighbour(Image p){
	//cout<<"maxn"<<endl;
	RGB_to_HSV(p);
	vector<Pixel> L;
//cout<<"maxn"<<endl;

	for(int i = 0;i < p.get_height();i++){
		for(int j = 0;j < p.get_width();j++){
			if(Is_max( p,i,j)){
				L.push_back(p.get_ptr()[i][j]);
			}

			//count=0;
//		//	if(
//			if(i-1>=0){
//				if(SS[i][j]>SS[i-1][j]){
//					//max = SS[i-1][j];
//					//i_tracer = i-1;
//					//j_tracer = j;
//				}
//			}
//			if(i+1<p.get_height()){
//				if(SS[i+1][j]>max){
//					max = SS[i+1][j];
//					i_tracer = i+1;
//					j_tracer = j;
//				}
//			}
//			if(j-1>=0){
//				if(SS[i][j-1]>max){
//					max = SS[i][j-1];
//					i_tracer = i;
//					j_tracer = j-1;
//				}
//			}
//			if(j+1<p.get_width()){
//				if(SS[i][j+1]>max){
//					max = SS[i][j+1];
//					i_tracer = i;
//					j_tracer = j+1;
//				}
//			}
//			if((i-1>=0)&&(j-1>=0)){
//				if(SS[i-1][j-1]>max){
//					max = SS[i-1][j-1];
//					i_tracer = i-1;
//					j_tracer = j-1;
//				}
//			}
//			if((i-1>=0)&&(j+1<p.get_width())){
//				if(SS[i-1][j+1]>max){
//					max = SS[i-1][j+1];
//					i_tracer = i-1;
//					j_tracer = j+1;
//				}
//			}
//			if((i+1<p.get_height())&&(j-1>=0)){
//				if(SS[i+1][j-1]>max){
//					max = SS[i+1][j-1];
//					i_tracer = i+1;
//					j_tracer = j-1;
//				}
//			}
//			if((i+1<p.get_height())&&(j+1<p.get_width())){
//				if(SS[i+1][j+1]>max){
//					max = SS[i+1][j+1];
//					i_tracer = i+1;
//					j_tracer = j+1;
//				}
//			}
			//L.push_back(p.get_pixel(i_tracer,j_tracer));
		}
	}
	return L;
}


Image Neighbour::maxImage(vector<Pixel> L,Image p){
//	cout<<"_1";
	Image I(p.get_width(),p.get_height());
	for(int i=0;i<p.get_height();i++){
		for(int j=0;j<p.get_width();j++){
			I.setColor(i,j,0,0,0);
		}
	}
	int x,y;
//	for(int i=0;i<L.size();i++){
//		cout<<L[i].get_x()<<" "<<L[i].get_y()<<endl;
//	}
//	cout<<endl;
	for(int i=0;i<L.size();i++){
		Color c(255,255,255);
		x=L[i].get_x();
		y=L[i].get_y();
		for(int k=-2;k<3;k++){
			//cout<<"hi"<<endl;
			for(int l=-2;l<3;l++){
				if(x+k>=0 && x+k<I.get_height() && y+l>=0 && y+l<I.get_width()){
//					cout<<"hi"<<endl;
					I.setColor(x+k,y+l,255,255,255);
//					cout<<I.get_Color_x_y(y+l,x+k)<<" "<<y+l<<" "<<x+k<<endl;
			}
		}
	}

	}
//	cout<<I;
	return I;

}


Image Neighbour::Gaussian(vector<Pixel> L,Image img){
	    int g[5][5] = {{1,4,7,4,1},
                   {4,16,26,16,4},
                 {7,26,41,26,7},{4,16,26,16,4},{1,4,7,4,1}};
    for(int i=0;i<L.size();i++){
    	//cout<<"gaussian"
      int x = L[i].get_x();
      int y = L[i].get_y();
      int x1,x2,y1,y2;
      x1 = ((x-2)<0?0:(x-2));
      x2 = ((x-2)<0?(2-x):0);
      y1 = ((y-2)<0?0:(y-2));
      y2 = ((y-2)<0?(2-y):0);
      for(;x1<=x+2 && x1<img.get_height();x1++,x2++){
        int a_y = y1;
        int a_y1 = y2;
        for(;a_y<=y+2 && a_y<img.get_width();a_y++,a_y1++){
          int temp = int((255*g[x2][a_y1])/273);
          if(img.get_Color_x_y(x1,a_y1).get_red()!=255){
            temp+=img.get_Color_x_y(x1,a_y1).get_red();
            temp/=2;
          }
          img.setColor(x1,a_y,temp,temp,temp);
        }
      }
    }
    Image temp = img;

    return temp;

  }
