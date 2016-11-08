#pragma once

#include <string>
#include <vector>


namespace cvdemo
{
	namespace video
	{
		class VideoFileInfo
		{
		public:
			VideoFileInfo(std::string& filePath, float divideingWeight)
				: path(filePath), weight(divideingWeight)
			{
			}

		private:
			const std::string path;  // name? absolute vs relative path?
			const float weight;      // divideing weight.

		public:
			const std::string GetPath() const
			{
				return path;
			}
			const float GetWeight() const
			{
				return weight;
			}

			// friend std::ostream& operator<< (std::ostream& os, const VideoFileInfo& info);

		};

    }

}

std::ostream& operator<< (std::ostream& os, const cvdemo::video::VideoFileInfo& info);
