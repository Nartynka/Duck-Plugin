// Copyright Epic Games, Inc. All Rights Reserved.

#include "DuckPlugin.h"

#define LOCTEXT_NAMESPACE "FDuckPluginModule"

void FDuckPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	MyAssetAssetTypeActions = MakeShared<FMyAssetAssetTypeActions>();
	FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(MyAssetAssetTypeActions.ToSharedRef());
}

void FDuckPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (!FModuleManager::Get().IsModuleLoaded("AssetTools")) 
		return;
	FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(MyAssetAssetTypeActions.ToSharedRef());

}
#undef LOCTEXT_NAMESPACE

IMPLEMENT_PRIMARY_GAME_MODULE(FDuckPluginModule, DuckPlugin, "DuckPlugin")