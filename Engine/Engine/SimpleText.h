#ifndef _SIMPLETEXT_H_
#define _SIMPLETEXT_H_

#include "Gameobject.h"
#include <dwrite.h>
#include <d2d1.h>
#include "d3dclass.h"

class SimpleText {
public:
	SimpleText();
	~SimpleText();
	ID2D1Factory* pD2DFactory_;
	ID2D1RenderTarget* pRT_;
	ID2D1SolidColorBrush* pColoredBrush_;
	RECT rc;
	HRESULT hr;
	HWND hwnd;
	COLORREF pBrushColor;
	ID3D11RenderTargetView* m_renderTargetView;

	void Init(HWND hwnd_, COLORREF pBrushColor_, D3DClass*);
	HRESULT CreateDeviceResources();
	void DiscardDeviceResources();
	void ConfigureBrush(FLOAT posX, FLOAT posY, const wchar_t* wszText_);
	bool DrawTextOnScene(FLOAT posX, FLOAT posY, const wchar_t* wszText_);

private:
	IDWriteFactory* pDWriteFactory_;
	IDWriteTextFormat* pTextFormat_;
};

#endif


