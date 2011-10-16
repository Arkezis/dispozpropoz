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


class Propoz :
	public Object
	{
public:
	Propoz();
	virtual ~Propoz();


	void construct(IList* aKey, IList* aValue);


	int id;
	double x;
	long date;
	String volumes;
	double nombres;
	double y;
	int domaine;
	String titre;

	String range;

	String getCategory();
};

#endif /* PROPOZ_H_ */
