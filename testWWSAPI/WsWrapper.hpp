#pragma once
#if defined _MSC_VER
#include <WebServices.h>
#pragma comment (lib, "WebServices.lib")
#include <string>
namespace TestWWSAPI
{
	class WsError
	{
		WS_ERROR* m_h;
	public:
		WsError() : m_h(0)
		{
		}
		~WsError()
		{
			if (0 != m_h)
			{
				WsFreeError(m_h);
				m_h = 0;
			}
		}
		HRESULT Create(const WS_ERROR_PROPERTY* properties,
			ULONG propertyCount)
		{
			return WsCreateError(properties, propertyCount, &m_h);
		}
		HRESULT GetProperty(WS_ERROR_PROPERTY_ID id, void* buffer,
			ULONG bufferSize)
		{
			return WsGetErrorProperty(m_h, id, buffer, bufferSize);
		}
		template <typename T>
		HRESULT GetProperty(WS_ERROR_PROPERTY_ID id, T* buffer)
		{
			return GetProperty(id, buffer, sizeof(T));
		}
		HRESULT GetString(ULONG index, WS_STRING* string)
		{
			return WsGetErrorString(m_h, index, string);
		}
		HRESULT Reset(void)
		{
			return WsResetError(m_h);
		}
		operator WS_ERROR*() const
		{
			return m_h;
		}
		WS_ERROR* Get(void) const
		{
			return m_h;
		}
		std::wstring GetLastWSError(void)
		{
			ULONG ulErrCnt = 0;
			std::wstring wstrErrMsg;
			if (S_OK == GetProperty(WS_ERROR_PROPERTY_STRING_COUNT, &ulErrCnt, sizeof(ULONG))
				&& ulErrCnt > 0)
			{
				WS_STRING string;
				if (S_OK == GetString(ulErrCnt - 1, &string))
				{
					wstrErrMsg.assign(string.chars, string.length);
				}
			}
			Reset();
			return wstrErrMsg;
		}
	};
}
#endif