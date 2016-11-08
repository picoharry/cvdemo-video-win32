#include "stdafx.h"
#include <stdio.h>
#include <sstream>
#include <stdexcept>
#include "CVDemo.Video.VideoFileInfo.hpp"

using namespace std;

namespace cvdemo
{
	namespace video
	{
		//std::ostream& operator<< (std::ostream& os, const VideoFileInfo& info)
		//{
		//	os << info.GetPath() << ":" << info.GetWeight();
		//	return os;
		//}
	}
}

std::ostream& operator<< (std::ostream& os, const cvdemo::video::VideoFileInfo& info)
{
	os << info.GetPath() << ":" << info.GetWeight();
	return os;
}
