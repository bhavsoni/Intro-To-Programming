//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "..\Common\game.h"

namespace TicTacToeWinRT
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
   private:
      tictactoe_game game;

      void PlaceCut(tictactoe_cell const start, tictactoe_cell const end);
      void PlaceMark(tictactoe_cell const cell, tictactoe_player const player);
      void DisplayResult(tictactoe_player const player);
      void ResetGame();

	public:
		MainPage();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
   private:
      void btnStartUser_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
      void btnStartComputer_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
      void board_PointerReleased(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
   };
}
