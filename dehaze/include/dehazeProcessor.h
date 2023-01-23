#pragma once
#include <opencv2/opencv.hpp>
class dehazeProcessor
{
public:
	void setInput(const cv::Mat& input);

	void setInput(const cv::String & filename);

	// void setFileName(cv::String filename);

	void getOutput(cv::Mat & output);

	dehazeProcessor(const cv::Mat& srcImg);

	dehazeProcessor(const cv::String & filename);

	// dehazeProcessor(const cv::Mat & srcImg, const cv::String & filename);

	dehazeProcessor() {}

	cv::Mat & src() { return this->srcImg; }
	cv::Mat & dst() { return this->dstImg; }

public:
	virtual void process() = 0;
	virtual void hazeFree() = 0;

private:
	cv::Mat srcImg;
	cv::Mat dstImg;
	// cv::String filename;
};

void hazeFree(cv::Mat & srcImg, cv::Mat & output, int type);