#include <algorithm>
#include <cassert>
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

  assert(r >= 0.0 && r <= 1.0 && "rgb_hsv input r");
  assert(g >= 0.0 && g <= 1.0 && "rgb_hsv input g");
  assert(b >= 0.0 && b <= 1.0 && "rgb_hsv input b");

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

  assert(h >= 0.0 && h <= 360.0 && "rgb_hsv output h");
  assert(s >= 0.0 && s <= 1.0 && "rgb_hsv output s");
  assert(v >= 0.0 && v <= 1.0 && "rgb_hsv output v");
  ////////////////////////////////////////////////////////////////////////////
}
