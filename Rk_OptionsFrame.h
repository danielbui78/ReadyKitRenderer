//
//  Rk_OptionsFrame.h
//  ReadyKitRenderer
//
//  Created by Daniel Bui on 5/25/15.
//  Copyright (c) 2015 Daniel Bui. All rights reserved.
//

#ifndef __ReadyKitRenderer__Rk_OptionsFrame__
#define __ReadyKitRenderer__Rk_OptionsFrame__

#include "dzoptionsframe.h"
#include "Rk_GraphicsState.h"

class DzFilterNavigationBar;
class DzSideNavPropertyListView;
class DzFileProperty;
class DzStringProperty;
class DzAppSettings;
class DzBoolProperty;
class DzIntProperty;
class DzFloatProperty;
class DzEnumProperty;

class Rk_OptionsFrame : public DzOptionsFrame {
    Q_OBJECT
public:
    //    YaLuxOptions(const QString &label, QWidget *parent=0, const QString &name=QString::null);
    Rk_OptionsFrame( Rk_RendererGraphicsState *gs);
    
    public slots:
    virtual void	applyChanges();
    virtual void	resetOptions();
    virtual bool	applyValid() const;
    virtual void	restoreOptions( DzRenderOptions *options );
    
signals:
    //    void	optionsChanged();
    
public:
    DzAppSettings *settings;
    Rk_RendererGraphicsState *graphicsState;
    
private:
    DzFilterNavigationBar *filterBar;
    DzSideNavPropertyListView *listView;
    
/*
    QStringList maxTextureSizeList = QStringList() << "250" << "500" << "1000" << "2000" << "none";
    QStringList debugLevelList = QStringList() << "Level 0: Errors Only" << "Level 1: Errors and Info" << "Level 2: Errors, Info, Debug" << "Level 3: Verbose Debugging Data";
    QStringList renderModeList = QStringList() << "Software" << "Hardware" << "Custom Render String...";
*/
    
/*
    QStringList toneMapMethodList = QStringList() << "linear" << "autolinear" << "maxwhite" << "contrast" << "reinhard";
    QStringList renderModeList = QStringList() << "Software" << "Hybrid" << "(PATH)OpenCL GPU only" << "(PATH)OpenCL CPU only" << "(PATH)OpenCL GPU+CPU" << "Custom Render String...";
    QStringList specularModeList = QStringList() << "90% Diffuse + 10% Specular" << "Specular * Glossiness" << "(75% Diffuse + 25% Specular) * Glossiness" << "10% Specular" << "Full Specular (may wash-out Diffuse color)" << "Specular Off";
*/
  
    
    // Moved to graphicsState
    // property-widget list
/*
    DzFileProperty      *execPath;
    DzStringProperty    *argumentList;
    DzEnumProperty      *renderMode;
    DzStringProperty    *customRenderString;
    DzEnumProperty      *debugLevel;
    DzBoolProperty      *networkRenderOn;
    DzStringProperty    *renderServerList;
    DzEnumProperty       *maxTextureSize;
    DzBoolProperty      *saveAlphaChannel;
*/
 
/*
    DzBoolProperty      *showLuxWindow;

    DzIntProperty       *haltTime;
    DzIntProperty       *haltSPP;
    DzFloatProperty     *haltThreshold;

    DzFloatProperty     *tonemapGamma;
    DzFloatProperty     *tonemapFstop;
    DzFloatProperty     *tonemapExposureTime;
    DzIntProperty       *tonemapISO;
    DzEnumProperty      *toneMapMethod;

    DzEnumProperty      *specularMode;
*/
};



#endif /* defined(__ReadyKitRenderer__Rk_OptionsFrame__) */
