#include <iostream>
#include <cctype>
#include <cstring>

//Trae Williams
//CS202
//4/21/2020
//Declaration file for Application hiearchy

int const SIZE = 50;

class profile
{
	public:
	//Constructors
	profile();
	~profile();
	profile(const profile & obj);
	
	//Functions
	int profilemenu();
	int changeinfo();
	int display() const;
	int copy(char * original, char *& copied);
	protected:

	private:
	//Recursive or access to private
	char * name;
	char * phone;
	char * address;

};

class app 
{
	public:
	//Constructors	
	app();
	app(char * username, char * password, bool logstatus, bool firstlog);
	~app();
	app(const app & obj);

	//Public Functions
	int logcheck();
	bool login();
	bool logout();
	int mainmenu();
	int change();
	bool firstlogin();

	//Wrappers for Profile
	int p_menu();
		
	protected:

	//Functions
	bool firstlogin(char * user, char *& username, char * pass, char *& password);
	bool login(bool & logstatus);
	bool logout(bool & logstatus);
	int change(char * user, char *& username, char * pass, char *& password);
	
	//Data Members
	char * username;
	char * password;
	bool logstatus;
	bool firstlog;

	//"Has a"
	profile info;
};



class grade:public app
{

	public:
	//Constructors
	grade();
	grade(char * username, char * password, bool logstatus, bool firstlog);
	grade(const grade * obj);
	~grade();
	
	//Functions
	int menu();	
	int displayLP();
	int displayFB();
	int input();
	float forecast(char & letter);
	bool send_forecast();
	float calculate(float percent);
	protected:

	private:
	//Private access/ Data members
	int input(float worth, float earn, float & percentage, char & letter, float & p_total, float & p_earned);
	float p_total;
	float p_earned;
	char letter;
	float percentage;
};
