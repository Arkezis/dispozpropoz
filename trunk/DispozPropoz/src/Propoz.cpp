/*
 * Propoz.cpp
 *
 *  Created on: 15 oct. 2011
 *      Author: cilheo
 */

#include "Propoz.h"
Propoz::Propoz() {
}

Propoz::~Propoz() {
	// TODO Auto-generated destructor stub
}

void Propoz::construct(IList* aKey, IList* aValue){
	int i=0;

	while (i<aKey->GetCount()){
		String* key = ((String*)aKey->GetAt(i));
		String* value = ((String*)aValue->GetAt(i));

		if (key->CompareTo("id") == 0) Integer::Decode(value->GetPointer(),this->id);
		else if (key->CompareTo("x") == 0) Double::Parse(value->GetPointer(),this->x);
		else if (key->CompareTo("date") == 0) Long::Parse(value->GetPointer(),this->date);
		else if (key->CompareTo("volumes") == 0) this->volumes =String(value->GetPointer());
		else if (key->CompareTo("nombres") == 0) Double::Parse(value->GetPointer(),this->nombres);
		else if (key->CompareTo("y") == 0) Double::Parse(value->GetPointer(),this->y);
		else if (key->CompareTo("domaine") == 0) Integer::Decode(value->GetPointer(),this->domaine);
		else if (key->CompareTo("titre") == 0) this->titre =String(value->GetPointer());
		else if (key->CompareTo("distance") == 0) this->range = String(value->GetPointer());
		i++;
	}
	i = 0;
	this->range.IndexOf('.',0,i);

	this->range.SetLength(i);
	this->range.Append(" m");
}

String Propoz::getCategory(){
	return "fruit";
}

