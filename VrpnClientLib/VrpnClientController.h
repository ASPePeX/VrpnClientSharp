#include "stdafx.h"
#include "VrpnClientAnalogCallback.h"
#include "VrpnClientButtonCallback.h"
#include "VrpnClientTrackerCallback.h"

#include <vector>
#include <list>
#pragma once

using namespace System;

namespace VrpnClientLib {

	public ref class VrpnClientController
	{
	public:
		VrpnClientController();
		int AddAnalog(System::String^ name);
		int AddButton(System::String^ name);
		int AddTracker(System::String^ name);
		array<double>^	GetAnalogData(int index);
		array<int>^		GetButtonData(int index);
		array<double>^	GetTrackerData(int index);

	private:
		std::vector<VrpnClientAnalogCallback>* vrpnAnalogList = new std::vector<VrpnClientAnalogCallback>;
		std::vector<VrpnClientButtonCallback>* vrpnButtonList = new std::vector<VrpnClientButtonCallback>;
		std::vector<VrpnClientTrackerCallback>* vrpnTrackerList = new std::vector<VrpnClientTrackerCallback>;
	};
};


