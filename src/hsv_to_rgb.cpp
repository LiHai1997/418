#include <algorithm>
#include <cmath>
#include <iostream>
#include <cassert>
#include "hsv_to_rgb.h"

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  r = 0;
  g = 0;
  b = 0;

  // input value range check
  assert(h >= 0.0 && h <= 360.0 && "hsv_rgb input h");
  assert(s >= 0.0 && s <= 1.0 && "hsv_rgb input s");
  assert(v >= 0.0 && v <= 1.0 && "hsv_rgb input v");

  double chroma = v * s;
  double h_prime = h / 60;
  double x = chroma * (1 - std::fabs(std::fmod(h / 60, 2) - 1));
  double m = v - chroma;

  if (h_prime > 0 && h_prime <=1)
  {
	  r = chroma;
	  g = x;
  }
  else if (h_prime > 1 && h_prime <= 2)
  {
	  r = x;
	  g = chroma;
  }
  else if (h_prime > 2 && h_prime <= 3)
  {
	  g = chroma;
	  b = x;
  }
  else if (h_prime > 3 && h_prime <= 4)
  {
	  g = x;
	  b = chroma;
  }
  else if (h_prime > 4 && h_prime <= 5)
  {
	  r = chroma;
	  b = x;
  }
  else if (h_prime > 5 && h_prime <= 6)
  {
	  r = x;
	  b = chroma;
  }

  r += m;
  g += m;
  b += m;

  // output value range check
  assert(r >= 0.0 && r <= 1.0 && "hsv_rgb output r");
  assert(g >= 0.0 && g <= 1.0 && "hsv_rgb output g");
  assert(b >= 0.0 && b <= 1.0 && "hsv_rgb output b");

  ////////////////////////////////////////////////////////////////////////////
}
