#pragma once
#include "Includes.h"
#include "Algorithm.h"
#include "Setting.h"
#include "Data.h"
#include "DX11.h"
#include "Memory.h"
#include "Offset.h"


#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_internal.h"


namespace Esp
{
	extern D3DMATRIX ViewMatrix;

	VOID EspThread();
}

class CControl
{
	friend class CGUI;
	friend class CTab;
	friend class CWindow;
public:
	void SetPosition(int x, int y);
	void SetSize(int w, int h);
	void GetSize(int& w, int& h);
	void SetFileId(std::string fid);
	int FileControlType;

	bool Flag(int f);
	CControl* parent_group;
	int g_tab = 0;
protected:
	int m_x, m_y;
	int m_iWidth, m_iHeight;
	int m_Flags;

	std::string FileIdentifier;

	virtual void Draw(bool) = 0;
	virtual void OnUpdate() = 0;
	virtual void OnClick() = 0;

};

class CColorSelector : public CControl
{
public:
	CColorSelector();
	int* GetValue() {
		return color;
	}
	void SetColor(int r, int g, int b, int a)
	{
		color[0] = r;
		color[1] = g;
		color[2] = b;
		color[3] = a;
	}

protected:
	int color[4] = { 255, 255, 255, 255 };
	bool is_open;
	bool set_new_pos = false;
	bool toggle = false;
	float brightness = 1.f;
	void Draw(bool hover);
	void OnUpdate();
	void OnClick();
};
