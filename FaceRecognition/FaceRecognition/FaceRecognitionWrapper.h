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

namespace K2OCV {
	ref class LBPHTrainerWrapper;
	ref class LBPHRecognizerWrapper;
	ref class ModelLoaderWrapper;

	public ref class BioMetricFaceEngine {
	public:
		//////////////////////////////////////////////////////////////////////////////


		ref class FaceModelLoader {
		public: property ModelLoaderWrapper^ loaderWrapper;
		public:
			ModelLoaderWrapper^ getLoaderWrapper();
			FaceModelLoader();
			~FaceModelLoader();
			!FaceModelLoader();
		};


		//////////////////////////////////////////////////////////////////////////////



		ref class Trainer {
			LBPHTrainerWrapper^ managedTrainer;
			property String^ name;
			property Int32 label;
		public:
			Trainer();
			~Trainer();
			!Trainer();
			void setNameLabel(String^ name, Int32 label);
			bool trainModel();
			void updateModel();
		};


		//////////////////////////////////////////////////////////////////////////////


		ref class Recognizer {
			LBPHRecognizerWrapper^ managedRecognizer;
			property Double predictionConfidence;
			property Int32 predictedLable;
			void setPredictionConcfidence(Double confidence);
			void setPredictedLable(Int32 lable);
			std::string startRecognition();
			ModelLoaderWrapper^ loaderWrapper;
		public:
			Recognizer();
			Recognizer(ModelLoaderWrapper^ loaderWrapper);
			~Recognizer();
			!Recognizer();
			Double getPredictionConfidence();
			Int32 getPredictedLable();
			void recognizeSubject();
		};

		//////////////////////////////////////////////////////////////////////////////
	};
}