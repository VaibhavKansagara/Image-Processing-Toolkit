#include "task_5.h"
#include "CompositeImage.h"
#include "Color.h"
#include "Image.h"
#include "Pixel.h"
#include <bits/stdc++.h>

task_5 :: task_5(){}

task_5 :: ~task_5(){}

task_5 :: task_5(Image& I){
   int c,max_count=0;
   Color temp;
   w=I.get_width();
   h=I.get_height();
   for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
         temp=I.get_Color_x_y(i,j);
         c=(temp.get_red()+temp.get_blue()+temp.get_green())/3;
         v[c]+=1;
      }
   }
}

void task_5 :: find_min(){
   for(int i=5;i<251;i++){
     if(v[i]<v[i-1] && v[i]<v[i-2] &&v[i]<v[i-3]
         &&v[i]<v[i-4] &&v[i]<v[i-5]&& v[i]<v[i+1]
         &&v[i]<v[i+2] && v[i]<v[i+3] &&v[i]<v[i+4]
         &&v[i]<v[i+5] && v[i]!=0)
            min.push_back(i);
   }
}

void task_5 :: set_t(){
   T1=w*h;
   T2=w*h;
   if(min.size()<2) T1=T2=-1;
   else{
      for(int i=0;i<min.size();i++){
         if(v[min[i]]<T1){
            T2=T1;
            T1=min[i];
         }
         else if (v[min[i]] < T2 && v[min[i]] != T1)  T2 = min[i];
      }
   }
}

void task_5 :: create(Image& I){
   Color temp;
   int c;
   Image C(I.get_width(),I.get_height());
   Image D(I.get_width(),I.get_height());
   if(T1==-1 && T2==-1){
      CompositeImage compos(I.reflectionAboutY(),I.reflectionAboutX(),0.2);
      ofstream write2("Images/output_task5_imt2016128.ppm");
      write2 << compos;
      write2.close();
   }
   else{
      for(int i=0;i<I.get_height();i++){
         for(int j=0;j<I.get_width();j++){
            temp=I.get_Color_x_y(i,j);
            c=(temp.get_red()+temp.get_blue()+temp.get_green())/3;
            if(T1!=I.get_width()*I.get_height()){
               if(c<T1) C.setColor(i,j,0,0,255);
               else C.setColor(i,j,255,255,255);
            }
            if(T2!=I.get_width()*I.get_height()){
               if(c<T2) D.setColor(i,j,255,255,0);
               else D.setColor(i,j,255,255,255);
            }
         }
      }
      CompositeImage compos(C,D,0.2);
      ofstream write2("Images/output_task5_imt2016128.ppm");
      write2 << compos;
      write2.close();
   }
}
