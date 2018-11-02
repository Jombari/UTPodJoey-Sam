final: UtPodDriver.o UtPod.o Song.o
	g++ -otest  UtPodDriver.o UtPod.o Song.o
driver: UtPodDriver.cpp UtPod.h Song.h
	g++ -c UtPod_Driver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c  UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp
