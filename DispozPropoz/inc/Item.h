/*
 * Item.h
 *
 *  Created on: 15 Oct 2011
 *      Author: vj
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <FBase.h>
#include <FLocQualifiedCoordinates.h>

using namespace Osp::Base;
using namespace Osp::Locations;

class Item {
public:
	Item();
	virtual ~Item();

private:
	String title;
	String description;
	QualifiedCoordinates location;
	Integer id;
};

#endif /* ITEM_H_ */
