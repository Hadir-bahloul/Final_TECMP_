#ifndef CAPTUREMODULEDEVICE_H
#define CAPTUREMODULEDEVICE_H

#include "CaptureModuleInterface.h"
#include "TE-DriverBase/DriverBaseTypes.hpp"
#include <string>
#include <vector>
#include <mutex>
#include <thread>
#include <atomic>

struct Message {
    std::string timestamp;
    std::string fieldId;
    int dataLength;
    std::string data;
    std::string dataFlags;
};

class CaptureModuleDevice : public CaptureModuleInterface, public TE::Driver::Devices {
protected:
    int channels;
    bool isConnected;
    std::string type;
    std::string saveDirectory;
    std::mutex dataMutex;
    std::string flexrayChannel;
    std::vector<std::string> wsChannels;
 
    std::vector<Message>::iterator FindMessageByFieldId(const std::string& fieldId);

public:
std::vector<std::string> canChannels;
std::vector<std::string> linChannels;
std::atomic<bool> isCapturing{false};
std::thread captureThread;
std::vector<Message> messages;
static std::vector<Message> frame;

    CaptureModuleDevice(TE::Base::u16 deviceType,TE::Base::u16 deviceId, const std::string& deviceIp);
    virtual ~CaptureModuleDevice();
    virtual std::string GetType() const = 0;
    int getDeviceId() const override { return deviceId; }
    std::string getDeviceInfo() const override {
        return type + " Capture Module ID: " + std::to_string(deviceId) ;
    }
    std::string getDeviceIP() const override;
    DeviceType getDeviceType() const override { return CAPTURE_MODULE; }

    //hw functions
    static void sendCanMessage(TE::Base::u16 deviceId, int channelNum, uint32_t messageId, bool isExtendedId, TE::Base::u8 dataLength, const std::vector<TE::Base::u8>& dataVector);
    static void sendLinMessage(TE::Base::u16 deviceId, int channelNum, uint32_t messageId , const std::vector<TE::Base::u8>& dataVector);
    // Channel accessors
    const std::vector<std::string>& GetCanChannels() const { return canChannels; }
    const std::vector<std::string>& GetLinChannels() const { return linChannels; }
    const std::string& GetFlexrayChannel() const { return flexrayChannel; }
    const std::vector<std::string>& GetWsChannels() const { return wsChannels; }

};

#endif // CAPTUREMODULEDEVICE_H