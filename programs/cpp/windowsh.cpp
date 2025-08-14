#include <windows.h>
#include <commctrl.h>
#include <string>

#pragma comment(lib, "comctl32.lib")

#define WIDTH 512
#define HEIGHT 512

HWND hButton, hEdit, hRadio, hSlider;
bool hoverButton = false;
int counter = 0;

void PaintBackground(HWND hwnd, HDC hdc) {
    RECT rc;
    GetClientRect(hwnd, &rc);
    HBRUSH brush = CreateSolidBrush(RGB(30, 30, 40));
    FillRect(hdc, &rc, brush);
    DeleteObject(brush);
}

void PaintButton(HWND hwnd, HDC hdc) {
    RECT rc;
    GetClientRect(hwnd, &rc);
    HBRUSH brush = CreateSolidBrush(hoverButton ? RGB(70, 130, 180) : RGB(100, 100, 120));
    FillRect(hdc, &rc, brush);
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(255, 255, 255));
    std::wstring txt = L"Clicked " + std::to_wstring(counter) + L" times";
    DrawText(hdc, txt.c_str(), -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    DeleteObject(brush);
}

LRESULT CALLBACK ButtonProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_MOUSEMOVE: {
        if (!hoverButton) {
            hoverButton = true;
            InvalidateRect(hwnd, NULL, TRUE);
        }
        TRACKMOUSEEVENT tme = { sizeof(tme), TME_LEAVE, hwnd, 0 };
        TrackMouseEvent(&tme);
    } break;
    case WM_MOUSELEAVE: {
        hoverButton = false;
        InvalidateRect(hwnd, NULL, TRUE);
    } break;
    case WM_LBUTTONDOWN: {
        counter++;
        InvalidateRect(hwnd, NULL, TRUE);
    } break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        PaintButton(hwnd, hdc);
        EndPaint(hwnd, &ps);
        return 0;
    }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_SIZE: {
        int w = LOWORD(lParam);
        int h = HIWORD(lParam);
        MoveWindow(hButton, w/2 - 90, 50, 180, 40, TRUE);
        MoveWindow(hEdit, w/2 - 90, 110, 180, 25, TRUE);
        MoveWindow(hRadio, w/2 - 90, 150, 180, 20, TRUE);
        MoveWindow(hSlider, w/2 - 90, 190, 180, 30, TRUE);
    } break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        PaintBackground(hwnd, hdc);
        EndPaint(hwnd, &ps);
    } break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {
    INITCOMMONCONTROLSEX icex = { sizeof(icex), ICC_BAR_CLASSES };
    InitCommonControlsEx(&icex);

    const wchar_t CLASS_NAME[] = L"MyWindow";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    RegisterClass(&wc);

    const wchar_t BTN_CLASS[] = L"MyButton";
    WNDCLASS bwc = {};
    bwc.lpfnWndProc = ButtonProc;
    bwc.hInstance = hInstance;
    bwc.lpszClassName = BTN_CLASS;
    RegisterClass(&bwc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"GUI Playground",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        WIDTH, HEIGHT, nullptr, nullptr, hInstance, nullptr);

    hButton = CreateWindowEx(0, BTN_CLASS, L"", WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, hwnd, nullptr, hInstance, nullptr);
    hEdit = CreateWindow(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, 0, 0, hwnd, nullptr, hInstance, nullptr);
    hRadio = CreateWindow(L"BUTTON", L"Option 1", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 0, 0, 0, 0, hwnd, nullptr, hInstance, nullptr);
    hSlider = CreateWindowEx(0, TRACKBAR_CLASS, L"", WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS, 0, 0, 0, 0, hwnd, nullptr, hInstance, nullptr);

    SendMessage(hSlider, TBM_SETRANGE, TRUE, MAKELPARAM(0, 100));
    SendMessage(hSlider, TBM_SETPOS, TRUE, 50);

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
