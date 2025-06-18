#ifndef LINCAPTUREMODULEDEVICE_H
#define LINCAPTUREMODULEDEVICE_H

#include "CaptureModuleDevice.h"

#include <TE-DriverBase/DriverBaseInitData.hpp>

class LINCaptureModuleDevice : public CaptureModuleDevice {
public:
    LINCaptureModuleDevice(TE::Base::u16 index);
    std::string GetType() const override;
};

#endif // LINCAPTUREMODULEDEVICE_H