/*
 * User.cpp
 *
 *  Created on: 15 Oct 2011
 *      Author: vj
 *  svj: added empty shell functions
 */

#include "User.h"

User::User() {
	// TODO Auto-generated constructor stub

}

User::~User() {
	// TODO Auto-generated destructor stub
}

User User::GetUser(Integer id) {

	AppLog("Not implemented yet!");
	//return NULL;
}

//static method
//Create profile information.  Return false if there is an error.
User User::CreateUser(String name, String phoneNumber, bool showPhoneNumber,
		String email, bool showEmail,
		QualifiedCoordinates coordinates){

	User u =  User();

	u.name = name;
	u.phoneNumber = phoneNumber;
	u.showPhoneNumber = showPhoneNumber;
	u.email = email;
	u.showEmail = showEmail;
	u.defaultCoordinates = coordinates;
	return u;
}

bool User::save(){
	return false;
}

bool User::UpdateUser(String name, String phoneNumber, bool showPhoneNumber,
			String email, bool showEmail,
			QualifiedCoordinates coordinates){

	this->name = name;
	this->phoneNumber = phoneNumber;
	this->showPhoneNumber = showPhoneNumber;
	this->email = email;
	this->showEmail = showEmail;
	this->defaultCoordinates = coordinates;
}
