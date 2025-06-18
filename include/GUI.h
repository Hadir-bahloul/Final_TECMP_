#ifndef GUI_H
#define GUI_H

#include "BTSRevoDevice.h"
#include "CaptureModuleDevice.h"
#include <vector>
#include <memory>
#include <string>

class GUI {
public:
static std::string Conf_file;
static std::string yaml_file;
static std::vector<std::shared_ptr<BTSRevoDevice>> btsDevices;
static std::vector<std::shared_ptr<CaptureModuleDevice>> captureModules;


static void ImportConf();
static void Initialize();
static void GUI::SetSaveDirectory(const std::string& directory);
static void Render();

static std::string saveDirectory;

private:
    static void ShowImportPopup();
};

#endif // GUI_H
