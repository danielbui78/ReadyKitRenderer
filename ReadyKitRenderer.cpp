//
//  ReadyKitRenderer.cpp
//  ReadyKit Renderer
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

////////////////////
// Constructor
//      NOTES:  This method is called twice by the Daz Studio (4.8) framework when the Daz Studio application first starts up.
////////////////////
ReadyKitRenderer::ReadyKitRenderer()
{
    // Initialize the plugin and instantiate the graphics state
    // Remember, the graphicsState should contain all the scene-related information your specific renderer will need.
    // See RendererGrahpicsState Class above.
    graphicsState = new Rk_RendererGraphicsState;

}

void ReadyKitRenderer::log( QString string, int debugLevel )
{
    // check debugLevel against current renderer settings
    if (debugLevel >= graphicsState->getDebugLevel())
    {
        dzApp->log(string);
    }
    
}

////////////////////
// DzOptionsFrame* getOptionsFrame
//      Returns a pointer to an OptionsFrame object.  This will be used by DazGUI to draw the Renderer Advanced Settings tab.
//      NOTES:  I've looked for a way to modify the main Renderer Settings tab like the Daz Studio supplied renderers like
//              3Delight and Iray, but it seems that requires undocumented calls to the system.
//              The OptionsFrame widget appears to be destroyed when the Renderer is changed.  The work-around is to create
//              a new widget whenever this method is called.
////////////////////
DzOptionsFrame* ReadyKitRenderer::getOptionsFrame() const
{
    logConst("ReadyKitRenderer: getOptionsFrame()");
//    return graphicsState->renderOptionsFrame;
    return graphicsState->getOptionsFrame();
}

//////////////////
// bool render( DzRenderHandler *handler, DzCamera *camera, const DzRenderOptions &opt )
//      Called by the Daz Studio framework (such as clicking Render button) or a script to do rendering.
//      My assumption is that this method returns true if the image is successfully rendered and false if the
//      render is cancelled or somehow aborted.  However, I have not been able to see any difference in Daz Studio
//      behavior no matter which value I return.
//      NOTES:  When the user clicks Render button, the DzRenderMgr will call this method from the main UI event loop.
//              This means that the UI will stop updating/being interactive if you do not return from this method or at
//              least process events from the eventloop.
//              Also: the DzRenderHandler passed to this method by DzRenderMgr is deleted after this method returns.
//              This means calling *handler from another thread and allowing this method to return will result in a
//              memory access violation crash (reading from a null pointer).  A work-around to this is to copy the
//              *handler to a new instance of DzRenderHandler which you manage yourself.
//////////////////
bool ReadyKitRenderer::render( DzRenderHandler *handler, DzCamera *camera, const DzRenderOptions &opt )
{
    logDebugVerbose("ReadyKitRenderer: render( DzRenderHandler *handler, DzCamera *camera, const DzRenderOptions &opt )");
    return false;

}


///////////////////
// void prepareImage( const DzTexture *img, const QString &filename )
//      Converts an original texturemap/image file to a format and size which is usable by the renderer.
//      Called by the Daz Studio framework, usually when scene is first loaded.  After the image is prepared, Daz Studio framework
//      expects the Renderer to emit the imagePrepared() signal with a filename to a temporary image containing a format/size
//      that is compatible with this Renderer.  The theoretical benefit of implementing this method is that you should only need to
//      convert images once when scene is loaded and then all subsequent renders can skip this step.  For example, 3Delight will
//      generate *.tdl files in the Daz Studio temporary folder when a scene is loaded.
//      NOTES:  This method is called from the event loop thread, so not returning from this method will block the application
//              UI from updating or being interactive.  The recommendation from Daz Studio SDK is to spawn a thread when
//              prepareImage is called and return from this method as quickly as possible so you do not block the UI event loop.
//              Also: when a scene is initially loaded, Daz Studio will call the currently selected Renderer's prepareImage
//              method on each texture.  If you select a new Renderer after the scene is loaded, this method will not
//              be called.  Perhaps this is a bug with Daz Studio which will be fixed in later versions.  Whatever the case,
//              this behavior means that the Renderer can never be sure that Daz Studio has already called this function on all
//              scene images prior to starting a render().  One work-around is to query the image files and check if the temporary
//              filename associated with them is what you would expect to be generated by this Renderer (essentially creating a
//              cache of filenames using temporaryfilename generation as a hash function).  Another more brute-force technique is to
//              just load the temporary file and query the format and size to see if it's compatible with this Renderer.
////////////////////
void ReadyKitRenderer::prepareImage( const DzTexture *img, const QString &filename )
{
    logDebugVerbose("ReadyKitRenderer: prepareImage( const DzTexture *img, const QString &filename )");
    
}

#include "moc_ReadyKitRenderer.cpp"

