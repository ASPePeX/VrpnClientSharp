#include "stdafx.h"
#include "VrpnClientController.h"

#pragma once

using namespace VrpnClientLib;

VrpnClientController::VrpnClientController() {

}

void VrpnClientController::mainloop() {
	for (VrpnClientAnalogCallback n : *vrpnAnalogList)
	{
		n.remote->mainloop();
	}
	for (VrpnClientButtonCallback n : *vrpnButtonList)
	{
		n.remote->mainloop();
	}
	for (VrpnClientTrackerCallback n : *vrpnTrackerList)
	{
		n.remote->mainloop();
	}
}

int VrpnClientController::AddAnalog(System::String^ name)
{
	const char* cname = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(name)).ToPointer();

	VrpnClientAnalogCallback* aData = new VrpnClientAnalogCallback(cname);

	vrpnAnalogList->push_back(*aData);

	return vrpnAnalogList->size() -1;
}

int VrpnClientController::AddButton(System::String^ name)
{
	const char* cname = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(name)).ToPointer();

	VrpnClientButtonCallback* aData = new VrpnClientButtonCallback(cname);

	vrpnButtonList->push_back(*aData);

	return vrpnButtonList->size() -1;
}

int VrpnClientController::AddTracker(System::String^ name)
{
	const char* cname = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(name)).ToPointer();

	VrpnClientTrackerCallback* aData = new VrpnClientTrackerCallback(cname);
	
	vrpnTrackerList->push_back(*aData);

	return vrpnTrackerList->size() -1;
}

array<double>^ VrpnClientController::GetAnalogData(int index)
{
	array<double>^ data = gcnew array<double>(2);

	try {
		double *callbackdata = vrpnAnalogList->at(index).GetData();

		data[0] = callbackdata[0];
		data[1] = callbackdata[1];
	}
	catch (const std::out_of_range& e) {
		std::cout << "Error: GetAnalogData() index out of range.";
	}

	return data;
}

array<int>^ VrpnClientController::GetButtonData(int index)
{
	array<int>^ data = gcnew array<int>(2);

	try {
		int *callbackdata = vrpnButtonList->at(index).GetData();

		data[0] = callbackdata[0];
		data[1] = callbackdata[1];
	}
	catch (const std::out_of_range& e) {
		std::cout << "Error: GetButtonData() index out of range.";
	}

	return data;
}

array<double>^ VrpnClientController::GetTrackerData(int index)
{
	array<double>^ data = gcnew array<double>(7);

	try {
		double *callbackdata = vrpnTrackerList->at(index).GetData();

		data[0] = callbackdata[0];
		data[1] = callbackdata[1];
		data[2] = callbackdata[2];
		data[3] = callbackdata[3];
		data[4] = callbackdata[4];
		data[5] = callbackdata[5];
		data[6] = callbackdata[6];
	}
	catch (const std::out_of_range& e) {
		std::cout << "Error: GetTrackerData() index out of range.";
	}

	return data;
}
