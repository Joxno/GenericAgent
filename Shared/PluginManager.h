#pragma once
#include "Utility.h"
#include "Plugin.h"
#include <iostream>
#include <vector>
using namespace std;

namespace Shared
{

	class PluginManager
	{
	private:
		PluginManager() {}

		vector<unique_ptr<Plugin>> m_Plugins;
	public:
		static PluginManager &Instance()
		{
			static PluginManager t_Instance;
			return t_Instance;
		}

		void LoadPlugins();
		void RunPlugins();
	};


}