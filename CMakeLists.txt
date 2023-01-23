cmake_minimum_required(VERSION 3.10)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${CMAKE_SOURCE_DIR}/include)
include_directories( ${CMAKE_SOURCE_DIR}/dehaze/include)

add_executable( DisplayImage 
				src/Main.cpp				
				src/Videoio.cpp
				src/Show.cpp
				dehaze/src/Atmosphere.cpp
				dehaze/src/Darkchannel.cpp
				dehaze/src/darkchannelPriorProcessor.cpp
				dehaze/src/dehazeProcessor.cpp
				dehaze/src/guidedfilter.cpp
				dehaze/src/Transmission.cpp
				dehaze/src/Dehaze.cpp)

target_link_libraries( DisplayImage ${OpenCV_LIBS})
