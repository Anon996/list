#*********************************************************************************
#Copyright(C),2015-2020, Robsense. All rights reserved.
#FileName:    Makefile
#Author:      HeBin
#Version:     0.1
#Date:        2020-06-25 23:30:26
#Last Modify: 2020-06-25 23:30:26
#Description: 
#**********************************************************************************

all:
	mkdir -p build
	cd build && cmake ../ && make -j
	cd example && mkdir -p build && cd build && cmake ../ && make -j

clean:
	rm -rf build
	rm -rf example/build

