#include "email.h"
//Trae Williams
//CS202
//4/21/2020
//Email hiearchy Implimentation files

using namespace std;

//Email Class constructors
email::email()
{
	title = NULL;
	contents = NULL;
	reciever = NULL;
	signature = NULL;
	star = false;
	L_grade = '\0';
	P_diff = 0;
}

email::email(char * title, char * contents, char * reciever, char * signature, bool star)
{
	
}

email::email(const email & obj)
{
	if(obj.title)
	{
		title = new char[strlen(obj.title + 1)];
		strcpy(title, obj.title);
	}
	else
	{
		title = NULL;
	}
	if(obj.contents)
	{
		contents = new char[strlen(obj.contents + 1)];
		strcpy(contents, obj.contents);
	}
	else
	{
		contents = NULL;
	}
	if(obj.reciever)
	{
		reciever = new char[strlen(obj.reciever + 1)];
		strcpy(reciever, obj.reciever);
	}
	else
	{
		reciever = NULL;
	}
	if(obj.signature)
	{
		signature = new char[strlen(obj.signature + 1)];
		strcpy(signature, obj.signature);
	}
	else
	{
		signature = NULL;
	}

}

email::~email()
{

}

//Node class constructors
node::node()
{
	next = NULL;
}

node::~node()
{

}

node::node(const node & obj)
{
		
		
}
node::node(char * title, char * contents, char * reciever, char * signature, bool Star):email(title, contents, reciever, signature, star)
{
	
}

//INBOX

inbox::inbox()
{
	head = NULL;	
	page = 0;
	lng = 0;
}

inbox::inbox(const inbox & obj)
{
	
	head = new node *[AMT];
	int num = 0;
	
	while(num < AMT && obj.head[num])
	{	
		while(obj.head[num])
		{
			head[num] = new node;
			head[num] = obj.head[num];
			obj.head[num] = obj.head[num]->go_next();
			head[num] = head[num]->go_next();

		}

		++num;

	}

					
	
}

inbox::~inbox()
{

}

//Functions
int email::display() const
{
	cout << "Title: " << title << endl;
	if(contents)
		cout << "Email body: " << contents << endl;
	if(reciever)
		cout << "The person who sent this email is: " << reciever << endl;	
	if(signature)	
		cout << "The signature is: " << signature << endl;
	if(L_grade != '\0')
		cout << L_grade << endl;
	if(P_diff != 0)
		cout << P_diff << endl;
	
	return 0;
}

int email::copy(char * original, char *& copied)
{
	if(copied)
		delete copied;
	copied = new char[strlen(original) + 1];
	strcpy(copied, original);

	return 0;
}

int email::compose()
{
	char * stuff = new char[LENGTH];

	cout << "What would you like your title to be?" << endl;
	cin.get(stuff, LENGTH,'\n');
	cin.ignore(1234, '\n');
	
	copy(stuff, title);

	stuff[0] = '\0';

	cout << "What would you like the email body to say?" << endl;
	cin.get(stuff, LENGTH, '\n');
	cin.ignore(1234, '\n');

	copy(stuff, contents);

	stuff[0] = '\0';

	cout << "Who would you like to have sent this email?" << endl;
	cin.get(stuff, LENGTH, '\n');
	cin.ignore(1234, '\n');

	copy(stuff, reciever);

	stuff[0] = '\0';

	

	delete stuff;

	return 0;
}

int email::create_signature() 
{
	char * stuff = new char[LENGTH];

	cout << "What would you like the signature to be" << endl;
	cin.get(stuff, LENGTH, '\n');
	cin.ignore(1234, '\n');

	copy(stuff, signature);

	delete stuff;

	return 0;
}

int email::compare(char * search)
{
	int check;
	if(strcmp(search, title) == 0)
		check = 0;	
	else
		check = 1;
	return check;
}

int email::remove()
{
	if(title)
	{
		delete title;
		title = NULL;
	}
	if(contents)
	{
		delete contents;
		contents = NULL;
	}
	if(reciever)
	{
		delete reciever;
		reciever = NULL;
	}
	if(signature)
	{
		delete signature;
		signature = NULL;
	}
	

	return 0;
}

int email::retrieve(char letter, float diff)
{
	retrieve(title, L_grade, P_diff, letter, diff);

	return 0;
}

int email::retrieve(char *& title, char & L_grade, float & P_diff, char letter, float diff)
{
	cout << "What would you like the title to be?" << endl;
	if(!title)
	{
		title = new char[LENGTH];
	}
	cin.get(title, LENGTH, '\n');
	cin.ignore(1234, '\n');

	L_grade = letter;

	P_diff = diff;

	return 0;
}
  
//NODE


node * node::go_next()
{
	return next;
}

int node::set_next(node * temp)
{
	set_next(temp, next);
	return 0;
}

int node::set_next(node * temp, node *& next)
{
	next = temp;
	return 0;	
}

//INBOX

int inbox::build()
{
	return build(head);	
}

int inbox::build(node **& head)
{
	head = new node * [AMT];
	return 0;
}

int inbox::compare(char * search, node * temp)
{
	int check = temp->compare(search);	
	return check;
}

int inbox::capacity() 
{
	int count = 0;

	if(page != 1)
	{
		count = page * 5;
		count += capacity(head[page]);
	}
	else if(page == 1 && !head[page])
	{
		count = 0;
	}
	else if(page == 1)
	{
		count += capacity(head[page]);
	}
	cout << count << endl;	
	return count;
}

int inbox::capacity(node * head)
{	
	node * temp;
	if(!head)
		return 0;
	temp = head->go_next();
	return 1 + capacity(temp);
}
int inbox::remove()
{
	int origin = capacity();
	int after = 0;
	char * stuff = new char[LENGTH];

	cout << "What is the name of the email you'd like to remove?" << endl;
	cin.get(stuff, LENGTH, '\n');
	cin.ignore(1234, '\n');

	char * search = new char[strlen(stuff) + 1];
	strcpy(search, stuff);
	
	for(int i = 0; i < AMT; ++i)
	{
		if(head[i])	
		{
			remove(search, head[i]); 
		}
		else
			i = 10;
	}	
	after = capacity();

	delete search;
	delete stuff;

	if(origin > after )
		cout << "Removed." << endl;
	else
		cout << "Unable to find" << endl;
	return 0;
}

int inbox::remove(char * search, node *& head)
{
	node * temp;

	if(!head)
	{
		return 0;
	}
	temp = head->go_next();
	remove(search, temp);

	if(head->compare(search) == 0)
	{
		temp = head->go_next();
		delete head;
		head = temp;
	}

	return 0;
}

int inbox::remove_all()
{
	for(int i = page; i >= 0; --i)
	{
		remove_all(head[i]);
		delete head[i];	
		head[i] = NULL;
		--page;
	}
	page = 0;
	lng = 0;
	
	return 0;

}

int inbox::remove_all(node *& head)
{
	if(!head)
		return 0;
	node * temp = head->go_next();
	remove_all(temp);

	delete head;
	head->remove();

	head = NULL;

	return 0;
}

int inbox::display_all() const
{
	node * temp = NULL;
	if(head[0])
	{
		for(int i = 0; i < AMT; ++i)
		{
			if(head[i])
			{
				temp = head[i];
				cout << "Page: " << i+1 << endl;
				display_all(temp);	
				temp = NULL;
			}
			else
			{
				i=10;
			}
		}
		
	}
	else
		cout << "Inbox is empty" << endl;
	return 0;
}

int inbox::display_all(node * head) const
{
	if(!head)
		return 0;

	head->display();
	display_all(head->go_next());
	return 0;
}

int inbox::insert()
{
	node * temp = NULL;
	node * next = NULL;
	if(lng == AMT && page == AMT)
	{
		cout << "Inbox is full" << endl;
	}
	else if(lng == AMT)
	{
		++page;
		lng = 1;
		head[page] = new node;
		next = head[page]->go_next();
		insert(head[page], next);
	}
	else if(!head[page])
	{
		++lng;
		insert(head[page], next);
	}
	else
	{
		++lng;
		next = head[page]; 
		temp = next->go_next();
		while(temp)
		{
			next = temp;
			temp = next->go_next();
		}
		
		insert(next, temp);	
	}

	return 0;
}

int inbox::insert(node *& head, node *& next)
{
	node * temp;
	if(!head)
	{
		head = new node;
		next = head->go_next();
		next = NULL;	
		head->compose();
	}
	else
	{
		temp = new node;
		head->set_next(temp);
		temp->compose();
	}
	return 0;
}



int inbox::retrieve(char letter, float diff)
{
	node * found;
	if(lng == AMT && page == AMT)
	{
		cout << "The inbox your attempting to send to is full" << endl;
	}
	else
	{
		found = find_end(head[page]);
		
	}

	
	found->retrieve(letter, diff);
	return 0;
}

node * inbox::find_end(node *& place)
{
	node * temp;
	if(!place)
	{
		if(lng == AMT && page < AMT)
		{
			++page;
			lng = 1;
			place = new node;
		}
		else if(lng < AMT)
		{
			place = new node;
			return place;
		}
	}

	return find_end(temp);	

	
}

int inbox::menu()
{
	int choice = 0;
	
	cout << "Welcome to your inbox. Would you like to:" << endl;
	build();
	do
	{

		cout << "1. Display all Emails" << endl;
		cout << "2. Build a draft and save in inbox(Yes this is just my way of saying insert into list)" << endl;
		cout << "3. Remove a certain email" << endl;
		cout << "4. Remove all emails" << endl;
		cout << "5. Exit back to main menu" << endl;

		cin >> choice;
		cin.ignore(1234, '\n');

		if(choice == 1)
			display_all();
		else if(choice == 2)
			insert();
		else if(choice == 3)
			remove();	
		else if(choice == 4)
			remove_all();	
		else
			cout << "Returning to main menu" << endl;
	}
	while(choice > 0 && choice < 5);
	
	return 0;
}
