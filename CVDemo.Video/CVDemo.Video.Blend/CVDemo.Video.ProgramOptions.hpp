#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <boost/program_options.hpp>
#include "CVDemo.Video.TargetVideoMode.hpp"
#include "CVDemo.Video.VideoFileInfo.hpp"

namespace po = boost::program_options;


namespace cvdemo
{
	namespace video
	{
		class ProgramOptions
		{
		public:
			ProgramOptions(int argc, const char* argv[], std::string configFile = "");

		private:
			int cmdlineArgc;
			const char** cmdlineArgv;
			std::string configFilePath;

		private:
			bool isParsed = false;
			// bool isForInfoOnly = false;
			bool isForUsageInfo = false;
			bool isForVersionInfo = false;
			bool isForOptionsDisplay = false;   // true == like "echo" for options.
												// These flags make sense only if isParsed == true.
			bool hasSyntacticError = false;
			bool isValid = false;
		public:
			//bool IsInitialized()
			//{
			//	return isInitialized;
			//}
			//bool IsParsed()
			//{
			//	return isParsed;
			//}
			bool IsForInfoOnly()
			{
				if (!isParsed) {
					_Parse();
				}
				return isForUsageInfo || isForVersionInfo || isForOptionsDisplay;
			}
			bool IsForUsageInfo()
			{
				if (!isParsed) {
					_Parse();
				}
				return isForUsageInfo;
			}
			bool IsForVersionInfo()
			{
				if (!isParsed) {
					_Parse();
				}
				return isForVersionInfo;
			}
			bool IsForOptionsDisplay()
			{
				if (!isParsed) {
					_Parse();
				}
				return isForOptionsDisplay;
			}
			bool HasSyntacticError()
			{
				if (!isParsed) {
					_Parse();
				}
				return hasSyntacticError;
			}
			bool IsValid()
			{
				if (HasSyntacticError()) {
					return false;
				}
				else {
					return isValid;
				}
			}

		public:
			void DisplayUsageInfo(std::ostream& os)
			{
				//if (!isParsed) {
				//	_Parse();
				//}
				os << visible_options << std::endl;
			}
			void DisplayInputOptions(std::ostream& os)
			{
				if (!isParsed) {
					_Parse();
				}

				os << "Input options parsed:" << std::endl;
				os << "Has syntax error? " << hasSyntacticError << std::endl;
				os << "Is orverall valid? " << isValid << std::endl;


				std::vector<std::string> unrecognized = GetUnrecognizedArgs();
				for (auto &i : unrecognized) {
					os << "Unrecognized: " << i << std::endl;
				}

				// ???
				//for (auto &a : vm) {
				//	os << "Name = " << a.first << "; Value = " << a.second.value << std::endl;
				//}

				if (vm.count("resize-allowed")) {
					os << "Resize-Allowed is set to " << vm["resize-allowed"].as<bool>() << "." << std::endl;
				}

				if (vm.count("output-video-mode")) {
					auto oim = vm["output-video-mode"].as<std::string>();
					auto m = TargetVideoModes::FromString(oim);
					os << "Output video mode: " << m << ":" << oim << std::endl;
				}

				std::vector<std::string> fgFiles;
				if (vm.count("video-file")) {
					fgFiles = vm["video-file"].as<std::vector<std::string>>();
				}
				for (auto &i : fgFiles) {
					os << "Foreground file: " << i << std::endl;
				}

				std::vector<float> weights;
				if (vm.count("blending-weight")) {
					weights = vm["blending-weight"].as<std::vector<float>>();
				}
				for (auto &i : weights) {
					os << "Blending weight: " << i << std::endl;
				}

				// Processed values.
				for (auto &i : videoFileInfos) {
					os << "Video file info: " << i << std::endl;
				}

			}
			std::vector<std::string> GetUnrecognizedArgs()
			{
				if (!isParsed) {
					_Parse();
				}
				return unrecognized;
			}

		public:
			// For debugging purposes:
			void DisplayUnrecognizedArgs(std::ostream& os)
			{
				std::vector<std::string> unrecognized = GetUnrecognizedArgs();
				for (auto &i : unrecognized) {
					os << "Unrecognized: " << i << std::endl;
				}
			}
			void DisplayResizeAllowed(std::ostream& os)
			{
				if (vm.count("resize-allowed")) {
					os << "Resize-Alloweed is set to " << vm["resize-allowed"].as<bool>() << "." << std::endl;
				}
			}
			void DisplayOutputVideoMode(std::ostream& os)
			{
				if (vm.count("output-video-mode")) {
					// auto m = TargetVideoModes::FromString(vm["output-video-mode"].as<std::string>());
					auto m = vm["output-video-mode"].as<std::string>();
					os << "Output video mode: " << m << std::endl;
				}
			}
			void DisplayVideoFileNames(std::ostream& os)
			{
				std::vector<std::string> fgFiles;
				if (vm.count("video-file")) {
					fgFiles = vm["video-file"].as<std::vector<std::string>>();
				}
				for (auto &i : fgFiles) {
					os << "Video file: " << i << std::endl;
				}
			}
			void DisplayBlendingWeights(std::ostream& os)
			{
				std::vector<float> weights;
				if (vm.count("blending-weight")) {
					weights = vm["blending-weight"].as<std::vector<float>>();
				}
				for (auto &i : weights) {
					os << "Blending weight: " << i << std::endl;
				}
			}
			void DisplayVideoFileInfos(std::ostream& os)
			{
				for (auto &i : videoFileInfos) {
					os << "Video file info: " << i << std::endl;
				}
			}

		public:
			bool IsResizeAllowed()
			{
				if (!isParsed) {
					_Parse();
				}
				if (!isValid) {
					throw std::exception("Options are invalid.");
				}
				return vm["resize-allowed"].as<bool>();
			}
			TargetVideoMode GetOutputVideoMode()
			{
				if (!isParsed) {
					_Parse();
				}
				if (!isValid) {
					throw std::exception("Options are invalid.");
				}
				return TargetVideoModes::FromString(vm["output-video-mode"].as<std::string>());
			}
			std::vector<std::string> GetVideoFiles()
			{
				if (!isParsed) {
					_Parse();
				}
				if (!isValid) {
					throw std::exception("Options are invalid.");
				}
				return vm["video-file"].as<std::vector<std::string>>();
			}
			std::vector<float> GetBlendingWeights()
			{
				if (!isParsed) {
					_Parse();
				}
				if (!isValid) {
					throw std::exception("Options are invalid.");
				}
				return vm["blending-weight"].as<std::vector<float>>();
			}

		private:
			// std::vector<VideoFileInfo&> videoFileInfos;
			std::vector<VideoFileInfo> videoFileInfos;

		public:
			// std::vector<VideoFileInfo&> GetVideoFileInfos()
			std::vector<VideoFileInfo> GetVideoFileInfos()
			{
				if (!isParsed) {
					_Parse();
				}
				if (!isValid) {
					throw std::exception("Options are invalid.");
				}
				return videoFileInfos;
			}

		private:
			po::variables_map vm;
			po::options_description cmdline_options;
			po::options_description config_file_options;
			po::options_description visible_options;
			// po::options_description visible_options("Allowed options");
			std::vector<std::string> unrecognized;

		private:
			void _Initialize();
			void _Parse();

		};
	}
}
