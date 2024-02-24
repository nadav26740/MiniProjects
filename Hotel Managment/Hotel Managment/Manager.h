#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>

#define DEFAULT_FILE "Booked_rooms.dat"

typedef struct Room_Information
{
	short Days_Booked = 0;
	std::string Customer_Name = "";

	std::string Booked_by = "";
	std::string to_string() const;

}Room_Information;

class Manager
{
protected:
	std::string m_ManagerName;
	void SendLog(const char* log);

	// pair of room number and room_infromation
	std::unique_ptr<std::map<short, Room_Information>> m_Booked_Rooms;

private:
	void Set_Default_Varibles();

public:
	Manager();
	Manager(const char* ManagerName);

	Room_Information GetRoomInformation(const short RoomNumber);
	std::string GetRoomInformation_Formated(const short RoomNumber);

	void Book_a_room(const short RoomNumber, const std::string& customer_name, const short Days_to_book);
	void Remove_a_room(const short RoomNumber);
	void edit_customer_Name(const short RoomNumber);
	void Print_all_booked_rooms();

	// To file
	void Export_To_File(std::string file_path = DEFAULT_FILE);
	void Import_From_File(std::string file_path = DEFAULT_FILE);
};

