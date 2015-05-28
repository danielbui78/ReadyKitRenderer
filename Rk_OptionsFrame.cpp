//
//  Rk_OptionsFrame.cpp
//  ReadyKitRenderer
//
//  Created by Daniel Bui on 5/25/15.
//  Copyright (c) 2015 Daniel Bui. All rights reserved.
//

#include "Rk_OptionsFrame.h"

#include <QtGUI/QLayout>
#include <QtGUI/QTreeWidget>

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
    graphicsState = gs;
    
    layout1 = new QVBoxLayout(this);
    
    filterBar = new DzFilterNavigationBar(this);
    filterBar->setAutoHidePageNavigation(true);
    filterBar->setPageSizeVisible(false);
    filterBar->setPageViewVisible(false);
    filterBar->setPageNavigationVisible(false);
    filterBar->setPageLabelVisible(false);

//    tree = new QTreeView(this);
    
    listView = new DzSideNavPropertyListView(this);
    connect(filterBar, SIGNAL(filterChanged(const QString &)),
            listView, SLOT(setFilterString(const QString &)) );
    
    // connect the graphicsState render options to the UI
/*
    listView->addProperty(gs->execPath);
    listView->addProperty(gs->argumentList);
    listView->addProperty(gs->renderMode);
    listView->addProperty(gs->customRenderString);
    listView->addProperty(gs->maxTextureSize);
    listView->addProperty(gs->debugLevel);
    listView->addProperty(gs->renderServerList);
    listView->addProperty(gs->saveAlphaChannel);
*/
//    tree->setModel(gs->propertyListModel);
    listView->setModel(gs->propertyListModel);
    
    layout1->addWidget(filterBar);
//    layout1->addWidget(tree);
    layout1->addWidget(listView);
    
    this->setLayout(layout1);

    
}

/////////////////////
// Rk_OptionsFrame() Destructor
//      This class is deleted whenever the renderer changes.  Thus, we need
//      to do object cleanup and then reset the the graphicsState pointer since
//      this object is about to be deleted.
/////////////////////
Rk_OptionsFrame::~Rk_OptionsFrame()
{
    delete listView;
    delete layout1;
    delete filterBar;
    
    graphicsState->renderOptionsFrame = NULL;
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
    graphicsState->loadSettings();
}