#include <iostream>
#include <cctype>
#include <cstring>

//Trae Williams
//CS202
//4/21/2020
//Declaration file for email hiearchy

int const AMT = 5;
int const LENGTH = 100;

class email
{
	public:
	//Constructors
	email();
	~email();
	email(char * title, char * contents, char * reciever, char * signature, bool star);
	email(const email & obj);
	
	//Functions/Wrappers
	int compose();
	int create_signature();
	int copy(char * original, char *& copied);	
	int display() const;
	int compare(char * search);
	int remove();
	int retrieve(char letter, float diff);
	protected:

	//Recursive Functions
	
	//Data Members/private access functions
	int retrieve(char *& title, char & L_grade, float & P_diff, char letter, float diff);
	char * title;
	char * contents;
	char * reciever;
	char * signature;
	char L_grade;
	float P_diff;
	bool star;

	private:
};

class node:public email
{
	public:
	//Constructors
	node();
	node(char * title, char * contents, char * reciever, char * signature, bool star);
	node(const node & obj);
	~node();

	//Functions
	node * go_next();
	int set_next(node * temp);
	protected:

	private:
	//Next pointer and private access
	node * next;
	int set_next(node * temp, node *& next);
};

class inbox 
{
	public:
	//Constructors
	inbox();
	inbox(const inbox & obj);
	~inbox();
	
	//Functions	
	int remove();
	int remove_all();
	int insert();
	int display_all() const;
	int compare(char * search, node * temp);
	int build();		
	int capacity();
	int menu();
	int retrieve(char letter, float diff);
	node * find_end(node *& place);
	protected:
		
	private:
	//Private member changes.
	int insert(node *& head, node *& next);
	int capacity(node * head);
	int build(node **& head);
	int display_all(node * head) const;
	int remove_all(node *& head);
	int remove(char * title, node *& head);

	//Data members
	node ** head;
	int page;
	int lng;
};




