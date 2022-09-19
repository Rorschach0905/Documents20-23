#include "PluginParticleFactoryCore.h"
#include "CSnooker.h"

using namespace NApiFactory;

EXPORT_MACRO IPluginParticleFactory* GETFACTORYINSTANCE()
{
    return new CSnooker();
}

EXPORT_MACRO void RELEASEFACTORYINSTANCE(IPluginParticleFactory* instance)
{
    if (0 != instance)
    {
        delete instance;
    }
}

EXPORT_MACRO int GETFACTINTERFACEVERSION()
{
    static const int INTERFACE_VERSION_MAJOR = 0x02;
    static const int INTERFACE_VERSION_MINOR = 0x01;
    static const int INTERFACE_VERSION_PATCH = 0x00;

    return (INTERFACE_VERSION_MAJOR << 16 |
            INTERFACE_VERSION_MINOR << 8 |
            INTERFACE_VERSION_PATCH);
}

