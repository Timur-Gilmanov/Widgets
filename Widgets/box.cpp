#include "box.hpp"
using namespace widgets;

widgets::box::box(kind kind) : _kind(kind) { }

int widgets::box::width() const
{
	return 0;
}

int widgets::box::height() const
{
	return 0;
}

int widgets::box::size() const
{
	return this->elements.size();
}

widget* widgets::box::get(int index) const
{
	return (index < 0 || index > this->size() - 1 ? nullptr : elements.at(index).get());
}

widget* widgets::box::add(std::unique_ptr<widget> child)
{
	elements.push_back(std::move(child));
	return elements.back().get();
}

std::unique_ptr<widget> widgets::box::remove(int index)
{
	return std::unique_ptr<widget>();
}

void widgets::box::update_layout()
{
}

widget* widgets::box::child_at(int x, int y)
{
	return nullptr;
}

std::unique_ptr<box> widgets::make_box(box::kind kind)
{
	return std::make_unique<box>(kind);
}
