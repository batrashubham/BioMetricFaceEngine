// This is the main DLL file.

#include "KinectSourceWrapper.h"
#include "KinectSource.hpp"

namespace K2OCV {

	CKinectSourceWrapper::CKinectSourceWrapper()
	{
		kinectSrc = new CKinectSource();
	}
	CKinectSourceWrapper::~CKinectSourceWrapper()
	{
		this->!CKinectSourceWrapper();
	}
	CKinectSourceWrapper::!CKinectSourceWrapper()
	{

	}
	UInt32 CKinectSourceWrapper::initSensor()
	{
		return kinectSrc->initSensor();
	}
}