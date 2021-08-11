#pragma once
#pragma once
#ifndef PICTURE_H_
#define PICTURE_H_

#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
#include <ctime>

namespace picture {
	void takePicture(cv::Mat);

}

#endif