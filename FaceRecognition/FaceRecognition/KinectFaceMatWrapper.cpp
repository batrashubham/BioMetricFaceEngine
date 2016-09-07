#include "KinectFaceMatWrapper.h"
#include "KinectFaceMat.hpp"

namespace K2OCV {

	CKinectFaceMatWrapper::CKinectFaceMatWrapper()
	{
		faceMatSource = new CKinectFaceMat();
	}

	CKinectFaceMatWrapper::~CKinectFaceMatWrapper()
	{
		this->!CKinectFaceMatWrapper();
	}

	CKinectFaceMatWrapper::!CKinectFaceMatWrapper()
	{
		delete faceMatSource;
	}

}