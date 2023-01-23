#include "Show.hpp"

extern queue<Mat> filtered_frames;
extern std::mutex mtx;
extern int control;


void Show::showStream(){

    float f;
    float FPS[16];
    int i,Fcnt=0;
    //some timing
    std::chrono::steady_clock::time_point Tbegin, Tend;
    for(i=0;i<16;i++) FPS[i]=0.0;

    namedWindow("Video");
    //int sayi1 = 0;
    while(true){
        if (filtered_frames.empty()){continue;}
        //string path = "data/"+to_string(sayi1)+".jpg";
        //imwrite(path,filtered_frames.front());
        //sayi1=sayi1+1;
        imshow("Video",filtered_frames.front());
        waitKey(1);
        filtered_frames.pop();
    }
    

}