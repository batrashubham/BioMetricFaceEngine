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

#include "LBPHTrainer.h"
#include "IOUtils.hpp"

namespace K2OCV {
	bool LBPHTrainer::createFaceModel()
	{
		return this->takeImages();
	}

	void LBPHTrainer::saveModel()
	{
		bool loaded = loadFiles();
		if (loaded) {
			try {
				model->load("at\\faceModel.yml");
			}
			catch (cv::Exception& e) {
				string s = e.msg;
			}
			model->setLabelInfo(labels[0], name);
			model->update(images, labels);
			model->save("at\\faceModel.yml");
		}
	}

	bool LBPHTrainer::loadFiles(bool all)
	{
		try {
			if (!all)
			{
				IOUtils::read_csv("at\\faceDataTemp.csv", this->images, this->labels);
			}
			else {
				IOUtils::read_csv("at\\faceData.csv", this->images, this->labels);
			}
		}
		catch (cv::Exception& e) {
			std::cerr << "Error Reading File faceDataTemp.csv " << e.msg << std::endl;
			exit(-1);
		}

		if (images.size() <= 1) {
			std::string error_message = "This Program needs at least 2 images to work. Please Add more images to your data set\n";
			CV_Error(cv::Error::StsError, error_message);
			return false;
		}
		return true;
	}

	LBPHTrainer::LBPHTrainer()
	{
		this->label = -1;
		this->name = "default";
		model = cv::face::createLBPHFaceRecognizer(RADIUS, NEIGHBORS, GRID_X, GRID_Y, THRESHOLD);
	}

	LBPHTrainer::LBPHTrainer(std::string name, int label)
	{
		this->label = label;
		this->name = name;
		model = cv::face::createLBPHFaceRecognizer(RADIUS, NEIGHBORS, GRID_X, GRID_Y, THRESHOLD);
	}
	void LBPHTrainer::updateModel()
	{
		bool loaded = loadFiles(true);
		if (loaded) {
			
			model->setLabelInfo(labels[0], name);
			model->train(images, labels);
			model->save("at\\faceModel.yml");
		}
	}
}