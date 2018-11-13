#include "Image.h"
#include "histogram1.h"
#include "CompositeImage.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

histogram1::histogram1(){

	}

histogram1::histogram1(Image im){
	for(int j=0;j<im.get_height();j++){
		for(int k=0;k<im.get_width();k++){
			int l=mean(im.get_pixel(j,k));
			values.push_back(l);
			index1.push_back(j);
			index2.push_back(k);
			}
		}
		for(int a=0;a<values.size();a++){
			pair<map<int,int>::iterator,bool> ret;
  			ret = index.insert(pair<int,int>(values[a],1) );
  			if (ret.second==false) {
   				(ret.first->second)++;
  			}
		}
		for(int a=0;a<256;a++){
			arr[a]=0;
		}
		for (it=index.begin();it!=index.end(); ++it){
			arr[it->first]=it->second;
		}
			//for(int a=0;a<256;a++){
			//cout<<a<<"-"<<arr[a]<<endl;
			//}
		final.push_back(0);
		it2 = 0;
		while((it2+1)<256){
			it2++;
			if(arr[it2-1]>arr[it2] && arr[it2]<arr[it2+1]){
				final.push_back(it2);
			}

		}
		//cout<<final.size()<<endl;
		if(final.size()==1){
			Image ref(im.get_width(),im.get_height());
			ref=im.reflectionAboutY();
			CompositeImage cim(ref,im,0.4);
			float alpha=0.4;
			ofstream outfile;
			outfile.open("Images/output_task4_imt2016109.ppm");
			outfile<<cim;
			outfile.close();

		}
		else{
			Image c(im.get_width(),im.get_height());
		for(int j=0;j<im.get_height();j++){
			for(int k=0;k<im.get_width();k++){
					c.get_pixel(j,k).set_color(0,0,0);
			}
		}
		c=writefile(values,index1,index2,final,im.get_height(),im.get_width());
		CompositeImage cim(c,im,0.4);
		float alpha=0.4;
		ofstream outfile;
		outfile.open("Images/output_task4_imt2016109.ppm");
		outfile<<cim;
		outfile.close();
		}
	}
	Image histogram1:: writefile(vector<int> list1,vector<int> list2,vector<int> list3,vector<int> thres,int h,int w){
		Image image(w,h);
		vector<int> list4;
		for(int h=0;h<thres.size()-1;h++){
			list4=findpixel(list1,thres[h],thres[h+1]);
			for(int m=0;m<list4.size();m++){
				if(h==0){
					image.get_pixel(list2[list4[m]],list3[list4[m]]).set_color(255,0,0);
				}
				else if(h==1){
					image.get_pixel(list2[list4[m]],list3[list4[m]]).set_color(0,255,0);
				}
				else if(h==2){
					image.get_pixel(list2[list4[m]],list3[list4[m]]).set_color(0,0,255);
				}
				else if(h==3){
					image.get_pixel(list2[list4[m]],list3[list4[m]]).set_color(255,255,0);
				}
				else if(h==4){
					image.get_pixel(list2[list4[m]],list3[list4[m]]).set_color(255,0,255);
				}
				else if(h==5){
					image.get_pixel(list2[list4[m]],list3[list4[m]]).set_color(0,255,255);
				}

			}
		}
		return image;
	}
	int histogram1:: mean(Pixel& p){
		return (p.get_color().get_blue()+p.get_color().get_green()+p.get_color().get_red())/3;
	}
	vector<int> histogram1:: findpixel(vector<int> lis,int num,int num1){
		 vector<int> li;
		for(int i=0;i<lis.size();i++){
			if(num<lis[i] && lis[i]<=num1){
				li.push_back(i);
			}
		}
		return li;
	}
	int histogram1::findkey(map<int,int> map1,int ind){
		map<int,int> ::iterator i=map1.begin();
		int num=0;
		for(i=map1.begin();i!=map1.end();++i){
			num++;
			if(num==ind){
				return i->first;
			}
		}
	}
	histogram1::~histogram1(){

	}

// int main(int argc,char* argv[]){
//
// 	ifstream myfile;
// 	myfile.open(argv[1]);
// 	Image i;
// 	myfile>>i;
// 	histogram1 h(i);
// 	myfile.close();
// }
