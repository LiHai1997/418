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
		  int index = num_channels * (h * width + w);
		  if (num_channels == 3) {
			  int rot_index = 3 * ((width - w - 1) * height + h);
			  for (int i = 0; i < 3; i++) {
				  rotated[rot_index + i] = input[index + i];
			  }
		  }
		  else {
			  int rot_index = (width - w - 1) * height + h;
			  rotated[rot_index] = input[index];
		  }
	  }
  }
  ////////////////////////////////////////////////////////////////////////////
}
