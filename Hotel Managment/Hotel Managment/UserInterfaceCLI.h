#include <iostream>
#include <string>
#include <memory>
#include "Manager.h"

namespace UserInterface
{
	enum MenuOptions
	{
		EXIT_SYSTEM,
		BOOK_ROOM,
		SHOW_ROOM_LIST,
		REMOVE_ROOM_BOOK,
		GET_ROOM_INFORMATION,
		EXPORT_BOOK,
		IMPORT_BOOK
	};	

	std::string Temp_input(const std::string text_to_print);

	/// <summary>
	/// The function getting input directly from the user
	/// calling the currect function based on the input
	/// Than returning the function status
	/// </summary>
	/// <returns> Methood end code </returns>
	int ChoiceSelector();

	/// <summary>
	/// Printing the Main Menu
	/// </summary>
	void Print_MainMenu();
}