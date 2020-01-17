#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  double r, g, b, h, s, v;
  for (int hei = 0; hei < height; h++) 
  {
	  for (int w = 0; w < width; w++)
	  {
		  r = rgb[hei * width * 3 + w * 3] / 255.0;
		  g = rgb[hei * width * 3 + w * 3 + 1] / 255.0;
		  b = rgb[hei * width * 3 + w * 3 + 2] / 255.0;

		  rgb_to_hsv(r, g, b, h, s, v);
		  s *= (1.0 - factor);

		  hsv_to_rgb(h, s, v, r, g, b);
		  desaturated[hei * width * 3 + w * 3] = (unsigned char)(r * 255);
		  desaturated[hei * width * 3 + w * 3 + 1] = (unsigned char)(g * 255);
		  desaturated[hei * width * 3 + w * 3 + 2] = (unsigned char)(b * 255);
	  }
  
  }
  ////////////////////////////////////////////////////////////////////////////
}
