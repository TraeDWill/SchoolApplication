#include "email.h"
#include "app.h"

using namespace std;

//Trae Williams
//CS202
//4/17/2020
//Main application file

int main()
{
	//Variables and objects

	float diff;
	char send;
	char letter;
	int stuff = 0;
	int check = 0;
	int choice = 0;
	app base;
	inbox mail;
	grade anxiety;
	
	mail.build();
	
	//Login
	do
	{
		check = base.logcheck();
		if(check == 1)
			base.firstlogin();
		else if(check == 2)
			base.login();
	}
	while(check == 0);

	//Main Menu	
	do
	{	
		//Login	
		
		check = base.logcheck();

		if(check == 2)
			base.login();
		
		//Main menu
		choice = base.mainmenu();
		
		//Change User/Pass
		if(choice == 1)
		{
			base.change();	
		}
		//Profile Menu
		else if(choice == 2)
		{
			base.p_menu();	
		}
		//Grades Menu
		else if(choice == 3)
		{
			do
			{
				stuff = anxiety.menu();
				//Interaction between grades and email
				if(stuff == 4)
				{	
					diff = anxiety.forecast(letter);
					
					cout << "Would you like to send this to your inbox? Y for yes and N for no" << endl;

					cin >> send;
					cin.ignore(1234, '\n');

					send = toupper(send);

					if(send == 'Y')
						mail.retrieve(diff, letter);
					else
						cout << "We will now return to the grades menu" << endl;
				}
			}
			while(stuff > 0 && stuff < 5);
		}
		//Email menu
		else if(choice == 4)
		{
			mail.menu();
		}
		//Logout
		else if(choice == 5)
		{
			base.logout();	
		}
		//Exit program
		else if(choice == 6)
			cout << "Have a nice day!" << endl;
	}
	while(choice > 0 && choice < 6);	



}
