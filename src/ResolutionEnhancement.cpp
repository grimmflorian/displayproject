#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <stdio.h>
using namespace cv;

// Declare Functions
void showPic(Mat* images, int hertz);

int main( int argc, char** argv ){

	// Test case: Create 3 images (red, green, blue) and show them with a certain amount of hertz
	Mat test_images[3];
	std::vector<Mat> red;
	std::vector<Mat> green;
	std::vector<Mat> blue;
	Mat ones = Mat::ones(Size(512, 512), CV_8UC1);
	Mat zeros = Mat::zeros(Size(512, 512), CV_8UC1);

	red.push_back(zeros);
	red.push_back(zeros);
	red.push_back(ones);

	green.push_back(zeros);
	green.push_back(ones);
	green.push_back(zeros);

	blue.push_back(ones);
	blue.push_back(zeros);
	blue.push_back(zeros);

	merge(red, test_images[0]);
	merge(green, test_images[1]);
	merge(blue, test_images[2]);

	int hertz = 75;
	showPic(test_images, hertz);



	return 0;
}


void showPic(Mat* images, int hertz){

	// Amount of seconds
	float sec = 1000/hertz;

	// Breaking condition: How many seconds should it go
	int breakSec = 3;
	int curSec = 0;

	// Amount of images shown
	int total = 0;

	// while loop
	while(curSec < breakSec * 1000){

		// Loop through images
		for(int i = 0; i < 3; i++){

			// Show current picture
			namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
			imshow("Display Image", images[i] * 255);
			waitKey(sec);

			// Increase curSec and total
			curSec = curSec + sec;
			total += 1;

		}
	}

	// Status message
	std::cout << "Shown Images: " << total << " in " << breakSec << " seconds!" << std::endl;


}
