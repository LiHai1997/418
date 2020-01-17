#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  double r_a, g_a, b_a, a_a, r_b, g_b, b_b, a_b;
  double r, g, b, a;

  for (int h = 0; h < height; h++)
  {
	  for (int w = 0; w < width; w++)
	  {
		  r_a = A[h * width * 4 + w * 4];
		  g_a = A[h * width * 4 + w * 4 + 1];
		  b_a = A[h * width * 4 + w * 4 + 2];
		  a_a = A[h * width * 4 + w * 4 + 3] / 255.0;
		  r_b = B[h * width * 4 + w * 4];
		  g_b = B[h * width * 4 + w * 4 + 1];
		  b_b = B[h * width * 4 + w * 4 + 2];
		  a_b = B[h * width * 4 + w * 4 + 3] / 255.0;


		  a = a_a + a_b * (1 - a_a);
		  r = (r_a * a_a + r_b * a_b * (1 - a_a)) / a;
		  g = (g_a * a_a + g_b * a_b * (1 - a_a)) / a;
		  b = (b_a * a_a + b_b * a_b * (1 - a_a)) / a;

		  C[h * width * 4 + w * 4] = (unsigned char)r;
		  C[h * width * 4 + w * 4 + 1] = (unsigned char)g;
		  C[h * width * 4 + w * 4 + 2] = (unsigned char)b;
		  C[h * width * 4 + w * 4 + 3] = (unsigned char)a * 255;
	  }
  }
  ////////////////////////////////////////////////////////////////////////////
}
