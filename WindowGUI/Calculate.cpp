#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include "DoubleIntegral.h"
#include "Integral.h"
#include "Integral2.h"
using namespace std;

#define HELP_MENU_DOUBLE 2
#define HELP_MENU_INTEGRAL 1
#define MENU_Exit 3
#define MENU_INTEGRAL 4
#define MENU_DOUBLE_INTEGRAL 5

LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);

void AddMenus(HWND);
void AddControls(HWND);
void loadImages();
void registerDialogClass(HINSTANCE);
void displayDialogSin(HWND);
void displayDialogDou(HWND);
void func1(HWND);
void func2(HWND);


HMENU hMenu;
HWND hBG,hMainWindow,hBGA,hBGB,input1,input2,input3,input4,stepx,stepy,constant,power,hBGA1,hBGB1,up,low,power2;
HBITMAP hBGImage,hLogoI,hLogoII,hExit,hBGSin,hBGDou,hCal,hClose,hfuc1,hfuc2,hbgfunc1,hbgfunc2,hback; 
char n1[100],n2[100],n3[100],n4[100],rs[100],I1[100],I2[100],sumchar[100],upx[100],lowx[100],powerx[100],result[100];
float a,b,c,d;
float f,g;
float ux2,lx2,powerxi;
float sum2 = 0;
float sum = 0;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args,int ncmdshow){
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW ;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"Calculate";
    wc.lpfnWndProc =  WindowProcedure;  

    if(!RegisterClassW(&wc))
        return -1;
    
    registerDialogClass(hInst);

    hMainWindow = CreateWindowW(L"Calculate",L"Calculate Integral",WS_MINIMIZEBOX|WS_SYSMENU|WS_VISIBLE,100,100,500,500,NULL,NULL,NULL,NULL);
    MSG msg = {0};

    while( GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    } 
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{
    int val;
    switch (msg)
    {
        case WM_COMMAND:

            switch (wp)
            {
                case HELP_MENU_DOUBLE:
                MessageBeep(MB_ICONINFORMATION);
                MessageBox(hwnd,"Calculate for find Area by Double Integral.Only input by number value.","Double Integral",MB_OK);
                break;
                case HELP_MENU_INTEGRAL:
                MessageBeep(MB_ICONINFORMATION);
                MessageBox(hwnd,"Normal Integral","Integral",MB_OK);
                break;
                case MENU_Exit:
                val = MessageBoxW(hwnd,L"Are you sure?",L"Message",MB_YESNO | MB_ICONWARNING);
                if(val==IDYES){
                    DestroyWindow(hwnd);
                }
                else if(val==IDNO){
                    break;
                }
                case MENU_INTEGRAL:
                    displayDialogSin(hwnd);
                    break;
                 case MENU_DOUBLE_INTEGRAL:
                    displayDialogDou(hwnd);
                    break;
                break;
            }

            break;
        case WM_CREATE:
            loadImages();
            AddMenus(hwnd);
            AddControls(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            DefWindowProcW(hwnd,msg,wp,lp);
    }
}

void AddMenus(HWND hwnd)
{
    hMenu = CreateMenu();
    HMENU hHelpMenu = CreateMenu();
    AppendMenu(hHelpMenu,MF_STRING,HELP_MENU_INTEGRAL,"Integral");
    AppendMenu(hHelpMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hHelpMenu,MF_STRING,HELP_MENU_DOUBLE,"Double Integral");
    
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hHelpMenu,"Help");

    SetMenu(hwnd,hMenu);
}

void AddControls(HWND hwnd)
{
    hBG = CreateWindowW(L"Static",NULL,WS_VISIBLE|WS_CHILD|SS_BITMAP,0,0,0,0,hwnd,NULL,NULL,NULL);
    SendMessageW(hBG,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hBGImage);
    HWND hButA = CreateWindowW(L"Button",L"INTEGRAL",WS_VISIBLE|WS_CHILD|BS_BITMAP,135,80,230,100,hwnd,(HMENU) MENU_INTEGRAL,NULL,NULL);
    SendMessageW(hButA,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hLogoI);
    HWND hButB = CreateWindowW(L"Button",L"DOUBLE INTEGRAL",WS_VISIBLE|WS_CHILD|BS_BITMAP,135,200,230,100,hwnd,(HMENU) MENU_DOUBLE_INTEGRAL,NULL,NULL);
    SendMessageW(hButB,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hLogoII);
    HWND hButExit = CreateWindowW(L"Button",L"Exit",WS_VISIBLE|WS_CHILD|BS_BITMAP,200,340,100,50,hwnd,(HMENU) MENU_Exit,NULL,NULL);
    SendMessageW(hButExit,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hExit);
}
    

void loadImages()
{
    hBGImage = (HBITMAP)LoadImageW(NULL,L"picture\\BG.bmp",IMAGE_BITMAP,492,450,LR_LOADFROMFILE);
    hLogoI = (HBITMAP)LoadImageW(NULL,L"picture\\LogoI.bmp",IMAGE_BITMAP,230,100,LR_LOADFROMFILE);
    hLogoII = (HBITMAP)LoadImageW(NULL,L"picture\\LogoII.bmp",IMAGE_BITMAP,230,100,LR_LOADFROMFILE);
    hExit = (HBITMAP)LoadImageW(NULL,L"picture\\Exit.bmp",IMAGE_BITMAP,100,50,LR_LOADFROMFILE);
    hBGDou = (HBITMAP)LoadImageW(NULL,L"picture\\BGI.bmp",IMAGE_BITMAP,492,470,LR_LOADFROMFILE);
    hBGSin = (HBITMAP)LoadImageW(NULL,L"picture\\BGII.bmp",IMAGE_BITMAP,492,470,LR_LOADFROMFILE);
    hCal = (HBITMAP)LoadImageW(NULL,L"picture\\Cal.bmp",IMAGE_BITMAP,100,40,LR_LOADFROMFILE);
    hClose = (HBITMAP)LoadImageW(NULL,L"picture\\Close.bmp",IMAGE_BITMAP,100,40,LR_LOADFROMFILE);
    hfuc1 = (HBITMAP)LoadImageW(NULL,L"picture\\button select1.bmp",IMAGE_BITMAP,250,100,LR_LOADFROMFILE);
    hfuc2 = (HBITMAP)LoadImageW(NULL,L"picture\\button select2.bmp",IMAGE_BITMAP,250,100,LR_LOADFROMFILE);
    hbgfunc1 = (HBITMAP)LoadImageW(NULL,L"picture\\BGfunc1.bmp",IMAGE_BITMAP,492,470,LR_LOADFROMFILE);
    hbgfunc2 = (HBITMAP)LoadImageW(NULL,L"picture\\BGfunc2.bmp",IMAGE_BITMAP,492,470,LR_LOADFROMFILE);
    hback = (HBITMAP)LoadImageW(NULL,L"picture\\Back.bmp",IMAGE_BITMAP,100,40,LR_LOADFROMFILE);
}

//หน้าต่างใหม่

LRESULT CALLBACK DialogProcedure(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch(msg)
    {
        case WM_COMMAND:
        int val1,val2,val3;
            switch (wp)
            {
            case 1:
                EnableWindow(hMainWindow,true);
                DestroyWindow(hwnd);
                break;
            case 2:
                GetWindowText(input1,n1,100);
                GetWindowText(input2,n2,100);
                GetWindowText(input3,n3,100);
                GetWindowText(input4,n4,100);
                a = atof(n1); //up y
                b = atof(n2); // low y
                c = atof(n3); // up x
                d = atof(n4); // low x
                sum = Calculate(d,c,b,a);
                sprintf(rs,"%f",sum);
                MessageBeep(MB_ICONINFORMATION);
                val1 = MessageBox(hwnd,rs,"Result",MB_OK);
                break;
            case 3:
                GetWindowText(constant,I1,100);
                GetWindowText(power,I2,100);
                f = atof(I1); // constant
                g = atof(I2); // power
                if(g == 0)
                {
                    MessageBeep(MB_ICONINFORMATION);
                 val2 =   MessageBox(hwnd,"0","Result",MB_OK);
                }
                else if(f == 0)
                {
                    MessageBeep(MB_ICONINFORMATION);
                 val2 =   MessageBox(hwnd,"0","Result",MB_OK);
                }
                else{
                    g = g+1;
                    f = f/g;
                    sprintf(sumchar,"%fx^%f",f,g);
                    MessageBeep(MB_ICONINFORMATION);
                 val2 =   MessageBox(hwnd,sumchar,"Result",MB_OK);
                }
                
                break;
                case 4:
                    func1(hwnd);
                break;
                case 5:
                    func2(hwnd);
                break;
                case 6:
                    DestroyWindow(hwnd);
                break;
                case 7:
                    GetWindowText(up,upx,100);
                    GetWindowText(power2,powerx,100);
                    GetWindowText(low,lowx,100);
                    ux2 = atof(upx);
                    lx2 = atof(lowx);
                    powerxi = atof(powerx);
                    sum2 = SpaceCal(lx2,ux2,powerxi);
                    sprintf(result,"%f",sum2);
                    MessageBeep(MB_ICONINFORMATION);
                    val3 =  MessageBox(hwnd,result,"Result",MB_OK);
                break;
            default:
                break;
            }
        case WM_CLOSE:
            break;
        default:
            return DefWindowProcW(hwnd,msg,wp,lp);
    }
}

void registerDialogClass(HINSTANCE hInst)
{
    WNDCLASSW dialog = {0};

    dialog.hbrBackground = (HBRUSH)COLOR_WINDOW ;
    dialog.hCursor = LoadCursor(NULL,IDC_ARROW);
    dialog.hInstance = hInst;
    dialog.lpszClassName = L"Dialog Calculate";
    dialog.lpfnWndProc = DialogProcedure;  

    RegisterClassW(&dialog);
}

void displayDialogSin(HWND hwnd)
{
    HWND hDlgA = CreateWindowW(L"Dialog Calculate",L"Integral",WS_MINIMIZEBOX|WS_VISIBLE|WS_POPUP,700,100,492,470,hwnd,NULL,NULL,NULL);
    hBGA = CreateWindowW(L"Static",NULL,WS_VISIBLE|WS_CHILD|SS_BITMAP,0,0,0,0,hDlgA,NULL,NULL,NULL);
    SendMessageW(hBGA,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hBGSin);
    HWND ButtonFuc1 = CreateWindowW(L"Button",L"Fuc1",WS_VISIBLE|WS_CHILD|BS_BITMAP,120,100,250,100,hDlgA,(HMENU) 4,NULL,NULL);
    SendMessageW(ButtonFuc1,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hfuc1);
    HWND ButtonFuc2 = CreateWindowW(L"Button",L"Fuc2",WS_VISIBLE|WS_CHILD|BS_BITMAP,120,220,250,100,hDlgA,(HMENU) 5,NULL,NULL);
    SendMessageW(ButtonFuc2,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hfuc2);
    HWND hButtonCloseA = CreateWindowW(L"Button",L"Close",WS_VISIBLE|WS_CHILD|BS_BITMAP,340,380,100,40,hDlgA,(HMENU) 1,NULL,NULL);
    SendMessageW(hButtonCloseA,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hClose);
    EnableWindow(hwnd,false);
}

void displayDialogDou(HWND hwnd)
{
    HWND hDlgB = CreateWindowW(L"Dialog Calculate",L"Double Integral",WS_MINIMIZEBOX|WS_VISIBLE|WS_POPUP,700,100,492,470,hwnd,NULL,NULL,NULL);
    hBGB = CreateWindowW(L"Static",NULL,WS_VISIBLE|WS_CHILD|SS_BITMAP,0,0,0,0,hDlgB,NULL,NULL,NULL);
    SendMessageW(hBGB,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hBGDou);
    input1 = CreateWindowW(L"Edit",L"",WS_VISIBLE|WS_CHILD,50,120,40,20,hDlgB,NULL,NULL,NULL); //up y
    input2 = CreateWindowW(L"Edit",L"",WS_VISIBLE|WS_CHILD,50,255,40,20,hDlgB,NULL,NULL,NULL); // low y
    input3 = CreateWindowW(L"Edit",L"",WS_VISIBLE|WS_CHILD,130,120,40,20,hDlgB,NULL,NULL,NULL); // up x
    input4 = CreateWindowW(L"Edit",L"",WS_VISIBLE|WS_CHILD,130,255,40,20,hDlgB,NULL,NULL,NULL); // low x
    // stepx = CreateWindowW(L"Edit",L"",WS_VISIBLE|WS_CHILD,390,18,40,20,hDlgB,NULL,NULL,NULL); //h
    // stepy = CreateWindowW(L"Edit",L"",WS_VISIBLE|WS_CHILD,390,48,40,20,hDlgB,NULL,NULL,NULL); //k
    HWND hButtonCalB = CreateWindowW(L"Button",L"Calculate",WS_VISIBLE|WS_CHILD|BS_BITMAP,350,380,100,40,hDlgB,(HMENU) 2,NULL,NULL);
    SendMessageW(hButtonCalB,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hCal);
    HWND hButtonCloseB =CreateWindowW(L"Button",L"Close",WS_VISIBLE|WS_CHILD|BS_BITMAP,240,380,100,40,hDlgB,(HMENU) 1,NULL,NULL);
    SendMessageW(hButtonCloseB,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hClose);
    EnableWindow(hwnd,false);
}

void func1(HWND hwnd)
{
    HWND calfunc1 = CreateWindowW(L"Dialog Calculate",L"Integral Function I",WS_MINIMIZEBOX|WS_VISIBLE|WS_POPUP,700,100,492,470,hwnd,NULL,NULL,NULL);
    hBGA1 = CreateWindowW(L"Static",NULL,WS_VISIBLE|WS_CHILD|SS_BITMAP,0,0,0,0,calfunc1,NULL,NULL,NULL);
    SendMessageW(hBGA1,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hbgfunc1);
    HWND hButtonCloseC =CreateWindowW(L"Button",L"Back",WS_VISIBLE|WS_CHILD|BS_BITMAP,230,380,100,40,calfunc1,(HMENU) 6,NULL,NULL);
    SendMessageW(hButtonCloseC,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hback);
    HWND hButtonCalA = CreateWindowW(L"Button",L"Calculate",WS_VISIBLE|WS_CHILD|BS_BITMAP,350,380,100,40,calfunc1,(HMENU) 3,NULL,NULL);
    SendMessageW(hButtonCalA,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hCal);
    constant = CreateWindowW(L"Edit",L"",WS_VISIBLE|WS_CHILD,130,190,60,50,calfunc1,NULL,NULL,NULL);
    power = CreateWindowW(L"Edit",L"",WS_VISIBLE|WS_CHILD,245,135,60,50,calfunc1,NULL,NULL,NULL);
}

void func2(HWND hwnd)
{
    HWND calfunc2 = CreateWindowW(L"Dialog Calculate",L"Integral Function II",WS_MINIMIZEBOX|WS_VISIBLE|WS_POPUP,700,100,492,470,hwnd,NULL,NULL,NULL);
    hBGB1 = CreateWindowW(L"Static",NULL,WS_VISIBLE|WS_CHILD|SS_BITMAP,0,0,0,0,calfunc2,NULL,NULL,NULL);
    SendMessageW(hBGB1,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hbgfunc2);
    HWND hButtonCloseD =CreateWindowW(L"Button",L"Back",WS_VISIBLE|WS_CHILD|BS_BITMAP,230,380,100,40,calfunc2,(HMENU) 6,NULL,NULL);
    HWND hButtonCalC = CreateWindowW(L"Button",L"Calculate",WS_VISIBLE|WS_CHILD|BS_BITMAP,350,380,100,40,calfunc2,(HMENU) 7,NULL,NULL);
    SendMessageW(hButtonCalC,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hCal);
    SendMessageW(hButtonCloseD,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hback);
    low = CreateWindowW(L"Edit",L"",WS_VISIBLE|WS_CHILD,80,255,60,50,calfunc2,NULL,NULL,NULL);
    power2 = CreateWindowW(L"Edit",L"",WS_VISIBLE|WS_CHILD,245,135,60,50,calfunc2,NULL,NULL,NULL);
    up = CreateWindowW(L"Edit",L"",WS_VISIBLE|WS_CHILD,80,80,60,50,calfunc2,NULL,NULL,NULL);
}
