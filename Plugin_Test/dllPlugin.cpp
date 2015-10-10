#include "dllPlugin.h"
using namespace Shared;
using namespace std;

PluginMeta Register()
{
	PluginMeta t_Info("Test_Plugin", Version(1, 0, 0));
	t_Info.SetExecutionPolicy(true, false, false);


	return t_Info;
}

void Execute()
{
	std::cout << "Executing from DLL." << std::endl;
}

thread *ExecuteConcurrent()
{
	return nullptr;
}

InventoryData ExecuteInventory()
{
	return InventoryData();
}

void HandlePacket(Packet P)
{

}

void SendPacket()
{
}
