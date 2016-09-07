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

#include "IOUtils.hpp"

namespace K2OCV {
	void IOUtils::read_csv(const string & filename, vector<cv::Mat>& images, vector<int>& labels, char separator)
	{
		int skipper = 3;
		std::ifstream file(filename.c_str(), ifstream::in);
		if (!file) {
			string error_message = "No valid input file was given, please check the given filename.";
			CV_Error(CV_StsBadArg, error_message);
		}
		string line, path, classlabel;
		while (getline(file, line)) {
			if (skipper == 4) {
				stringstream liness(line);
				getline(liness, path, separator);
				getline(liness, classlabel);
				if (!path.empty() && !classlabel.empty()) {
					images.push_back(cv::imread(path, 0));
					labels.push_back(atoi(classlabel.c_str()));
				}
				skipper = 1;
			}
			else {
				skipper++;
			}
		}
	}

	void IOUtils::read_csv2(const string & filename, vector<cv::Mat>& images, vector<int>& labels, char separator)
	{
		
		std::ifstream file(filename.c_str(), ifstream::in);
		if (!file) {
			string error_message = "No valid input file was given, please check the given filename.";
			CV_Error(CV_StsBadArg, error_message);
		}
		string line, path, classlabel;
		while (getline(file, line)) {
				stringstream liness(line);
				getline(liness, path, separator);
				getline(liness, classlabel);
				if (!path.empty() && !classlabel.empty()) {
					images.push_back(cv::imread(path, 0));
					labels.push_back(atoi(classlabel.c_str()));
				}
				
		}
	}


	cv::Ptr<cv::face::LBPHFaceRecognizer> IOUtils::faceModelLoader()
	{
		cv::Ptr<cv::face::LBPHFaceRecognizer> model = cv::face::createLBPHFaceRecognizer();

		try {
			model->load("at\\faceModel.yml");
		}
		catch (cv::Exception& e) {
			std::string error_msg = e.msg;
		}

		return model;
	}
}