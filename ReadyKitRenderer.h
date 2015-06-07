//
//  ReadyKitRenderer.h
//  ReadyKit Renderer
//
//  Created by Daniel Bui on 5/17/15.
//  Copyright (c) 2015 Daniel Bui. All rights reserved.
//

#ifndef __ReadyKitRenderer__
#define __ReadyKitRenderer__



//#include "plugin.h"
#include "dzrenderer.h"
#include "dzapp.h"

#include "Rk_GraphicsState.h"

class ReadyKitRenderer : public DzRenderer {
    Q_OBJECT
public:
    ReadyKitRenderer();
    void log( QString string, int debugLevel );
    void logError( QString string) { log(string, 0); }
    void logUserInfo( QString string) { log(string, 1); }
    void logDebugInfo( QString string) { log(string, 2); }
    void logDebugVerbose( QString string) { log(string, 3); }
    void logConst( QString string ) const { dzApp->log(string); }
    
    // Each renderer class will have one graphics state.  This will be useful to not only encapsulate graphics-state data, but also
    // store 
    Rk_RendererGraphicsState *graphicsState;

    //////////////////////////
    // RENDERPERSON INTERFACE
    //      The graphics state consists of options, attributes and interface mode.  Options affect the entire scene.  Attributes can
    //      vary between individual objects within a scene.
    /////////////////////////


    ///////////////////////////
    // State-Changing routines
    //      Scene is begun with DiWorldBegin().  Once called, option values are frozen and forbidden to call option-changing procedures
    //      until scene description is finished.  Attributes can be changed within the scene.  Geometry is described by using primitive
    //      geometry calls.  The attributes in the current graphics state applies to the geometry at the time they are described using
    //      API calls.
    //////////////////////////
    virtual DtVoid  DiWorldBegin()  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiWorldBegin()"); }
    virtual DtVoid  DiWorldEnd()    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiWorldEnd()"); }
    virtual DtContextHandle DiGetContext()  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiGetContext()"); return NULL; }
    virtual DtVoid  DiContext( DtContextHandle handle ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiContext( DtContextHandle handle ) "); }
    virtual DtVoid  DiAttributeBegin()  { logDebugVerbose("\nReadyKitRenderer: unimplemented method: DiAttributeBegin()"); }
    virtual DtVoid  DiAttributeEnd()    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiAttributeEnd()"); }
    virtual DtVoid  DiTransformBegin()  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiTransformBegin()"); }
    virtual DtVoid  DiTransformEnd()    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiTransformEnd()"); }
    virtual DtVoid  DiSolidBegin( DtToken type )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiSolidBegin( DtToken type )"); }
    virtual DtVoid  DiSolidEnd()    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiSolidEnd()"); }
    virtual DtVoid  DiMotionBeginV( DtInt N, DtFloat times[] )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiMotionBeginV( DtInt N, DtFloat times[] )"); }
    virtual DtVoid  DiMotionEnd()   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiMotionEnd() "); }
    virtual DtToken DiDeclare( const char *name, const char *declaration )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiDeclare( const char *name, const char *declaration )"); return NULL; }
    virtual DtVoid  DiScreenWindow( DtFloat left, DtFloat right, DtFloat bot, DtFloat top ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiScreenWindow( DtFloat left, DtFloat right, DtFloat bot, DtFloat top )"); }
    virtual DtVoid  DiIfBeginV( DtToken expression, DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiIfBeginV( DtToken expression, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiElseIfV( DtToken expression, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiElseIfV( DtToken expression, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiElse()    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiElse()"); }
    virtual DtVoid  DiIfEnd()   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiIfEnd()"); }
    virtual DtVoid  DiErrorHandler( DtErrorHandler handler )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiErrorHandler( DtErrorHandler handler )"); }
    virtual DtVoid  DiSynchronize( DtToken )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiSynchronize( DtToken )"); }


    // ------------------ Attributes
    virtual DtVoid  DiAttributeV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiAttributeV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiBound( DtBound bound )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiBound( DtBound bound )"); }
    virtual DtVoid  DiColor( DtColor Cs )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiColor( DtColor Cs )"); }
    virtual DtVoid  DiDetail( DtBound bound )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiDetail( DtBound bound )"); }
    virtual DtVoid  DiDetailRange( DtFloat minvis, DtFloat lowtran, DtFloat uptran, DtFloat maxvis )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiDetailRange( DtFloat minvis, DtFloat lowtran, DtFloat uptran, DtFloat maxvis )"); }
    virtual DtVoid  DiGeometricApproximation( DtToken type, DtFloat value ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiGeometricApproximation( DtToken type, DtFloat value )"); }
    virtual DtVoid  DiIlluminate( DtLightHandle light, DtBoolean onoff )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiIlluminate( DtLightHandle light, DtBoolean onoff )"); }
    virtual DtVoid  DiMatte( DtBoolean onoff )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiMatte( DtBoolean onoff )"); }
    virtual DtVoid  DiMultiplyShadingRate( DtFloat ratemultiplier ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiMultiplyShadingRate( DtFloat ratemultiplier )"); }
    virtual DtVoid  DiOpacity( DtColor Cs ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiOpacity( DtColor Cs )"); }
    virtual DtVoid  DiOrientation( DtToken orientation )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiOrientation( DtToken orientation )"); }
    virtual DtVoid  DiReverseOrientation()  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiReverseOrientation()"); }
    virtual DtVoid  DiShadingInterpolation( DtToken type )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiShadingInterpolation( DtToken type )"); }
    virtual DtVoid  DiShadingRate( DtFloat size )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiShadingRate( DtFloat size )"); }
    virtual DtVoid  DiSides( DtInt nsides ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiSides( DtInt nsides )"); }
    virtual DtVoid  DiTextureCoordinates( DtFloat s1, DtFloat t1, DtFloat s2, DtFloat t2, DtFloat s3, DtFloat t3, DtFloat s4, DtFloat t4 )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiTextureCoordinates( DtFloat s1, DtFloat t1, DtFloat s2, DtFloat t2, DtFloat s3, DtFloat t3, DtFloat s4, DtFloat t4 )"); }


    // ------------------ Shaders
    virtual DtLightHandle   DiAreaLightSourceV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiAreaLightSourceV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )"); return NULL; }
    virtual DtVoid  DiAtmosphereV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiAtmosphereV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiDisplacementV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiDisplacementV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiExteriorV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method:  DiExteriorV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiImagerV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiImagerV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiInteriorV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiInteriorV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtLightHandle   DiLightSourceV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiLightSourceV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )"); return NULL; }
    virtual DtVoid  DiShaderV( DtToken name, DtToken handle, DtInt n, const DtToken tokens[], DtPointer params[] )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiShaderV( DtToken name, DtToken handle, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiSurfaceV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiSurfaceV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )"); }


    // ------------------ Transformations
    virtual DtVoid  DiConcatTransform( DtMatrix transform ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiConcatTransform( DtMatrix transform )"); }
    virtual DtVoid  DiCoordinateSystem( DtToken space ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiCoordinateSystem( DtToken space )"); }
    virtual DtVoid  DiCoordSysTransform( DtToken space )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiCoordSysTransform( DtToken space )"); }
    virtual DtVoid  DiIdentity()    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiIdentity()"); }
    virtual DtVoid  DiPerspective( DtFloat fov )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiPerspective( DtFloat fov )"); }
    virtual DtVoid  DiRotate( DtFloat angle, DtFloat dx, DtFloat dy, DtFloat dz )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiRotate( DtFloat angle, DtFloat dx, DtFloat dy, DtFloat dz )"); }
    virtual DtVoid  DiScale( DtFloat dx, DtFloat dy, DtFloat dz )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiScale( DtFloat dx, DtFloat dy, DtFloat dz )"); }
    virtual DtVoid  DiScopedCoordinateSystem( DtToken space )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiScopedCoordinateSystem( DtToken space )"); }
    virtual DtVoid  DiSkew( DtFloat angle, DtFloat dx1, DtFloat dy1, DtFloat dz1, DtFloat dx2, DtFloat dy2, DtFloat dz2 )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiSkew( DtFloat angle, DtFloat dx1, DtFloat dy1, DtFloat dz1, DtFloat dx2, DtFloat dy2, DtFloat dz2 )"); }
    virtual DtVoid  DiTransform( DtMatrix transform )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiTransform( DtMatrix transform )"); }
    virtual DtPoint*    DiTransformPoints( DtToken fromspace, DtToken tospace, DtInt npoints, DtPoint *points ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiTransformPoints( DtToken fromspace, DtToken tospace, DtInt npoints, DtPoint *points )"); return NULL;}
    virtual DtVoid  DiTranslate( DtFloat dx, DtFloat dy, DtFloat dz )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiTranslate( DtFloat dx, DtFloat dy, DtFloat dz )"); }


    // ------------------ Geometric Primitives
    virtual DtVoid  DiBasis( DtBasis ubasis, DtInt ustep, DtBasis vbasis, DtInt vstep ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiBasis( DtBasis ubasis, DtInt ustep, DtBasis vbasis, DtInt vstep )"); }
    virtual DtVoid  DiBlobbyV( DtInt nleaf, DtInt ncode, DtInt code[], DtInt nflt, DtFloat flt[], DtInt nstr, DtString str[], DtInt n, const DtToken tokens[], DtPointer params[] ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiBlobbyV( DtInt nleaf, DtInt ncode, DtInt code[], DtInt nflt, DtFloat flt[], DtInt nstr, DtString str[], DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiConeV( DtFloat height, DtFloat radius, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiConeV( DtFloat height, DtFloat radius, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiCurvesV( DtToken degree, DtInt ncurves, DtInt nverts[], DtToken wrap, DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiCurvesV( DtToken degree, DtInt ncurves, DtInt nverts[], DtToken wrap, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiCylinderV( DtFloat radius, DtFloat zmin, DtFloat zmax, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiCylinderV( DtFloat radius, DtFloat zmin, DtFloat zmax, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiDiskV( DtFloat height, DtFloat radius, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiDiskV( DtFloat height, DtFloat radius, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiGeneralPolygonV (DtInt nloops, DtInt *nverts, DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiGeneralPolygonV (DtInt nloops, DtInt *nverts, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiGeometryV( DtToken type, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiGeometryV( DtToken type, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiHyperboloidV( DtPoint point1, DtPoint point2, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiHyperboloidV( DtPoint point1, DtPoint point2, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiNuCurvesV( DtInt ncurves, DtInt nvertices[], DtInt order[], DtFloat knot[], DtFloat min[], DtFloat max[], DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiNuCurvesV( DtInt ncurves, DtInt nvertices[], DtInt order[], DtFloat knot[], DtFloat min[], DtFloat max[], DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiNuPatchV( DtInt nu, DtInt uorder, DtFloat *uknot, DtFloat umin, DtFloat umax, DtInt nv, DtInt vorder, DtFloat *vknot, DtFloat vmin, DtFloat vmax, DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiNuPatchV( DtInt nu, DtInt uorder, DtFloat *uknot, DtFloat umin, DtFloat umax, DtInt nv, DtInt vorder, DtFloat *vknot, DtFloat vmin, DtFloat vmax, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiParaboloidV( DtFloat rmax, DtFloat zmin, DtFloat zmax, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] ){ logDebugVerbose("ReadyKitRenderer: unimplemented method: DiParaboloidV( DtFloat rmax, DtFloat zmin, DtFloat zmax, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiPatchV( DtToken type, DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiPatchV( DtToken type, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiPatchMeshV( DtToken type, DtInt nu, DtToken uwrap, DtInt nv, DtToken vwrap, DtInt n, const DtToken tokens[], DtPointer params[] ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiPatchMeshV( DtToken type, DtInt nu, DtToken uwrap, DtInt nv, DtToken vwrap, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiPointsV( DtInt npts, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiPointsV( DtInt npts, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiPointsGeneralPolygonsV( DtInt npolys, DtInt *nloops, DtInt *nverts, DtInt *verts, DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiPointsGeneralPolygonsV( DtInt npolys, DtInt *nloops, DtInt *nverts, DtInt *verts, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiPointsPolygonsV( DtInt npolys, DtInt *nverts, DtInt *verts, DtInt n, const DtToken tokens[], DtPointer params[] ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiPointsPolygonsV( DtInt npolys, DtInt *nverts, DtInt *verts, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiPolygonV( DtInt nvertices, DtInt n, const DtToken tokens[], DtPointer params[] )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiPolygonV( DtInt nvertices, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiSphereV( DtFloat radius, DtFloat zmin, DtFloat zmax, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiSphereV( DtFloat radius, DtFloat zmin, DtFloat zmax, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiSubdivisionMeshV( DtToken scheme, DtInt nfaces, DtInt nvertices[], DtInt vertices[], DtInt ntags, const DtToken tags[], DtInt nargs[], DtInt intargs[], DtFloat floatargs[], DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiSubdivisionMeshV( DtToken scheme, DtInt nfaces, DtInt nvertices[], DtInt vertices[], DtInt ntags, const DtToken tags[], DtInt nargs[], DtInt intargs[], DtFloat floatargs[], DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiHierarchicalSubdivisionMeshV(	DtToken scheme, DtInt nfaces, DtInt nvertices[], DtInt vertices[], DtInt ntags, const DtToken tags[], DtInt nargs[], DtInt intargs[], DtFloat floatargs[], const DtToken stringargs[], DtInt n, const DtToken tokens[], DtPointer params[]) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiHierarchicalSubdivisionMeshV(	DtToken scheme, DtInt nfaces, DtInt nvertices[], DtInt vertices[], DtInt ntags, const DtToken tags[], DtInt nargs[], DtInt intargs[], DtFloat floatargs[], const DtToken stringargs[], DtInt n, const DtToken tokens[], DtPointer params[])"); }
    virtual DtVoid  DiTorusV( DtFloat majorrad, DtFloat minorrad, DtFloat phimin, DtFloat phimax, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiTorusV( DtFloat majorrad, DtFloat minorrad, DtFloat phimin, DtFloat phimax, DtFloat thetamax, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiTrimCurve( DtInt nloops, DtInt *ncurves, DtInt *order, DtFloat *knot, DtFloat *amin, DtFloat *amax, DtInt *n, DtFloat *u, DtFloat *v, DtFloat *w )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiTrimCurve( DtInt nloops, DtInt *ncurves, DtInt *order, DtFloat *knot, DtFloat *amin, DtFloat *amax, DtInt *n, DtFloat *u, DtFloat *v, DtFloat *w )"); }


    // ------------------ Procedural primitives
    virtual DtVoid  DiProcedural( DtPointer data, DtBound bound, DtVoid (*subdivfunc) (DtPointer, DtFloat), DtVoid (*freefunc) (DtPointer) )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiProcedural( DtPointer data, DtBound bound, DtVoid (*subdivfunc) (DtPointer, DtFloat), DtVoid (*freefunc) (DtPointer) )"); }
    virtual DtVoid  DiProcDelayedReadArchive (DtPointer data, DtFloat detail)   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiProcDelayedReadArchive (DtPointer data, DtFloat detail)"); }
    virtual DtVoid  DiProcRunProgram (DtPointer data, DtFloat detail)   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiProcRunProgram (DtPointer data, DtFloat detail)"); }
    virtual DtVoid  DiProcDynamicLoad (DtPointer data, DtFloat detail)  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiProcDynamicLoad (DtPointer data, DtFloat detail)"); }


    // ------------------ Object Instancing
    virtual DtObjectHandle  DiObjectBegin() { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiObjectBegin()"); return NULL;}
    virtual DtObjectHandle  DiObjectBeginV( DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiObjectBeginV( DtInt n, const DtToken tokens[], DtPointer params[] )"); return NULL;}
    virtual DtVoid  DiObjectEnd()   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiObjectEnd()"); }
    virtual DtVoid  DiObjectInstance( DtObjectHandle handle )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiObjectInstance( DtObjectHandle handle )"); }


    // ------------------ Resourcing
    virtual DtVoid  DiResourceV(DtToken handle, DtToken type, DtInt n, const DtToken tokens[], DtPointer params[])  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiResourceV(DtToken handle, DtToken type, DtInt n, const DtToken tokens[], DtPointer params[])"); }
    virtual DtVoid  DiResourceBegin()   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiResourceBegin()"); }
    virtual DtVoid  DiResourceEnd() { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiResourceEnd()"); }


    // ------------------ Texture map creation */
    virtual DtVoid  DiMakeBrickMapV( DtInt nptc, const char *const *ptcnames, const char *bkmname, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiMakeBrickMapV( DtInt nptc, const char *const *ptcnames, const char *bkmname, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiMakeBumpV( const char *picturename, const char *texturename, DtToken swrap, DtToken twrap, DtFilterFunc filterfunc, DtFloat swidth, DtFloat twidth, DtInt n, const DtToken tokens[], DtPointer params[] ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiMakeBumpV( const char *picturename, const char *texturename, DtToken swrap, DtToken twrap, DtFilterFunc filterfunc, DtFloat swidth, DtFloat twidth, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiMakeCubeFaceEnvironmentV( const char *px, const char *nx, const char *py, const char *ny, const char *pz, const char *nz, const char *tex, DtFloat fov, DtFilterFunc filterfunc, DtFloat swidth, DtFloat twidth, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiMakeCubeFaceEnvironmentV( const char *px, const char *nx, const char *py, const char *ny, const char *pz, const char *nz, const char *tex, DtFloat fov, DtFilterFunc filterfunc, DtFloat swidth, DtFloat twidth, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiMakeLatLongEnvironmentV( const char *pic, const char *tex, DtFilterFunc filterfunc, DtFloat swidth, DtFloat twidth, DtInt n, const DtToken tokens[], DtPointer params[] ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiMakeLatLongEnvironmentV( const char *pic, const char *tex, DtFilterFunc filterfunc, DtFloat swidth, DtFloat twidth, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiMakeShadowV( const char *pic, const char *tex, DtInt n, const DtToken tokens[], DtPointer params[] )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiMakeShadowV( const char *pic, const char *tex, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiMakeTextureV( const char *pic, const char *tex, DtToken swrap, DtToken twrap, DtFilterFunc filterfunc, DtFloat swidth, DtFloat twidth, DtInt n, const DtToken tokens[], DtPointer params[] )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiMakeTextureV( const char *pic, const char *tex, DtToken swrap, DtToken twrap, DtFilterFunc filterfunc, DtFloat swidth, DtFloat twidth, DtInt n, const DtToken tokens[], DtPointer params[] )"); }


    // ------------------ Reading and writing archive files
    virtual DtVoid  DiArchiveRecord( DtToken type, const char *format, ... ){ logDebugVerbose("ReadyKitRenderer: unimplemented method: DiArchiveRecord( DtToken type, const char *format, ... )"); }
    virtual DtVoid  DiReadArchiveV( DtString filename, DtArchiveCallback callback, int n, const DtToken tokens[], DtPointer params[] )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiReadArchiveV( DtString filename, DtArchiveCallback callback, int n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtArchiveHandle DiArchiveBeginV( DtToken archivename, DtInt n, const DtToken tokens[], DtPointer params[] ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiArchiveBeginV( DtToken archivename, DtInt n, const DtToken tokens[], DtPointer params[] )"); return NULL;}
    virtual DtVoid  DiArchiveEnd()  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiArchiveEnd()"); }


    // ------------------ Renderer options
    virtual DtVoid  DiCameraV( DtToken camera, DtInt n, const DtToken tokens[], DtPointer params[] )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiCameraV( DtToken camera, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiClipping( DtFloat hither, DtFloat yon )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiClipping( DtFloat hither, DtFloat yon )"); }
    virtual DtVoid  DiClippingPlane( DtFloat x, DtFloat y, DtFloat z, DtFloat nx, DtFloat ny, DtFloat nz )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiClippingPlane( DtFloat x, DtFloat y, DtFloat z, DtFloat nx, DtFloat ny, DtFloat nz )"); }
    virtual DtVoid  DiColorSamples( DtInt N, DtFloat *nRGB, DtFloat *RGBn ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiColorSamples( DtInt N, DtFloat *nRGB, DtFloat *RGBn )"); }
    virtual DtVoid  DiCropWindow( DtFloat xmin, DtFloat xmax, DtFloat ymin, DtFloat ymax )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiCropWindow( DtFloat xmin, DtFloat xmax, DtFloat ymin, DtFloat ymax )"); }
    virtual DtVoid  DiDepthOfField( DtFloat fstop, DtFloat focallength, DtFloat focaldistance ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiDepthOfField( DtFloat fstop, DtFloat focallength, DtFloat focaldistance )"); }
    virtual DtVoid  DiDisplayV( const char *name, DtToken type, DtToken mode, DtInt n, const DtToken tokens[], DtPointer params[] ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiDisplayV( const char *name, DtToken type, DtToken mode, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiDisplayChannelV( const char *channel, DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiDisplayChannelV( const char *channel, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiExposure( DtFloat gain, DtFloat gamma )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiExposure( DtFloat gain, DtFloat gamma )"); }
    virtual DtVoid  DiFormat( DtInt xres, DtInt yres, DtFloat aspect )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiFormat( DtInt xres, DtInt yres, DtFloat aspect )"); }
    virtual DtVoid  DiFrameAspectRatio( DtFloat aspect )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiFrameAspectRatio( DtFloat aspect )"); }
    virtual DtVoid  DiHiderV( DtToken type, DtInt n, const DtToken tokens[], DtPointer params[] )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiHiderV( DtToken type, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiOptionV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiOptionV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiPixelFilter( DtFilterFunc function, DtFloat xwidth, DtFloat ywidth )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiPixelFilter( DtFilterFunc function, DtFloat xwidth, DtFloat ywidth )"); }
    virtual DtVoid  DiPixelSamples( DtFloat xsamples, DtFloat ysamples )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiPixelSamples( DtFloat xsamples, DtFloat ysamples )"); }
    virtual DtVoid  DiPixelVariance( DtFloat variation )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiPixelVariance( DtFloat variation )"); }
    virtual DtVoid  DiProjectionV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiProjectionV( DtToken name, DtInt n, const DtToken tokens[], DtPointer params[] )"); }
    virtual DtVoid  DiQuantize( DtToken type, DtInt one, DtInt qmin, DtInt qmax, DtFloat ampl ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiQuantize( DtToken type, DtInt one, DtInt qmin, DtInt qmax, DtFloat ampl )"); }
    virtual DtVoid  DiRelativeDetail( DtFloat relativedetail )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiRelativeDetail( DtFloat relativedetail )"); }
    virtual DtVoid  DiShutter( DtFloat smin, DtFloat smax ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiShutter( DtFloat smin, DtFloat smax )"); }


    // ------------------ Shader Language Interrogation
    virtual int DSlo_SetPath( const char *i_path )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_SetPath( const char *i_path )"); return -1;}
    virtual int DSlo_SetShader( const char *i_name )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_SetShader( const char *i_name )"); return -1;}
    virtual const char* DSlo_GetName()  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_GetName()"); return NULL;}
    virtual DSLO_TYPE   DSlo_GetType()  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_GetType()"); return DSLO_TYPE_UNKNOWN;}
    virtual int DSlo_HasMethod( const char *i_name )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_HasMethod( const char *i_name )"); return -1;}
    virtual const char* const*	DSlo_GetMethodNames(){ logDebugVerbose("ReadyKitRenderer: unimplemented DSlo call"); return NULL;};
    virtual int DSlo_GetNArgs() { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_GetNArgs()"); return 0;}

    virtual DSLO_VISSYMDEF* DSlo_GetArgById( int i_id ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_GetArgById( int i_id )"); return NULL;}
    virtual DSLO_VISSYMDEF* DSlo_GetArgByName( const char *i_name ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_GetArgByName( const char *i_name )"); return NULL;}
    virtual DSLO_VISSYMDEF* DSlo_GetArrayArgElement( DSLO_VISSYMDEF *i_array, int i_index ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_GetArrayArgElement( DSLO_VISSYMDEF *i_array, int i_index )"); return NULL;}

    virtual int DSlo_GetNAnnotations()  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_GetNAnnotations()"); return 0;}
    virtual const char* DSlo_GetAnnotationKeyById( int i_id )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_GetAnnotationKeyById( int i_id )"); return NULL;}
    virtual const char* DSlo_GetAnnotationByKey( const char *i_key )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_GetAnnotationByKey( const char *i_key )"); return NULL;}

    virtual void    DSlo_EndShader()    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_EndShader()"); }
    virtual const char* DSlo_TypetoStr( DSLO_TYPE i_type )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_TypetoStr( DSLO_TYPE i_type )"); return NULL;}
    virtual const char* DSlo_StortoStr( DSLO_STORAGE i_storage )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_StortoStr( DSLO_STORAGE i_storage )"); return NULL;}
    virtual const char* DSlo_DetailtoStr( DSLO_DETAIL i_detail )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DSlo_DetailtoStr( DSLO_DETAIL i_detail )"); return NULL;}


    // ------------------ Rendering
    virtual bool    render( DzRenderHandler *handler, DzCamera *camera, const DzRenderOptions &opt );
    virtual bool    customRender( DzRenderHandler *handler, DzCamera *camera, DzLightList &lights, DzNodeList &nodes, const DzRenderOptions &opt )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: customRender( DzRenderHandler *handler, DzCamera *camera, DzLightList &lights, DzNodeList &nodes, const DzRenderOptions &opt )"); return false;}

    //////////////////////////////////////////////////////////
    //////////// ********* public slots ********//////////////
    //////////////////////////////////////////////////////////
    public slots:

    //
    // MANIPULATORS
    //

    virtual void    prepareImage( const DzTexture *img, const QString &filename );
    virtual QString compileShader( const QString &shaderPath, QString &output ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: compileShader( const QString &shaderPath, QString &output )"); return NULL;}
    virtual DzShaderDescription*    getShaderInfo( const QString &shaderPath )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: getShaderInfo( const QString &shaderPath )"); return NULL;}
    virtual void    killRender()    { logDebugVerbose("ReadyKitRenderer: unimplemented method: killRender()"); }

    virtual bool    bake( DzRenderHandler *handler, DzCamera *camera, DzLightListIterator &lights, DzNodeListIterator &nodes, const DzBakerOptions &opt )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: bake( DzRenderHandler *handler, DzCamera *camera, DzLightListIterator &lights, DzNodeListIterator &nodes, const DzBakerOptions &opt )"); return false;}
    virtual bool    autoBake( DzRenderHandler *handler, DzCamera *camera, DzLightListIterator &lights, DzNodeListIterator &nodes, const DzBakerOptions &opt )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: autoBake( DzRenderHandler *handler, DzCamera *camera, DzLightListIterator &lights, DzNodeListIterator &nodes, const DzBakerOptions &opt )"); return false;}
    virtual void    stopBaking()    { logDebugVerbose("ReadyKitRenderer: unimplemented method: stopBaking()"); }
    virtual void    saveBakeImage( const DzBakerOptions &opt, bool wait )   { logDebugVerbose("ReadyKitRenderer: unimplemented method: saveBakeImage( const DzBakerOptions &opt, bool wait )"); }
    virtual bool    textureConvert( DzRenderHandler *handler, DzCamera *camera, const DzTextureConvertorOptions &opt )  { logDebugVerbose("ReadyKitRenderer: unimplemented method: textureConvert( DzRenderHandler *handler, DzCamera *camera, const DzTextureConvertorOptions &opt )"); DzRenderer::textureConvert(handler, camera, opt); return false;}
    //
    // ACCESSORS
    //

    virtual QString getShaderCompilerPath() { logDebugVerbose("ReadyKitRenderer: unimplemented method: getShaderCompilerPath()"); return NULL;}
    virtual QString getTextureUtilityPath() { logDebugVerbose("ReadyKitRenderer: unimplemented method: getTextureUtilityPath()"); return NULL;}

    virtual QStringList getShaderSearchPaths() const { logConst("ReadyKitRenderer: unimplemented method: getShaderSearchPaths()"); return QStringList("");}
    virtual QString processShaderName( const QString &shaderName ) const { logConst("ReadyKitRenderer: unimplemented method: processShaderName( const QString &shaderName )"); return NULL;}
    virtual QString getShaderPath( const QString &shaderName, bool withExtension = true ) const { logConst("ReadyKitRenderer: unimplemented method: getShaderPath( const QString &shaderName, bool withExtension = true )"); return NULL;}
    virtual QString getShaderFileName( const QString &shaderName ) const    { logConst("ReadyKitRenderer: unimplemented method: getShaderFileName( const QString &shaderName )"); return NULL;}
    virtual QString getShaderExtension() const  { logConst("ReadyKitRenderer: unimplemented method: getShaderExtension()"); return NULL;}
    virtual bool    isRendering() const { logConst("ReadyKitRenderer: unimplemented method: isRendering()"); return false;}
    virtual QString getName() const { logConst("ReadyKitRenderer: getName()"); return graphicsState->rendererName;}
    virtual DzNode* getCurrentNode() const  { logConst("ReadyKitRenderer: unimplemented method: getCurrentNode()"); return NULL;}


public:

    virtual DzOptionsFrame* getOptionsFrame() const ;
    virtual DtFilterFunc    getFilterFunction( DzRenderOptions::PixelFilter filterType ) const  { logConst("ReadyKitRenderer: unimplemented method: getFilterFunction( DzRenderOptions::PixelFilter filterType )"); return NULL;}

protected:

    // ------------------ Basic control flow, scoping, stacks

    virtual DtVoid  DiBegin( DtToken name ) { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiBegin( DtToken name )"); }
    virtual DtVoid  DiEnd() { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiEnd()"); }
    virtual DtVoid  DiFrameBegin( DtInt number )    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiFrameBegin( DtInt number )"); }
    virtual DtVoid  DiFrameEnd()    { logDebugVerbose("ReadyKitRenderer: unimplemented method: DiFrameEnd()"); }

private:




};


#endif /* defined(__ReadyKitRenderer__) */
