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

using namespace System;
using namespace System::Threading;

namespace K2OCV {
	class LBPHTrainer;

	ref class LBPHTrainerWrapper {
		LBPHTrainer* nativeLBPHTrainer;
	public:
		property String^ subjectName;
		property Int32 subjectLabel;

		LBPHTrainerWrapper();
		LBPHTrainerWrapper(String^ name, Int32 label);
		~LBPHTrainerWrapper();
		!LBPHTrainerWrapper();

		void setNameAndLabel(String^ subName, Int32 label);

		bool trainModel();

		void saveModelToFile();

		void updateModel();
	};
}