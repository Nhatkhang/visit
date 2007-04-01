// ************************************************************************* //
//                               MeshPluginInfo.h                            //
// ************************************************************************* //

#ifndef MESH_PLUGIN_INFO_H
#define MESH_PLUGIN_INFO_H
#include <PlotPluginInfo.h>
#include <plot_plugin_exports.h>

class MeshAttributes;

// ****************************************************************************
//  Class: MeshPluginInfo
//
//  Purpose:
//    Five classes that provide all the information about a Mesh
//    plot plugin.  The information is broken up into five classes since
//    portions of it are only relevant to particular components within
//    visit.  There is the general information which all the components
//    are interested in, the gui information which the gui is interested in,
//    the viewer information which the viewer is interested in, the
//    engine information which the engine is interested in, and finally a.
//    scripting portion that enables the Python VisIt extension to use the
//    plugin.
//
//  Programmer: whitlocb -- generated by xml2info
//  Creation:   Fri Mar 26 15:09:42 PST 2004
//
// ****************************************************************************

class MeshGeneralPluginInfo: public virtual GeneralPlotPluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
};

class MeshCommonPluginInfo : public virtual CommonPlotPluginInfo, public virtual MeshGeneralPluginInfo
{
  public:
    virtual AttributeSubject *AllocAttributes();
    virtual void CopyAttributes(AttributeSubject *to, AttributeSubject *from);
};

class MeshGUIPluginInfo: public virtual GUIPlotPluginInfo, public virtual MeshCommonPluginInfo
{
  public:
    virtual const char *GetMenuName() const;
    virtual int GetVariableTypes() const;
    virtual QvisPostableWindowObserver *CreatePluginWindow(int type,
        AttributeSubject *attr, QvisNotepadArea *notepad);
    virtual const char **XPMIconData() const;
};

class MeshViewerPluginInfo: public virtual ViewerPlotPluginInfo, public virtual MeshCommonPluginInfo
{
  public:
    virtual AttributeSubject *GetClientAtts();
    virtual AttributeSubject *GetDefaultAtts();
    virtual void SetClientAtts(AttributeSubject *atts);
    virtual void GetClientAtts(AttributeSubject *atts);

    virtual avtPlot *AllocAvtPlot();

    virtual void InitializePlotAtts(AttributeSubject *atts,
        const avtDatabaseMetaData *md,
        const char *variableName);
    virtual const char **XPMIconData() const;
    virtual int GetVariableTypes() const;

    static void InitializeGlobalObjects();
  private:
    static MeshAttributes *defaultAtts;
    static MeshAttributes *clientAtts;
};

class MeshEnginePluginInfo: public virtual EnginePlotPluginInfo, public virtual MeshCommonPluginInfo
{
  public:
    virtual avtPlot *AllocAvtPlot();
};

class MeshScriptingPluginInfo : public virtual ScriptingPlotPluginInfo, public virtual MeshCommonPluginInfo
{
  public:
    virtual void InitializePlugin(AttributeSubject *subj, FILE *log);
    virtual void *GetMethodTable(int *nMethods);
    virtual bool TypesMatch(void *pyobject);
    virtual void SetLogging(bool val);
    virtual void SetDefaults(const AttributeSubject *atts);
};

#endif
