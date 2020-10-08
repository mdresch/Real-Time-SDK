#include "EnumTypeTable.h"
#include "EnumTypeTableImpl.h"

using namespace refinitiv::ema::rdm;

EnumTypeTable::EnumTypeTable()
{
	_pImpl = new EnumTypeTableImpl();
}


EnumTypeTable::~EnumTypeTable()
{
	if ( _pImpl )
	{
		delete _pImpl;
		_pImpl = 0;
	}
}

EnumTypeTable& EnumTypeTable::operator=(const EnumTypeTable& other)
{
	_pImpl->rsslEnumTypeTable(other._pImpl->getRsslEnumTypeTable());

	return *this;
}

const refinitiv::ema::access::EmaVector<EnumType>& EnumTypeTable::getEnumTypes() const
{
	return _pImpl->getEnumTypes();
}

const refinitiv::ema::access::EmaVector<refinitiv::ema::access::Int16>& EnumTypeTable::getFidReferences() const
{
	return _pImpl->getFidReferences();
}

const refinitiv::ema::access::EmaString& EnumTypeTable::toString() const
{
	return _pImpl->toString();
}

EnumTypeTable::operator const char* () const
{
	return _pImpl->toString().c_str();
}
