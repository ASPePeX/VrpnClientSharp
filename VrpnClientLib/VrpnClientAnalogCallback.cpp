#include "stdafx.h"
#include "VrpnClientAnalogCallback.h"

using namespace VrpnClientLib;

VrpnClientAnalogCallback::VrpnClientAnalogCallback(const char* devicename)
{
	data[0] = 0;
	data[1] = 0;

	name = devicename;
	remote = new vrpn_Analog_Remote(name);
	remote->register_change_handler(this, handle_analog);
}

VrpnClientAnalogCallback::~VrpnClientAnalogCallback()
{
}

void VrpnClientAnalogCallback::SetData(double a1, double a2)
{
	data[0] = a1;
	data[1] = a2;
}

double* VrpnClientAnalogCallback::GetData()
{
	remote->mainloop();
	return data;
}

const char * VrpnClientLib::VrpnClientAnalogCallback::GetName()
{
	return name;
}

void VRPN_CALLBACK VrpnClientAnalogCallback::handle_analog(void* userData, const vrpn_ANALOGCB a)
{
	static_cast<VrpnClientAnalogCallback*>(userData)->SetData(a.channel[0], a.channel[1]);
}

