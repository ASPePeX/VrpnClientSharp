#include "stdafx.h"
#include "VrpnClientTrackerCallback.h"

using namespace VrpnClientLib;

VrpnClientTrackerCallback::VrpnClientTrackerCallback(const char* devicename)
{
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	data[3] = 0;
	data[4] = 0;
	data[5] = 0;
	data[6] = 0;

	name = devicename;
	remote = new vrpn_Tracker_Remote(name);
	remote->register_change_handler(this, handle_tracker);
}

VrpnClientTrackerCallback::~VrpnClientTrackerCallback()
{
}

void VrpnClientTrackerCallback::SetData(double p1, double p2, double p3, double q1, double q2, double q3, double q4)
{
	data[0] = p1;
	data[1] = p2;
	data[2] = p3;
	data[3] = q1;
	data[4] = q2;
	data[5] = q3;
	data[6] = q4;
}

double* VrpnClientTrackerCallback::GetData()
{
	return data;
}

const char * VrpnClientLib::VrpnClientTrackerCallback::GetName()
{
	return name;
}

void VRPN_CALLBACK VrpnClientTrackerCallback::handle_tracker(void* userData, const vrpn_TRACKERCB t)
{
	static_cast<VrpnClientTrackerCallback*>(userData)->SetData(t.pos[0], t.pos[1], t.pos[2], t.quat[0], t.quat[1], t.quat[2], t.quat[3]);
}

