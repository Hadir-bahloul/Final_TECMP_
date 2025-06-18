#ifndef LEGACYGUI_H
#define LEGACYGUI_H

#include "CaptureModuleDevice.h"
#include "BTSRevoDevice.h"
#include "Logging.h"
#include "Themes.h"
#include <vector>
#include <memory>
#include <imgui.h>

class LegacyGUI {
protected:

int filterId;
int channels;
bool isConnected;

std::string type;
std::string saveDirectory;
std::vector<uint32_t> canChannels;
std::vector<uint32_t> linChannels;
std::string flexrayChannel;
std::vector<std::string> wsChannels;

std::atomic<bool> isCapturing{false};
std::thread captureThread;
public:
    static void RenderCaptureModuleControl(std::shared_ptr<CaptureModuleDevice> device, int selectedCaptureModuleIndex,const std::string& directoryPath, bool& isDarkTheme);
    static void RenderSendMessagePopup(std::shared_ptr<CaptureModuleDevice> device, bool& isDarkTheme,std::string channel);
    static void RenderMessagesTable(const std::vector<Message>& msgs,bool& isDarkTheme);
    static void ExportCaptureData(CaptureModuleDevice& device, const std::string& directoryPath,int selectedCaptureModuleIndex);
};

#endif // LEGACYGUI_H