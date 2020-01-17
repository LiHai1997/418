#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int i = 0; i < gray.size(); i++) {
	  // more precise formula from stackoverflow
	  gray[i] = (int)((double)rgb[i * 3] * 0.2126 + (double)rgb[i * 3 + 1] * 0.7152 + (double)rgb[i * 3 + 2] * 0.0722);
  }
  ////////////////////////////////////////////////////////////////////////////
}


