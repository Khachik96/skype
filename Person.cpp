#include"Person.h"
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

User::User()
	:m_name("name")
	, m_lastname("firstname")
	, m_password("password")
	, m_email("email")
	, m_city("Armenia")
	, m_phone("000000")
	,m_male_female("male")
	,m_day(00)
	,m_month(00)
	,m_year(1996)
{}
User::User(std::string name, std::string lastname,  std::string email, std::string password /*, std::string city,std::string phone,std::string male_female*/)
{
	if (!recurrent_email(email))
	{
		if (reviwname(name) && reviwlastname(lastname) && reviwemail(email) && reviwpassword(password))
		{
			m_name = name;
			m_lastname = lastname;
			m_email = email;
			m_password = password;
			outputfile_name();
			outputfile_lastname();
			outputfile_email();
			outputfile_password();
		}
		else
		{
			std::cout << "Sxalaaaa" << std::endl;
		}
	}
	else
	{
		std::cout << "such address exists" << std::endl;
	}
}
User::User(std::string email, std::string password)
{
	if (login_name(email) && login_password(password))
	{
		std::cout << "Log in:"<<std::endl;
		print_name_lastname();
	}
	else
	{
		std::cout << "invalid email or password" << std::endl;
	}
}

User::User(int day,int month,int year)
{
	m_day = day;
	m_month = month;
	m_year = year;
}

bool User::reviwname(std::string r_name)
{
	bool a = false;
	std::regex regular("[a-zA-Z]{4,}");
	if (std::regex_match(r_name,regular))
	{
		a = true;
		std::cout << "Name: ok" << std::endl;
	}
	else
	{
		std::cout << "Name: error " << std::endl;
	}
	
		
	return a;
}
bool User::reviwlastname(std::string r_lastname)
{
	bool a = false;
	std::regex regular("([a-zA-Z]{4,})");
	if (std::regex_match(r_lastname, regular))
	{
		a = true;
		std::cout << "Lastname: ok" << std::endl;
	}
	else
	{
		std::cout << "Lastname: error " << std::endl;
	}
	return a;
}
bool User::reviwemail(std::string r_email)
{
	bool a = false;
	std::regex regular("(\\w+)(\\|._)?(\\w*)@(\\w+(\\.)(\\w+))+");
	if (std::regex_match(r_email, regular))
	{
		a = true;
		std::cout << "Email: ok" << std::endl;
	}
	else
	{
		std::cout << "Email: error " << std::endl;
	}
	return a;
}
bool User::reviwpassword(std::string r_password)
{
	bool a = false;
	if ((r_password.size())>=6)
	{
		a = true;
		std::cout << "Password: ok" << std::endl;
	}
	else
	{
		std::cout << "Password: error " << std::endl;
	}
	return a;
}

void User::outputfile_name(void)const
{
	filename << m_name<<"\n";
}
void User::outputfile_lastname(void)const
{
	filelastname <<m_lastname<<"\n";
}
void User::outputfile_email(void)const
{
	filemail <<m_email<<"\n";
}
void User::outputfile_password(void)const
{
	filepassword << m_password<<"\n";
}

bool User::login_name(std::string l_email)
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
bool User::login_password(std::string l_password)
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

bool User::recurrent_email(std::string r_email)
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

void User::print_name_lastname()
{
	int count1 = 0;
	std::string temp,temp1;
	bool a = false;
	while (std::getline(o_filename, temp) && std::getline(o_filelastname,temp1))
	{
		count1++;
		if (count1==count)
		{
			std::cout << "Hello! " << temp << "  " << temp1 << std::endl;
			break;
		}
	}
}

/*bool User::search(std::string email)
{
	bool a = false;
	if (reviwemail(email))
	{
		std::string temp;
		while (std::getline(o_filemail, temp))
		{
			if (email == temp)
			{
				a = true;
				break;
			}
		}
	}
	return a;
}*/
