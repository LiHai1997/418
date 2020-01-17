#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int h = 0; h < height;h++) {
	  for (int w = 0; w < width; w++) {
		  if (num_channels == 3) {
			  for (int i = 0; i < 3; i++) {
				  rotated[h * height * num_channels + w * num_channels + i] = input[(w + 1) * width * num_channels - h * num_channels - (3 - i)];
			  }
		  }
		  else {
			  rotated[h * height + w] = input[(w + 1) * width - h - 1];
		  }
	  }
  }
  ////////////////////////////////////////////////////////////////////////////
}
