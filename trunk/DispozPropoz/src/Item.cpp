/*
 * Item.cpp
 *
 *  Created on: 15 Oct 2011
 *      Author: vj
 */

#include "Item.h"

Item::Item() {
	// TODO Auto-generated constructor stub

}

Item::~Item() {
	// TODO Auto-generated destructor stub
}

bool Item::UpdateItem(Integer id, String title, String description,
		QualifiedCoordinates coordinates, Integer proposerId){
	AppLog("Not implemented yet!");
	return false;
}

Item Item::CreateItem(String title, String description,
		QualifiedCoordinates coordinates, Integer proposerId){
	AppLog("Not implemented yet!");
}

Item Item::GetItem(Integer id){
	AppLog("Not implemented yet!");
}

bool Item::DeleteItem(Integer id){
	AppLog("Not implemented yet!");
	return false;
}
