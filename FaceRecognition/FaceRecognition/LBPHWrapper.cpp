#include "stdafx.h"
#include "LBPHWrapper.h"
#include "LBPHTrainer.h"

namespace K2OCV {

	LBPHWrapper::LBPHWrapper()
	{
		lbph = new LBPHTrainer();
	}

	LBPHWrapper::~LBPHWrapper()
	{
		this->!LBPHWrapper();
	}

	LBPHWrapper::!LBPHWrapper()
	{

	}

	void LBPHWrapper::train()
	{
		lbph->train();
	}

}