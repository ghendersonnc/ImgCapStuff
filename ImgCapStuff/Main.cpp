// Author: me
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include "Picture.h"

int main() {
	// 16:9 resolution
	const int WIDTH = 960;
	const int HEIGHT = 540;
	cv::Mat frame;
	cv::VideoCapture capDevice;

	int deviceID = 0;
	int apiID = cv::CAP_ANY;
	bool running = true;

	capDevice.open(deviceID, apiID);
	capDevice.set(cv::CAP_PROP_FRAME_WIDTH, WIDTH);
	capDevice.set(cv::CAP_PROP_FRAME_HEIGHT, HEIGHT);

	if (!capDevice.isOpened()) {
		std::cerr << "Unable to open camera\n";
		return -1;
	}

	while (running) {
		capDevice.read(frame);

		if (frame.empty()) {
			std::cerr << "Blank frame";
			return -1;
		}

		cv::imshow("Webcam", frame);

		switch (cv::waitKey(5)) {
			case 27:
				running = false;
				break;
			// Use current frame for picture
			case 80:
			case 112:
				picture::takePicture(frame);
		}
	}
}

