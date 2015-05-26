//
//  Rk_GraphicsState.cpp
//  ReadyKitRenderer
//
//  Created by Daniel Bui on 5/25/15.
//  Copyright (c) 2015 Daniel Bui. All rights reserved.
//


#include "Rk_GraphicsState.h"
#include "Rk_OptionsFrame.h"

#include "dzrenderoptions.h"
#include "dzappsettings.h"

#include "dzfileio.h"
#include "dzproperty.h"
#include "dzfileproperty.h"
#include "dzenumproperty.h"
#include "dzboolproperty.h"


// This sets the executable extension to be used for the executable selection dialogs and path checking code.
#if defined( Q_OS_WIN )
const char *Rk_ExecutableExt = "exe";
#elif defined( Q_WS_MAC )
const char *Rk_ExecutableExt = "app";
#endif


////////////////////
// RendererGraphicsState Class
//      Method definitions for the GrapicsState Class.  Subclass this class to store all of your
//      relevant state-related information.
////////////////////

// Constructor for the GraphicsState object, which will manage all of our graphics contexts
Rk_RendererGraphicsState::Rk_RendererGraphicsState()
{
    // Initialize the graphics states
    rendererName = "ReadyKit Renderer"; // This is the name which will be displayed by Daz Studio
    renderOptions = new DzRenderOptions;
    
    // Initialize Default Object Attributes
    Rk_ObjectAttributes *oa = new Rk_ObjectAttributes;
    attributeStack.append(*oa);

    settings = new DzAppSettings("rk_renderer");
    
    int i;
    
    // render executable path
    execPath = new DzFileProperty("rk_renderer_executable_path", false);
    execPath->setLabel("Folder to Luxrender Application");
    execPath->setType(DzFileProperty::FileType::FileOpen);
    execPath->setFilter( QString("FilterName (*.%1)").arg(Rk_ExecutableExt));
    connect(execPath, SIGNAL(currentValueChanged()),
            this, SLOT(execPathChanged()) );
    
    // Luxrender executable arguments
    argumentList = new DzStringProperty("rk_renderer_executable_arguments", false);
    argumentList->setLabel("Luxrender Commandline Arguments");
    
    // Render Mode
    renderMode = new DzEnumProperty("rk_renderer_render_mode", false, false);
    renderMode->setLabel("Render Engine");
    for (i=0; i<renderModeList.count(); i++) {
        renderMode->addItem(renderModeList[i]);
    }
    
    // Custom Render String
    customRenderString = new DzStringProperty("rk_renderer_render_custom", false);
    customRenderString->setLabel("Custom Render String (use Custom Render Engine)");
    
    // Max Texture Size
    maxTextureSize = new DzEnumProperty("rk_renderer_max_texturesize", false, false);
    maxTextureSize->setLabel("Maximum Texture Size");
    for (i=0; i<maxTextureSizeList.count(); i++) {
        maxTextureSize->addItem(maxTextureSizeList[i]);
    }
    
    // Debug output level
    debugLevel = new DzEnumProperty("rk_renderer_debug_level", true, false);
    debugLevel->setLabel("Debug Output");
    for (i=0; i<debugLevelList.count(); i++) {
        debugLevel->addItem(debugLevelList[i]);
    }
    
    // network render on/off
    networkRenderOn = new DzBoolProperty("rk_renderer_network_render", false, false, false);
    networkRenderOn->setLabel("Enable Network Rendering");
    
    // render server list
    renderServerList = new DzStringProperty("rk_renderer_network_serverlist", false);
    renderServerList->setLabel("Network Render Servers (IP/hostnames)");
    
    // Save Alpha Channel
    saveAlphaChannel = new DzBoolProperty("rk_renderer_save_alpha", true, false, true);
    saveAlphaChannel->setLabel("Save alpha channel in final rendered image");

    // create the render options frame
    renderOptionsFrame = new Rk_OptionsFrame(this);
    
    setDefaultSettings();
    loadSettings();

}

void Rk_RendererGraphicsState::setDefaultSettings()
{
    /*
     showLuxWindow->setDefaultBoolValue(false);
     haltTime->setDefaultValue(300);
     haltSPP->setDefaultValue(0);
     haltThreshold->setDefaultValue(1.0);
     tonemapGamma->setDefaultValue(2.2);
     tonemapFstop->setDefaultValue(2.8);
     tonemapExposureTime->setDefaultValue(0.5);
     tonemapISO->setDefaultValue(200);
     toneMapMethod->setDefaultValue(0);
     specularMode->setDefaultValue(0);
     */
    renderMode->setDefaultValue(0);
    maxTextureSize->setDefaultValue(4);
    networkRenderOn->setDefaultBoolValue(false);
    saveAlphaChannel->setDefaultBoolValue(true);
    debugLevel->setDefaultValue(0);
    
}

///////////
// Load Settings
///////////
void	Rk_RendererGraphicsState::loadSettings()
{
    if ( settings->getBoolValue("readykit_renderer_settings_exist") )
    {
        execPath->setValue( settings->getStringValue( execPath->getName()) );
        argumentList->setValue( settings->getStringValue( argumentList->getName()) );
        //        showLuxWindow->setBoolValue( settings->getBoolValue( showLuxWindow->getName()) );
        saveAlphaChannel->setBoolValue( settings->getBoolValue( saveAlphaChannel->getName()) );
        debugLevel->setValue( settings->getIntValue( debugLevel->getName()) );
        /*
         haltTime->setValue( settings->getIntValue( haltTime->getName()) );
         haltSPP->setValue( settings->getIntValue( haltSPP->getName()) );
         haltThreshold->setValue( settings->getFloatValue( haltThreshold->getName()) );
         tonemapGamma->setValue( settings->getFloatValue( tonemapGamma->getName()) );
         tonemapFstop->setValue( settings->getFloatValue( tonemapFstop->getName()) );
         tonemapExposureTime->setValue( settings->getFloatValue( tonemapExposureTime->getName()) );
         tonemapISO->setValue( settings->getIntValue( tonemapISO->getName()) );
         toneMapMethod->setValue( settings->getIntValue( toneMapMethod->getName()) );
         */
        renderServerList->setValue( settings->getStringValue( renderServerList->getName()) );
        renderMode->setValue( settings->getIntValue( renderMode->getName()) );
        customRenderString->setValue( settings->getStringValue( customRenderString->getName()) );
        //        specularMode->setValue( settings->getIntValue( specularMode->getName()) );
        networkRenderOn->setBoolValue( settings->getBoolValue( networkRenderOn->getName()) );
        maxTextureSize->setValue( settings->getIntValue( maxTextureSize->getName()) );
    }
}


///////////
// Save Settings
///////////
void	Rk_RendererGraphicsState::saveSettings()
{
    settings->setStringValue(execPath->getName(), execPath->getValue());
    settings->setStringValue(argumentList->getName(), argumentList->getValue());
    //    settings->setIntValue(showLuxWindow->getName(), showLuxWindow->getBoolValue());
    settings->setBoolValue(saveAlphaChannel->getName(), saveAlphaChannel->getBoolValue());
    settings->setIntValue(debugLevel->getName(), debugLevel->getValue());
    /*
     settings->setIntValue(haltTime->getName(), haltTime->getValue());
     settings->setIntValue(haltSPP->getName(), haltSPP->getValue());
     settings->setFloatValue(haltThreshold->getName(), haltThreshold->getValue());
     settings->setFloatValue(tonemapGamma->getName(), tonemapGamma->getValue());
     settings->setFloatValue(tonemapFstop->getName(), tonemapFstop->getValue());
     settings->setFloatValue(tonemapExposureTime->getName(), tonemapExposureTime->getValue());
     settings->setIntValue(tonemapISO->getName(), tonemapISO->getValue());
     settings->setIntValue(toneMapMethod->getName(), toneMapMethod->getValue());
     */
    settings->setStringValue(renderServerList->getName(), renderServerList->getValue());
    settings->setIntValue(renderMode->getName(), renderMode->getValue());
    settings->setStringValue(customRenderString->getName(), customRenderString->getValue());
    //    settings->setIntValue(specularMode->getName(), specularMode->getValue());
    settings->setIntValue(maxTextureSize->getName(), maxTextureSize->getValue());
    settings->setBoolValue(networkRenderOn->getName(), networkRenderOn->getBoolValue());
    
    settings->setBoolValue("readykit_renderer_settings_exist", true);
    
}


// When executable file is selected, change the path setting to point to the executables folder.
void Rk_RendererGraphicsState::execPathChanged()
{
    QString path;
    path = execPath->getValue();
    if ( DzFileIO::getFileExtension(path).contains(Rk_ExecutableExt) )
    {
        path = DzFileIO::getFilePath(path);
        execPath->setValue(path);
    }
}

// Returns the currently active attribute from the graphics stack
QString Rk_RendererGraphicsState::getObjectAttribute()
{
    Rk_ObjectAttributes *activeAttributes = &attributeStack.last();
    return activeAttributes->objectAttribute;
}

