#ifndef BTSREVODEVICE_H
#define BTSREVODEVICE_H

#include "BTSInterface.h"
#include "Logging.h"
#include "TE-Base/Types.hpp"
#include "TE-DriverBase/DriverBaseTypes.hpp"
#include <vector>
#include <string>
#include <ctime>
#include "imgui.h"
using namespace std;
using namespace TE::Driver;
using namespace TE;

// Constants for BTS_Revo
const int NUM_DAGGERS = 6;
const int NUM_BLITZES = 3;
const int CHANNELS_PER_BLITZ = 8;
const int TOTAL_CHANNELS = 24;
const int CHANNELS_PER_DAGGER = 4;

struct ChannelMeasurement
{
    float voltage = 0.0f;
    float current = 0.0f;
    bool isActive = false;
    bool isSelected = false;
    float pwmFrequency = 0.0f;
    float pwmDutyCycle = 0.0f;
};

class BTSRevoDevice : public BTSInterface, public TE::Driver::Devices
{
public:
static double voltage;
static double current;
static bool wasUserActivated[TOTAL_CHANNELS];
bool isBlitzActive = false;
bool isDaggerActive = false;
bool Blitz = false;
bool Dagger = false;

    BTSRevoDevice(TE::Base::u16 deviceType,TE::Base::u16 deviceId, const std::string& deviceIp);
    ~BTSRevoDevice() override = default;
    //IO measurements control
    void setChannelVoltage(int channel, float voltage) {
        channelMeasurements[channel].voltage = voltage;
    }
    void setChannelCurrent(int channel, float current) {
        channelMeasurements[channel].current = current;
    }
    //hw functions
    static void OpenLoad(Base::u8 btsBoardNumber, Base::u8 channelNumber,  bool enable);
    static void shortVBat(Base::u8 btsBoardNumber, Base::u8 channelNumber, bool value);
    static void shortGnd(Base::u8 btsBoardNumber, Base::u8 channelNumber, bool value);
    static void generatePWM(Base::u8 btsBoardNumber, Base::u8 channelNumber, bool enable, Base::u16 onTime, Base::u16 offTime);
    // BTSInterface implementation
    void activateChannel(int channelId) override;
    void deactivateChannel(int channelId) override;
    bool isChannelActive(int channelId) const override;
    float measureVoltage(int channelId) override;
    float measureCurrent(int channelId) override;
    DeviceType getDeviceType() const override { return BTS_REVO; }
    std::string getDeviceIP() const override;
    
    std::string getDeviceInfo() const override;
    int getDeviceId() const override;

    // Original BTSRevoDevice methods
    void UpdateChannelActivation();
    bool hasDagger[NUM_DAGGERS];
    bool hasBlitz[NUM_BLITZES];
    ChannelMeasurement channelMeasurements[TOTAL_CHANNELS];
    int defaultChannelId;
    int selectedChannelId;
};

#endif // BTSREVODEVICE_H