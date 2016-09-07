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

#include "LBPHTrainerWrapper.h"
#include "LBPHTrainer.h"

namespace K2OCV {
	LBPHTrainerWrapper::LBPHTrainerWrapper()
	{
	}

	LBPHTrainerWrapper::LBPHTrainerWrapper(String ^ name, Int32 label)
	{
		//Marshalling to unmanaged type
		std::string subName = msclr
			::interop
			::marshal_as<std::string>(name);

		int subLabel = (int)label;

		nativeLBPHTrainer = new LBPHTrainer(subName, subLabel);
	}

	LBPHTrainerWrapper::~LBPHTrainerWrapper()
	{
		this->!LBPHTrainerWrapper();
	}

	LBPHTrainerWrapper::!LBPHTrainerWrapper()
	{
	}

	void LBPHTrainerWrapper::setNameAndLabel(String ^ subName, Int32 label)
	{
		this->subjectName = subName;
		this->subjectLabel = label;

		//Marshalling to unmanaged type
		std::string stdSubName = msclr::interop::marshal_as<std::string>(this->subjectName);

		int stdSubLabel = (int)this->subjectLabel;
		nativeLBPHTrainer = new LBPHTrainer(stdSubName, stdSubLabel);
	}

	bool LBPHTrainerWrapper::trainModel()
	{
		bool success = nativeLBPHTrainer->createFaceModel();

		Thread^ saveModelThread = gcnew Thread(gcnew ThreadStart(this, &LBPHTrainerWrapper::saveModelToFile));
		saveModelThread->Name = "saveModelThread";
		saveModelThread->Start();

		/* Do something in between */

		saveModelThread->Join();
		return success;
	}

	void LBPHTrainerWrapper::saveModelToFile()
	{
		nativeLBPHTrainer->saveModel();
	}
	void LBPHTrainerWrapper::updateModel()
	{
		nativeLBPHTrainer = new LBPHTrainer();
		nativeLBPHTrainer->updateModel();
	}
}