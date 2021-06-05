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
class QVBoxLayout;

class Rk_OptionsFrame : public DzOptionsFrame {
    Q_OBJECT
public:
    Rk_OptionsFrame( Rk_RendererGraphicsState *gs);
    ~Rk_OptionsFrame();
    
    public slots:
    virtual void	applyChanges();
    virtual void	resetOptions();
    virtual bool	applyValid() const;
    virtual void	restoreOptions( DzRenderOptions *options );
    
signals:
    //    void	optionsChanged();
    
public:
    Rk_RendererGraphicsState *graphicsState;
    
private:
    DzFilterNavigationBar *filterBar;
    DzSideNavPropertyListView *propertiesListView;

};



#endif /* defined(__ReadyKitRenderer__Rk_OptionsFrame__) */
