#include "Manager.h"

void Manager::SendLog(const char* log)
{
	std::cout << "[Log]" << m_ManagerName << ": " << log << std::endl;
}

void Manager::Set_Default_Varibles()
{
	this->m_Booked_Rooms = std::make_unique<std::map<short, Room_Information>>();
}

Manager::Manager()
{
	Set_Default_Varibles();
}

Manager::Manager(const char* ManagerName)
{
	Set_Default_Varibles();
	this->m_ManagerName = ManagerName;
}

Room_Information Manager::GetRoomInformation(const short RoomNumber)
{
	auto room_itr_ptr = this->m_Booked_Rooms->find(RoomNumber);
	if (room_itr_ptr == this->m_Booked_Rooms->end())
		throw std::exception("Room Not found");

	return room_itr_ptr->second;
}

std::string Manager::GetRoomInformation_Formated(const short RoomNumber)
{
	std::string output = "";
	Room_Information room = GetRoomInformation(RoomNumber);

	output += "Room Number:\t\t" + std::to_string(RoomNumber) + "\n";
	output += room.to_string();

	return output;
}

void Manager::Book_a_room(const short RoomNumber, const std::string& customer_name, const short Days_to_book)
{
	if (this->m_Booked_Rooms->find(RoomNumber) != this->m_Booked_Rooms->end())
		throw std::exception("Room already exists");

	Room_Information new_room;
	new_room.Booked_by = this->m_ManagerName;
	new_room.Customer_Name = customer_name;
	new_room.Days_Booked = Days_to_book;

	this->m_Booked_Rooms->insert(std::pair<short, Room_Information>(RoomNumber, new_room));
}

void Manager::Remove_a_room(const short RoomNumber)
{
	auto room_itr_ptr = this->m_Booked_Rooms->find(RoomNumber);
	if (room_itr_ptr == this->m_Booked_Rooms->end())
		throw std::exception("Room Not found");

	this->m_Booked_Rooms->
		erase(room_itr_ptr);
}

void Manager::edit_customer_Name(const short RoomNumber)
{
	auto room_itr_ptr = this->m_Booked_Rooms->find(RoomNumber);
	if (room_itr_ptr == this->m_Booked_Rooms->end())
		throw std::exception("Room Not found");
	std::cout << "Enter New Customer name: ";
	std::cin >> room_itr_ptr->second.Customer_Name;

	std::cout << "New Name set: " << room_itr_ptr->second.Customer_Name << std::endl;
}

void Manager::Print_all_booked_rooms()
{
	std::cout << "========= Booked rooms =========" << std::endl;
	for (auto room_itr_ptr : *this->m_Booked_Rooms)
	{
		std::cout << "----------- Room: " << room_itr_ptr.first << " -----------" << std::endl;
		std::cout << room_itr_ptr.second.to_string() << std::endl;
	}
}

void Manager::Export_To_File(std::string file_path)
{
	std::ofstream file_handler(file_path, std::ios::out | std::ios::binary);
	std::uint8_t temp_byte;

	if (!file_handler)
	{
		throw std::exception("Failed to open file");
	}
	
	for (auto room_itr : (*this->m_Booked_Rooms))
	{
		file_handler.write((char*)&room_itr.first, sizeof(room_itr.first));
		file_handler.write((char*)&room_itr.second.Days_Booked, sizeof(Room_Information::Days_Booked));

		temp_byte = room_itr.second.Customer_Name.length() + 1;
		file_handler.write((char*)&temp_byte, sizeof(temp_byte));
		file_handler.write((char*)room_itr.second.Customer_Name.c_str(), temp_byte);

		temp_byte = room_itr.second.Booked_by.length() + 1;
		file_handler.write((char*)&temp_byte, sizeof(temp_byte));
		file_handler.write((char*)room_itr.second.Booked_by.c_str(), temp_byte);

	}

	file_handler.close();
	if (!file_handler.good())
	{
		throw std::exception("Failed to close the file");
	}
}

void Manager::Import_From_File(std::string file_path)
{
	std::ifstream file_handler(file_path, std::ios::in | std::ios::binary);
	std::uint8_t temp_byte;
	
	Room_Information temp_room;
	short room_number;
	
	char buffer[UCHAR_MAX];
	uint8_t string_length;
	
	if (!file_handler)
	{
		throw std::exception("Failed to open file");
	}

	// prime start
	file_handler.read((char*)&room_number, sizeof(room_number));
	while (!file_handler.eof())
	{
		file_handler.read((char*)&temp_room.Days_Booked, sizeof(temp_room.Days_Booked)); // getting room days booked
		
		// getting customer name
		file_handler.read((char*)&string_length, sizeof(string_length));
		file_handler.read(buffer, string_length);
		temp_room.Customer_Name = buffer;

		// getting booked by name
		file_handler.read((char*)&string_length, sizeof(string_length));
		file_handler.read(buffer, string_length);
		temp_room.Booked_by = buffer;

		// adding the room that has been created to the map
		this->m_Booked_Rooms->insert(std::pair<short, Room_Information>(room_number, temp_room));

		// getting the new room number or EOF
		file_handler.read((char*)&room_number, sizeof(room_number)); 
	}
}

std::string Room_Information::to_string() const
{
	std::string output = "";
	output += "Customer name:\t\t" + this->Customer_Name + "\n";
	output += "Booked for:\t\t" + std::to_string(this->Days_Booked) + " Days" + "\n";
	output += "Booked By:\t\t" + this->Booked_by + "\n";
	return output;
}
