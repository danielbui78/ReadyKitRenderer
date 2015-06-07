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

#include "dzpropertylistview.h"
#include "dzfilternavigationbar.h"
#include "dzsidenavpropertylistview.h"
#include "DzDynamicDividerWgt.h"
#include "dzdividerbar.h"

///////////////////
// Rk_OptionsFrame Constructor
//  This is the Frame class which encapsulates all of the Renderer settings which show up on the "Advanced" tab on the Render Pane.
//  We need to create our widgets for the settings tab here.
///////////////////////
Rk_OptionsFrame::Rk_OptionsFrame(Rk_RendererGraphicsState *gs) : DzOptionsFrame("ReadyKit Options Frame", 0, "ReadyKit Options Frame")
{
    graphicsState = gs;
    
    QHBoxLayout *hlayout = new QHBoxLayout(this);
    
    QListView *groupList = new QListView(this);
    QFrame *contentFrame = new QFrame(this);
//    DzDividerBar *dividerBar = new DzDividerBar(this, Qt::Vertical);
    DzDynamicDividerWgt *dividerWgt = new DzDynamicDividerWgt(groupList, contentFrame, this, Qt::Vertical);
    dividerWgt->setMargin(0);
    
    layout1 = new QVBoxLayout(contentFrame);
    layout1->setMargin(0);
    
    filterBar = new DzFilterNavigationBar(contentFrame);
    filterBar->setAutoHidePageNavigation(true);
    filterBar->setPageSizeVisible(false);
    filterBar->setPageViewVisible(false);
    filterBar->setPageNavigationVisible(false);
    filterBar->setPageLabelVisible(false);
    
    propertiesList = new DzSideNavPropertyListView(contentFrame);
    connect(filterBar, SIGNAL(filterChanged(const QString &)),
            propertiesList, SLOT(setFilterString(const QString &)) );
    
    // connect the graphicsState render options to the UI
    // ...more specifically, connect the properties data model to the listview
    propertiesList->addProperty(gs->execPath);
    propertiesList->addProperty(gs->argumentList);
    propertiesList->addProperty(gs->renderMode);
    propertiesList->addProperty(gs->customRenderString);
    propertiesList->addProperty(gs->debugLevel);
    propertiesList->addProperty(gs->networkRenderOn);
    propertiesList->addProperty(gs->renderServerList);
    propertiesList->addProperty(gs->maxTextureSize);
    propertiesList->addProperty(gs->saveAlphaChannel);
    
//    propertiesList->setModel(gs->propertyListModel);
    groupList->setModel(gs->propertyListModel);
    
    layout1->addWidget(filterBar);
    layout1->addWidget(propertiesList);

    hlayout->addWidget(dividerWgt);
//    hlayout->addWidget(groupList);
//    hlayout->addWidget(dividerBar);
    
//    hlayout->addWidget(filterBar);
//    hlayout->addWidget(propertiesList);
//    hlayout->addWidget(contentFrame);
//    hlayout->addWidget(filterBar);
    hlayout->setMargin(0);
    
//    contentFrame->setLayout(layout1);
    this->setLayout(hlayout);
//      this->setLayout(layout1);
    
}

/////////////////////
// Rk_OptionsFrame() Destructor
//      This class is deleted whenever the renderer changes.  Thus, we need
//      to do object cleanup and then reset the the graphicsState pointer since
//      this object is about to be deleted.
/////////////////////
Rk_OptionsFrame::~Rk_OptionsFrame()
{
    delete propertiesList;
    delete layout1;
    delete filterBar;
    
    // Set the graphicsState pointer back to NULL since we don't want it
    // pointing into deleted space.
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