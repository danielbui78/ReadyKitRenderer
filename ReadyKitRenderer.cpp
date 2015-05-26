//
//  ReadyKitRenderer.cpp
//  yaluxplug
//
//  Created by Daniel Bui on 5/17/15.
//  Copyright (c) 2015 Daniel Bui. All rights reserved.
//

#include "ReadyKitRenderer.h"


////////////////////
// ReadyKitRenderer Class
//      This is the main renderer plugin class.  Subclass this class and override whatever DzRenderer API calls
//      you will need to make your renderer work.  Ex, you will need to override at least some of the renderman API calls
//      to implement a renderer that uses the renderman pipeline.
/////////////////////

// Constructor
ReadyKitRenderer::ReadyKitRenderer()
{
    // Initialize the plugin and instantiate the graphics state
    // Remember, the graphicsState should contain all the scene-related information your specific renderer will need.
    // See RendererGrahpicsState Class above.
    graphicsState = new Rk_RendererGraphicsState;

}

// DzOptionsFrame* getOptionsFrame
//      Returns a pointer to an OptionsFrame object.  This will be used by DazGUI to draw the Renderer Advanced Settings tab
DzOptionsFrame* ReadyKitRenderer::getOptionsFrame() const
{
    return graphicsState->renderOptionsFrame;
}

