#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Histogram.h"
#include "Image.h"
#include "Color.h"
#include "Pixel.h"

using namespace std;

Histogram::Histogram(){}

Histogram::~Histogram(){}

Histogram::Histogram(Image i):brightness(i.get_height(), vector <int> (i.get_width()))
{
  int h = i.get_height();
  int w = i.get_width();
  for(int k = 0; k < h; k++)
  {
    for(int j = 0; j < w; j++)
    {
      Color c;
      c = i.get_ptr()[k][j].get_color();
      brightness[k][j] = (c.get_red() + c.get_blue() + c.get_green())/3;
    }
  }
  vector <int> histogram(256, 0);
  for(int i = 0; i < h; i++)
  {
    for(int j = 0; j < w; j++)
    {
      histogram[brightness[i][j]]++;
    }
  }

  for(int i = 1; i < 255; i++)
  {
    if(histogram[i] < histogram[i-1] && histogram[i+1] > histogram[i])
      threshold.push_back(i);
  }

}

int Histogram::getThreshold()
{
  return threshold[threshold.size()/2];
}

vector< vector<int> > Histogram::getBrightness()
{
  return brightness;
}
