#include <cmath>
#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  double r, g, b, h, s, v;

  for (int i = 0; i < shifted.size(); i+=3)
  {
	  r = rgb[i] / 255.0;
	  g = rgb[i + 1] / 255.0;
	  b = rgb[i + 2] / 255.0;
	  rgb_to_hsv(r, g, b, h, s, v);
	  h += shift;
	  if (h < 0)
	  {
		  h += 360;
	  }
	  h = std::fmod(h, 360.0);
	  hsv_to_rgb(h, s, v, r, g, b);
	  shifted[i] = r * 255;
	  shifted[i + 1] = g * 255;
	  shifted[i + 2] = b * 255;
  }






  ////////////////////////////////////////////////////////////////////////////
}
