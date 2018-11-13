#ifndef histogram11_H_
#define histogram11_H_

#include "Image.h"
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

class histogram1{
	public:
		histogram1();
		histogram1(Image i);
		~histogram1();
		int mean(Pixel& p);
		int findkey(map<int,int> map1,int ind);
		vector<int> findpixel(vector<int> list2,int num,int num2);
		int check(int n,vector<int> list1,vector<int> list2,vector<int> list3,vector<int> list4,vector<int> list5,vector<int> list6);
		Image writefile(vector<int> list1,vector<int> list2,vector<int> list3,vector<int> thres,int h,int w);
	private:
		private:
		vector<int> values;
		vector<int> count;
		vector<int> final;
		vector<int> index1;
		vector<int> index2;
		int arr[256];
		map <int,int> index;
		map <int,int>::iterator it;
		int it2;
		int  it3;
		int prev,val;
		//it3;
		//it2=index.begin();//it3=index.begin();
		//global int count=0,count2=0,count3=0;
		int count2,count3;
};


#endif
