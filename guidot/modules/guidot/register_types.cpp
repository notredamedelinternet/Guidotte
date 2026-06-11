/**************************************************************************/
/*  register_types.cpp — Guidot façade module                             */
/**************************************************************************/

#include "register_types.h"

#include "core/object/class_db.h"

#include "widgets/widget.h"

void initialize_guidot_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	GDREGISTER_CLASS(guidot::Widget);
}

void uninitialize_guidot_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}
