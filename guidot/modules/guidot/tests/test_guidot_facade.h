/**************************************************************************/
/*  test_guidot_facade.h — smoke tests for the Guidot façade (M1-W2)      */
/**************************************************************************/

#pragma once

#include "../guidot.h"

#include "tests/test_macros.h"

#include <type_traits>

namespace TestGuidotFacade {

// Rows 1–3, 5–6 are pure aliases: the types must be *identical*, not derived.
static_assert(std::is_same_v<guidot::Element, ::Node>);
static_assert(std::is_same_v<guidot::ElementTree, ::SceneTree>);
static_assert(std::is_same_v<guidot::Composition, ::PackedScene>);
static_assert(std::is_same_v<guidot::Renderable2D, ::CanvasItem>);
static_assert(std::is_same_v<guidot::OutputSurface, ::Viewport>);

TEST_CASE("[Guidot] Element alias builds a tree identical to Node") {
	guidot::Element *root = memnew(guidot::Element);
	root->set_name("root");
	guidot::Element *child = memnew(guidot::Element);
	child->set_name("child");
	root->add_child(child);

	CHECK(root->get_child_count() == 1);
	CHECK(root->get_child(0) == child);
	// The alias is the same ClassDB type: gamedev view sees a plain Node.
	CHECK(String(root->get_class()) == "Node");

	memdelete(root); // frees child too
}

TEST_CASE("[Guidot] Widget wrapper registers and delegates bounds") {
	guidot::Widget *w = memnew(guidot::Widget);
	CHECK(String(w->get_class()) == "Widget");
	CHECK(Object::cast_to<Control>(w) != nullptr);

	w->set_bounds(Rect2(10, 20, 300, 200));
	CHECK(w->get_bounds() == Rect2(10, 20, 300, 200));
	CHECK(w->get_position() == Point2(10, 20));
	CHECK(w->get_size() == Size2(300, 200));

	memdelete(w);
}

} // namespace TestGuidotFacade
