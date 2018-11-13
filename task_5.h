#ifndef task_5_H_
#define task_5_H_

#include <bits/stdc++.h>
#include "CompositeImage.h"
#include "Color.h"
#include "Image.h"
#include "Pixel.h"

using namespace std;

class task_5{
private:
   int T1,T2;
   int v[256]={0};
   vector<int> min;
   int h,w;
public:
   task_5();
   ~task_5();
   task_5(Image& I);
   void find_min();
   void set_t();
   void create(Image& I);
   };

#endif
