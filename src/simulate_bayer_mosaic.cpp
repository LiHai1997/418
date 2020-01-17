#include <cmath>
#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int h = 0; h < height; h++) {
	  for (int w = 0; w < width; w++) {
		  if (std::fmod(h,2)==0)
		  {
			  if (std::fmod(w, 2) == 0)
			  {
				  // take G channel
				  bayer[h * width + w] = rgb[h * width * 3 + w * 3 + 1];
			  }
			  else
			  {
				  // take B channel
				  bayer[h * width + w] = rgb[h * width * 3 + w * 3 + 2];
			  }
		  }
		  else
		  {
			  if (std::fmod(w, 2) == 0)
			  {
				  // take R channel
				  bayer[h * width + w] = rgb[h * width * 3 + w * 3];
			  }
			  else
			  {
				  // take G channel
				  bayer[h * width + w] = rgb[h * width * 3 + w * 3 + 1];
			  }
		  }
	  }
  }
  ////////////////////////////////////////////////////////////////////////////
}
