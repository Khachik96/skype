#include<iostream>
#include<string>
#include"Person.h"

int main()
{
	//User user("Gegam", "Khachatryan", "gegam_99@bk.ru", "077350430");
	
	User use("gegam_99@bk.ru", "077350430");
	User user;
	std::cout<<user.search("khachik_96@bk.ru")<<std::endl;
	system("pause");
}