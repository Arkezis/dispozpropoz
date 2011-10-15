/*
 * Propoz.h
 *
 *  Created on: 15 oct. 2011
 *      Author: cilheo
 */

#ifndef PROPOZ_H_
#define PROPOZ_H_
#include <FBase.h>
using namespace Osp::Base;
using namespace Osp::Base::Collection;


class Propoz {
public:
	Propoz();
	virtual ~Propoz();


	Propoz(ArrayList* aKey, IList* aValue);


	int id;
	double x;
	long date;
	String* autre;
	double y;
	int domaine;
	String* titre;
};

#endif /* PROPOZ_H_ */
