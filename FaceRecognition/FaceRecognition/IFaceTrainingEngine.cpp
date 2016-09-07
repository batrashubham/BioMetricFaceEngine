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

#include "IFaceTrainingEngine.h"

namespace K2OCV {
	void IFaceTrainingEngine::getLable(int lable)
	{
		this->label = label;
	}

	bool IFaceTrainingEngine::takeImages()
	{
		this->imgGrabber = new ImageGrabber();
		imgGrabber->getNameAndLabel(name, label);
		return imgGrabber->doProcess();
	}

	void IFaceTrainingEngine::getName(std::string name)
	{
		this->name = name;
	}
}