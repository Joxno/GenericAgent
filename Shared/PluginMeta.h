#pragma once
#include "Version.h"
#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;

namespace Shared
{

	class PluginMeta
	{
	private:
		string m_Name = "Default";
		Version m_Version;
		bool m_Execute = false;
		bool m_ExecuteConcurrent = false;
		bool m_ExecuteInventory = false;
		bool m_Initialized = false;
		bool m_ExecuteOnLoad = false;
		bool m_ExecuteOnInterval = false;
		bool m_ExecuteOnTime = false;

		duration<double> m_Interval;
		time_point<system_clock> m_TimePoint;
	public:
		PluginMeta() {}
		PluginMeta(string Name, Version V) { m_Name = Name; m_Version = V; m_Initialized = true; }
		void SetExecutionPolicy(bool Exec = false, bool ExecConcurrent = false, bool ExecInv = false) { m_Execute = Exec; m_ExecuteConcurrent = ExecConcurrent; m_ExecuteInventory = ExecInv; }
		void SetTimePolicy(bool Load = false, bool Interval = false, bool Time = false) { m_ExecuteOnLoad = Load; m_ExecuteOnInterval = Interval; m_ExecuteOnTime = Time; }

		string GetName() const { return m_Name; }
		Version GetVersion() const { return m_Version; }
		bool GetExecute() const { return m_Execute; }
		bool GetExecuteConcurrent() const { return m_ExecuteConcurrent; }
		bool GetExecuteInventory() const { return m_ExecuteInventory; }
		bool IsInitialized() const { return m_Initialized; }
		bool GetExecuteOnLoad() const { return m_ExecuteOnLoad; }
		bool GetExcuteOnInterval() const { return m_ExecuteOnInterval; }
		bool GetExecuteOntime() const { return m_ExecuteOnTime; }
	};

}