#include <iostream>
#include <string.h>
#include <CL/opencl.h>

using namespace std;

int main(int argc, char** argv)
{
  cl_uint numPlatforms = 0;
  cl_int errNum = clGetPlatformIDs(0, NULL, &numPlatforms);
  cout << "Num Platforms: " << numPlatforms << endl;
  cl_platform_id* platformIds = new cl_platform_id[numPlatforms];
  errNum = clGetPlatformIDs(numPlatforms, platformIds, NULL);
  int i = 0;
  for( int i = 0; i < numPlatforms; i++ )
  {
    size_t size = 0;
    errNum = clGetPlatformInfo(platformIds[i], CL_PLATFORM_NAME, 0, NULL, &size);
    char* name = new char[size];
    errNum = clGetPlatformInfo(platformIds[i], CL_PLATFORM_NAME, size, name, NULL);
    errNum = clGetPlatformInfo(platformIds[i], CL_PLATFORM_VENDOR, 0, NULL, &size);
    char* vendor = new char[size];
    errNum = clGetPlatformInfo(platformIds[i], CL_PLATFORM_VENDOR, size, vendor, NULL);
    errNum = clGetPlatformInfo(platformIds[i], CL_PLATFORM_VERSION, 0, NULL, &size);
    char* version = new char[size];
    errNum = clGetPlatformInfo(platformIds[i], CL_PLATFORM_VERSION, size, version, NULL);
    errNum = clGetPlatformInfo(platformIds[i], CL_PLATFORM_PROFILE, 0, NULL, &size);
    char* profile = new char[size];
    errNum = clGetPlatformInfo(platformIds[i], CL_PLATFORM_PROFILE, size, profile, NULL);
    errNum = clGetPlatformInfo(platformIds[i], CL_PLATFORM_EXTENSIONS, 0, NULL, &size);
    char* extensions = new char[size];
    errNum = clGetPlatformInfo(platformIds[i], CL_PLATFORM_EXTENSIONS, size, extensions, NULL);
    cout << "Name: " << name << ", Vendor: " << vendor << ", Version: " << version << endl;
    cout << "  Profile: " << profile << ", Extensions: " << extensions << endl;
  }
}

