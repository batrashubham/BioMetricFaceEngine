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

#include "LBPHRecognizer.h"

namespace K2OCV {
	void LBPHRecognizer::loadFaceModel(cv::Ptr<cv::face::LBPHFaceRecognizer> faceModel)
	{
		this->model = faceModel;
	}

	std::string LBPHRecognizer::predictSubject()
	{
		getFace();
		if (face.data) {
			std::string lableConfidence = "";
			model->predict(face, predictedLabel, confidence);

			if (confidence <= THRESHOLD) {
				//name = model->getLabelInfo(predictedLabel);
				lableConfidence += std::to_string(predictedLabel);
			}
			else {
				lableConfidence += std::to_string(-predictedLabel);
			}

			lableConfidence += " " + std::to_string(confidence);

			this->name = lableConfidence;
		}
		return name;
	}

	LBPHRecognizer::LBPHRecognizer()
	{
		
	}
	void LBPHRecognizer::loadFaceModel()
	{
	}
}