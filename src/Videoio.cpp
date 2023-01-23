#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include "Videoio.hpp"

#include <cstdlib>
#include <unistd.h>

using namespace cv;
using namespace std;


extern queue<Mat> original_frames;
extern std::mutex mtx;
extern int control;

Videoio::Videoio(string path){
    this->video_path = path;
    this->cap.open(path);
}
Videoio::Videoio(int id){
    this->cam_id = id;
    this->cap.open(id);
}



void Videoio::readCamStream(){
    
    Mat frame;
    for(;;)
    {
        this->cap >> frame;
        original_frames.push(frame);
    }
    control = 0;
    //return 0;
    

}

void Videoio::readVideoStream(){
    Mat frame;
    for(;;)
    {
        this->cap >> frame;
        original_frames.push(frame);
        //imshow("Video",frame);
        //waitKey(1);

    }
    control = 0;
    cout<<"Bitt."<<endl;
    //return 0;
}

void Videoio::showStream(){
    namedWindow("Video");
    while(control){
        if (original_frames.empty()){continue;}
        imshow("Video",original_frames.front());
        waitKey(1);
        original_frames.pop();
    }
    

}

