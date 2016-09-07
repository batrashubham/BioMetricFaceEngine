#pragma once

namespace K2OCV {

	class LBPHTrainer;

	public ref class LBPHWrapper {
		LBPHTrainer* lbph;
		
	public:
		LBPHWrapper();
		~LBPHWrapper();
		!LBPHWrapper();

		void train();
	};

}