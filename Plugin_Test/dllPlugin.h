#pragma once
#include "PluginMeta.h"
#include "InventoryData.h"
#include "Packet.h"
#include "Utility.h"
#include <thread>

EXTERN_C DLL_EXPORT Shared::PluginMeta Register();
EXTERN_C DLL_EXPORT void Execute();
EXTERN_C DLL_EXPORT std::thread *ExecuteConcurrent();
EXTERN_C DLL_EXPORT Shared::InventoryData ExecuteInventory();
EXTERN_C DLL_EXPORT void HandlePacket(Shared::Packet P);
EXTERN_C DLL_EXPORT void SendPacket();