/*
 * User.h
 *
 *  Created on: 15 Oct 2011
 *      Author: vj
 *  svj: added member variables and empty functions
 */

#ifndef USER_H_
#define USER_H_

#include <FBase.h>
#include <FLocQualifiedCoordinates.h>
#include "Transaction.h"

using namespace Osp::Base;
using namespace Osp::Locations;

class User {
public:
	User();
	virtual ~User();

public:
	//Create profile information.  Return false if there is an error.
	static User CreateUser(String name, String phoneNumber, bool showPhoneNumber,
			String email, bool showEmail,
			QualifiedCoordinates coordinates);

	//Update profile information.  Return false if there is an error.
	bool UpdateUser(String name, String phoneNumber, bool showPhoneNumber,
			String email, bool showEmail,
			QualifiedCoordinates coordinates);

	//Load the user information corresponding to this id.
	//Usage: could be used to load the previous user who logged in on this one.
	//Id information would have to be saved to disk prior to exit.
	static User GetUser(Integer id);

	//Computes the overall rating for this user
	float GetOverallRating();

	//Get all previous transactions of user in reverse chronological order
	//You could pick out the previous comments and ratings for this user from this list
	Transaction* GetAllTransactions();

	Transaction* GetAllProposedTransactions();

	Transaction* GetAllBorrowedTransactions();

//private:
//svj: decided to make this public for now to avoid individual getters and setters.
public:
	String name;
	String phoneNumber;
	bool showPhoneNumber;
	String email;
	bool showEmail;
	QualifiedCoordinates defaultCoordinates;
	Integer id;
};

#endif /* USER_H_ */
