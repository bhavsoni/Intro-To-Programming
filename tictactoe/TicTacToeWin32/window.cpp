#include "pch.h"
#include "window.h"
#include "resource.h"

TicTacToeWindow::TicTacToeWindow()
{
   auto hModule = ::GetModuleHandle(nullptr);
   hBmp0 = ::LoadBitmap(hModule, MAKEINTRESOURCE(IDB_BITMAP_0));
   hBmpX = ::LoadBitmap(hModule, MAKEINTRESOURCE(IDB_BITMAP_X));

   ::GetObject(hBmp0, sizeof(bmp0), &bmp0);
   ::GetObject(hBmpX, sizeof(bmpX), &bmpX);  
}

TicTacToeWindow::~TicTacToeWindow()
{
   ::DeleteObject(hBmp0);
   ::DeleteObject(hBmpX);
}

void TicTacToeWindow::OnLeftButtonUp(int x, int y, WPARAM params)
{
   if(game.is_started() && !game.is_finished())
   {
      RECT rcClient;
      ::GetClientRect(hWnd, &rcClient);

      int cellw = (rcClient.right - rcClient.left) / 3;
      int cellh = (rcClient.bottom - rcClient.top) / 3;

      int col = x / cellw;
      int row = y / cellh;

      if(game.move(tictactoe_cell(row, col), tictactoe_player::user))
      {
         if(!game.is_finished())
            game.move(tictactoe_player::computer);

         Invalidate(FALSE);
      }
   }
}

void TicTacToeWindow::OnMenuItemClicked(int menuId)
{
   switch(menuId)
   {
   case ID_GAME_EXIT:
      ::PostMessage(hWnd, WM_CLOSE, 0, 0);
      break;

   case ID_GAME_STARTUSER:
      game.start(tictactoe_player::user);
      Invalidate(FALSE);
      break;

   case ID_GAME_STARTCOMPUTER:
      game.start(tictactoe_player::computer);
      game.move(tictactoe_player::computer);
      Invalidate(FALSE);
      break;
   }
}

void TicTacToeWindow::DrawBackground(HDC dc, RECT rc)
{
   auto brWhite = ::CreateSolidBrush(COLORREF(0xffffff));
   auto brOld = ::SelectObject(dc, brWhite);

   ::FillRect(dc, &rc, static_cast<HBRUSH>(brOld));

   ::SelectObject(dc, brOld);
}

void TicTacToeWindow::DrawGrid(HDC dc, RECT rc)
{
   auto penLine = ::CreatePen(PS_SOLID, 1, COLORREF(0x111111));
   auto penOld = ::SelectObject(dc, static_cast<HPEN>(penLine));

   ::Rectangle(dc, rc.left, rc.top, rc.right, rc.bottom);

   int cellw = (rc.right - rc.left) / 3;
   int cellh = (rc.bottom - rc.top) / 3;

   for(int i = 0; i < 2; ++i)
   {
      ::MoveToEx(dc, rc.left, rc.top + (i+1)*cellh, nullptr);
      ::LineTo(dc, rc.right, rc.top + (i+1)*cellh);
   }

   for(int j = 0; j < 2; ++j)
   {
      ::MoveToEx(dc, rc.left + (j+1)*cellw, rc.top, nullptr);
      ::LineTo(dc, rc.left + (j+1)*cellw, rc.bottom);
   }

   ::SelectObject(dc, penOld);
}

void TicTacToeWindow::DrawMarks(HDC dc, RECT rc)
{
   auto status = game.get_status();

   int cellw = (rc.right - rc.left) / 3;
   int cellh = (rc.bottom - rc.top) / 3;

   for(int i = 0; i < 3; ++i)
   {
      for(int j = 0; j < 3; j++)
      {
         HANDLE hbmp = nullptr;
         int width = 0;
         int height = 0;

         switch(status[i*3+j])
         {
         case 1:
            hbmp = hBmpX;
            width = bmpX.bmWidth;
            height = bmpX.bmHeight;
            break;
         case 2:
            hbmp = hBmp0;
            width = bmp0.bmWidth;
            height = bmp0.bmHeight;
            break;
         }

         auto memdc2 = ::CreateCompatibleDC(dc);
         auto bmpOld2 = ::SelectObject(memdc2, hbmp);

         if(hbmp != nullptr)
            ::BitBlt(
            dc, 
            rc.left + j * cellw + (cellw - width) / 2,
            rc.top + i * cellh + (cellh - height) / 2,
            width,
            height,
            memdc2,
            0,
            0,
            SRCCOPY);

         ::SelectObject(memdc2, bmpOld2);
         ::DeleteDC(memdc2);
      }
   }
}

void TicTacToeWindow::DrawCut(HDC dc, RECT rc)
{
   if(game.is_finished())
   {
      auto streak = game.get_winning_line();

      if(streak.first.is_valid() && streak.second.is_valid())
      {
         int cellw = (rc.right - rc.left) / 3;
         int cellh = (rc.bottom - rc.top) / 3;

         auto penLine = ::CreatePen(PS_SOLID, 15, COLORREF(0x2222ff));
         auto penOld = ::SelectObject(dc, static_cast<HPEN>(penLine));

         ::MoveToEx(
            dc, 
            rc.left + streak.first.col * cellw + cellw/2, 
            rc.top + streak.first.row * cellh + cellh/2,
            nullptr);

         ::LineTo(dc,
            rc.left + streak.second.col * cellw + cellw/2,
            rc.top + streak.second.row * cellh + cellh/2);

         ::SelectObject(dc, penOld);
      }
   }
}

void TicTacToeWindow::OnPaint(DeviceContext* dc)
{
   RECT rcClient;
   ::GetClientRect(hWnd, &rcClient);

   auto memdc = ::CreateCompatibleDC(*dc);
   auto membmp = ::CreateCompatibleBitmap(*dc, rcClient.right - rcClient.left, rcClient.bottom-rcClient.top);
   auto bmpOld = ::SelectObject(memdc, membmp);

   DrawBackground(memdc, rcClient);

   DrawGrid(memdc, rcClient);

   DrawMarks(memdc, rcClient);

   DrawCut(memdc, rcClient);

   ::BitBlt(*dc, 
      rcClient.left, 
      rcClient.top, 
      rcClient.right - rcClient.left, 
      rcClient.bottom-rcClient.top,
      memdc, 
      0, 
      0, 
      SRCCOPY);

   ::SelectObject(memdc, bmpOld);
   ::DeleteObject(membmp);
   ::DeleteDC(memdc);
}