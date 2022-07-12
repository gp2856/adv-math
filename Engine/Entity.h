#pragma once

#include <vector>
#include "Vec2.h"
#include "Drawable.h"

class Entity
{
public:
	Entity(std::vector<Vec2> model, const Vec2& pos = { 0.0f, 0.0f }, Color c = Colors::Yellow)
		:
		model(std::move(model)),
		pos(pos),
		c(c)
	{}

	const Vec2& GetPos() const
	{
		return pos;
	}
	void SetPos(const Vec2& newPos)
	{
		pos = newPos;
	}
	const float GetScale() const
	{
		return scale;
	}
	void SetScale(float s)
	{
		scale = s;
	}
	void TranslateBy(const Vec2& offset)
	{
		pos += offset;
	}
	Drawable GetDrawable() const
	{
		Drawable d(model, c);
		d.Scale(scale);
		d.Translate(pos);
		return d;
	}

	
private:
	Color c;
	float scale = 1.0f;
	Vec2 pos = { 0.0f, 0.0f };
	std::vector<Vec2> model;
};