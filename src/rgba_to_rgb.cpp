#include "rgba_to_rgb.h"
#include <cmath>

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  int count = 0;
  for (int i = 0; i < rgba.size(); i++) {
	  if (std::fmod(i + 1, 4) != 0) {
		  rgb[count] = rgba[i];
		  count++;
	  }
  }
  ////////////////////////////////////////////////////////////////////////////
}
