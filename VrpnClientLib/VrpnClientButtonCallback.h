#pragma once

using namespace System;

namespace VrpnClientLib
{
	public class VrpnClientButtonCallback
	{
	public:
		VrpnClientButtonCallback(const char* devicename);
		~VrpnClientButtonCallback();

		vrpn_Button_Remote* remote;

		int* GetData();
		const char* GetName();

	private:
		const char* name;

		int* data = new int[2];
		void SetData(int f1, int f2);

		static void VRPN_CALLBACK handle_button(void* userData, const vrpn_BUTTONCB b);
	};
}