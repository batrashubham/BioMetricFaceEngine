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
#include "IFaceTrainingEngine.h"

namespace K2OCV {
#define RADIUS    1
#define NEIGHBORS 8
#define GRID_X    8
#define GRID_Y    8
#define THRESHOLD 200.0

	struct IOUtils;

	class LBPHTrainer : public IFaceTrainingEngine {
		cv::Ptr<cv::face::LBPHFaceRecognizer>  model;

	public:
		// Inherited via IFaceTrainingEngine
		virtual bool createFaceModel();

		// Inherited via IFaceTrainingEngine
		virtual void saveModel();

		// Inherited via IFaceTrainingEngine
		virtual bool loadFiles(bool all = false);

		// Inherited via IFaceTrainingEngine
		virtual void updateModel();

		LBPHTrainer();
		LBPHTrainer(std::string name, int label);

	};
}