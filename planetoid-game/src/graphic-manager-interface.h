#pragma once
#include "error.h"

struct Point
{
	float x;
	float y;
};

struct Line
{
	float x0;
	float y0;
	float x1;
	float x2;
};

struct Rect
{
	float x;
	float y;
	float w;
	float h;
};

typedef unsigned int color;

struct RGBAColor
{
	color r;
	color g;
	color b;
	color a;
};

class IGraphicManager
{
public:
	

	~IGraphicManager() {}

	virtual error Init(int width, int height) = 0;
	virtual void Cleanup() = 0;
	virtual error Render(float interpolation) = 0;

	virtual void FillColor(RGBAColor rgbacolor) = 0;

	virtual void DrawRectangle(const Rect & rect, RGBAColor rgbacolor) = 0;
};