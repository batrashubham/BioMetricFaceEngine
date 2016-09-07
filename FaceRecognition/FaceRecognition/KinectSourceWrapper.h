// FaceRecognition.h

#pragma once

#include "KinectSource.hpp"

using namespace System;

namespace K2OCV {

	public ref class CKinectSourceWrapper
	{
		CKinectSource* kinectSrc;

	public:
		CKinectSourceWrapper();
		~CKinectSourceWrapper();
		!CKinectSourceWrapper();

		UInt32 initSensor();
	};
}
