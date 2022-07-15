#pragma once
#include "CoordinateTransformer.h"
#include "RectF.h"

class Camera
{
public:
	Camera(CoordinateTransformer& ct)
		:
		ct(ct)
	{}
	Vec2 GetPos() const
	{
		return pos;
	}
	void MoveBy(const Vec2& offset)
	{
		pos += offset;
	}
	void MoveTo(const Vec2& pos_in)
	{
		pos = pos_in;
	}
	const float GetScale() const
	{
		return scale;
	}
	void SetScale(float scale_in)
	{
		scale = scale_in;
	}
	void Draw(Drawable& drawable) const
	{
		drawable.Translate(-pos);
		drawable.Scale(scale);
		ct.Draw(drawable);
	}
	RectF GetViewportRect() const
	{
		const float zoom = 1.0f / scale;
		return RectF::FromCenter(
			pos,
			float(Graphics::ScreenWidth / 2) * zoom,
			float(Graphics::ScreenHeight / 2) * zoom
		);
	}
private:
	float scale = 1.0f;
	Vec2 pos = {0.0f, 0.0f};
	CoordinateTransformer& ct;
};