#include <iostream>
#include <opencv2/opencv.hpp>
#include <mutex>
#include <queue>
#include <thread>

#include "Videoio.hpp"
#include "Show.hpp"
#include "Dehaze.h"

using namespace cv;
using namespace std;


std::mutex mtx;
queue<Mat> original_frames;
queue<Mat> filtered_frames;
int control = 1;


int main(int argc, char *argv[]) {

    class Videoio videoio(0);
    class Dehaze dehaze1;
    class Dehaze dehaze2;
    class Dehaze dehaze3;
    class Show show_object;
    
    thread th1(&Videoio::readCamStream,&videoio);
    thread th2(&Dehaze::doDehaze,&dehaze1);
    thread th3(&Dehaze::doDehaze,&dehaze2);
    //thread th4(&Dehaze::doDehaze,&dehaze3);
    thread th5(&Show::showStream,&show_object);

    th1.join();
    th2.join();
    th3.join();
    //th4.join();
    th5.join();


    return 0;
}
