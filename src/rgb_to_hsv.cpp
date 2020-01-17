#include <algorithm>
#include "rgb_to_hsv.h"

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  h = 0;
  s = 0;
  v = 0;

  double max = std::max(std::max(r, g), b);
  double min = std::min(std::min(r, g), b);
  double diff = max - min;

  // handle h
  if (r == g && g == b)
  {
	  h = 0;
  }
  else if (max == r)
  {
	  h = 60 * (0 + (g - b) / diff);
  }
  else if (max == g)
  {
	  h = 60 * (2 + (b - r) / diff);
  }
  else if (max == b)
  {
	  h = 60 * (4 + (r - g) / diff);
  }
  
  // handle s
  if (max == 0)
  {
	  s = 0;
  }
  else
  {
	  s = diff / max;
  }

  // handle v;
  v = max;
  ////////////////////////////////////////////////////////////////////////////
}
