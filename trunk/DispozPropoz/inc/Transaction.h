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

private:
	Integer itemId;
	Integer proposerId;
	Integer borrowerId;
	String comment;
	Integer rating;
	Integer id;
};

#endif /* TRANSACTION_H_ */
