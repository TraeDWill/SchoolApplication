#include "app.h"
//Trae Williams
//CS202
//4/21/2020
//Implimentation file of my Application hiearchy
using namespace std;

//Constructors
//APP
app::app():username(NULL), password(NULL), logstatus(false), firstlog(true)  
{

}
app::app(char * username, char * password, bool logstatus, bool firstlog)
{

}
app::~app()
{

}

app::app(const app & stuff)
{
	username = new char[strlen(stuff.username) + 1];
	strcpy(username, stuff.username);

	password = new char[strlen(stuff.password) + 1];
	strcpy(password, stuff.password);
}

//PROFILE
profile::profile()
{

	name = NULL;
	phone = NULL;
	address = NULL;
}

profile::profile(const profile & obj)
{
	name = new char[strlen(obj.name) + 1];
	strcpy(name, obj.name);

	phone = new char[strlen(obj.phone) + 1];
	strcpy(phone, obj.phone);

	address = new char[strlen(obj.address) + 1];
	strcpy(address, obj.address);
}

profile::~profile()
{
	
}

//GRADE

grade::grade()
{

	p_total = 0;
	p_earned = 0;
	letter = 0;
	percentage = 0.0;
}
grade::grade(char * username, char * password, bool logstatus, bool firstlog):app(username, password, logstatus, firstlog)
{

}

grade::~grade()
{

}

//Application Class Functions

//APP Functions
int app::logcheck()
{
	int check;
	if(firstlog == true)
		check = 1;		
	else if(firstlog == false && logstatus == false)
		check = 2;
	else
		check = 3;
	return check;

}
bool app::firstlogin()
{
	char * user = new char[SIZE];
	char * pass = new char[SIZE];
	bool confirm;

	cout << "Welcome to the Imaginethisisreal University online platform!" << endl;
	cout << "\n" << "Since this is your first time logging on we will now create your username and password!" << endl;
	cout << "\n" << "What will be your username?" << endl;

	cin.get(user, SIZE, '\n');
	cin.ignore(1234, '\n');

	cout << "You've chosen the username: " << user << endl;
	cout << "\n" << "Now lets choose your password! What will your password be?" << endl;	

	cin.get(pass, SIZE, '\n');
	cin.ignore(1234, '\n');

	cout << "You've chose the password: " << pass << endl;
	cout << "Congraulations on your first login and welcome to Imaginethisisreal University!" << endl;

	confirm = firstlogin(user, username, pass, password); 
	
	delete user;
	delete pass;

	return confirm;
}

bool app::firstlogin(char * user, char *& username, char * pass, char *& password)
{

	username = new char[strlen(user) + 1];
	strcpy(username, user);

	password = new char[strlen(pass) + 1];
	strcpy(password, pass);
	
	logstatus = true;
	firstlog = false;

	return logstatus;
}

bool app::login()
{
	char * user = new char[SIZE];
	char * pass = new char[SIZE];
	bool log;
	do
	{
		cout <<"What is your username?" << endl;
		cin.get(user, SIZE, '\n');
		cin.ignore(1234, '\n');

		cout <<"What is your password?" << endl;
		cin.get(pass, SIZE, '\n');
		cin.ignore(1234, '\n');

		if(strcmp(user, username) == 0 && strcmp(pass, password) == 0)
			log = login(logstatus);
		else
		{	
			log = false;
			user[0] = '\0';
			pass[0] = '\0';
		}
	}
	while(log == false);

	delete user;
	delete pass;

	cout << "Welcome to the Imaginethisisreal University online platform once more" << endl;

	return log;
}

bool app::login(bool & logstatus)
{
	logstatus = true;
	return logstatus;
}

bool app::logout()
{
	return logout(logstatus);
}

bool app::logout(bool & logstatus)
{
	logstatus = false;
	return logstatus;
}

int app::change()
{
	char * user = new char[SIZE];
	char * pass = new char[SIZE];

	cout << "What will be your new username?" << endl;

	cin.get(user, SIZE , '\n');
	cin.ignore(1234, '\n');

	cout << "What will be your new password?" << endl;
	cin.get(pass, SIZE, '\n');
	cin.ignore(1234, '\n');
	
	change(user,username,pass,password);
	
	delete user;
	delete pass;
	return 0;
}

int app::change(char * user, char *& username, char * pass, char *& password)
{
	if(username)
		delete username;
	if(password)	
		delete password;
	username = new char[strlen(user) + 1];
	strcpy(username, user);
	cout << "Your new username is: " << username << endl;

	password = new char[strlen(pass) + 1];
	strcpy(password, pass);
	cout << "Your new password is: " <<  password << endl;

	return 0;
	
}

int app::mainmenu()
{
	int choice = 0;
	do
	{
		cout << "Welcome to the main menu. Would you like to:" << endl;
		cout << "1. Change username/password" << endl;
		cout << "2. Go to profile" << endl;
		cout << "3. Go to grades" << endl;
		cout << "4. Go to email" << endl;
		cout << "5. Logout" << endl;
		cout << "6. Exit Program" << endl;

		cin >> choice;
		cin.ignore(1234, '\n');

		if(choice < 0 || choice > 6)
			cout << "Invalid choice, please select again" << endl;

	}
	while(choice < 0 || choice > 6 );

	return choice;
}

int app::p_menu()
{

	return info.profilemenu();

}

//Profile Class Functions
int profile::profilemenu()
{
	int choice = 0;
	
	do
	{
		cout << "Would like like to: " << "\n" << endl;
		cout << "1.Display" << endl;
		cout << "2.Change info" << endl;
		cout << "3.Exit" << endl;

		cin >> choice;
		cin.ignore(1234,'\n');

		if(choice == 1)
		{
			if(!name)
			{
				changeinfo();
				display();
			}
			else
			{
				display();
			}
		}
		else if(choice == 2)
			changeinfo();
		else
			choice = 3;	
	}
	while(choice >= 1  && choice <= 2);
	return choice;
}

int profile::display() const
{
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Phone Number: " << phone << endl;
	return 0;
}

int profile::copy(char * original, char *& copied)
{
	if(copied)
		delete copied;
	copied = new char[strlen(original) + 1];
	strcpy(copied, original);

	return 0;
}

int profile::changeinfo()
{
	char * Name = new char[SIZE];
	char * Address = new char[SIZE];
	char * Phone = new char[SIZE];

	cout << "What is your preferred name?" << endl;
	cin.get(Name, SIZE, '\n');
	cin.ignore(1234, '\n');

	cout << "What is your address?" << endl;
	cin.get(Address, SIZE, '\n');
	cin.ignore(1234, '\n');

	cout << "What is your phone number?" << endl;
	cin.get(Phone, SIZE, '\n');
	cin.ignore(1234, '\n');

	copy(Name, name);
	copy(Address, address);
	copy(Phone, phone);

	return 0;
}
//Grade Class Functions


int grade::displayLP()
{
	cout << "Your grade in this class is: " << letter << endl;
	cout << "The percentage of points you've earned is: " << percentage << endl;
	return 0;
}

int grade::displayFB()
{
	cout << "This is the feedback your teacher has left you: " << endl;
	if(letter == 'A')
		cout << "You are doing fantastic!" << endl;
	else if(letter == 'B')
		cout << "You are doing very well!" << endl;
	else if(letter == 'C')
		cout << "At least your passing" << endl;
	else if(letter == 'D')
		cout << "You only sort of suck, but aren't too far gone... I think?" << endl;
	else if(letter == 'F')
		cout << "F for failure. Description or grade? Who knows." << endl;
	if(letter == 'F' && percentage < 25.0)
		cout << "At this point if your deciding between, screw it, and maybe you'll have a comeback. I suggest the former." << endl;
	return 0;

}

int grade::input()
{
	float worth;
	float earn;
	do
	{
		cout << "What was the assignment worth, points wise?" << endl;
		cin >> worth;
	
		cout << "How many points did you earn?" << endl;
		cin >> earn;

		if(earn/worth > 1 || earn/worth < 0)
			cout << "Incorrect amount of points, please input again" << endl;
	}
	while(earn/worth > 1 ||  earn/worth < 0);
	
	input(worth, earn, percentage, letter, p_total, p_earned);

	return 0;
}

int grade::input(float worth, float earn, float & percentage, char & letter, float & p_total, float & p_earned)
{	
	p_total += worth;

	p_earned += earn;

	percentage = earn/worth * 100; 
	
	if(percentage <= 100.0 && percentage > 89.9)
		letter = 'A';
	else if(percentage < 90.0 && percentage >= 80.0)
		letter = 'B';
	else if(percentage < 80.0 && percentage >= 70)
		letter = 'C';
	else if(percentage < 70 && percentage >= 60)
		letter = 'D';
	else
		letter = 'F';

	return 0;
}

int grade::menu()
{
	int choice = 0;
	do
	{

		cout << "Welcome to the grades menu. Your choices are:" << endl;
		cout << "1.Input grade" << endl;
		cout << "2.Display letter grade and percentage" << endl;
		cout << "3.Display teacher feedback" << endl;
		cout << "4.Forecast grade change" << endl;	
		cout << "5.Return to main menu" << endl;
		
		cin >> choice;
		cin.ignore(1234, '\n');

		if(choice == 1)
			input();
		else if(choice == 2)
			displayLP();
		else if(choice == 3)
			displayFB();
	}
	while(choice > 0 && choice < 4);

	return choice;
}

float grade::calculate(float percent)
{
	float diff = 0;
	     
	diff = (p_total * percent);

	cout << "Point difference: " << diff << endl;
	
	diff -= p_earned;

	return diff;
}

float grade::forecast(char & choice)
{
	float diff;
	float need;
	displayLP();

	cout << "What letter grade would you like?" << endl;
	cin >> choice;
	cin.ignore(1234,'\n');

	choice = toupper(choice);
	cout << choice << endl;	
	if(choice == 'A')
	{
		diff = .9;
		need = calculate(diff);
		cout << "You need: " << need << " points" << endl;	
	}
	else if(choice == 'B')
	{
		diff = .8;
		need = calculate(diff);
		cout << "You need: " << need << " points" << endl;	
	}
	else if(choice == 'C')
	{
		diff = .7;
		need = calculate(diff);
		cout << "You need: " << need << " points" << endl;	
	}
	else if(choice == 'D')
	{
		diff = .6;
		need = calculate(diff);
		cout << "You need: " << need << " points" << endl;	
	}
	else if(choice == 'F')
	{
		diff = .5;
		need = calculate(diff);
		cout << "You need: " << need << " points" << endl;	
	}
	else
		cout << "You've chosen incorrectly" << endl;
	return need;
}

