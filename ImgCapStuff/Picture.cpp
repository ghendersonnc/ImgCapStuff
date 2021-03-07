#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include "Picture.h"


namespace picture {

	namespace {
		std::string namePicture();
		void savePicture(cv::Mat img) {
			std::string fileName = namePicture();
			// Relative path for quick testing Use absolute paths instead
			std::string imageDir = "Resources/";

			std::vector<int> compressionParams;
			compressionParams.push_back(cv::IMWRITE_PNG_COMPRESSION);
			compressionParams.push_back(9); // Max compression time (smallest size)

			bool result = false;

			std::string filePath = imageDir + fileName;
			try {
				result = cv::imwrite(filePath, img, compressionParams);
			}
			catch (const cv::Exception& ex) {
				std::cerr << "Exception: " << ex.what() << std::endl;
			}

			if (result) {
				std::cout << "Image saved as " << fileName << std::endl;
			}
			else {
				std::cout << "ERROR: Could not save PNG file." << std::endl;
			}
		}

		std::string namePicture() {
			// Name file using seconds since 1 Jan 1970
			std::time_t now = std::time(0);

			std::string dateAlloc = std::to_string(now);
			return "picture_" + dateAlloc + ".png";

		}
	}

	void takePicture(cv::Mat img) {
		cv::imshow("PICTURE", img);
		bool pictureMode = true;

		while (pictureMode) {
			switch (cv::waitKey(0)) {
				case 27:
					pictureMode = false;
					break;
				// Save picture if user presses S key
				case 83:
				case 115:
					savePicture(img);
					break;
				default:
					break;
			}

		}
		cv::destroyWindow("PICTURE");
	}
}


