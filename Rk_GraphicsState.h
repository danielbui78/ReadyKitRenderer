//
//  Rk_GraphicsState.h
//  ReadyKitRenderer
//
//  Created by Daniel Bui on 5/25/15.
//  Copyright (c) 2015 Daniel Bui. All rights reserved.
//

#ifndef __ReadyKitRenderer__Rk_GraphicsState__
#define __ReadyKitRenderer__Rk_GraphicsState__

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QRect>

class DzRenderData;
class QFrame;
class QTextEdit;
class DzProgress;
class DzObject;

class DzRenderOptions;
class DzOptionsFrame;
class DzRenderHandler;
class QFrame;
class QTextEdit;
class DzProgress;
class DzNode;
class DzMaterial;
class DzShape;

class DzBoolProperty;
class DzIntProperty;
class DzFloatProperty;
class DzEnumProperty;
class DzFileProperty;
class DzStringProperty;
class DzAppSettings;

////////////////////////
// RendererGraphicsState
//      This class will encapsulate all the data and stack functionallity for the graphics state / context.
//      This class can be subclassed and used to store all the renderer-specific state information.
//      Terminology:
//          Options == scene-wide parameters which should not change within a scene
//          Attributes == parameters which can vary from object to object
///////////////////////
class Rk_RendererGraphicsState : QObject {
Q_OBJECT
public: // methods
    Rk_RendererGraphicsState();

    
public slots:
    void execPathChanged();
    void loadSettings();
    void saveSettings();
    
    // placeholder member
    QString getObjectAttribute();
    
public: // members
    QString rendererName;
    DzAppSettings *settings;
    DzRenderOptions *renderOptions;
    DzOptionsFrame *renderOptionsFrame;
    DzRenderHandler *activeRenderHandler;
    
    QFrame *logWindow;
    QTextEdit *logBuffer;
    DzProgress *renderProgress;
    DzProgress *frameProgress;
    
    // scene-wide render options
    bool bIsRendering;
    int totalFrames;
    int frame_counter;
    int activeFrame;
    int endFrame;
    bool bIsSpotRender;
    QRect cropWindow;
    
    QStringList maxTextureSizeList = QStringList() << "250" << "500" << "1000" << "2000" << "none";
    QStringList debugLevelList = QStringList() << "Level 0: Errors Only" << "Level 1: Errors and Info" << "Level 2: Errors, Info, Debug" << "Level 3: Verbose Debugging Data";
    QStringList renderModeList = QStringList() << "Software" << "Hardware" << "Custom Render String...";

    // Render Options
    DzFileProperty      *execPath;
    DzStringProperty    *argumentList;
    DzEnumProperty      *renderMode;
    DzStringProperty    *customRenderString;
    DzEnumProperty      *debugLevel;
    DzBoolProperty      *networkRenderOn;
    DzStringProperty    *renderServerList;
    DzEnumProperty      *maxTextureSize;
    DzBoolProperty      *saveAlphaChannel;
    
    // filenames, temporary files
    QString tempPath; // directory to store all temporary generated files
    QString imageCachePath; // path to cache the image files that have already been converted to a render engine-specific/compliant format
    QString sceneFilename;
    QString temporaryRenderFilename;
    
    struct Rk_ObjectAttributes
    {
        DzNode *currentNode;
        DzShape *currentShape;
        DzObject *currentObject;
        DzMaterial *currentMaterial;
        
        // place holder member
        QString objectAttribute;
    };
    QList<Rk_ObjectAttributes> attributeStack;

private:
    void setDefaultSettings();
    
};

#endif /* defined(__ReadyKitRenderer__Rk_GraphicsState__) */
