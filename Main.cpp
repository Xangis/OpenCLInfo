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
    cout << "Name: " << name << ", ID: " << platformIds[i] << ", Vendor: " << vendor << ", Version: " << version << endl;
    cout << "  Profile: " << profile << ", Extensions: " << extensions;

    cl_uint numDevices = 0;
    errNum = clGetDeviceIDs(platformIds[i], CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices);
    cout << " Num Devices: " << numDevices << endl;
    cl_device_id* deviceIds = new cl_device_id[numDevices];
    clGetDeviceIDs(platformIds[i], CL_DEVICE_TYPE_ALL, numDevices, deviceIds, NULL);
    for( int j = 0; j < numDevices; j++ )
    {
      cl_device_type deviceType = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_TYPE, sizeof(cl_device_type), &deviceType, &size);
      cl_uint numComputeUnits = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &numComputeUnits, &size);
      cout << "  Device " << deviceIds[j] << ", Type: " << deviceType << ", Compute Units: " << numComputeUnits << endl;
    }
  }
}

