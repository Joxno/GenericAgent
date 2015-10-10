#pragma once
#include "PluginMeta.h"
#include "Utility.h"
#include "Packet.h"
#include "InventoryData.h"

#include <windows.h>
#include <string>
#include <functional>
#include <thread>
using namespace std;

namespace Shared
{
	class Plugin
	{
	private:
		HINSTANCE m_DLLHandle = NULL;
		PluginMeta m_MetaData{};
		string m_PluginPath = "";
		thread *m_Thread = nullptr;

		// Plugin Functions
			function<PluginMeta()> F_Register;
			function<void()> F_Execute;
			function<thread*()> F_ExecuteConcurrent;
			function<InventoryData()> F_ExecuteInventory;
			function<void(Packet)> F_HandlePacket;
			function<void()> F_SendPacket;

	public:
		// Interface
			void Execute() { F_Execute(); }
			void ExecuteConcurrent() { m_Thread = F_ExecuteConcurrent(); }
			void ExecuteInventory() { auto t_Data = F_ExecuteInventory(); }
			void HandlePacket(Packet P) {}

		void Initialize(const string &Path)
		{
			if (LoadPlugin(Path))
			{
				cout << "Loaded Plugin Successfully." << endl;
				m_PluginPath = Path;
				m_MetaData = F_Register();
				cout << m_MetaData.GetName() << endl << m_MetaData.GetVersion().GetString() << endl;
			}
			else
				cout << "Could not Load Plugin: " + Path << endl;
		}

		bool IsRegistered() const { return m_MetaData.IsInitialized(); }
		PluginMeta GetMeta() const { return m_MetaData; }

		bool LoadPlugin(const string &Path)
		{
			// Load DLL
			if ( ( m_DLLHandle = LoadLibrary(Path.c_str()) ) == NULL)
				return false;

			// DLL has been loaded successfully
			// Load Functions
			try
			{
				F_Register = LoadDLLFunction<PluginMeta()>(m_DLLHandle, "Register");
				F_Execute = LoadDLLFunction<void()>(m_DLLHandle, "Execute");
				F_ExecuteConcurrent = LoadDLLFunction<thread*()>(m_DLLHandle, "ExecuteConcurrent");
				F_ExecuteInventory = LoadDLLFunction<InventoryData()>(m_DLLHandle, "ExecuteInventory");
				F_HandlePacket = LoadDLLFunction<void(Packet)>(m_DLLHandle, "HandlePacket");
				F_SendPacket = LoadDLLFunction<void()>(m_DLLHandle, "SendPacket");
			}
			catch (exception e)
			{
				cout << e.what() << endl;
				return false;
			}


			return true;
		}

		bool UnloadPlugin()
		{
			if (m_DLLHandle != NULL)
				FreeLibrary(m_DLLHandle);
		}


		~Plugin()
		{
			if (m_DLLHandle != NULL)
				FreeLibrary(m_DLLHandle);
		}
	};

}