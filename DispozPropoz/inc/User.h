/*
 * User.h
 *
 *  Created on: 15 Oct 2011
 *      Author: vj
 */

#ifndef USER_H_
#define USER_H_

#include <FBase.h>
#include <FLocQualifiedCoordinates.h>

using namespace Osp::Base;
using namespace Osp::Locations;

class User {
public:
	User();
	virtual ~User();

private:
	String name;
	String phoneNumber;
	bool showPhoneNumber;
	String email;
	bool showEmail;
	QualifiedCoordinates defaultCoordinates;
};

#endif /* USER_H_ */
