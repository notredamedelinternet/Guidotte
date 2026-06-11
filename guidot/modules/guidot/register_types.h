/**************************************************************************/
/*  register_types.h — Guidot façade module                               */
/*  Guidot is additive: the godot:: view is untouched (ADR-0001).         */
/**************************************************************************/

#pragma once

#include "modules/register_module_types.h"

void initialize_guidot_module(ModuleInitializationLevel p_level);
void uninitialize_guidot_module(ModuleInitializationLevel p_level);
