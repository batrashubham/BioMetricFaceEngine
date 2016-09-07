#include "KinectStreamsMatWrapper.h"
#include "KinectStreamsMat.hpp"

namespace K2OCV {

	CKinectStreamsMatWrapper::CKinectStreamsMatWrapper()
	{
		streamsMatSource = new CKinectStreamsMat();
	}
	CKinectStreamsMatWrapper::~CKinectStreamsMatWrapper()
	{
		this->!CKinectStreamsMatWrapper();
	}
	CKinectStreamsMatWrapper::!CKinectStreamsMatWrapper()
	{
		delete streamsMatSource;
	}


}