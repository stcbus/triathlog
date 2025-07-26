// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

// CHyperlink wrapper class
#pragma once

class CHyperlink : public COleDispatchDriver
{
public:
    CHyperlink(){} // Calls COleDispatchDriver default constructor
    CHyperlink(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
    CHyperlink(const CHyperlink& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

    // Attributes
public:

    // Operations
public:


    // Hyperlink methods
public:
    void Delete()
    {
        InvokeHelper(0x60020000, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void Follow(BOOL NewWindow)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0x60020001, DISPATCH_METHOD, VT_EMPTY, NULL, parms, NewWindow);
    }
    CString get_Address()
    {
        CString result;
        InvokeHelper(0x60020002, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    void put_Address(LPCTSTR newValue)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x60020002, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    CString get_Name()
    {
        CString result;
        InvokeHelper(0x60020004, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    void put_Name(LPCTSTR newValue)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x60020004, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    LPDISPATCH get_Parent()
    {
        LPDISPATCH result;
        InvokeHelper(0x60020006, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
        return result;
    }
    CString get_Subaddress()
    {
        CString result;
        InvokeHelper(0x60020007, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    void put_Subaddress(LPCTSTR newValue)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x60020007, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }

    // Hyperlink properties
public:

};
