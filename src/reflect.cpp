#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int h = 0; h < height;h++) {
	  for (int w = 0; w < width; w++) {
		  if (num_channels == 3) {
			  // handle rgb
			  for (int i = 0; i < 3; i++) {
				  reflected[h * width * num_channels + w * num_channels + i] = input[(h + 1) * width * num_channels - w * num_channels - (3-i)];
			  }
		  }
		  else {
			  // handle grayscale
			  reflected[h * width + w] = input[(h + 1) * width - w - 1];
		  }
	  }
  }
  ////////////////////////////////////////////////////////////////////////////
}
