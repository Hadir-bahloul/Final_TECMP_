// btsinterface.h
#ifndef BTSINTERFACE_H
#define BTSINTERFACE_H

#include "te_device_interface.h"
#include <vector>
#include <string>
#include <functional>
#include <utility>

class BTSInterface : public TE_Device_Interface {
public:
    virtual ~BTSInterface() = default;
    //device details
    DeviceType getDeviceType() const override { return BTS_REVO; }
    virtual std::string getDeviceIP() const override = 0;
    // Channel control
    virtual void activateChannel(int channelId) = 0;
    virtual void deactivateChannel(int channelId) = 0;
    virtual bool isChannelActive(int channelId) const = 0;
    // Measurement functions
    virtual float measureVoltage(int channelId) = 0;
    virtual float measureCurrent(int channelId) = 0;
};

#endif // BTSINTERFACE_H