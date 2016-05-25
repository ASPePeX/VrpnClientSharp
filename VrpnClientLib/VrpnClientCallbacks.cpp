#include "VrpnClientCallbacks.h"

void VRPN_CALLBACK VrpnClientCallbacks::handle_analog(void* userData, const vrpn_ANALOGCB a)
{
	reinterpret_cast<VrpnClientAnalogCallback*>(userData)->SetData(a.channel[0], a.channel[1]);
}

void VRPN_CALLBACK VrpnClientCallbacks::handle_button(void* userData, const vrpn_BUTTONCB b)
{
	std::cout << "Button '" << b.button << "': " << b.state << std::endl;
}


void VRPN_CALLBACK VrpnClientCallbacks::handle_tracker(void* userData, const vrpn_TRACKERCB t)
{
	std::cout << "Tracker '" << t.sensor << "' : " << t.pos[0] << "," << t.pos[1] << "," << t.pos[2] << std::endl;
}