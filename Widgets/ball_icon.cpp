#include "ball_icon.hpp"
using namespace widgets;

int widgets::ball_icon::width() const
{
	return 2 * _radius + 1;
}

int widgets::ball_icon::height() const
{
	return 2 * _radius + 1;
}

int widgets::ball_icon::radius() const
{
	return _radius;
}

void widgets::ball_icon::radius(int radius)
{
	this->_radius = radius;
}

widgets::ball_icon::ball_icon(int radius) : _radius(radius) { }

widget* widgets::ball_icon::child_at(int x, int y)
{
	if ((pow(x - _radius, 2) + pow(y - _radius, 2)) > pow(_radius, 2))
		return nullptr;
	return this;
}

std::unique_ptr<ball_icon> widgets::make_ball_icon(int radius)
{
	return std::make_unique<widgets::ball_icon>(std::move(radius));
}
