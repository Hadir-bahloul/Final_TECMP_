#ifndef CAPTUREMODULEINTERFACE_H
#define CAPTUREMODULEINTERFACE_H

#include "te_device_interface.h"
#include <string>
#include "Logging.h"

class CaptureModuleInterface : public TE_Device_Interface {
public:
    virtual ~CaptureModuleInterface() = default;
    
    virtual std::string GetType() const = 0;
};

#endif // CAPTUREMODULEINTERFACE_H