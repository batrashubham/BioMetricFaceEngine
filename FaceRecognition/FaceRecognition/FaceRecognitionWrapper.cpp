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

#include "FaceRecognitionWrapper.h"
#include "LBPHRecognizerWrapper.h"
#include "LBPHTrainerWrapper.h"
#include "ModelLoaderWrapper.h"

namespace K2OCV {
	//////////////////////////////////////////////////////////////////////////////

	BioMetricFaceEngine::Trainer::Trainer()
	{
		managedTrainer = gcnew LBPHTrainerWrapper();
	}

	//////////////////////////////////////////////////////////////////////////////

	void BioMetricFaceEngine::Trainer::setNameLabel(String ^ name, Int32 label)
	{
		managedTrainer->setNameAndLabel(name, label);
	}

	//////////////////////////////////////////////////////////////////////////////

	BioMetricFaceEngine::Trainer::~Trainer()
	{
		this->!Trainer();
	}

	//////////////////////////////////////////////////////////////////////////////

	BioMetricFaceEngine::Trainer::!Trainer()
	{

	}

	//////////////////////////////////////////////////////////////////////////////

	bool BioMetricFaceEngine::Trainer::trainModel()
	{
		return managedTrainer->trainModel();
	}


	//////////////////////////////////////////////////////////////////////////////


	void BioMetricFaceEngine::Trainer::updateModel()
	{
		managedTrainer->updateModel();
	}

	//////////////////////////////////////////////////////////////////////////////

	BioMetricFaceEngine::Recognizer::Recognizer()
	{
		throw gcnew System::NotImplementedException();
	}

	//////////////////////////////////////////////////////////////////////////////

	BioMetricFaceEngine::Recognizer::Recognizer(ModelLoaderWrapper ^ loaderWrapper)
	{
		managedRecognizer = gcnew LBPHRecognizerWrapper(loaderWrapper);
	}

	//////////////////////////////////////////////////////////////////////////////

	BioMetricFaceEngine::Recognizer::~Recognizer()
	{
		this->!Recognizer();
	}

	//////////////////////////////////////////////////////////////////////////////

	BioMetricFaceEngine::Recognizer::!Recognizer()
	{

	}

	//////////////////////////////////////////////////////////////////////////////

	void BioMetricFaceEngine::Recognizer::setPredictionConcfidence(Double confidence)
	{
		this->predictionConfidence = confidence;
	}

	//////////////////////////////////////////////////////////////////////////////

	void BioMetricFaceEngine::Recognizer::setPredictedLable(Int32 lable)
	{
		this->predictedLable = lable;
	}

	//////////////////////////////////////////////////////////////////////////////

	Double BioMetricFaceEngine::Recognizer::getPredictionConfidence()
	{
		return predictionConfidence;
	}

	//////////////////////////////////////////////////////////////////////////////

	Int32 BioMetricFaceEngine::Recognizer::getPredictedLable()
	{
		return predictedLable;
	}

	//////////////////////////////////////////////////////////////////////////////

	std::string BioMetricFaceEngine::Recognizer::startRecognition()
	{
		return managedRecognizer->predictSubject();
	}

	//////////////////////////////////////////////////////////////////////////////

	void BioMetricFaceEngine::Recognizer::recognizeSubject()
	{
		std::string result = startRecognition();

		size_t len = result.length();

		std::string::size_type pos = result.find_first_of(' ');

		if (pos > 0 && pos < 1000) {
			std::string lableNative = result.substr(0, pos);
			std::string predictionConfidenceNative = result.substr(pos + 1, len - pos);
			this->setPredictionConcfidence((Double)std::stod(predictionConfidenceNative));
			this->setPredictedLable((Int32)std::stoi(lableNative));
		}
		else {
			this->setPredictionConcfidence(-3);
			this->setPredictedLable(-2);
		}
	}

	//////////////////////////////////////////////////////////////////////////////

	BioMetricFaceEngine::FaceModelLoader::FaceModelLoader()
	{
		loaderWrapper = gcnew ModelLoaderWrapper;
	}

	//////////////////////////////////////////////////////////////////////////////

	BioMetricFaceEngine::FaceModelLoader::~FaceModelLoader()
	{
		this->!FaceModelLoader();
	}


	//////////////////////////////////////////////////////////////////////////////

	BioMetricFaceEngine::FaceModelLoader::!FaceModelLoader()
	{
		
	}

	//////////////////////////////////////////////////////////////////////////////


	ModelLoaderWrapper ^ BioMetricFaceEngine::FaceModelLoader::getLoaderWrapper()
	{
		return loaderWrapper;
	}

	//////////////////////////////////////////////////////////////////////////////
}