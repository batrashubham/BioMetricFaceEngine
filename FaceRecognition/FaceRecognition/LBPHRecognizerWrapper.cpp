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

#include "LBPHRecognizerWrapper.h"
#include "LBPHRecognizer.h"
#include "ModelLoaderWrapper.h"

namespace K2OCV {
	LBPHRecognizerWrapper::LBPHRecognizerWrapper()
	{
		throw gcnew System::NotImplementedException();
	}
	LBPHRecognizerWrapper::LBPHRecognizerWrapper(ModelLoaderWrapper^ loaderWrapper)
	{
		nativeLBPHRecognizer = new LBPHRecognizer();
		this->loaderWrapper = loaderWrapper;
		nativeLBPHRecognizer->model = loaderWrapper->getFaceModel();
	}

	LBPHRecognizerWrapper::~LBPHRecognizerWrapper()
	{
		this->!LBPHRecognizerWrapper();
	}

	LBPHRecognizerWrapper::!LBPHRecognizerWrapper()
	{
	}

	std::string LBPHRecognizerWrapper::predictSubject()
	{
		return nativeLBPHRecognizer->predictSubject();
	}
}