#ifndef DEVICEFACTORY_H
#define DEVICEFACTORY_H

#include <memory>
#include <vector>
#include <unordered_set>
#include "BTSRevoDevice.h"
#include "CANCaptureModuleDevice.h"
#include "LINCaptureModuleDevice.h"

class DeviceFactory {
private:
    static std::unordered_set<int> usedBTSRevoIds;
    static std::unordered_set<int> usedCaptureModuleIds;
    static void initializeDriver();

public:
    static std::shared_ptr<TE::Driver::ITEDriverIOs> iosInterface;
    static void discoverDevices();
    static std::vector<uint32_t> channels;

// Member variables
    static std::shared_ptr<TE::Driver::ITEDriver> _tecmp_driver_;
    static std::unordered_map<int, std::shared_ptr<BTSRevoDevice>> deviceMap;
    static std::vector<TE::Driver::Devices> _discovered_devices;

    // Create a CANCaptureModuleDevice with a unique ID
    static std::shared_ptr<CaptureModuleDevice> CreateCANCaptureModuleDevice(Base::u16 Id);

    // Create a LINCaptureModuleDevice with a unique ID
    static std::shared_ptr<CaptureModuleDevice> CreateLINCaptureModuleDevice(Base::u16 Id);

    // Discover BTSRevo devices (simulated)
    static std::vector<std::shared_ptr<BTSRevoDevice>> DiscoverBTSRevoDevices();

    // Discover CaptureModule devices (simulated)
    static std::vector<std::shared_ptr<CaptureModuleDevice>> DiscoverCaptureModuleDevices();
};

#endif // DEVICEFACTORY_H