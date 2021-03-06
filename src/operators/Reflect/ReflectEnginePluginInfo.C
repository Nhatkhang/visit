// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ****************************************************************************
//  File: ReflectEnginePluginInfo.C
// ****************************************************************************

#include <ReflectPluginInfo.h>
#include <avtReflectFilter.h>

VISIT_OPERATOR_PLUGIN_ENTRY_EV(Reflect,Engine)

// ****************************************************************************
//  Method: ReflectEnginePluginInfo::AllocAvtPluginFilter
//
//  Purpose:
//    Return a pointer to a newly allocated avtPluginFilter.
//
//  Returns:    A pointer to the newly allocated avtPluginFilter.
//
//  Programmer: generated by xml2info
//  Creation:   omitted
//
// ****************************************************************************

avtPluginFilter *
ReflectEnginePluginInfo::AllocAvtPluginFilter()
{
    return new avtReflectFilter;
}
