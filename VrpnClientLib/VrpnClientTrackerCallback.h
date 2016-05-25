#pragma once

using namespace System;

namespace VrpnClientLib
{
	public class VrpnClientTrackerCallback
	{
	public:
		VrpnClientTrackerCallback(const char* devicename);
		~VrpnClientTrackerCallback();

		vrpn_Tracker_Remote* remote;

		double* GetData();
		const char* GetName();

	private:
		const char* name;

		double* data = new double[7];
		void SetData(double p1, double p2, double p3, double q1, double q2, double q3, double q4);

		static void VRPN_CALLBACK handle_tracker(void* userData, const vrpn_TRACKERCB t);
	};
}