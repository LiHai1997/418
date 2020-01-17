#include <algorithm>
#include <cmath>
#include <iostream>
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

  r = std::round(255 * (r + m));
  g = std::round(255 * (g + m));
  b = std::round(255 * (b + m));



  ////////////////////////////////////////////////////////////////////////////
}
