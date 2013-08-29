//#include <fcntl.h>
//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
#include <string.h>
//#include <math.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <CL/opencl.h>

using namespace std;

int main(int argc, char** argv)
{
  cl_uint numPlatforms = 0;
  cl_platform_id* platformIds;
  cl_int errNum = clGetPlatformIDs(0, NULL, &numPlatforms);
  cout << "Num Platforms: " << numPlatforms << endl;
}

