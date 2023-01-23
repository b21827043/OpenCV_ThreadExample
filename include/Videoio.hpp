#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace cv;
using namespace std;

class Videoio{
public :
    string video_path;
    int cam_id;
    Videoio(string path);
    Videoio(int id);
    
    VideoCapture cap;

    void readCamStream();
    void readVideoStream();
    void showStream();


};