#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FUniversalUtilitiesModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
#if WITH_EDITOR
    // 디테일 패널에 커스텀 섹션 추가
    static void RegisterSectionMappings();
#endif
};
