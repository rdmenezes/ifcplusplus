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
#include "IfcShell.h"
#include "IfcSolidOrShell.h"
#include "IfcConnectedFaceSet.h"
//ENTITY
class IfcClosedShell : virtual public IfcShell, virtual public IfcSolidOrShell, public IfcConnectedFaceSet
{
public:
	IfcClosedShell();
	IfcClosedShell( int id );
	~IfcClosedShell();
	virtual shared_ptr<IfcPPObject> getDeepCopy( IfcPPCopyOptions& options );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void unlinkFromInverseCounterparts();
	virtual const char* className() const { return "IfcClosedShell"; }


	// IfcRepresentationItem -----------------------------------------------------------
	// inverse attributes:
	//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
	//  std::vector<weak_ptr<IfcStyledItem> >					m_StyledByItem_inverse;

	// IfcTopologicalRepresentationItem -----------------------------------------------------------

	// IfcConnectedFaceSet -----------------------------------------------------------
	// attributes:
	//  std::vector<shared_ptr<IfcFace> >						m_CfsFaces;

	// IfcClosedShell -----------------------------------------------------------
};

