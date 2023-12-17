// opencv_play_stream.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <opencv2/highgui.hpp>
using namespace cv;

#ifdef _DEBUG
#pragma comment(lib, "opencv_world420d.lib")   
#else 
#pragma comment(lib, "opencv_world420.lib")  

#endif

//const std::string url("tcp://127.0.0.1:47000?listen");
const std::string url("videoplayback.mp4");
int main()
{
	cv::VideoCapture vc(url);
	if (!vc.isOpened())
	{
		std::cerr << "can't open " << url << std::endl;
		return -1;
	}
	
	
	//auto out = cv::VideoWriter("rtp://127.0.0.1:5000",
	//cv::VideoWriter::fourcc('X', '2', '6', '4'), 20.0, cv::Size(640, 480));
	//if (!out.isOpened())
	//{
	//	std::cerr << "can't open out!\n"  << std::endl;
	//}
	cv::Mat frame;
	while (true)
	{
		vc >> frame;
		cv::imshow(url, frame);
		cv::waitKey(10);
		//out << frame;
	}
    return 0;
}

