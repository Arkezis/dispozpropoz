/*
 * Transaction.cpp
 *
 *  Created on: 15 Oct 2011
 *      Author: vj
 */

#include "Transaction.h"

Transaction::Transaction() {
	// TODO Auto-generated constructor stub

}

Transaction::~Transaction() {
	// TODO Auto-generated destructor stub
}

//Create transaction information.  Return false if there is an error.
Transaction Transaction::CreateTransaction(Integer itemId, Integer proposerId, Integer borrowerId,
		String comment, Integer rating) {
	AppLog("Not implemented yet!");
}

//Load the transaction information corresponding to this id.
Transaction Transaction::GetTransaction(Integer id) {
	AppLog("Not implemented yet!");
}
