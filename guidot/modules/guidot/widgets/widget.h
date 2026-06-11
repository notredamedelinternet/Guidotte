/**************************************************************************/
/*  widget.h — Guidot façade, row 4 (Control → Widget, wrapper)           */
/*  Thin wrapper: UI-framework conveniences, every method delegates to    */
/*  Control/Node internals. Never duplicates implementation (ADR-0001).   */
/**************************************************************************/

#pragma once

#include "scene/gui/control.h"

namespace guidot {

class Widget : public ::Control {
	GDCLASS(Widget, Control);

protected:
	static void _bind_methods();

public:
	// Bounds = position + size in one call, the idiom every UI toolkit ships.
	void set_bounds(const Rect2 &p_bounds);
	Rect2 get_bounds() const;

	Widget() = default;
};

} // namespace guidot
