#include "Dehaze.h"

#include "../include/darkchannelPriorProcessor.h"
#include "../include/Autotune.h"
#include <sstream>

#include <chrono>
using namespace std::chrono;

using namespace cv;
using namespace std;


extern queue<Mat> original_frames;
extern queue<Mat> filtered_frames;
extern std::mutex mtx;
extern int control;

void Dehaze::doDehaze(){
    Mat dst;
    while(true){
        mtx.lock();
        if (original_frames.empty()){mtx.unlock();continue;}
        Mat src = original_frames.front();
        if (src.rows > 300)
            resize(src, src, Size(src.cols * 400 / src.rows, 400));
        original_frames.pop();
        mtx.unlock();
        auto start = high_resolution_clock::now();
        auto_tune(src,src);
        deHazeByDarkChannelPrior(src, dst);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        //cout << "Time taken by function: "<< duration.count() << " milliseconds" << endl;
        filtered_frames.push(dst);
    }
}