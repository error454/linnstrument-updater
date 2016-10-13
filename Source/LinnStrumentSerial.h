/*
 Copyright 2014 Roger Linn Design (www.rogerlinndesign.com)
 
 Written by Geert Bevin (http://gbevin.com).
 
 This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/
 or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#ifndef LINNSTRUMENTSERIAL_H_INCLUDED
#define LINNSTRUMENTSERIAL_H_INCLUDED

#include "JuceHeader.h"

class LinnStrumentSerial
{
public:
    LinnStrumentSerial() : projectCount(0), projectSize(0) {};
    virtual ~LinnStrumentSerial() {};

    virtual String getFullLinnStrumentDevice() = 0;
    virtual bool findFirmwareFile() = 0;
    virtual bool hasFirmwareFile() = 0;
    virtual bool detect() = 0;
    virtual bool isDetected() = 0;
    virtual bool prepareDevice() = 0;
    virtual bool performUpgrade() = 0;
    
    bool readSettings();
    bool restoreSettings();
    
private:
	MemoryBlock settings;
    MemoryBlock projects;
    uint8_t projectCount;
    uint32_t projectSize;
};

#endif  // LINNSTRUMENTSERIAL_H_INCLUDED
