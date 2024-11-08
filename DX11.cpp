﻿#include "DX11.h"
/*
File Scanned By PR(AI)
*/
#pragma region Variables
HWND DX11::hWindow;
MARGINS DX11::Margins;
INT DX11::Left;
INT DX11::Top;
INT DX11::Width;
INT DX11::Height;
int DiffX;
int DiffY;
bool DX11::IsClickable = true;


ID3D11Device* DX11::pDevice = NULL;
ID3D11DeviceContext* DX11::pImmediateContext = NULL;
IDXGISwapChain* DX11::pSwapChain = NULL;
ID3D11RenderTargetView* DX11::pRenderTargetView = NULL;
ID3D11VertexShader* DX11::pVertexShader = NULL;
ID3D11PixelShader* DX11::pPixelShader = NULL;
ID3D11InputLayout* DX11::pVertexLayout = NULL;
ID3D11Buffer* DX11::pVertexBuffer = NULL;
ID3D11Texture2D* DX11::pDepthStencilBuffer = NULL;
ID3D11DepthStencilView* DX11::pDepthStencilView = NULL;
ID3D11DepthStencilState* DX11::pDepthStencilState = NULL;
ID3D11RasterizerState* DX11::pRasterizerState = NULL;
ID3D11BlendState* DX11::pBlendState = NULL;

D3D11_INPUT_ELEMENT_DESC Layout[] =
{
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
};

UINT NumElements = ARRAYSIZE(Layout);
#pragma endregion



#pragma region Utils

HRESULT CompileShaderFromMemory(const char* szdata, SIZE_T len, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut)
{
	HRESULT hr = S_OK;
	DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;

	ID3DBlob* pErrorBlob;
	hr = D3DX11CompileFromMemory(szdata, len, NULL, NULL, NULL, szEntryPoint, szShaderModel, dwShaderFlags, 0, NULL, ppBlobOut, &pErrorBlob, NULL);
	if (FAILED(hr))
	{
		if (pErrorBlob != NULL)
			OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
		if (pErrorBlob) pErrorBlob->Release();
		return hr;
	}

	if (pErrorBlob) pErrorBlob->Release();

	return S_OK;
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
// Win32 message handler
LRESULT WINAPI DX11::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (pDevice != NULL && wParam != SIZE_MINIMIZED)
		{

			CleanupRender();
			pSwapChain->ResizeBuffers(1, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_R8G8B8A8_UNORM, 0);
			CreateRender();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}


void DX11::CleanupRender()
{
	if (pRenderTargetView)
	{
		pRenderTargetView->Release();
		pRenderTargetView = NULL;
	}

}
HRESULT DX11::CreateRender()
{
	ID3D11Texture2D* pBackBuffer;
	pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
	HRESULT hres = pDevice->CreateRenderTargetView(pBackBuffer, NULL, &pRenderTargetView);
	pBackBuffer->Release();
	return hres;
}
#pragma endregion




BOOL DX11::CreateOverlayWnd() {

	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = 0;
	wc.hIcon = 0;
	wc.hCursor = 0;
	wc.hbrBackground = 0;
	wc.lpszMenuName = "";
	wc.lpszClassName = "TaKaRRoF";
	wc.hIconSm = 0;

	RegisterClassEx(&wc);
	DX11::hWindow = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_NOACTIVATE, wc.lpszClassName, wc.lpszMenuName, WS_POPUP, 1, 1, 1, 1, NULL, NULL, NULL, NULL);
	if (DX11::hWindow == NULL)
		return FALSE;

	DX11::Margins = { -1, -1, -1, -1 };
	SetLayeredWindowAttributes(DX11::hWindow, 0, 255, LWA_ALPHA);
	DwmExtendFrameIntoClientArea(DX11::hWindow, &DX11::Margins);
	ShowWindow(DX11::hWindow, SW_SHOW);

	return TRUE;
}

BOOL DX11::CreateDeviceDx11(HWND hWindow)
{

	HRESULT hResult;
	DXGI_SWAP_CHAIN_DESC SwapChainDesc;
	ZeroMemory(&SwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	SwapChainDesc.Windowed = TRUE;
	SwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	SwapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	SwapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	SwapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	SwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	SwapChainDesc.BufferDesc.Height = Height;
	SwapChainDesc.BufferDesc.Width = Width;
	SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	SwapChainDesc.BufferCount = 1;
	SwapChainDesc.OutputWindow = hWindow;
	SwapChainDesc.SampleDesc.Count = 1;
	SwapChainDesc.SampleDesc.Quality = 0;

	D3D_FEATURE_LEVEL FeatureLevel = D3D_FEATURE_LEVEL_11_0;

	hResult = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL, D3D11_SDK_VERSION, &SwapChainDesc, &pSwapChain, &pDevice, &FeatureLevel, &pImmediateContext);
	if (FAILED(hResult)) return FALSE;
	pSwapChain->ResizeBuffers(1, (UINT)Width, (UINT)Height, DXGI_FORMAT_R8G8B8A8_UNORM, 0);
	D3D11_VIEWPORT ViewPort;
	ViewPort.Width = Width;
	ViewPort.Height = Height;
	ViewPort.MinDepth = 0.0f;
	ViewPort.MaxDepth = 1.0f;
	ViewPort.TopLeftX = 0;
	ViewPort.TopLeftY = 0;
	pImmediateContext->RSSetViewports(1, &ViewPort);

	hResult = CreateRender();
	if (FAILED(hResult)) return FALSE;

	D3D11_TEXTURE2D_DESC DepthBufferDesc;
	ZeroMemory(&DepthBufferDesc, sizeof(D3D11_TEXTURE2D_DESC));
	DepthBufferDesc.Width = Width;
	DepthBufferDesc.Height = Height;
	DepthBufferDesc.MipLevels = 1;
	DepthBufferDesc.ArraySize = 1;
	DepthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	DepthBufferDesc.SampleDesc.Count = 1;
	DepthBufferDesc.SampleDesc.Quality = 0;
	DepthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	DepthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	DepthBufferDesc.CPUAccessFlags = 0;
	DepthBufferDesc.MiscFlags = 0;
	hResult = pDevice->CreateTexture2D(&DepthBufferDesc, NULL, &pDepthStencilBuffer);
	if (FAILED(hResult)) return FALSE;

	D3D11_DEPTH_STENCIL_VIEW_DESC DepthStencilViewDesc;
	ZeroMemory(&DepthStencilViewDesc, sizeof(D3D11_DEPTH_STENCIL_VIEW_DESC));
	DepthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	DepthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	DepthStencilViewDesc.Texture2D.MipSlice = 0;
	pDevice->CreateDepthStencilView(pDepthStencilBuffer, &DepthStencilViewDesc, &pDepthStencilView);

	D3D11_DEPTH_STENCIL_DESC DepthStencilDesc;
	ZeroMemory(&DepthStencilDesc, sizeof(D3D11_DEPTH_STENCIL_DESC));
	DepthStencilDesc.DepthEnable = TRUE;
	DepthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	DepthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;
	DepthStencilDesc.StencilEnable = TRUE;
	DepthStencilDesc.StencilReadMask = 0xFF;
	DepthStencilDesc.StencilWriteMask = 0xFF;
	DepthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	DepthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	DepthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	DepthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
	DepthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	DepthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	DepthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	DepthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
	hResult = pDevice->CreateDepthStencilState(&DepthStencilDesc, &pDepthStencilState);
	if (FAILED(hResult)) return FALSE;

	pImmediateContext->OMSetDepthStencilState(pDepthStencilState, 0);
	pImmediateContext->OMSetRenderTargets(1, &pRenderTargetView, pDepthStencilView);

	D3D11_RASTERIZER_DESC RasterDesc;
	RasterDesc.AntialiasedLineEnable = TRUE;
	RasterDesc.CullMode = D3D11_CULL_BACK;
	RasterDesc.DepthBias = 100;
	RasterDesc.DepthBiasClamp = 100.0f;
	RasterDesc.DepthClipEnable = TRUE;
	RasterDesc.FillMode = D3D11_FILL_SOLID;
	RasterDesc.FrontCounterClockwise = FALSE;
	RasterDesc.MultisampleEnable = TRUE;
	RasterDesc.ScissorEnable = FALSE;
	RasterDesc.SlopeScaledDepthBias = 100.0f;
	hResult = pDevice->CreateRasterizerState(&RasterDesc, &pRasterizerState);
	if (FAILED(hResult)) return FALSE;
	pImmediateContext->RSSetState(pRasterizerState);

	ID3D10Blob* pVSBlob = NULL;
	hResult = CompileShaderFromMemory(VertexShader, sizeof(VertexShader), "VS", "vs_4_0", &pVSBlob);
	if (FAILED(hResult)) return FALSE;
	ID3D10Blob* pPSBlob = NULL;
	hResult = CompileShaderFromMemory(PixelShader, sizeof(PixelShader), "PS", "ps_4_0", &pPSBlob);
	if (FAILED(hResult)) return FALSE;

	hResult = pDevice->CreateVertexShader(pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), NULL, &pVertexShader);
	if (FAILED(hResult)) return FALSE;
	pDevice->CreateInputLayout(Layout, NumElements, pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), &pVertexLayout);
	if (FAILED(hResult)) return FALSE;
	pImmediateContext->IASetInputLayout(pVertexLayout);
	pVSBlob->Release();
	hResult = pDevice->CreatePixelShader(pPSBlob->GetBufferPointer(), pPSBlob->GetBufferSize(), NULL, &pPixelShader);
	if (FAILED(hResult)) return FALSE;
	pPSBlob->Release();

	pImmediateContext->VSSetShader(pVertexShader, NULL, 0);
	pImmediateContext->PSSetShader(pPixelShader, NULL, 0);

	D3D11_BUFFER_DESC BufferDesc;
	ZeroMemory(&BufferDesc, sizeof(D3D11_BUFFER_DESC));
	BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	BufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	BufferDesc.ByteWidth = sizeof(VERTEX) * 50;
	hResult = pDevice->CreateBuffer(&BufferDesc, NULL, &pVertexBuffer);

	UINT Stride = sizeof(VERTEX);
	UINT Offset = 0;
	pImmediateContext->IASetVertexBuffers(0, 1, &pVertexBuffer, &Stride, &Offset);

	D3D11_BLEND_DESC BlendStateDescription;
	ZeroMemory(&BlendStateDescription, sizeof(BlendStateDescription));
	BlendStateDescription.RenderTarget[0].BlendEnable = TRUE;
	BlendStateDescription.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	BlendStateDescription.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	BlendStateDescription.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	BlendStateDescription.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	BlendStateDescription.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	BlendStateDescription.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	BlendStateDescription.RenderTarget[0].RenderTargetWriteMask = 0x0f;

	hResult = pDevice->CreateBlendState(&BlendStateDescription, &pBlendState);
	if (FAILED(hResult)) return FALSE;
	float BlendFactor[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	pImmediateContext->OMSetBlendState(pBlendState, BlendFactor, 0xffffffff);


	return TRUE;
}



FLOAT Transparent[4] = { 0, 0, 0, 0 };
VOID DX11::ClearSurface()
{
	pImmediateContext->OMSetRenderTargets(1, &pRenderTargetView, NULL);
	pImmediateContext->ClearRenderTargetView(pRenderTargetView, Transparent);
	pImmediateContext->ClearDepthStencilView(pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

VOID DX11::EndDraw()
{
	pSwapChain->Present(1, 0);
}


#pragma region DrawingFunctions
VOID DX11::DrawLine(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, XMFLOAT4 Color)
{
	UINT ViewPortNumber = 1;
	D3D11_VIEWPORT ViewPort;

	pImmediateContext->RSGetViewports(&ViewPortNumber, &ViewPort);

	FLOAT _X1 = 2.0f * (X1 - 0.5f) / ViewPort.Width - 1.0f;
	FLOAT _Y1 = 1.0f - 2.0f * (Y1 - 0.5f) / ViewPort.Height;
	FLOAT _X2 = 2.0f * (X2 - 0.5f) / ViewPort.Width - 1.0f;
	FLOAT _Y2 = 1.0f - 2.0f * (Y2 - 0.5f) / ViewPort.Height;

	VERTEX* Vertex = nullptr;
	D3D11_MAPPED_SUBRESOURCE MapData;

	pImmediateContext->Map(pVertexBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &MapData);
	Vertex = (VERTEX*)MapData.pData;
	Vertex[0].Pos = XMFLOAT3(_X1, _Y1, 0.0f);
	Vertex[0].Color = Color;
	Vertex[1].Pos = XMFLOAT3(_X2, _Y2, 0.0f);
	Vertex[1].Color = Color;
	pImmediateContext->Unmap(pVertexBuffer, 0);

	pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
	pImmediateContext->VSSetShader(pVertexShader, 0, 0);
	pImmediateContext->PSSetShader(pPixelShader, 0, 0);

	pImmediateContext->Draw(2, 0);
}

VOID DX11::IMGUIDRAWLINE(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, ImColor Color, FLOAT Thickness)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	window->DrawList->AddLine(ImVec2(X1, Y1), ImVec2(X2, Y2), Color, Thickness);

}

VOID DX11::DrawCircle(FLOAT X, FLOAT Y, UINT Radius, XMFLOAT4 Color)
{
	UINT ViewPortNumber = 1;
	D3D11_VIEWPORT ViewPort;
	pImmediateContext->RSGetViewports(&ViewPortNumber, &ViewPort);

	float WedgeAngle = (float)((2 * 3.141592654f) / Radius);
	D3D11_MAPPED_SUBRESOURCE MapData;
	VERTEX* Vertex = nullptr;
	pImmediateContext->Map(pVertexBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &MapData);

	Vertex = (VERTEX*)MapData.pData;
	for (int i = 0; i <= Radius; i++)
	{
		float Theta = (float)(i * WedgeAngle);
		float x = (float)(X + Radius * cos(Theta));
		float y = (float)(Y - Radius * sin(Theta));
		Vertex[i].Pos.x = 2.0f * (x - 0.5f) / ViewPort.Width - 1.0f;
		Vertex[i].Pos.y = 1.0f - 2.0f * (y - 0.5f) / ViewPort.Height;
		Vertex[i].Pos.z = 0.0f;
		Vertex[i].Color = Color;
	}

	pImmediateContext->Unmap(pVertexBuffer, 0);

	pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
	pImmediateContext->VSSetShader(pVertexShader, 0, 0);
	pImmediateContext->PSSetShader(pPixelShader, 0, 0);

	pImmediateContext->Draw(Radius + 1, 0);
}

VOID DX11::IMGUIDRAWCIRCLE(FLOAT X, FLOAT Y, FLOAT Radius, ImColor Color, FLOAT Thickness)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window->DrawList->AddCircle(ImVec2(X, Y), Radius, Color, 0, Thickness);
}

VOID DX11::DrawCorneredBox(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, ImColor Color, FLOAT Thickness) {

	float lineW = (Width / 4);
	float lineH = (Height / 6);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + DiffX, Y + DiffY), ImVec2(X + DiffX, Y + DiffY + lineH), Color, Thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + DiffX, Y + DiffY), ImVec2(X + DiffX + lineW, Y + DiffY), Color, Thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + DiffX + Width - lineW, Y + DiffY), ImVec2(X + DiffX + Width, Y + DiffY), Color, Thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + DiffX + Width, Y + DiffY), ImVec2(X + DiffX + Width, Y + DiffY + lineH), Color, Thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + DiffX, Y + DiffY + Height - lineH), ImVec2(X + DiffX, Y + DiffY + Height), Color, Thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + DiffX, Y + DiffY + Height), ImVec2(X + DiffX + lineW, Y + DiffY + Height), Color, Thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + DiffX + Width - lineW, Y + DiffY + Height), ImVec2(X + DiffX + Width, Y + DiffY + Height), Color, Thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + DiffX + Width, Y + DiffY + Height - lineH), ImVec2(X + DiffX + Width, Y + DiffY + Height), Color, Thickness);

}

VOID DX11::DrawRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, XMFLOAT4 Color)
{
	UINT ViewPortNumber = 1;
	D3D11_VIEWPORT ViewPort;

	pImmediateContext->RSGetViewports(&ViewPortNumber, &ViewPort);

	float xx0 = 2.0f * (X - 0.5f) / ViewPort.Width - 1.0f;
	float yy0 = 1.0f - 2.0f * (Y - 0.5f) / ViewPort.Height;
	float xx1 = 2.0f * (Width - 0.5f) / ViewPort.Width - 1.0f;
	float yy1 = 1.0f - 2.0f * (Height - 0.5f) / ViewPort.Height;

	VERTEX* Vertex = nullptr;
	D3D11_MAPPED_SUBRESOURCE MapData;

	pImmediateContext->Map(pVertexBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &MapData);
	Vertex = (VERTEX*)MapData.pData;
	Vertex[0].Pos = XMFLOAT3(xx0, yy0, 0.0f);
	Vertex[0].Color = Color;
	Vertex[1].Pos = XMFLOAT3(xx1, yy0, 0.0f);
	Vertex[1].Color = Color;
	Vertex[2].Pos = XMFLOAT3(xx1, yy1, 0.0f);
	Vertex[2].Color = Color;
	Vertex[3].Pos = XMFLOAT3(xx0, yy1, 0.0f);
	Vertex[3].Color = Color;
	Vertex[4].Pos = XMFLOAT3(xx0, yy0, 0.0f);
	Vertex[4].Color = Color;
	pImmediateContext->Unmap(pVertexBuffer, 0);

	pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
	pImmediateContext->VSSetShader(pVertexShader, 0, 0);
	pImmediateContext->PSSetShader(pPixelShader, 0, 0);

	pImmediateContext->Draw(5, 0);
}

VOID DX11::DrawFilledRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, XMFLOAT4 Color)
{
	for (int i = X; i <= Width; i++)
	{
		DrawLine(i, Y, i, Height, Color);

	}
}

ImDrawList* DX11::ImGui_DX11::pImGuiDraw;
ImFont* DX11::ImGui_DX11::pRegularFont;
ImFont* DX11::ImGui_DX11::pNameFont;
ImFont* DX11::ImGui_DX11::pIconFont;

VOID DX11::ImGui_DX11::DrawLine(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, ImColor Color, FLOAT Thickness)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddLine(ImVec2(X1, Y1), ImVec2(X2, Y2), Color, Thickness);
}

VOID DX11::ImGui_DX11::DrawImage(ID3D11ShaderResourceView* img, int x, int y, int sizex, int sizey)
{
	ImGui::GetOverlayDrawList()->AddImage(img, ImVec2(x, y), ImVec2(x + sizex, y + sizey));
}

VOID DX11::ImGui_DX11::DrawCircle(FLOAT X, FLOAT Y, FLOAT Radius, ImColor Color, FLOAT Thickness)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddCircle(ImVec2(X, Y), Radius, Color, 0, Thickness);
}

VOID DX11::ImGui_DX11::DrawFilledCircle(FLOAT X, FLOAT Y, FLOAT Radius, ImColor Color)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(X, Y), Radius, Color, 0);
}

VOID DX11::ImGui_DX11::DrawRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, ImColor Color, FLOAT Thickness)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddRect(ImVec2(X, Y), ImVec2(X + Width, Y + Height), Color, 5, 0, Thickness);
}

VOID DX11::ImGui_DX11::DrawFilledBox(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, ImColor Color)//for around you
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(X + 1 + DiffX, Y + 1 + DiffY), ImVec2(((X + Width + DiffX) - 1), ((Y + Height + DiffY) - 1)), Color);
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(X + DiffX, Y + DiffY), ImVec2(X + Width + DiffX, Y + Height + DiffY), Color);
}

VOID DX11::ImGui_DX11::DrawFilledRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, ImColor Color)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddRectFilled(ImVec2(X, Y), ImVec2(X - Width, Y - Height), Color);
}

void DX11::ImGui_DX11::CornerBox(int x, int y, int w, int h, int thickness, float cornered, ImColor color)
{
	// Left Top
	DrawLine(x, y, x + (w * cornered), y, color, thickness);
	DrawLine(x, y, x, y + (h * cornered), color, thickness);
	// Left Bottom
	DrawLine(x, y + h, x + (w * cornered), y + h, color, thickness);
	DrawLine(x, y + h, x, (y + h) - (h * cornered), color, thickness);
	// Right Top
	DrawLine(x + w, y, (x + w) - (w * cornered), y, color, thickness);
	DrawLine(x + w, y, x + w, y + (h * cornered), color, thickness);
	// Right Bottom
	DrawLine(x + w, y + h, (x + w) - (w * cornered), y + h, color, thickness);
	DrawLine(x + w, y + h, x + w, (y + h) - (h * cornered), color, thickness);
}
void DX11::ImGui_DX11::DrawFilledRect(int x, int y, int w, int h, uint32_t color)
{

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddRectFilled(ImVec2(x, y - 1), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(r / 255.0, g / 255.0, b / 255.0, 1 / 255.0)), 0, 0);
	pImGuiDraw->AddRectFilled(ImVec2(x, y + 1), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(r / 255.0, g / 255.0, b / 255.0, 1 / 255.0)), 0, 0);
	pImGuiDraw->AddRectFilled(ImVec2(x - 1, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(r / 255.0, g / 255.0, b / 255.0, 1 / 255.0)), 0, 0);
	pImGuiDraw->AddRectFilled(ImVec2(x + 1, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(r / 255.0, g / 255.0, b / 255.0, 1 / 255.0)), 0, 0);
	pImGuiDraw->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0)), 0, 0);
}

void DX11::ImGui_DX11::DrawBlood(float x, float y, float w, float h, float fBlood)
{
	if (fBlood > 70.0)
	{
		//DrawBorderBox(x, y, w, h, 1, 255, 0, 255, 0);
		DrawFilledRect(x, y, w * fBlood / 100, h, ImColor(0.0f, 1.0f, 0.0f, 1.0f));
	}
	if (fBlood > 30.0 && fBlood <= 70.0)
	{
		//DrawBorderBox(x, y, w, h, 1, 255, 0, 255, 0);
		DrawFilledRect(x, y, w * fBlood / 100, h, ImColor(1.0f, 0.0f, 0.0f, 1.0f));
	}
	if (fBlood > 0.0 && fBlood <= 30.0)
	{
		//DrawBorderBox(x, y, w, h, 1, 255, 0, 255, 0);
		DrawFilledRect(x, y, w * fBlood / 100, h, ImColor(0.0f, 0.0f, 1.0f, 1.0f));

	}
}

VOID DX11::ImGui_DX11::DrawString(ImFont* pFont, FLOAT FontSize, string& Text, FLOAT X, FLOAT Y, ImColor Color, bool Center)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();

	if (Center)
	{
		ImVec2 TextSize = pFont->CalcTextSizeA(FontSize, FLT_MAX, 0.0f, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Text.c_str());
	}
	else
	{
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X, Y), Color, Text.c_str());
	}
}

VOID DX11::ImGui_DX11::DrawBorderString(ImFont* pFont, FLOAT FontSize, string& Text, FLOAT X, FLOAT Y, ImColor Color, bool Center)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();

	if (Center)
	{
		ImVec2 TextSize = pFont->CalcTextSizeA(FontSize, FLT_MAX, 0.0f, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y + 1.0f), DX11::ImGui_DX11::Color::Black, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y - 1.0f), DX11::ImGui_DX11::Color::Black, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y - 1.0f), DX11::ImGui_DX11::Color::Black, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y + 1.0f), DX11::ImGui_DX11::Color::Black, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Text.c_str());
	}
	else
	{
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - 1.0f, Y - 1.0f), DX11::ImGui_DX11::Color::Black, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - 1.0f, Y + 1.0f), DX11::ImGui_DX11::Color::Black, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X + 1.0f, Y - 1.0f), DX11::ImGui_DX11::Color::Black, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X + 1.0f, Y + 1.0f), DX11::ImGui_DX11::Color::Black, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X, Y), Color, Text.c_str());
	}
}

VOID DX11::ImGui_DX11::DrawBorderStringWithIcon(ImFont* pFont, FLOAT FontSize, const char* Text, FLOAT X, FLOAT Y, ImColor Color, bool Center)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();

	if (Center)
	{
		ImVec2 TextSize = pFont->CalcTextSizeA(FontSize, FLT_MAX, 0.0f, Text);
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y + 1.0f), DX11::ImGui_DX11::Color::Black, Text);
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y - 1.0f), DX11::ImGui_DX11::Color::Black, Text);
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y - 1.0f), DX11::ImGui_DX11::Color::Black, Text);
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y + 1.0f), DX11::ImGui_DX11::Color::Black, Text);
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Text);
	}
	else
	{
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - 1.0f, Y - 1.0f), DX11::ImGui_DX11::Color::Black, Text);
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - 1.0f, Y + 1.0f), DX11::ImGui_DX11::Color::Black, Text);
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X + 1.0f, Y - 1.0f), DX11::ImGui_DX11::Color::Black, Text);
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X + 1.0f, Y + 1.0f), DX11::ImGui_DX11::Color::Black, Text);
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X, Y), Color, Text);
	}
}

#pragma endregion


