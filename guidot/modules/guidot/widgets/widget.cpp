/**************************************************************************/
/*  widget.cpp — Guidot façade, row 4 (Control → Widget, wrapper)         */
/**************************************************************************/

#include "widget.h"

namespace guidot {

void Widget::set_bounds(const Rect2 &p_bounds) {
	set_position(p_bounds.position);
	set_size(p_bounds.size);
}

Rect2 Widget::get_bounds() const {
	return Rect2(get_position(), get_size());
}

void Widget::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_bounds", "bounds"), &Widget::set_bounds);
	ClassDB::bind_method(D_METHOD("get_bounds"), &Widget::get_bounds);
}

} // namespace guidot
