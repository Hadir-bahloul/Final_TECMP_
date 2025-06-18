#ifndef CANCAPTUREMODULEDEVICE_H
#define CANCAPTUREMODULEDEVICE_H

#include "CaptureModuleDevice.h"

#include <TE-DriverBase/DriverBaseInitData.hpp>

class CANCaptureModuleDevice : public CaptureModuleDevice {
public:
    CANCaptureModuleDevice(TE::Base::u16 index);
    std::string GetType() const override;
};

#endif // CANCAPTUREMODULEDEVICE_H