#pragma once

using namespace System;

namespace VrpnClientLib
{
	public class VrpnClientAnalogCallback
	{
	public:
		VrpnClientAnalogCallback(const char* devicename);
		~VrpnClientAnalogCallback();

		vrpn_Analog_Remote* remote;

		double* GetData();
		const char* GetName();

	private:
		const char* name;

		double* data = new double[2];
		void SetData(double f1, double f2);

		static void VRPN_CALLBACK handle_analog(void* userData, const vrpn_ANALOGCB a);
	};
}