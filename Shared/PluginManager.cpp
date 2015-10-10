#include "PluginManager.h"
#include <filesystem>
#include <string>
#include <experimental\filesystem>
namespace fs = std::experimental::filesystem;

namespace Shared
{

	void PluginManager::LoadPlugins()
	{
		auto t_PluginsFolder = "Plugins";
		for (auto &t_Entry : fs::directory_iterator(t_PluginsFolder))
		{
			auto t_Ext = t_Entry.path().extension().string();
			if (!fs::is_directory(t_Entry) && !strcmp(t_Ext.c_str(), ".dll"))
			{
				auto t_Plugin = make_unique<Plugin>();
				t_Plugin->Initialize(t_Entry.path().string());
				m_Plugins.push_back(move(t_Plugin));
			}
		}

	}

	void PluginManager::RunPlugins()
	{
		for (auto &t_Plugin : m_Plugins)
			if (t_Plugin->IsRegistered())
			{
				if (t_Plugin->GetMeta().GetExecute())
					t_Plugin->Execute();
			}
	}

}