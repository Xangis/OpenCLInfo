#include <iostream>
#include <string.h>
// If you are using NVIDIA CUDA OpenCL and have the CUDA toolkit installed,
// your include directory will probably be something like:
// C:\NVIDIA\CUDA\CUDAToolkit\include
#include <CL/opencl.h>
#ifdef WIN32
#include "Windows.h"
#endif

using namespace std;

const char* DeviceTypeString(unsigned int type)
{
    switch( type )
    {
        case CL_DEVICE_TYPE_CPU:
            return "CL_DEVICE_TYPE_CPU";
        case CL_DEVICE_TYPE_GPU:
            return "CL_DEVICE_TYPE_GPU";
        case CL_DEVICE_TYPE_ACCELERATOR:
            return "CL_DEVICE_TYPE_ACCELERATOR";
        case CL_DEVICE_TYPE_DEFAULT:
            return "CL_DEVICE_TYPE_DEFAULT";
        case CL_DEVICE_TYPE_ALL:
            return "CL_DEVICE_TYPE_ALL";
        default:
            return "Unknown device type.";
    }
}

int main(int argc, char** argv)
{
  cl_uint numPlatforms = 0;
  cl_int errNum = clGetPlatformIDs(0, NULL, &numPlatforms);
  cout << "Num Platforms: " << numPlatforms << endl;
  cl_platform_id* platformIds = new cl_platform_id[numPlatforms];
  errNum = clGetPlatformIDs(numPlatforms, platformIds, NULL);
  int i = 0;
  for( unsigned int i = 0; i < numPlatforms; i++ )
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
    cl_uint numDevices = 0;
    errNum = clGetDeviceIDs(platformIds[i], CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices);
	cout << "--------------------" << endl;
    cout << "Name: " << name << ", ID: " << platformIds[i] << ", Vendor: " << vendor << ", Version: " << version << endl;
    cout << "Profile: " << profile << ", Num Devices: " << numDevices << endl;
    cout << "Extensions: " << extensions << endl;
    delete[] name, vendor, version, profile, extensions;

    cl_device_id* deviceIds = new cl_device_id[numDevices];
    clGetDeviceIDs(platformIds[i], CL_DEVICE_TYPE_ALL, numDevices, deviceIds, NULL);
    for( unsigned int j = 0; j < numDevices; j++ )
    {
      cl_device_type deviceType = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_TYPE, sizeof(cl_device_type), &deviceType, &size);
      cl_uint numComputeUnits = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &numComputeUnits, &size);
      cl_uint maxWorkItemDimensions = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(cl_uint), &maxWorkItemDimensions, &size);
      cl_uint vendorID = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_VENDOR_ID, sizeof(cl_uint), &vendorID, &size);
      cl_uint maxClockFrequency = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(cl_uint), &maxClockFrequency, &size);
      cl_uint addressBits = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_ADDRESS_BITS, sizeof(cl_uint), &addressBits, &size);
      cl_ulong maxMemoryAlloc = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(cl_ulong), &maxMemoryAlloc, &size);
      cl_ulong globalMemory = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(cl_ulong), &globalMemory, &size);
      cl_bool imageSupport = CL_FALSE;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_IMAGE_SUPPORT, sizeof(cl_bool), &imageSupport, &size);
      cl_bool littleEndian = CL_FALSE;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_ENDIAN_LITTLE, sizeof(cl_bool), &littleEndian, &size);
      cl_bool errorCorrectionSupport = CL_FALSE;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_ERROR_CORRECTION_SUPPORT, sizeof(cl_bool), &errorCorrectionSupport, &size);
      size_t max2DWidth = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_IMAGE2D_MAX_WIDTH, sizeof(size_t), &max2DWidth, &size);
      size_t max2DHeight = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_IMAGE2D_MAX_HEIGHT, sizeof(size_t), &max2DHeight, &size);
      size_t max3DWidth = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_IMAGE3D_MAX_WIDTH, sizeof(size_t), &max3DWidth, &size);
      size_t max3DHeight = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_IMAGE3D_MAX_HEIGHT, sizeof(size_t), &max3DHeight, &size);
      size_t max3DDepth = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_IMAGE3D_MAX_DEPTH, sizeof(size_t), &max3DDepth, &size);
      cl_uint maxSamplers = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_MAX_SAMPLERS, sizeof(cl_uint), &maxSamplers, &size);
      size_t maxWorkGroup = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(size_t), &maxWorkGroup, &size);
      size_t maxParameterSize = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_MAX_PARAMETER_SIZE, sizeof(size_t), &maxParameterSize, &size);
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_NAME, 0, NULL, &size);
      char* deviceName = new char[size];
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_NAME, size, deviceName, NULL);
      errNum = clGetDeviceInfo(deviceIds[j], CL_DRIVER_VERSION, 0, NULL, &size);
      char* driverVersion = new char[size];
      errNum = clGetDeviceInfo(deviceIds[j], CL_DRIVER_VERSION, size, driverVersion, NULL);
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_EXTENSIONS, 0, NULL, &size);
      char* deviceExtensions = new char[size];
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_EXTENSIONS, size, deviceExtensions, NULL);
      cl_uint maxReadImageArgs = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_MAX_READ_IMAGE_ARGS, sizeof(cl_uint), &maxReadImageArgs, &size);
      cl_uint maxWriteImageArgs = 0;
      errNum = clGetDeviceInfo(deviceIds[j], CL_DEVICE_MAX_WRITE_IMAGE_ARGS, sizeof(cl_uint), &maxWriteImageArgs, &size);
      cout << "--------------------" << endl;
      cout << "  Device " << deviceIds[j] << ", Type: " << DeviceTypeString(deviceType) << ", Name: " << deviceName << endl;
      cout << "  Driver Ver: " << driverVersion << ", Compute Units: " << numComputeUnits << ", Vendor: " << vendor << " (ID " << vendorID << ")" << endl;
      cout << "  Max clock frequency: " << maxClockFrequency << ", Address bits: " << addressBits << ", Max memory alloc: " << maxMemoryAlloc << endl;
      cout << "  Global memory size: " << globalMemory << ", Max samplers/kernel: " << maxSamplers << ", Max work group: " << maxWorkGroup << endl;
      cout << "  Max work item dimensions: " << maxWorkItemDimensions << ", Max read img args: " << maxReadImageArgs << ", Max write img args: " << maxWriteImageArgs << endl;
      cout << "  Max parameter size: " << maxParameterSize << ", Little endian: " << littleEndian << ", Error correction support: " << errorCorrectionSupport << endl;
      cout << "  Image Support: " << imageSupport << ", Max 2D Image Width: " << max2DWidth << ", Max 2D Image Height: " << max2DHeight << endl;
      cout << "  Max 3D Image Width: " << max3DWidth << ", Max 3D Image Height: " << max3DHeight << ", Max 3D Image Depth: " << max3DDepth << endl;
      cout << "  Extensions: " << deviceExtensions << endl;
      delete[] deviceName, driverVersion;
    }
  }
#ifdef WIN32
  cout << endl << "Done. Hit enter to close the program." << endl;
  char c;
  cin.get(c);
  //while(1) { Sleep(50); }
#endif
}

