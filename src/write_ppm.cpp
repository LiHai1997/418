#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  std::ofstream fs;
  try {
	  fs.open(filename, std::ios::binary);
	  if (fs.fail()) {
		  return false;
	  }
	  if (num_channels == 3) {
		  fs << "P6" << std::endl;
	  }
	  else {
		  fs << "P5" << std::endl;
	  }
	  fs << width << " " << height << std::endl << "255" << std::endl;
	
	  int total_size = width * height * num_channels;
	  for (int i = 0; i < total_size; i++) {
		  fs << data[i];
	  }

	  fs.close();
	  return true;
  }
  catch (int e) {
	  if (fs.is_open()) {
		  fs.close();
	  }
	  return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}
