#include <iostream>
#include "PluginManager.h"
#include "Version.h"
using namespace std;

int main()
{
	Shared::PluginManager::Instance().LoadPlugins();
	Shared::PluginManager::Instance().RunPlugins();
}