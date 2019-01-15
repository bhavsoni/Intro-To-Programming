//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <stdlib.h>

using namespace TicTacToeWinRT;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Shapes;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

MainPage::MainPage()
{
	InitializeComponent();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property is typically used to configure the page.</param>
void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void) e;	// Unused parameter
}


void TicTacToeWinRT::MainPage::btnStartUser_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
   ResetGame();

   game.start(tictactoe_player::user);
}

void TicTacToeWinRT::MainPage::btnStartComputer_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
   ResetGame();

   game.start(tictactoe_player::computer);
   auto cell = game.move(tictactoe_player::computer);
   
   PlaceMark(cell, tictactoe_player::computer);
}

void TicTacToeWinRT::MainPage::board_PointerReleased(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
   if(game.is_started() && ! game.is_finished())
   {
      auto cellw = board->ActualWidth / 3;
      auto cellh = board->ActualHeight / 3;

      auto point = e->GetCurrentPoint(board);
      auto row = static_cast<int>(point->Position.Y / cellh);
      auto col = static_cast<int>(point->Position.X / cellw);

      game.move(tictactoe_cell(row, col), tictactoe_player::user);
      PlaceMark(tictactoe_cell(row, col), tictactoe_player::user);

      if(!game.is_finished())
      {
         auto cell = game.move(tictactoe_player::computer);
         PlaceMark(cell, tictactoe_player::computer);

         if(game.is_finished())
         {
            DisplayResult(
               game.is_victory(tictactoe_player::computer) ? 
               tictactoe_player::computer :
               tictactoe_player::none);
         }
      }
      else
      {
         DisplayResult(
            game.is_victory(tictactoe_player::user) ? 
            tictactoe_player::user :
            tictactoe_player::none);
      }
   }
}

void TicTacToeWinRT::MainPage::DisplayResult(tictactoe_player const player)
{
   Platform::String^ text = nullptr;
   switch (player)
   {
   case tictactoe_player::none:
      text = "It's a draw!";
      break;
   case tictactoe_player::computer:
      text = "Computer wins!";
      break;
   case tictactoe_player::user:
      text = "User wins!";
      break;
   }

   txtStatus->Text = text;

   if(player != tictactoe_player::none)
   {
      auto coordinates = game.get_winning_line();
      if(coordinates.first.is_valid() && coordinates.second.is_valid())
      {
         PlaceCut(coordinates.first, coordinates.second);
      }
   }
}

void TicTacToeWinRT::MainPage::PlaceMark(tictactoe_cell const cell, tictactoe_player const player)
{
   auto image = ref new Image();
   auto bitmap = ref new BitmapImage(
      ref new Uri(player == tictactoe_player::computer ? "ms-appx:///Assets/tttx.bmp" : "ms-appx:///Assets/ttt0.bmp"));
   bitmap->ImageOpened += ref new RoutedEventHandler( 
      [this, image, bitmap, cell](Object^ sender, RoutedEventArgs^ e) {
         image->Width = bitmap->PixelWidth;
         image->Height = bitmap->PixelHeight;
         image->Visibility = Windows::UI::Xaml::Visibility::Visible;
   });

   image->Source = bitmap;

   image->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
   image->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;
   image->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;

   Grid::SetRow(image, cell.row);
   Grid::SetColumn(image, cell.col);

   board->Children->Append(image);
}

void TicTacToeWinRT::MainPage::PlaceCut(tictactoe_cell const start, tictactoe_cell const end)
{
   auto cellw = board->ActualWidth / 3;
   auto cellh = board->ActualHeight / 3;

   auto line = ref new Line();
   line->X1 = start.col * cellw + cellw / 2;
   line->Y1 = start.row * cellh + cellh / 2;

   line->X2 = end.col * cellw + cellw / 2;
   line->Y2 = end.row * cellh + cellh / 2;

   line->StrokeStartLineCap = Windows::UI::Xaml::Media::PenLineCap::Round;
   line->StrokeEndLineCap = Windows::UI::Xaml::Media::PenLineCap::Round;
   line->StrokeThickness = 15;
   line->Stroke = ref new SolidColorBrush(Windows::UI::Colors::Red);

   line->Visibility = Windows::UI::Xaml::Visibility::Visible;

   Grid::SetRow(line, 0);
   Grid::SetColumn(line, 0);
   Grid::SetRowSpan(line, 3);
   Grid::SetColumnSpan(line, 3);

   board->Children->Append(line);
}

void TicTacToeWinRT::MainPage::ResetGame()
{
   std::vector<Windows::UI::Xaml::UIElement^> children;

   for(auto const & child : board->Children)
   {
      auto typeName = child->GetType()->FullName;
      if(typeName == "Windows.UI.Xaml.Controls.Image" ||
         typeName == "Windows.UI.Xaml.Shapes.Line")
      {
         children.push_back(child);
      }
   }

   for(auto const & child : children)
   {
      unsigned int index;
      if(board->Children->IndexOf(child, &index))
      {
         board->Children->RemoveAt(index);
      }
   }

   txtStatus->Text = nullptr;
}