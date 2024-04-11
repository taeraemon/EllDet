#include "EllipseDetector.h"
#include "util.h"
#include "EdgeDetector.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "Usage: " << argv[0] << " <Image File or Directory Path>" << std::endl;
		return 1;
	}

	auto start = clock();
	EllipseDetector ellipse_Detector;
	std::vector<Ellipse> ellipses;

	// Img Read
	std::string imagePath = argv[1];
	cv::Mat img = cv::imread(imagePath);
	if(img.empty()){
		std::cerr << "Error: Image could not be read." << std::endl;
        return 1;
	}

	// Ellipse Detection
	ellipses = ellipse_Detector.DetectImage(img);

	// Make New Image
	cv::Mat3b img0 = ellipse_Detector.image();

	// Darw Ellipse
	draw_ellipses_all(ellipses, img0);

	// Result Print
	printf("Time: %.2f ms\n", (clock() - start) * 1000.0 / CLOCKS_PER_SEC);
	cv::imshow("Result", img0);
	cv::waitKey();

	return 0;
}