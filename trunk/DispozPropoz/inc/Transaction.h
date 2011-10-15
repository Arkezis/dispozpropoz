/*
 * Transaction.h
 *
 *  Created on: 15 Oct 2011
 *      Author: vj
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <FBase.h>

using namespace Osp::Base;

class Transaction {
public:
	Transaction();
	virtual ~Transaction();

public:
	//Create transaction information.  Return false if there is an error.
	static Transaction CreateTransaction(Integer itemId, Integer proposerId, Integer borrowerId,
			String comment, Integer rating);

	//Load the transaction information corresponding to this id.
	static Transaction GetTransaction(Integer id);

//private:
//svj: decided to make this public for now to avoid getters/setters
public:
	Integer itemId;
	Integer proposerId;
	Integer borrowerId;
	String comment;
	Integer rating;
	Integer id;
};

#endif /* TRANSACTION_H_ */
