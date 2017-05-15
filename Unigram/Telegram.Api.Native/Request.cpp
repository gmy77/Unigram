#include "pch.h"
#include "Request.h"

using namespace Telegram::Api::Native;


Request::Request(ITLObject* object, INT32 token, ConnectionType connectionType, UINT32 datacenterId, ISendRequestCompletedCallback* sendCompletedCallback, IRequestQuickAckReceivedCallback* quickAckReceivedCallback) :
	m_object(object),
	m_token(token),
	m_connectionType(connectionType),
	m_datacenterId(datacenterId),
	m_sendCompletedCallback(sendCompletedCallback),
	m_quickAckReceivedCallback(quickAckReceivedCallback)
{
}

Request::~Request()
{
}

HRESULT Request::get_Object(_Out_ ITLObject** value)
{
	if (value == nullptr)
	{
		return E_POINTER;
	}

	return m_object.CopyTo(value);
}

HRESULT Request::get_Token(INT32* value)
{
	if (value == nullptr)
	{
		return E_POINTER;
	}

	*value = m_token;
	return S_OK;
}

HRESULT Request::get_ConnectionType(ConnectionType* value)
{
	if (value == nullptr)
	{
		return E_POINTER;
	}

	*value = m_connectionType;
	return S_OK;
}

HRESULT Request::get_DatacenterId(UINT32* value)
{
	if (value == nullptr)
	{
		return E_POINTER;
	}

	*value = m_datacenterId;
	return S_OK;
}