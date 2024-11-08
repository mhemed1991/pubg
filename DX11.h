#pragma once

#include <dxgi.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <D3DX11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <DirectXColors.h>
#include <xnamath.h>
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "d3dx11.lib")

#include "Includes.h"

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_internal.h"

const char VertexShader[] =
{
"struct VS_OUTPUT\n"
"{\n"
	"float4 Pos : SV_POSITION;\n"
	"float4 Color : COLOR;\n"
"};\n"
"VS_OUTPUT VS(float4 inPos : POSITION, float4 inColor : COLOR)\n"
"{\n"
	"VS_OUTPUT output;\n"

	"output.Pos = inPos;\n"
	"output.Color = inColor;\n"

	"return output;\n"
"}\n"
};

const char PixelShader[] =
{
"struct VS_OUTPUT\n"
"{\n"
"float4 Pos : SV_POSITION;\n"
"float4 Color : COLOR;\n"
"};\n"
"float4 PS(VS_OUTPUT input) : SV_TARGET\n"
"{\n"
"return input.Color;\n"
"}\n"
};

struct VERTEX
{
	XMFLOAT3 Pos;
	XMFLOAT4 Color;

};

namespace DX11
{
	extern HWND hWindow;
	extern MARGINS Margins;
	extern INT Left;
	extern INT Top;
	extern INT Width;
	extern INT Height;
	extern bool IsClickable;

	BOOL CreateOverlayWnd();
	LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pImmediateContext;
	extern IDXGISwapChain* pSwapChain;
	extern ID3D11RenderTargetView* pRenderTargetView;
	extern ID3D11VertexShader* pVertexShader;
	extern ID3D11PixelShader* pPixelShader;
	extern ID3D11InputLayout* pVertexLayout;
	extern ID3D11Buffer* pVertexBuffer;
	extern ID3D11Texture2D* pDepthStencilBuffer;
	extern ID3D11DepthStencilView* pDepthStencilView;
	extern ID3D11DepthStencilState* pDepthStencilState;
	extern ID3D11RasterizerState* pRasterizerState;
	extern ID3D11BlendState* pBlendState;

	BOOL CreateDeviceDx11(HWND hWindow);
	VOID ClearSurface();
	void CleanupRender();
	HRESULT CreateRender();
	VOID EndDraw();
	VOID DrawLine(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, XMFLOAT4 Color);
	VOID IMGUIDRAWLINE(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, ImColor Color, FLOAT Thickness);
	VOID DrawCircle(FLOAT X, FLOAT Y, UINT Radius, XMFLOAT4 Color);
	VOID IMGUIDRAWCIRCLE(FLOAT X, FLOAT Y, FLOAT Radius, ImColor Color, FLOAT Thickness);
	VOID DrawRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, XMFLOAT4 Color);
	VOID DrawFilledRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, XMFLOAT4 Color);
	VOID DrawCorneredBox(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, ImColor Color, FLOAT Thickness);
	namespace ImGui_DX11
	{
		extern ImDrawList* pImGuiDraw;
		extern ImFont* pRegularFont;
		extern ImFont* pNameFont;
		extern ImFont* pIconFont;

		VOID DrawLine(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, ImColor Color, FLOAT Thickness = 1);
		VOID DrawImage(ID3D11ShaderResourceView* img, int x, int y, int sizex, int sizey);
		VOID DrawCircle(FLOAT X, FLOAT Y, FLOAT Radius, ImColor Color, FLOAT Thickness = 1);
		VOID DrawFilledCircle(FLOAT X, FLOAT Y, FLOAT Radius, ImColor Color);
		VOID DrawRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, ImColor Color, FLOAT Thickness = 1);
		void CornerBox(int x, int y, int w, int h, int thickness, float cornered, ImColor color);
		void DrawFilledRect(int x, int y, int w, int h, uint32_t color);
		void DrawBlood(float x, float y, float w, float h, float fBlood);
		VOID DrawFilledRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, ImColor Color);
		VOID DrawString(ImFont* pFont, FLOAT FontSize, string& Text, FLOAT X, FLOAT Y, ImColor Color, bool Center);
		VOID DrawBorderString(ImFont* pFont, FLOAT FontSize, string& Text, FLOAT X, FLOAT Y, ImColor Color, bool Center);
		VOID DrawBorderStringWithIcon(ImFont* pFont, FLOAT FontSize, const char* Text, FLOAT X, FLOAT Y, ImColor Color, bool Center);
		VOID DrawFilledBox(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, ImColor Color);

		namespace Color
		{
			const ImColor White = ImColor(255, 255, 255);
			const ImColor Black = ImColor(0, 0, 0);
			const ImColor Red = ImColor(255, 0, 0);
			const ImColor Green = ImColor(0, 255, 0);
			const ImColor Blue = ImColor(0, 150, 255);
			const ImColor Yellow = ImColor(255, 255, 0);
			const ImColor Cyan = ImColor(0, 180, 255);
			const ImColor Orange = ImColor(255, 165, 0);
			const ImColor Maroon = ImColor(128, 0, 0);
			const ImColor Magenta = ImColor(255, 0, 255);
			const ImColor Olive = ImColor(128, 128, 0);
			const ImColor Purple = ImColor(128, 0, 128);
			const ImColor Chocolate = ImColor(255, 127, 36);
			const ImColor CarColor = ImColor(255, 247, 0);
			const ImColor EnemyAround = ImColor(0, 0, 200);
			const ImColor GlassBlack = ImColor(0, 0, 0, 15);
			const ImColor PdisColor = ImColor(73, 252, 142);
		}

	}
}