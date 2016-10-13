#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
#include "point_detector.h"
#include "round_target.h"

void test_point(Mat &origin)
{
	vector<Point2d> points;
	PointDetector pd;

	//����
	pd.Detect(origin, points);

	//������Ե
	//for (int i = 0; i < points.size(); ++i){

		//������ѡ����
		//cv::circle(origin, points[i], 5, Scalar(0, 255, 0));
	//}

	imshow("origin", origin);

	//waitKey(); 
}

void test_target(Mat &origin)
{
	RoundTarget tar;

	tar.Detect(origin);

	imshow("origin", origin);
	waitKey();
}

int main(void)
{
	Mat origin;
	int key;
	VideoCapture capture(0);
	stringstream savename;
	int index;

	if (false == capture.isOpened()) {
		cerr << "can open capture device.\n" << endl;
		return -1;
	}

	key = 0;
	index = 0;
	while ('q' != key) {
		capture >> origin;
		key = waitKey(1);
		if ('s' == key) {
			stringstream savename;
			savename << "snap" << index << ".png";
			index += 1;
			imwrite(savename.str(), origin);
		}
		test_point(origin);
	}

	return 0;
}

int main1(int argc, char* argv[])
{
	Mat origin;

	if (argc < 2){
		printf("%s image_file\n", argv[0]);
		return -1;
	}

	//read image
	origin = imread(argv[1]);
	if(origin.empty()){ cerr << "ERR: Unable to open image.\n" << endl;
		return -1;
	}

	test_point(origin);
	//test_target(origin);

	return 0;
}