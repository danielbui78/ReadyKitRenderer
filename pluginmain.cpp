//
//  pluginmain.cpp
//  yaluxplug
//
//  Created by Daniel Bui on 4/23/15.
//  Copyright (c) 2015 Daniel Bui. All rights reserved.
//

#include "dzplugin.h"
#include "dzapp.h"

#include "version.h"
#include "readykitrenderer.h"



DZ_PLUGIN_DEFINITION( "ReadyKitRenderer" );

DZ_PLUGIN_AUTHOR( "DB" );

DZ_PLUGIN_VERSION( PLUGIN_MAJOR, PLUGIN_MINOR, PLUGIN_REV, PLUGIN_BUILD );

DZ_PLUGIN_DESCRIPTION( "ReadyKit Renderer plugin.  You will see it as an additional Renderer option on the Render Pane." );

DZ_PLUGIN_CLASS_GUID( ReadyKitRenderer, EBD3758C-FDE9-44DA-8A58-41366E569AFC );
