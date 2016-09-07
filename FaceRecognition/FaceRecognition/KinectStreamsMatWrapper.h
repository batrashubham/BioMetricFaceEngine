#pragma once

namespace K2OCV {

	class CKinectStreamsMat;

	public ref class CKinectStreamsMatWrapper {
		CKinectStreamsMat* streamsMatSource;

	public:
		CKinectStreamsMatWrapper();
		~CKinectStreamsMatWrapper();
		!CKinectStreamsMatWrapper();

	};

}