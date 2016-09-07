/*
* Copyright (C) 2016, Shubham Batra (https://www.github.com/batrashubham)
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* http://www.apache.org/licenses/LICENSE-2.0
* Unless required by applicable law or agreed to in writing,
* software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
* either express or implied.
* See the License for the specific language governing permissions and limitations under the License.
*
*/

#pragma once

#include "helper.hpp"

namespace K2OCV {
	class CKinectSource;

	class ImageGrabber {
		cv::Mat face;
		CKinectSource* kinectSrc = nullptr;
		std::ofstream faceD;
		std::ofstream faceDT;
		std::ofstream name_lables;
		std::wstring folder;
		std::wstring directory;
		std::wstring csvDir;
		std::wstring ymlDir;
		std::vector<int> params;
		int faceLable;
		std::string name;

		bool writeFaceToFile(unsigned int& num);
		void initFiles();
	public:
		cv::Mat grabFace();
		void getNameAndLabel(std::string name, int faceLable);
		bool doProcess();
		ImageGrabber();
		~ImageGrabber();
	};
}