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
#include "IFaceRecognitionEngine.hpp"

namespace K2OCV {
#define THRESHOLD 200.0

	class LBPHRecognizer : public IFaceRecognitionEngine {
	public:
		// Inherited via IFaceRecognitionEngine
		virtual void loadFaceModel(cv::Ptr<cv::face::LBPHFaceRecognizer> faceModel);
		virtual std::string predictSubject();

		cv::Ptr<cv::face::LBPHFaceRecognizer> model;

		LBPHRecognizer();

		// Inherited via IFaceRecognitionEngine
		virtual void loadFaceModel();
	};
}