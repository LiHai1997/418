#include <cmath>
#include <numeric>
#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  int pixel = 0;
  for (int h = 0; h < height; h++)
  {
	  for (int w = 0; w < width; w++) 
	  {
		  std::vector<double> r_channel;
		  std::vector<double> g_channel;
		  std::vector<double> b_channel;
		  // calculate rgb value from 3x3 neighbour
		  for (int i = -1; i < 2; i++)
		  {
			  for (int j = -1; j < 2; j++) 
			  {
				  int x = h + i, y = w + j;
				  if (x >= 0 && x < height && y >= 0 && y < width) {
					  if (std::fmod(x, 2) == 1 && std::fmod(y, 2) == 0)
					  {
						  r_channel.push_back(bayer[width * x + y]);
					  }
					  else if ((std::fmod(x, 2) == 0 && std::fmod(y, 2) == 0) || (std::fmod(x, 2) == 1 && std::fmod(y, 2) == 1))
					  {
						  g_channel.push_back(bayer[width * x + y]);
					  }
					  else if (std::fmod(x, 2) == 0 && std::fmod(y, 2) == 1)
					  {
						  b_channel.push_back(bayer[width * x + y]);
					  }
				  }
			  }
		  }
		  // calculate average of three channel
		  unsigned char r_average = (unsigned char)(std::accumulate(r_channel.begin(), r_channel.end(), 0.0) / r_channel.size());
		  unsigned char g_average = (unsigned char)(std::accumulate(g_channel.begin(), g_channel.end(), 0.0) / g_channel.size());
		  unsigned char b_average = (unsigned char)(std::accumulate(b_channel.begin(), b_channel.end(), 0.0) / b_channel.size());

		  if (std::fmod(h, 2) == 1 && std::fmod(w, 2) == 0)
		  {
			  rgb[pixel] = bayer[width*h + w];
			  rgb[pixel + 1] = g_average;
			  rgb[pixel + 2] = b_average;
		  }
		  else if ((std::fmod(h, 2) == 0 && std::fmod(w, 2) == 0) || (std::fmod(h, 2) == 1 && std::fmod(w, 2) == 1))
		  {
			  rgb[pixel] = r_average;
			  rgb[pixel + 1] = bayer[width * h + w];
			  rgb[pixel + 2] = b_average;
		  }
		  else if (std::fmod(h, 2) == 0 && std::fmod(w, 2) == 1)
		  {
			  rgb[pixel] = r_average;
			  rgb[pixel + 1] = g_average;
			  rgb[pixel + 2] = bayer[width * h + w];
		  }
		  pixel += 3;
	  }
  }
  
  ////////////////////////////////////////////////////////////////////////////
}
