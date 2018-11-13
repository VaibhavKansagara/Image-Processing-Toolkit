#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include<vector>
#include<algorithm>
#include<fstream>
#include<ctime>
#include "task_5.h"
#include "ScaledImage.h"
#include "Image.h"
#include "TempImage.h"
#include "Clip.h"
#include "Stencil.h"
#include "CompositeImage.h"
#include "Color.h"
#include "Pixel.h"
#include "ConnectedComponent.h"
#include "Histogram.h"
#include "histogram1.h"
#include "Reflection_Image.h"
#include "Gaussian.h"


using namespace std;
void IMT2016016(char const * fname){
  string s;
  int w,h;
  ifstream file(fname);
  file >> s;
  file >> w >> h;
  int maxVal;
  file >> maxVal;
  Image img(w,h);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int x,y,z;
      file >> x >> y >> z;
      Color * tempCol = new Color(x,y,z);
      Pixel * tempPix = new Pixel(i,j,*tempCol);
      (img).setColor(i,j,(*tempPix).get_color().get_red(),(*tempPix).get_color().get_green(),(*tempPix).get_color().get_blue());
    }
  }
  Image noise(w,h);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int x,y,z;
      x = rand()%256;
      y = rand()%256;
      z = rand()%256;
      Color * tempCol = new Color(x,y,z);
      Pixel * tempPix = new Pixel(i,j,*tempCol);
            (noise).setColor(i,j,(*tempPix).get_color().get_red(),(*tempPix).get_color().get_green(),(*tempPix).get_color().get_blue());

    }
  }
  CompositeImage compo(img,noise,0.5);
  Histogram histo(compo);
  // cout << histo.getThreshold();
  ConnectedComponent * newImg = new ConnectedComponent((compo).binarize(compo,histo.getThreshold()));
  ofstream outFile("Images/output_task8_imt2016016.ppm");
  outFile << s;
  outFile << '\n';
  outFile << w << " " << h << '\n';
  outFile << maxVal << '\n';
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      outFile << (*newImg).get_ptr()[i][j];
    }
    outFile << '\n';
  }
}

void IMT2016044(char const * fname){
    ifstream file(fname);

    Image i1;
    string str;
    file>>str;
    file>>i1;
    file.close();

    // cout << "wid : " << i1.get_width() << " hei : " << i1.get_height() << endl;
    Reflection_Image r1=Reflection_Image(i1);

    // ofstream file1("X_reflected.ppm");

    // file1<<r1;

    // file1.close();
    Gaussian *r=new Gaussian(r1);
    // ofstream file2("gaussian.ppm");
    // file2<<*r;



    CompositeImage S=CompositeImage(r1,*r,0.75);
    ofstream file4("Images/output_task3_imt2016044.ppm");
    file4<<S;

}


void IMT2016089(char const * fname){
    ifstream f1,f2;
    f1.open(fname);
    string _;
    f1>>_;
    Image p;
    ofstream ans("Images/output_task7_imt2016089.ppm");
    f1 >> p;
    ScaledImage x(p.get_width(), p.get_height(), p);
    ans << x;
}



void IMT2016068(char const * fname){
    ifstream f_ptr(fname);
    string _;
    f_ptr>>_;
    Image i;
    f_ptr >> i;

    TempImage tempimage(i.get_width(),i.get_height());
    tempimage.generateimage();
    tempimage.addcircles();

    // ofstream o_ptr("TempImage.ppm");
    // o_ptr << tempimage;

    Clip clip(i.get_width(),i.get_height());
    clip.combineimage(i,tempimage);
    // ofstream h_ptr("Clip.ppm");
    // h_ptr << clip;

    //this is the new part-start
    Image ref=i.reflectionAboutY();
    Stencil stencil(ref,ref.get_width(),ref.get_height());
    stencil.combineimage(tempimage);
    //uptil here.

    // ofstream k_ptr("Stencil.ppm");
    // k_ptr << stencil;

    CompositeImage compos(clip,stencil,0.5);
    ofstream m_ptr("Images/output_task1_imt2016068.ppm");
    m_ptr << compos;
}


void IMT2016128(char const * fname){
    int img_width,img_height,waste;
    char* p=new char;
    Image yo;
    ifstream read1(fname);
    read1>>p;
    read1>>yo;
    read1.close();

    task_5 tk(yo);
    tk.find_min();
    tk.set_t();
    tk.create(yo);
}
void IMT2016109(char const * fname){
    ifstream myfile;
    myfile.open(fname);
    string _;
    myfile>>_;
    Image i;
    myfile>>i;
    histogram1 h(i);
    myfile.close();
}



int main(int argc, char *argv[]) {

  if (argc < 2) {
    cout << "Wrong command line arguements" << endl;
    return 0;
  }
  cout << "Our group task ID combination is: 1,3,4,5,7,8" << endl << endl;

  // modify taskList to execute tasks selectively
  int taskList[8] = {1,3,4,5,7,8};
  int taskCount;
  if (argc == 2) {
    taskCount = 6;
  } else {
    taskCount = argc - 2;
    cout << "Executing tasks: ";
    for (int i = 0; i < taskCount; i++) {
        taskList[i] = atoi(argv[i + 2]);
      if (i)
        cout << ", " << taskList[i];
      else
        cout << taskList[i];
    }
    cout << endl << endl;
  }

  // Add your task function here
  void (*taskPtrs[8])(char const *) = {IMT2016068, NULL, IMT2016044, IMT2016109,IMT2016128, NULL,IMT2016089, IMT2016016};
  // void (*taskPtrs[8])(char const *) = {NULL, NULL, NULL, NULL,NULL, NULL,IMT2016089, NULL};
  for (int i = 0; i < taskCount; i++) {
    if (taskPtrs[taskList[i] - 1])
      taskPtrs[taskList[i] - 1](argv[1]);
    else {
      cout << "Task " << taskList[i] << " not found!" << endl << endl;
    }
  }
}
