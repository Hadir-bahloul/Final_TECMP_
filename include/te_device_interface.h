// te_device_interface.h
#ifndef TE_DEVICE_INTERFACE_H
#define TE_DEVICE_INTERFACE_H

#include <string>

class TE_Device_Interface {
public:
    virtual ~TE_Device_Interface() = default;
    
    // Common device functionality
    
    virtual std::string getDeviceInfo() const = 0;
    virtual int getDeviceId() const = 0;
    virtual std::string getDeviceIP() const = 0;
    // Device type identification
    enum DeviceType {
        BTS_REVO,
        CAPTURE_MODULE
    };
    
    virtual DeviceType getDeviceType() const = 0;
};

#endif // TE_DEVICE_INTERFACE_H