#pragma once

#include <string>

namespace cvdemo
{
	namespace video
	{
		enum TargetVideoMode
		{
			unknown = 0,
			bounding = 1,
			overlap = 2
		};

		class TargetVideoModes
		{
		public:
			static std::string ToString(const TargetVideoMode mode)
			{
				switch (mode) {
				case TargetVideoMode::bounding:
					return "bounding";
				case TargetVideoMode::overlap:
					return "overlap";
				default:
				case TargetVideoMode::unknown:
					return "unknown";
				}
			}
			static TargetVideoMode FromString(const std::string str)
			{
				if (str == "bounding") {
					return TargetVideoMode::bounding;
				}
				else if (str == "overlap") {
			    	return TargetVideoMode::overlap;
				}
				else {
					return TargetVideoMode::unknown;
				}
			}
		};
	}
}
