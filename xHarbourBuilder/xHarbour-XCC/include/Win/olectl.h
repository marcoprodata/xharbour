#ifndef _OLECTL_H
#define _OLECTL_H

/* Windows OLE Control definitions */

#include <pshpack8.h>
#include <ocidl.h>

#if __POCC__ >= 290
#pragma warn(push)
#pragma warn(disable:2198)  /* Nameless field is not standard */
#endif

#define WINOLECTLAPI EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define WINOLECTLAPI_(type) EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE

#define DISPID_AUTOSIZE  (-500)
#define DISPID_BACKCOLOR  (-501)
#define DISPID_BACKSTYLE  (-502)
#define DISPID_BORDERCOLOR  (-503)
#define DISPID_BORDERSTYLE  (-504)
#define DISPID_BORDERWIDTH  (-505)
#define DISPID_DRAWMODE  (-507)
#define DISPID_DRAWSTYLE  (-508)
#define DISPID_DRAWWIDTH  (-509)
#define DISPID_FILLCOLOR  (-510)
#define DISPID_FILLSTYLE  (-511)
#define DISPID_FONT  (-512)
#define DISPID_FORECOLOR  (-513)
#define DISPID_ENABLED  (-514)
#define DISPID_HWND  (-515)
#define DISPID_TABSTOP  (-516)
#define DISPID_TEXT  (-517)
#define DISPID_CAPTION  (-518)
#define DISPID_BORDERVISIBLE  (-519)
#define DISPID_APPEARANCE  (-520)
#define DISPID_MOUSEPOINTER  (-521)
#define DISPID_MOUSEICON  (-522)
#define DISPID_PICTURE  (-523)
#define DISPID_VALID  (-524)
#define DISPID_READYSTATE  (-525)
#define DISPID_LISTINDEX  (-526)
#define DISPID_SELECTED  (-527)
#define DISPID_LIST  (-528)
#define DISPID_COLUMN  (-529)
#define DISPID_LISTCOUNT  (-531)
#define DISPID_MULTISELECT  (-532)
#define DISPID_MAXLENGTH  (-533)
#define DISPID_PASSWORDCHAR  (-534)
#define DISPID_SCROLLBARS  (-535)
#define DISPID_WORDWRAP  (-536)
#define DISPID_MULTILINE  (-537)
#define DISPID_NUMBEROFROWS  (-538)
#define DISPID_NUMBEROFCOLUMNS  (-539)
#define DISPID_DISPLAYSTYLE  (-540)
#define DISPID_GROUPNAME  (-541)
#define DISPID_IMEMODE  (-542)
#define DISPID_ACCELERATOR  (-543)
#define DISPID_ENTERKEYBEHAVIOR  (-544)
#define DISPID_TABKEYBEHAVIOR  (-545)
#define DISPID_SELTEXT  (-546)
#define DISPID_SELSTART  (-547)
#define DISPID_SELLENGTH  (-548)
#define DISPID_REFRESH  (-550)
#define DISPID_DOCLICK  (-551)
#define DISPID_ABOUTBOX  (-552)
#define DISPID_ADDITEM  (-553)
#define DISPID_CLEAR  (-554)
#define DISPID_REMOVEITEM  (-555)
#define DISPID_CLICK  (-600)
#define DISPID_DBLCLICK  (-601)
#define DISPID_KEYDOWN  (-602)
#define DISPID_KEYPRESS  (-603)
#define DISPID_KEYUP  (-604)
#define DISPID_MOUSEDOWN  (-605)
#define DISPID_MOUSEMOVE  (-606)
#define DISPID_MOUSEUP  (-607)
#define DISPID_ERROREVENT  (-608)
#define DISPID_READYSTATECHANGE  (-609)
#define DISPID_CLICK_VALUE  (-610)
#define DISPID_RIGHTTOLEFT  (-611)
#define DISPID_TOPTOBOTTOM  (-612)
#define DISPID_THIS  (-613)
#define DISPID_AMBIENT_BACKCOLOR  (-701)
#define DISPID_AMBIENT_DISPLAYNAME  (-702)
#define DISPID_AMBIENT_FONT  (-703)
#define DISPID_AMBIENT_FORECOLOR  (-704)
#define DISPID_AMBIENT_LOCALEID  (-705)
#define DISPID_AMBIENT_MESSAGEREFLECT  (-706)
#define DISPID_AMBIENT_SCALEUNITS  (-707)
#define DISPID_AMBIENT_TEXTALIGN  (-708)
#define DISPID_AMBIENT_USERMODE  (-709)
#define DISPID_AMBIENT_UIDEAD  (-710)
#define DISPID_AMBIENT_SHOWGRABHANDLES  (-711)
#define DISPID_AMBIENT_SHOWHATCHING  (-712)
#define DISPID_AMBIENT_DISPLAYASDEFAULT  (-713)
#define DISPID_AMBIENT_SUPPORTSMNEMONICS  (-714)
#define DISPID_AMBIENT_AUTOCLIP  (-715)
#define DISPID_AMBIENT_APPEARANCE  (-716)
#define DISPID_AMBIENT_CODEPAGE  (-725)
#define DISPID_AMBIENT_PALETTE  (-726)
#define DISPID_AMBIENT_CHARSET  (-727)
#define DISPID_AMBIENT_TRANSFERPRIORITY  (-728)
#define DISPID_AMBIENT_RIGHTTOLEFT  (-732)
#define DISPID_AMBIENT_TOPTOBOTTOM  (-733)
#define DISPID_Name  (-800)
#define DISPID_Delete  (-801)
#define DISPID_Object  (-802)
#define DISPID_Parent  (-803)

#define DISPID_FONT_NAME  0
#define DISPID_FONT_SIZE  2
#define DISPID_FONT_BOLD  3
#define DISPID_FONT_ITALIC  4
#define DISPID_FONT_UNDER  5
#define DISPID_FONT_STRIKE  6
#define DISPID_FONT_WEIGHT  7
#define DISPID_FONT_CHARSET  8
#define DISPID_FONT_CHANGED  9

#define DISPID_PICT_HANDLE  0
#define DISPID_PICT_HPAL  2
#define DISPID_PICT_TYPE  3
#define DISPID_PICT_WIDTH  4
#define DISPID_PICT_HEIGHT  5
#define DISPID_PICT_RENDER  6

#ifndef FACILITY_CONTROL
#define FACILITY_CONTROL  0xa
#endif

#define STD_CTL_SCODE(n)  MAKE_SCODE(SEVERITY_ERROR,FACILITY_CONTROL,n)
#define CTL_E_ILLEGALFUNCTIONCALL  STD_CTL_SCODE(5)
#define CTL_E_OVERFLOW  STD_CTL_SCODE(6)
#define CTL_E_OUTOFMEMORY  STD_CTL_SCODE(7)
#define CTL_E_DIVISIONBYZERO  STD_CTL_SCODE(11)
#define CTL_E_OUTOFSTRINGSPACE  STD_CTL_SCODE(14)
#define CTL_E_OUTOFSTACKSPACE  STD_CTL_SCODE(28)
#define CTL_E_BADFILENAMEORNUMBER  STD_CTL_SCODE(52)
#define CTL_E_FILENOTFOUND  STD_CTL_SCODE(53)
#define CTL_E_BADFILEMODE  STD_CTL_SCODE(54)
#define CTL_E_FILEALREADYOPEN  STD_CTL_SCODE(55)
#define CTL_E_DEVICEIOERROR  STD_CTL_SCODE(57)
#define CTL_E_FILEALREADYEXISTS  STD_CTL_SCODE(58)
#define CTL_E_BADRECORDLENGTH  STD_CTL_SCODE(59)
#define CTL_E_DISKFULL  STD_CTL_SCODE(61)
#define CTL_E_BADRECORDNUMBER  STD_CTL_SCODE(63)
#define CTL_E_BADFILENAME  STD_CTL_SCODE(64)
#define CTL_E_TOOMANYFILES  STD_CTL_SCODE(67)
#define CTL_E_DEVICEUNAVAILABLE  STD_CTL_SCODE(68)
#define CTL_E_PERMISSIONDENIED  STD_CTL_SCODE(70)
#define CTL_E_DISKNOTREADY  STD_CTL_SCODE(71)
#define CTL_E_PATHFILEACCESSERROR  STD_CTL_SCODE(75)
#define CTL_E_PATHNOTFOUND  STD_CTL_SCODE(76)
#define CTL_E_INVALIDPATTERNSTRING  STD_CTL_SCODE(93)
#define CTL_E_INVALIDUSEOFNULL  STD_CTL_SCODE(94)
#define CTL_E_INVALIDFILEFORMAT  STD_CTL_SCODE(321)
#define CTL_E_INVALIDPROPERTYVALUE  STD_CTL_SCODE(380)
#define CTL_E_INVALIDPROPERTYARRAYINDEX  STD_CTL_SCODE(381)
#define CTL_E_SETNOTSUPPORTEDATRUNTIME  STD_CTL_SCODE(382)
#define CTL_E_SETNOTSUPPORTED  STD_CTL_SCODE(383)
#define CTL_E_NEEDPROPERTYARRAYINDEX  STD_CTL_SCODE(385)
#define CTL_E_SETNOTPERMITTED  STD_CTL_SCODE(387)
#define CTL_E_GETNOTSUPPORTEDATRUNTIME  STD_CTL_SCODE(393)
#define CTL_E_GETNOTSUPPORTED  STD_CTL_SCODE(394)
#define CTL_E_PROPERTYNOTFOUND  STD_CTL_SCODE(422)
#define CTL_E_INVALIDCLIPBOARDFORMAT  STD_CTL_SCODE(460)
#define CTL_E_INVALIDPICTURE  STD_CTL_SCODE(481)
#define CTL_E_PRINTERERROR  STD_CTL_SCODE(482)
#define CTL_E_CANTSAVEFILETOTEMP  STD_CTL_SCODE(735)
#define CTL_E_SEARCHTEXTNOTFOUND  STD_CTL_SCODE(744)
#define CTL_E_REPLACEMENTSTOOLONG  STD_CTL_SCODE(746)

#define CUSTOM_CTL_SCODE(n)  MAKE_SCODE(SEVERITY_ERROR,FACILITY_CONTROL,n)
#define CTL_E_CUSTOM_FIRST  CUSTOM_CTL_SCODE(600)

#define CONNECT_E_FIRST  MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0200)
#define CONNECT_E_LAST  MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x020F)
#define CONNECT_S_FIRST  MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0200)
#define CONNECT_S_LAST  MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x020F)

#define CONNECT_E_NOCONNECTION  (CONNECT_E_FIRST+0)
#define CONNECT_E_ADVISELIMIT  (CONNECT_E_FIRST+1)
#define CONNECT_E_CANNOTCONNECT  (CONNECT_E_FIRST+2)
#define CONNECT_E_OVERRIDDEN  (CONNECT_E_FIRST+3)

#define SELFREG_E_FIRST  MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0200)
#define SELFREG_E_LAST  MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x020F)
#define SELFREG_S_FIRST  MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0200)
#define SELFREG_S_LAST  MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x020F)

#define SELFREG_E_TYPELIB  (SELFREG_E_FIRST+0)
#define SELFREG_E_CLASS  (SELFREG_E_FIRST+1)

#define PERPROP_E_FIRST  MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0200)
#define PERPROP_E_LAST  MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x020F)
#define PERPROP_S_FIRST  MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0200)
#define PERPROP_S_LAST  MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x020F)

#define PERPROP_E_NOPAGEAVAILABLE  (PERPROP_E_FIRST+0)

#define OLEMISC_INVISIBLEATRUNTIME  0x00000400L
#define OLEMISC_ALWAYSRUN  0x00000800L
#define OLEMISC_ACTSLIKEBUTTON  0x00001000L
#define OLEMISC_ACTSLIKELABEL  0x00002000L
#define OLEMISC_NOUIACTIVATE  0x00004000L
#define OLEMISC_ALIGNABLE  0x00008000L
#define OLEMISC_SIMPLEFRAME  0x00010000L
#define OLEMISC_SETCLIENTSITEFIRST  0x00020000L
#define OLEMISC_IMEMODE  0x00040000L

#ifndef OLEIVERB_PROPERTIES
#define OLEIVERB_PROPERTIES  (-7L)
#endif

#define VT_STREAMED_PROPSET  73
#define VT_STORED_PROPSET  74
#define VT_BLOB_PROPSET  75
#define VT_VERBOSE_ENUM  76

#define VT_COLOR  VT_I4
#define VT_XPOS_PIXELS  VT_I4
#define VT_YPOS_PIXELS  VT_I4
#define VT_XSIZE_PIXELS  VT_I4
#define VT_YSIZE_PIXELS  VT_I4
#define VT_XPOS_HIMETRIC  VT_I4
#define VT_YPOS_HIMETRIC  VT_I4
#define VT_XSIZE_HIMETRIC  VT_I4
#define VT_YSIZE_HIMETRIC  VT_I4
#define VT_TRISTATE  VT_I2
#define VT_OPTEXCLUSIVE  VT_BOOL
#define VT_FONT  VT_DISPATCH
#define VT_PICTURE  VT_DISPATCH
#define VT_HANDLE  VT_I4

#define OCM__BASE  (WM_USER+0x1C00)
#define OCM_COMMAND  (OCM__BASE+WM_COMMAND)
#define OCM_CTLCOLORBTN  (OCM__BASE+WM_CTLCOLORBTN)
#define OCM_CTLCOLOREDIT  (OCM__BASE+WM_CTLCOLOREDIT)
#define OCM_CTLCOLORDLG  (OCM__BASE+WM_CTLCOLORDLG)
#define OCM_CTLCOLORLISTBOX  (OCM__BASE+WM_CTLCOLORLISTBOX)
#define OCM_CTLCOLORMSGBOX  (OCM__BASE+WM_CTLCOLORMSGBOX)
#define OCM_CTLCOLORSCROLLBAR  (OCM__BASE+WM_CTLCOLORSCROLLBAR)
#define OCM_CTLCOLORSTATIC  (OCM__BASE+WM_CTLCOLORSTATIC)
#define OCM_DRAWITEM  (OCM__BASE+WM_DRAWITEM)
#define OCM_MEASUREITEM  (OCM__BASE+WM_MEASUREITEM)
#define OCM_DELETEITEM  (OCM__BASE+WM_DELETEITEM)
#define OCM_VKEYTOITEM  (OCM__BASE+WM_VKEYTOITEM)
#define OCM_CHARTOITEM  (OCM__BASE+WM_CHARTOITEM)
#define OCM_COMPAREITEM  (OCM__BASE+WM_COMPAREITEM)
#define OCM_HSCROLL  (OCM__BASE+WM_HSCROLL)
#define OCM_VSCROLL  (OCM__BASE+WM_VSCROLL)
#define OCM_PARENTNOTIFY  (OCM__BASE+WM_PARENTNOTIFY)
#define OCM_NOTIFY  (OCM__BASE+WM_NOTIFY)

#define PICTYPE_UNINITIALIZED  (-1)
#define PICTYPE_NONE  0
#define PICTYPE_BITMAP  1
#define PICTYPE_METAFILE  2
#define PICTYPE_ICON  3
#define PICTYPE_ENHMETAFILE  4

#define LP_DEFAULT  0x00
#define LP_MONOCHROME  0x01
#define LP_VGACOLOR  0x02
#define LP_COLOR  0x04

#ifndef INITGUID
DEFINE_GUID(IID_IPropertyFrame,0xB196B28A,0xBAB4,0x101A,0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07);
DEFINE_GUID(CLSID_CFontPropPage,0x0be35200,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);
DEFINE_GUID(CLSID_CColorPropPage,0x0be35201,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);
DEFINE_GUID(CLSID_CPicturePropPage,0x0be35202,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);
DEFINE_GUID(CLSID_PersistPropset,0xfb8f0821,0x0164,0x101b,0x84,0xed,0x08,0x00,0x2b,0x2e,0xc7,0x13);
DEFINE_GUID(CLSID_ConvertVBX,0xfb8f0822,0x0164,0x101b,0x84,0xed,0x08,0x00,0x2b,0x2e,0xc7,0x13);
DEFINE_GUID(CLSID_StdFont,0x0be35203,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);
DEFINE_GUID(CLSID_StdPicture,0x0be35204,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);
DEFINE_GUID(GUID_HIMETRIC,0x66504300,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_COLOR,0x66504301,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_XPOSPIXEL,0x66504302,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_YPOSPIXEL,0x66504303,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_XSIZEPIXEL,0x66504304,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_YSIZEPIXEL,0x66504305,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_XPOS,0x66504306,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_YPOS,0x66504307,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_XSIZE,0x66504308,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_YSIZE,0x66504309,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
#ifndef _CGUID_H
DEFINE_GUID(GUID_TRISTATE,0x6650430A,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
#endif /* _CGUID_H */
DEFINE_GUID(GUID_OPTIONVALUEEXCLUSIVE,0x6650430B,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_CHECKVALUEEXCLUSIVE,0x6650430C,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_FONTNAME,0x6650430D,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_FONTSIZE,0x6650430E,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_FONTBOLD,0x6650430F,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_FONTITALIC,0x66504310,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_FONTUNDERSCORE,0x66504311,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_FONTSTRIKETHROUGH,0x66504312,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
DEFINE_GUID(GUID_HANDLE,0x66504313,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
#endif /* INITGUID */

typedef struct tagOCPFIPARAMS {
    ULONG cbStructSize;
    HWND hWndOwner;
    int x;
    int y;
    LPCOLESTR lpszCaption;
    ULONG cObjects;
    LPUNKNOWN *lplpUnk;
    ULONG cPages;
    CLSID *lpPages;
    LCID lcid;
    DISPID dispidInitialProperty;
} OCPFIPARAMS, *LPOCPFIPARAMS;

#define FONTSIZE(n) { n##0000, 0 }

typedef struct tagFONTDESC {
    UINT cbSizeofstruct;
    LPOLESTR lpstrName;
    CY cySize;
    SHORT sWeight;
    SHORT sCharset;
    BOOL fItalic;
    BOOL fUnderline;
    BOOL fStrikethrough;
} FONTDESC, *LPFONTDESC;

typedef struct tagPICTDESC {
    UINT cbSizeofstruct;
    UINT picType;
    union {
        struct {
            HBITMAP hbitmap;
            HPALETTE hpal;
        } bmp;
        struct {
            HMETAFILE hmeta;
            int xExt;
            int yExt;
        } wmf;
        struct {
            HICON hicon;
        } icon;
        struct {
            HENHMETAFILE hemf;
        } emf;
    };
} PICTDESC, *LPPICTDESC;

typedef enum {
    triUnchecked = 0,
    triChecked = 1,
    triGray = 2
} OLE_TRISTATE;

typedef long OLE_XPOS_PIXELS;
typedef long OLE_YPOS_PIXELS;
typedef long OLE_XSIZE_PIXELS;
typedef long OLE_YSIZE_PIXELS;
typedef float OLE_XPOS_CONTAINER;
typedef float OLE_YPOS_CONTAINER;
typedef float OLE_XSIZE_CONTAINER;
typedef float OLE_YSIZE_CONTAINER;
typedef VARIANT_BOOL OLE_OPTEXCLUSIVE;
typedef VARIANT_BOOL OLE_CANCELBOOL;
typedef VARIANT_BOOL OLE_ENABLEDEFAULTBOOL;

STDAPI DllRegisterServer(void);
STDAPI DllUnregisterServer(void);

typedef DWORD OLE_COLOR;  /* from ocidl.h */

WINOLECTLAPI OleCreatePropertyFrame(HWND,UINT,UINT,LPCOLESTR,ULONG,LPUNKNOWN*,ULONG,LPCLSID,LCID,DWORD,LPVOID);
WINOLECTLAPI OleCreatePropertyFrameIndirect(LPOCPFIPARAMS);
WINOLECTLAPI OleTranslateColor(OLE_COLOR,HPALETTE,COLORREF*);
WINOLECTLAPI OleCreateFontIndirect(LPFONTDESC,REFIID,LPVOID*);
WINOLECTLAPI OleCreatePictureIndirect(LPPICTDESC,REFIID,BOOL,LPVOID*);
WINOLECTLAPI OleLoadPicture(LPSTREAM,LONG,BOOL,REFIID,LPVOID*);
WINOLECTLAPI OleLoadPictureEx(LPSTREAM,LONG,BOOL,REFIID,DWORD,DWORD,DWORD,LPVOID*);
WINOLECTLAPI OleLoadPicturePath(LPOLESTR,LPUNKNOWN,DWORD,OLE_COLOR,REFIID,LPVOID*);
WINOLECTLAPI OleLoadPictureFile(VARIANT,LPDISPATCH*);
WINOLECTLAPI OleLoadPictureFileEx(VARIANT,DWORD,DWORD,DWORD,LPDISPATCH*);
WINOLECTLAPI OleSavePictureFile(LPDISPATCH,BSTR);
WINOLECTLAPI_(HCURSOR) OleIconToCursor(HINSTANCE,HICON);

#include <poppack.h>

#define STDOLE_TLB  "stdole2.tlb"
#define STDTYPE_TLB  "olepro32.dll"

#if __POCC__ >= 290
#pragma warn(pop)
#endif

#endif /* _OLECTL_H */
