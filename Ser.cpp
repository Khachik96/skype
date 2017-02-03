#include"Server.h"
int count = 0;
std::ofstream filename("name.txt", std::ios_base::app);
std::ofstream filelastname("lastname.txt", std::ios_base::app);
std::ofstream filemail("email.txt", std::ios_base::app);
std::ofstream filepassword("password.txt", std::ios_base::app);
std::ofstream friends("friend.txt", std::ios_base::app);

std::ifstream o_filename("name.txt");
std::ifstream o_filelastname("lastname.txt");
std::ifstream o_filemail("email.txt");
std::ifstream o_filepassword("password.txt");
std::ifstream o_friend("friend.txt");


void Server::outputfile_name(void)const
{
	filename << m_name << "\n";
}
void Server::outputfile_lastname(void)const
{
	filelastname << m_lastname << "\n";
}
void Server::outputfile_email(void)const
{
	filemail << m_email << "\n";
}
void Server::outputfile_password(void)const
{
	filepassword << m_password << "\n";
}

bool Server::recurrent_email(std::string r_email)
{
	std::string temp;
	bool a = false;
	while (std::getline(o_filemail, temp))
	{
		if (r_email == temp)
		{
			a = true;
		}
	}
	return a;
}

bool Server::login_name(std::string l_email) const 
{
	std::string temp;
	bool a = false;
	while (std::getline(o_filemail, temp))
	{
		count++;
		if (l_email == temp)
		{
			a = true;
			break;
		}
	}
	return a;
}
bool Server::login_password(std::string l_password)const
{
	int count1 = 0;
	std::string temp;
	bool a = false;
	while (std::getline(o_filepassword, temp))
	{
		count1++;
		if (count == count1)
		{
			if (l_password == temp)
			{
				a = true;
			}
			else
			{
				std::cout << "invalid Password:\n";
			}
		}
	}
	return a;
}

void Server::print_name_lastname()
{
	int count1 = 0;
	std::string temp, temp1;
	bool a = false;
	while (std::getline(o_filename, temp) && std::getline(o_filelastname, temp1))
	{
		count1++;
		if (count1 == count)
		{
			std::cout << "Hello! " << temp << "  " << temp1 << std::endl;
			break;
		}
	}
}

Server::Server(std::string email, std::string password)
{
	if (login_name(email) && login_password(password))
	{
		std::cout << "Log in:" << std::endl;
		print_name_lastname();
	}
	else
	{
		std::cout << "invalid email or password" << std::endl;
	}
}

