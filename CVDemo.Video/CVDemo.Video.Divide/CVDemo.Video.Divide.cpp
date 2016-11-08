// CVDemo.Video.Divide.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/video.hpp>
#include <stdio.h>
#include <sstream>
#include <stdexcept>
// #include <boost/program_options.hpp>
#include "CVDemo.Video.ProgramOptions.hpp"

using namespace cv;
using namespace std;
using namespace cvdemo::video;
// namespace po = boost::program_options;



int main(int argc, const char* argv[])
{
	// testing...
	string configFile = "../cvdemo.video.divide.cfg";
	ProgramOptions options = ProgramOptions(argc, argv, configFile);

	if (options.IsForUsageInfo()) {
		options.DisplayUsageInfo(cout);
		system("pause");
		return -1;
	}
	if (options.IsForVersionInfo()) {
		cout << "Version = 0.0.1" << endl;
		system("pause");
		return -1;
	}
	if (options.IsForOptionsDisplay()) {
		options.DisplayInputOptions(cout);
		system("pause");
		return -1;
	}

	if (!options.IsValid()) {
		cerr << ">>> Invalid input options." << endl;

		options.DisplayResizeAllowed(cerr);
		options.DisplayOutputVideoMode(cerr);
		options.DisplayFrameSamplingInterval(cerr);
		options.DisplayOutputFolder(cerr);
		options.DisplayVideoFileNames(cerr);
		options.DisplayBlendingWeights(cerr);
		// options.DisplayVideoFileInfos(cerr);
		options.DisplayUnrecognizedArgs(cerr);

		options.DisplayUsageInfo(cerr);

		system("pause");
		return -1;
	}



	// tbd:
	// ...

	namedWindow("Frames", WINDOW_AUTOSIZE);



	auto samplingInterval = options.GetFrameSamplingInterval();

	// tbd;
	// loop through all input video files.
	// Or, blend them together into a single input video???
	// tbd ....
	// For now, just use the first one.
	auto videoFile = options.GetVideoFiles()[0];

	auto cap = cvCreateFileCapture(videoFile.c_str());
	

	auto counter = 0;
	const int max = 100;   // tbd...
	while (counter++ < max)
	{
		cvGrabFrame(cap);
		auto img = cvRetrieveFrame(cap);
		// auto img2 = cvQueryFrame(cap);

		// ????
		Mat mat = cvarrToMat(&img);


		if (counter % samplingInterval == 0) {
			// save img
			// ...



			// tbd:
			// Create a file name
			auto filename = "abc.png";
			bool suc = imwrite(filename, mat);
			cout << " >> Image saved. filename = " << filename << "; suc = " + suc << endl;  // ????

		}

		imshow("Frames", mat);
		// waitKey(0);


		// if(no more frames || counter >= max_iter)
		// then break.
		// ....
	}
	// ???
	// cvReleaseCapture(cap);

	return 0;
}

