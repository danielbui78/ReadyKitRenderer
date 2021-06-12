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

    DzDynamicDividerWgt *dividerWgt = new DzDynamicDividerWgt(groupList, contentFrame, this, Qt::Vertical);
    dividerWgt->setMargin(0);
    
    QVBoxLayout *vlayout = new QVBoxLayout(contentFrame);
    vlayout->setMargin(0);
    
    filterBar = new DzFilterNavigationBar(contentFrame);
    filterBar->setAutoHidePageNavigation(true);
    filterBar->setPageSizeVisible(false);
    filterBar->setPageViewVisible(false);
    filterBar->setPageNavigationVisible(false);
    filterBar->setPageLabelVisible(false);
    
    propertiesListView = new DzSideNavPropertyListView(contentFrame);
    connect(filterBar, SIGNAL(filterChanged(const QString &)),
            propertiesListView, SLOT(setFilterString(const QString &)) );
    
    // connect the graphicsState render options to the UI
    propertiesListView->addProperty(gs->execPath);
    propertiesListView->addProperty(gs->argumentList);
    propertiesListView->addProperty(gs->renderMode);
    propertiesListView->addProperty(gs->customRenderString);
    propertiesListView->addProperty(gs->debugLevel);
    propertiesListView->addProperty(gs->networkRenderOn);
    propertiesListView->addProperty(gs->renderServerList);
    propertiesListView->addProperty(gs->maxTextureSize);
    propertiesListView->addProperty(gs->saveAlphaChannel);

// propertyList->setModel isn't working
//    propertiesList->setModel(gs->propertyListModel);
    
    // Set up groupList selector
    groupList->setModel((QAbstractItemModel*) gs->getPropertyGroupsModel());
    
    vlayout->addWidget(filterBar);
    vlayout->addWidget(propertiesListView);

    hlayout->addWidget(dividerWgt);
        hlayout->setMargin(0);
    
    contentFrame->setLayout(vlayout);
    this->setLayout(hlayout);
    
}

/////////////////////
// Rk_OptionsFrame() Destructor
//      This class is deleted whenever the renderer changes.  Thus, we need
//      to do object cleanup and then reset the the graphicsState pointer since
//      this object is about to be deleted.
/////////////////////
Rk_OptionsFrame::~Rk_OptionsFrame()
{
    delete propertiesListView;
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

#include "moc_Rk_OptionsFrame.cpp"
