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

#include "ImageGrabber.hpp"
#include "KinectSource.hpp"

namespace K2OCV {
	cv::Mat ImageGrabber::grabFace()
	{
		//int outerTries = 10000;
		cv::Mat faceMat;
		cv::Rect* faceRects = nullptr;
		cv::Mat irFrame;
		int trackedFaces = 0;
		int faceIndex;
		bool flag = true;
		time_t endTimeOutter;
		time_t startTimeOutter = time(NULL);
		time_t waitTimeOutter = 2;
		endTimeOutter = startTimeOutter + waitTimeOutter;
		while (flag /*&& outerTries--*/ && startTimeOutter < endTimeOutter) {
			irFrame = kinectSrc->getFrame(IR_F);
			startTimeOutter = time(NULL);
			if (irFrame.data) {
				//int innerTries = 10000;
				time_t endTimeInner;
				time_t startTimeInner = time(NULL);
				time_t waitTimeInner = 2;
				endTimeInner = startTimeInner + waitTimeInner;
				while (flag /* && innerTries--*/ && startTimeInner < endTimeInner) {
					startTimeInner = time(NULL);
					faceRects = kinectSrc->getFaceRect(trackedFaces);
					if (trackedFaces > 0) {
						for (int i = 0; i < trackedFaces; i++) {
							if (faceRects[i].height > 0 && faceRects[i].width > 0) {
								faceIndex = i;
								flag = false;
							}
						}
					}
				}
			}
		}

		if (!flag && faceRects[faceIndex].height < irFrame.rows && faceRects[faceIndex].width < irFrame.cols) {
			this->face = irFrame(faceRects[faceIndex]);
		}
		faceMat = face.clone();
		return faceMat;
	}

	void ImageGrabber::getNameAndLabel(std::string name, int faceLable)
	{
		this->faceLable = faceLable;
		this->name = name;

		initFiles();
	}

	bool ImageGrabber::writeFaceToFile(unsigned int& num)
	{
		bool success;
		grabFace();
		if (face.data) {
			std::string file = "faces\\" + this->name + "\\face";
			file.append(std::to_string(num));
			file.append(std::string("-"));
			cv::resize(face, face, cv::Size(125, 125), cv::INTER_CUBIC);
			file.append(std::to_string(0));
			file.append(std::string(".jpg"));
			success = cv::imwrite(file, face, params);
			if (success) {
				num++;
				faceD << file << ";" << faceLable << std::endl;
				faceDT << file << ";" << faceLable << std::endl;
			}
		}
		return success;
	}

	bool ImageGrabber::doProcess()
	{
		static unsigned int num = 0;
		bool operation = false;
		time_t endTimer;
		time_t waitTime = 20;
		time_t startTimer = time(NULL);
		endTimer = startTimer + waitTime;
		while (num < 300 && startTimer < endTimer) {
			startTimer = time(NULL);
			operation = writeFaceToFile(num);
		}
		return operation;
	}

	void ImageGrabber::initFiles()
	{
		name += std::to_string(faceLable);
		folder.assign(name.begin(), name.end());
		directory = L"\\" + folder;
		//csvDir = L"at" + directory;
		ymlDir = L"faces" + directory;
		//CreateDirectory(csvDir.c_str(),NULL);
		CreateDirectory(ymlDir.c_str(), NULL);

		//contains all the face files data
		faceD = std::ofstream("at\\facedata.csv", std::ios::out | std::ios::app);

		//contains the face files data for current training session
		faceDT = std::ofstream("at\\facedataTemp.csv", std::ios::out);

		//contains names associated with labels
		name_lables = std::ofstream("at\\name_labels.csv", std::ios::out | std::ios::app);
	}

	ImageGrabber::ImageGrabber()
	{
		kinectSrc = N_CKS;
		kinectSrc->initSensor();
		kinectSrc->initSourceReader(IR_S | FACE_S | BODY_S);
		params.push_back(CV_IMWRITE_JPEG_QUALITY);
		params.push_back(95);
	}

	ImageGrabber::~ImageGrabber()
	{
		if (faceD.is_open()) {
			faceD.close();
		}

		if (faceDT.is_open()) {
			faceDT.close();
		}

		if (name_lables.is_open()) {
			name_lables.close();
		}

		if (nullptr != kinectSrc) {
			delete kinectSrc;
			kinectSrc = nullptr;
		}
	}
}