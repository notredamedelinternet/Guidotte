/**************************************************************************/
/*  element.h — Guidot façade, NOMENCLATURE row 1 (Node → Element)        */
/*  Pure alias: identical type, SWE name (ADR-0001).                      */
/**************************************************************************/

#pragma once

#include "scene/main/node.h"

namespace guidot {

// Composable tree node — the base of every Guidot hierarchy.
using Element = ::Node;

} // namespace guidot
