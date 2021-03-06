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
  std::ofstream file;
  try {
	  file.open(filename, std::ios::binary);
	  // return false if the file can not open
	  if (file.fail()) {
		  return false;
	  }

	  if (num_channels == 3) {
		  // P6 is RGB image in ppm file
		  file << "P6" << std::endl;
	  }
	  else {
		  // P5 is grayscale in ppm file
		  file << "P5" << std::endl;
	  }
	  file << width << " " << height << std::endl << "255" << std::endl;
	
	  // write data in
	  int total_size = width * height * num_channels;
	  for (int i = 0; i < total_size; i++) {
		  file << data[i];
	  }

	  file.close();
	  return true;
  }
  catch (int e) {
	  if (file.is_open()) {
		  file.close();
	  }
	  return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}
