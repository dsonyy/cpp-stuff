#pragma once
#include <allegro5\allegro.h>
#include "graphic-manager-interface.h"

class AllegroGraphicManager
	: public IGraphicManager
{
public:
	AllegroGraphicManager();
	~AllegroGraphicManager();

	virtual error Init(int width, int height);
	virtual void Cleanup();
	virtual error Render(float interpolation);

	virtual void FillColor(RGBAColor rgbacolor);
	virtual void DrawRectangle(const Rect & rect, RGBAColor rgbacolor);

private:
	ALLEGRO_DISPLAY * display_;
};