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
  int length = gray.size();
  for (int i = 0; i < length; i++) {
	  // more precise formula from stackoverflow
	  gray[i] = (int)( (float)rgb[i * 3] * 0.2126 + (float)rgb[i * 3 + 1] * 0.7152 + (float)rgb[i * 3 + 2] * 0.0722 );
  }
  ////////////////////////////////////////////////////////////////////////////
}


