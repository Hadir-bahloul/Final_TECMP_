#ifndef BTSREVOGUI_H
#define BTSREVOGUI_H

#include "BTSRevoDevice.h"
#include "Themes.h"
#include "implot.h"
#include <string>
#include <map>
class BTSRevoGUI
{
public:
    static std::map<int, std::string> mapHwChannelsToSignals(int boardId, const std::string &yamlContent) noexcept;
    static void RenderControlPanel(BTSRevoDevice &device, bool &isDarkTheme, const std::string &directoryPath);
private:
    static void RenderDaggers(BTSRevoDevice &device, bool &isDarkTheme);
    static void RenderBlitzes(BTSRevoDevice &device, bool &isDarkTheme);
    static void RenderChannels(BTSRevoDevice &device, bool &isDarkTheme);
    static void RenderLogs(BTSRevoDevice &device, bool &isDarkTheme);
    static void RenderPopup(BTSRevoDevice &device, bool &isDarkTheme, int i, const char *base_functions[] );
    static void RenderIOTable(BTSRevoDevice &device, bool &isDarkTheme);
    static void ExportChannelMeasurements(BTSRevoDevice &device, const std::string &directoryPath);
};

#endif // BTSREVOGUI_H