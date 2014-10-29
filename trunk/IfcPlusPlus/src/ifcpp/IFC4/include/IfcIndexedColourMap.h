/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPObject.h"
#include "IfcPresentationItem.h"
class IfcTessellatedFaceSet;
class IfcSurfaceStyleShading;
class IfcColourRgbList;
//ENTITY
class IfcIndexedColourMap : public IfcPresentationItem
{
public:
	IfcIndexedColourMap();
	IfcIndexedColourMap( int id );
	~IfcIndexedColourMap();
	virtual shared_ptr<IfcPPObject> getDeepCopy( IfcPPCopyOptions& options );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void unlinkFromInverseCounterparts();
	virtual const char* className() const { return "IfcIndexedColourMap"; }


	// IfcPresentationItem -----------------------------------------------------------

	// IfcIndexedColourMap -----------------------------------------------------------
	// attributes:
	shared_ptr<IfcTessellatedFaceSet>	m_MappedTo;
	shared_ptr<IfcSurfaceStyleShading>	m_Overrides;				//optional
	shared_ptr<IfcColourRgbList>		m_Colours;
	std::vector<int >					m_ColourIndex;
};

