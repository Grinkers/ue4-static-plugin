// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TestPluginPrivatePCH.h"
#include "npp/dynamic.h"

DEFINE_LOG_CATEGORY(TestPlugin)

extern "C" {
	#include "extern/extern.h"
}

class FTestPlugin : public ITestPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FTestPlugin, TestPlugin )



void FTestPlugin::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	auto value = new npp::DummyDynamicLoader();
	UE_LOG(TestPlugin, Log, TEXT("npp::DummyDynamicLoader(): %d"), value);
	delete value;
	auto v2 = rs_trigger(100);
	UE_LOG(TestPlugin, Log, TEXT("rs_trigger(100): %d"), v2);
}


void FTestPlugin::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}
