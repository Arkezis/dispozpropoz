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

public:
	//Update item information.  Return false if there is an error.
	bool UpdateItem(Integer id, String title, String description,
			QualifiedCoordinates coordinates, Integer proposerId);

	//Create item information.  Return false if there is an error.
	static Item CreateItem(String title, String description,
			QualifiedCoordinates coordinates, Integer proposerId);

	//Load the item information corresponding to this id.
	static Item GetItem(Integer id);

	//Delete the item information corresponding to this id.
	static bool DeleteItem(Integer id);

//private:
//svj: decided to make this public for now to avoid getters/setters
public:
	String title;
	String description;
	QualifiedCoordinates location;
	Integer id;
	Integer proposerId;
};

#endif /* ITEM_H_ */
