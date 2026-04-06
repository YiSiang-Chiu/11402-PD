#include <iostream>
#include <Windows.h>

using namespace std;

class wpPOINT
{
public:
    int x, y;
    void set(int x1, int y1) 
    {
        x = x1;
        y = y1;
    }
};
class SHAP
{
protected:
    wpPOINT p1;
    wpPOINT p2;
public:
    void set(int x1, int y1, int x2, int y2) 
    {
        p1.set(x1, y1);
        p2.set(x2, y2);
    }
};

class LINE : public SHAP
{
public:
    void draw(HDC& hdc)
    {
        MoveToEx(hdc, p1.x, p1.y, 0);
        LineTo(hdc, p2.x, p2.y);
    }
};
class RECTANGLE : public SHAP
{
public:
    void draw(HDC hdc)
    {
        Rectangle(hdc, p1.x, p1.y, p2.x, p2.y);
    }
};

class APP 
{
public:
    void run() 
    {
        int type, x1, y1, x2, y2;
        cin >> type >> x1 >> y1 >> x2 >> y2;

        HWND hWnd = CreateWindow(L"static", L"C++ Drawing", WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, nullptr, nullptr, nullptr, nullptr);
        ShowWindow(hWnd, SW_SHOW);

        HDC hdc = GetDC(hWnd);

        if (type == 1) 
        {
            LINE line;
            line.set(x1, y1, x2, y2);
            line.draw(hdc);
        }
        else if (type == 2) 
        {
            RECTANGLE rect;
            rect.set(x1, y1, x2, y2);
            rect.draw(hdc);
        }
        ReleaseDC(hWnd, hdc);
    }
};

int main() 
{
    APP app;
    app.run();
    system("pause");
    return 0;
}