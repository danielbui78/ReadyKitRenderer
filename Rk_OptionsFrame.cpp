//
//  Rk_OptionsFrame.cpp
//  ReadyKitRenderer
//
//  Created by Daniel Bui on 5/25/15.
//  Copyright (c) 2015 Daniel Bui. All rights reserved.
//

#include "Rk_OptionsFrame.h"

#include <QtGUI/QLayout>

#include "dzappsettings.h"
#include "dzfileio.h"

#include "dzproperty.h"
#include "dzfileproperty.h"
#include "dzenumproperty.h"
#include "dzboolproperty.h"


#include "dzfilternavigationbar.h"
#include "dzsidenavpropertylistview.h"

///////////////////
// Rk_OptionsFrame Constructor
//  This is the Frame class which encapsulates all of the Renderer settings which show up on the "Advanced" tab on the Render Pane.
//  We need to create our widgets for the settings tab here.
///////////////////////
Rk_OptionsFrame::Rk_OptionsFrame(Rk_RendererGraphicsState *gs) : DzOptionsFrame("ReadyKit Options Frame", 0, "ReadyKit Options Frame")
{
    // connect the graphicsState render options to the UI
    graphicsState = gs;
    
    QVBoxLayout *layout1 = new QVBoxLayout(this);
    
    filterBar = new DzFilterNavigationBar(this);
    filterBar->setAutoHidePageNavigation(true);
    filterBar->setPageSizeVisible(false);
    filterBar->setPageViewVisible(false);
    filterBar->setPageNavigationVisible(false);
    filterBar->setPageLabelVisible(false);
    
    listView = new DzSideNavPropertyListView(this);
    connect(filterBar, SIGNAL(filterChanged(const QString &)),
            listView, SLOT(setFilterString(const QString &)) );
    
    layout1->addWidget(filterBar);
    layout1->addWidget(listView);
    
    listView->addProperty(gs->execPath);
    listView->addProperty(gs->argumentList);
    listView->addProperty(gs->renderMode);
    listView->addProperty(gs->customRenderString);
    listView->addProperty(gs->maxTextureSize);
    listView->addProperty(gs->debugLevel);
    listView->addProperty(gs->renderServerList);
    listView->addProperty(gs->saveAlphaChannel);
    
    this->setLayout(layout1);
    
}





void	Rk_OptionsFrame::applyChanges()
{
   
    // DEBUG - find a place for this
    graphicsState->saveSettings();
    
};

void	Rk_OptionsFrame::resetOptions()
{
    // TODO: should I set to default or reload from saved data?
    // DEBUG
};

bool    Rk_OptionsFrame::applyValid() const
{
    return true;
}

void	Rk_OptionsFrame::restoreOptions( DzRenderOptions *options )
{
    
};