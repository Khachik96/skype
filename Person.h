#include<iostream>
#include<fstream>
#include<string>
#include<regex>

class User
{
	private:
	std::string m_name;
	std::string m_lastname;
	std::string m_email;
	std::string m_password;
	
	std::string m_city;
	std::string m_phone;
	std::string m_male_female;
	int m_day, m_month, m_year;
	
public:
	User();
	User(std::string, std::string, std::string, std::string /*,std::string,std::string,std::string*/);
	User(int, int, int);
	User(std::string, std::string);

private:
	std::string m_login;
	std::string ml_password;

	bool reviwname(std::string);
	bool reviwlastname(std::string);
	bool reviwemail(std::string);
	bool reviwpassword(std::string);
	bool recurrent_email(std::string);

	void outputfile_name(void)const;
	void outputfile_lastname(void)const;
	void outputfile_email(void)const;
	void outputfile_password(void)const;

	bool login_name(std::string);
	bool login_password(std::string);
	
	void print_name_lastname(void);
};