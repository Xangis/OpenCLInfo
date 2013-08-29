#!/bin/bash
gcc -o OpenCLInfo Main.cpp -L/usr/lib/x86_64-linux-gnu/ -lOpenCL -lstdc++
#gcc -o OpenCLInfo Main.cpp -L/usr/lib/nvidia-304/ -lOpenCL -lstdc++
