#pragma once

#include <vector>
#include <string>
#include <memory>
#include "BTSRevoDevice.h"
#include "CaptureModuleDevice.h"
#include "Logging.h"

struct ScriptWindow;
class GenericScriptGUI
{

public:
	GenericScriptGUI();
	~GenericScriptGUI(); 
	static void Render(std::vector<std::shared_ptr<BTSRevoDevice>>& btsDevices,
		std::vector<std::shared_ptr<CaptureModuleDevice>>& captureModules,
		const std::string& saveDirectory,
		bool& isDarkTheme);

private:

	static std::string tempScriptDirectory;// Directory for temporary script files
	static std::unordered_map<std::string, std::string> scriptToTempFileMap; // Map script names to temp files

	static void LoadTempScripts(std::vector<ScriptWindow>& scriptWindows);
	static void ShowImportPopup(bool& showPopup, ScriptWindow& currentWindow);
	static void SaveToTempFile(const std::string& script, const std::string& windowName);
	static void RunScript(const std::string& script, const std::string& saveDirectory);

};