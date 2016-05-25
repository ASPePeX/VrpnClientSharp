#include "stdafx.h"
#include "VrpnClientButtonCallback.h"

using namespace VrpnClientLib;

VrpnClientButtonCallback::VrpnClientButtonCallback(const char* devicename)
{
	data[0] = 0;
	data[1] = 0;

	name = devicename;
	remote = new vrpn_Button_Remote(name);
	remote->register_change_handler(this, handle_button);
}

VrpnClientButtonCallback::~VrpnClientButtonCallback()
{
}

void VrpnClientButtonCallback::SetData(int b1, int b2)
{
	data[0] = b1;
	data[1] = b2;
}

int* VrpnClientButtonCallback::GetData()
{
	return data;
}

const char * VrpnClientLib::VrpnClientButtonCallback::GetName()
{
	return name;
}

void VRPN_CALLBACK VrpnClientButtonCallback::handle_button(void* userData, const vrpn_BUTTONCB b)
{
	static_cast<VrpnClientButtonCallback*>(userData)->SetData(b.button, b.state);
}

