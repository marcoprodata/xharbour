#ifndef _COMMCTRL_H
#define _COMMCTRL_H

/* Windows Common Controls definitions */

#ifndef _WINRESRC_H
#ifndef _WIN32_IE
#define _WIN32_IE 0x0501
#else
#if (_WIN32_IE < 0x0400) && defined(_WIN32_WINNT) && (_WIN32_WINNT >= 0x0500)
#error _WIN32_IE setting conflicts with _WIN32_WINNT setting
#endif
#endif /* _WIN32_IE */
#endif /* _WINRESRC_H */

#ifndef _HRESULT_DEFINED
#define _HRESULT_DEFINED
typedef LONG HRESULT;
#endif

#ifndef WINCOMMCTRLAPI
#define WINCOMMCTRLAPI DECLSPEC_IMPORT
#endif

#ifndef DUMMYUNIONNAME
#ifdef NONAMELESSUNION
#define DUMMYUNIONNAME  u
#define DUMMYUNIONNAME2  u2
#define DUMMYUNIONNAME3  u3
#define DUMMYUNIONNAME4  u4
#define DUMMYUNIONNAME5  u5
#else
#define DUMMYUNIONNAME
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if __POCC__ >= 290
#pragma warn(push)
#pragma warn(disable:2198)  /* Nameless field is not standard */
#endif

#include <prsht.h>

#ifndef SNDMSG
#ifdef __cplusplus
#define SNDMSG ::SendMessage
#else
#define SNDMSG SendMessage
#endif
#endif

WINCOMMCTRLAPI void WINAPI InitCommonControls(void);

typedef struct tagINITCOMMONCONTROLSEX {
    DWORD dwSize;
    DWORD dwICC;
} INITCOMMONCONTROLSEX, *LPINITCOMMONCONTROLSEX;

#ifdef _WINCE
#define ICC_LISTVIEW_CLASSES  0x00000001
#define ICC_TREEVIEW_CLASSES  0x00000002
#define ICC_BAR_CLASSES  0x00000004
#define ICC_TAB_CLASSES  0x00000008
#define ICC_UPDOWN_CLASS  0x00000010
#define ICC_PROGRESS_CLASS  0x00000020
#define ICC_WIN95_CLASSES  0x000000FF
#define ICC_DATE_CLASSES  0x00000100
#define ICC_COOL_CLASSES  0x00000400
#if defined(WINCEOSVER) && WINCEOSVER >= 400 && _WIN32_IE >= 0x0400
#define ICC_INTERNET_CLASSES  0x00000800
#endif
#define ICC_TOOLTIP_CLASSES  0x00001000
#define ICC_CAPEDIT_CLASS  0x00002000
#define ICC_FE_CLASSES  0x00004000  /* Smartphone only */
#else /* _WINCE */
#define ICC_LISTVIEW_CLASSES  0x00000001
#define ICC_TREEVIEW_CLASSES  0x00000002
#define ICC_BAR_CLASSES  0x00000004
#define ICC_TAB_CLASSES  0x00000008
#define ICC_UPDOWN_CLASS  0x00000010
#define ICC_PROGRESS_CLASS  0x00000020
#define ICC_HOTKEY_CLASS  0x00000040
#define ICC_ANIMATE_CLASS  0x00000080
#define ICC_WIN95_CLASSES  0x000000FF
#define ICC_DATE_CLASSES  0x00000100
#define ICC_USEREX_CLASSES  0x00000200
#define ICC_COOL_CLASSES  0x00000400
#if (_WIN32_IE >= 0x0400)
#define ICC_INTERNET_CLASSES  0x00000800
#define ICC_PAGESCROLLER_CLASS  0x00001000
#define ICC_NATIVEFNTCTL_CLASS  0x00002000
#endif
#if (_WIN32_WINNT >= 0x501)
#define ICC_STANDARD_CLASSES  0x00004000
#define ICC_LINK_CLASS  0x00008000
#endif
#endif /* _WINCE */

WINCOMMCTRLAPI BOOL WINAPI InitCommonControlsEx(LPINITCOMMONCONTROLSEX);

#define ODT_HEADER  100
#define ODT_TAB  101
#define ODT_LISTVIEW  102

/* Ranges for control message IDs *******************************************/

#define LVM_FIRST  0x1000
#define TV_FIRST  0x1100
#define HDM_FIRST  0x1200
#define TCM_FIRST  0x1300

#ifdef _WINCE
#define COMCTL32_VERSION  0x020c
#define CCM_SETVERSION  (CCM_FIRST+7)
#define CCM_GETVERSION  (CCM_FIRST+8)
#define CCM_FIRST  0x2000
#define CCM_LAST  (CCM_FIRST+0x200)
#endif /* _WINCE */

#if (_WIN32_IE >= 0x0400)
#define PGM_FIRST  0x1400
#if (_WIN32_WINNT >= 0x501)
#define ECM_FIRST  0x1500
#define BCM_FIRST  0x1600
#define CBM_FIRST  0x1700
#endif
#define CCM_FIRST  0x2000
#define CCM_LAST  (CCM_FIRST+0x200)
#define CCM_SETBKCOLOR  (CCM_FIRST+1)

typedef struct tagCOLORSCHEME {
    DWORD dwSize;
    COLORREF clrBtnHighlight;
    COLORREF clrBtnShadow;
} COLORSCHEME, *LPCOLORSCHEME;

#define CCM_SETCOLORSCHEME  (CCM_FIRST+2)
#define CCM_GETCOLORSCHEME  (CCM_FIRST+3)
#define CCM_GETDROPTARGET  (CCM_FIRST+4)
#define CCM_SETUNICODEFORMAT  (CCM_FIRST+5)
#define CCM_GETUNICODEFORMAT  (CCM_FIRST+6)

#if (_WIN32_IE >= 0x0500)
#ifndef _WINCE
#if (_WIN32_WINNT >= 0x501)
#define COMCTL32_VERSION  6
#else
#define COMCTL32_VERSION  5
#endif
#define CCM_SETVERSION  (CCM_FIRST+7)
#define CCM_GETVERSION  (CCM_FIRST+8)
#endif /* _WINCE_ */
#define CCM_SETNOTIFYWINDOW  (CCM_FIRST+9)
#if (_WIN32_WINNT >= 0x501)
#define CCM_SETWINDOWTHEME  (CCM_FIRST+0xb)
#define CCM_DPISCALE  (CCM_FIRST+0xc)
#endif
#endif

#define INFOTIPSIZE  1024
#endif /* _WIN32_IE >= 0x0400 */

/* WM_NOTIFY macros *********************************************************/

#define HANDLE_WM_NOTIFY(hwnd,wParam,lParam,fn)  (fn)((hwnd),(int)(wParam),(NMHDR*)(lParam))
#define FORWARD_WM_NOTIFY(hwnd,idFrom,pnmhdr,fn)  (LRESULT)(fn)((hwnd),WM_NOTIFY,(WPARAM)(int)(idFrom),(LPARAM)(NMHDR*)(pnmhdr))

/* Generic WM_NOTIFY notifications ******************************************/

#define NM_OUTOFMEMORY  (NM_FIRST-1)
#define NM_CLICK  (NM_FIRST-2)
#define NM_DBLCLK  (NM_FIRST-3)
#define NM_RETURN  (NM_FIRST-4)
#define NM_RCLICK  (NM_FIRST-5)
#define NM_RDBLCLK  (NM_FIRST-6)
#define NM_SETFOCUS  (NM_FIRST-7)
#define NM_KILLFOCUS  (NM_FIRST-8)
#define NM_CUSTOMDRAW  (NM_FIRST-12)
#define NM_HOVER  (NM_FIRST-13)
#if (_WIN32_IE >= 0x0400)
#define NM_NCHITTEST  (NM_FIRST-14)
#define NM_KEYDOWN  (NM_FIRST-15)
#define NM_RELEASEDCAPTURE  (NM_FIRST-16)
#define NM_SETCURSOR  (NM_FIRST-17)
#define NM_CHAR  (NM_FIRST-18)
#endif
#ifdef _WINCE
#define NM_RECOGNIZEGESTURE  (NM_FIRST-16)  /* Smartphone only */
#endif /* _WINCE */
#if (_WIN32_IE >= 0x0401)
#define NM_TOOLTIPSCREATED  (NM_FIRST-19)
#endif
#if (_WIN32_IE >= 0x0500)
#define NM_LDOWN  (NM_FIRST-20)
#define NM_RDOWN  (NM_FIRST-21)
#endif

#ifndef CCSIZEOF_STRUCT
#define CCSIZEOF_STRUCT(structname,member)  (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))
#endif

#if (_WIN32_IE >= 0x0401)
typedef struct tagNMTOOLTIPSCREATED {
    NMHDR hdr;
    HWND hwndToolTips;
} NMTOOLTIPSCREATED, *LPNMTOOLTIPSCREATED;
#endif

#if (_WIN32_IE >= 0x0400)
typedef struct tagNMMOUSE {
    NMHDR hdr;
    DWORD_PTR dwItemSpec;
    DWORD_PTR dwItemData;
    POINT pt;
    LPARAM  dwHitInfo;
} NMMOUSE, *LPNMMOUSE;
typedef NMMOUSE NMCLICK;
typedef LPNMMOUSE LPNMCLICK;

typedef struct tagNMOBJECTNOTIFY {
    NMHDR hdr;
    int iItem;
#ifdef __IID_DEFINED__
    const IID *piid;
#else
    const void *piid;
#endif
    void *pObject;
    HRESULT hResult;
    DWORD dwFlags;
} NMOBJECTNOTIFY, *LPNMOBJECTNOTIFY;

typedef struct tagNMKEY {
    NMHDR hdr;
    UINT nVKey;
    UINT uFlags;
} NMKEY, *LPNMKEY;

typedef struct tagNMCHAR {
    NMHDR hdr;
    UINT ch;
    DWORD dwItemPrev;
    DWORD dwItemNext;
} NMCHAR, *LPNMCHAR;
#endif /* _WIN32_IE >= 0x0400 */

#define NM_FIRST  (0U-0U)
#define NM_LAST  (0U-99U)
#define LVN_FIRST  (0U-100U)
#define LVN_LAST  (0U-199U)
#define HDN_FIRST  (0U-300U)
#define HDN_LAST  (0U-399U)
#define TVN_FIRST  (0U-400U)
#define TVN_LAST  (0U-499U)
#define TTN_FIRST  (0U-520U)
#define TTN_LAST  (0U-549U)
#define TCN_FIRST  (0U-550U)
#define TCN_LAST  (0U-580U)
#define CDN_FIRST  (0U-601U)
#define CDN_LAST  (0U-699U)
#define TBN_FIRST  (0U-700U)
#define TBN_LAST  (0U-720U)
#define UDN_FIRST  (0U-721U)
#define UDN_LAST  (0U-740U)
#define MCN_FIRST  (0U-750U)
#define MCN_LAST  (0U-759U)
#define DTN_FIRST  (0U-760U)
#define DTN_LAST  (0U-799U)
#define CBEN_FIRST  (0U-800U)
#define CBEN_LAST  (0U-830U)
#define RBN_FIRST  (0U-831U)
#define RBN_LAST  (0U-859U)
#if (_WIN32_IE >= 0x0400)
#define IPN_FIRST  (0U-860U)
#define IPN_LAST  (0U-879U)
#define SBN_FIRST  (0U-880U)
#define SBN_LAST  (0U-899U)
#define PGN_FIRST  (0U-900U)
#define PGN_LAST  (0U-950U)
#endif
#ifdef _WINCE
#define SHN_FIRST  (0U-1000U)
#define SHN_LAST  (0U-11000U)
#endif /* _WINCE */

#if (_WIN32_IE >= 0x0500)
#ifndef WMN_FIRST
#define WMN_FIRST  (0U-1000U)
#define WMN_LAST  (0U-1200U)
#endif
#endif

#if (_WIN32_WINNT >= 0x0501)
#define BCN_FIRST  (0U-1250U)
#define BCN_LAST  (0U-1350U)
#endif

#define MSGF_COMMCTRL_BEGINDRAG  0x4200
#define MSGF_COMMCTRL_SIZEHEADER  0x4201
#define MSGF_COMMCTRL_DRAGSELECT  0x4202
#define MSGF_COMMCTRL_TOOLBARCUST  0x4203

/* Common Control Styles ****************************************************/

#define CCS_TOP  0x00000001L
#define CCS_NOMOVEY  0x00000002L
#define CCS_BOTTOM  0x00000003L
#define CCS_NORESIZE  0x00000004L
#define CCS_NOPARENTALIGN  0x00000008L
#define CCS_ADJUSTABLE  0x00000020L
#define CCS_NODIVIDER  0x00000040L
#define CCS_VERT  0x00000080L
#define CCS_LEFT  (CCS_VERT|CCS_TOP)
#define CCS_RIGHT  (CCS_VERT|CCS_BOTTOM)
#define CCS_NOMOVEX  (CCS_VERT|CCS_NOMOVEY)

/* Custom Draw **************************************************************/

#define CDRF_DODEFAULT  0x00000000
#define CDRF_NEWFONT  0x00000002
#define CDRF_SKIPDEFAULT  0x00000004

#define CDRF_NOTIFYPOSTPAINT  0x00000010
#define CDRF_NOTIFYITEMDRAW  0x00000020
#if (_WIN32_IE >= 0x0400)
#define CDRF_NOTIFYSUBITEMDRAW  0x00000020
#endif
#define CDRF_NOTIFYPOSTERASE  0x00000040

#define CDDS_PREPAINT  0x00000001
#define CDDS_POSTPAINT  0x00000002
#define CDDS_PREERASE  0x00000003
#define CDDS_POSTERASE  0x00000004
#define CDDS_ITEM  0x00010000
#define CDDS_ITEMPREPAINT  (CDDS_ITEM|CDDS_PREPAINT)
#define CDDS_ITEMPOSTPAINT  (CDDS_ITEM|CDDS_POSTPAINT)
#define CDDS_ITEMPREERASE  (CDDS_ITEM|CDDS_PREERASE)
#define CDDS_ITEMPOSTERASE  (CDDS_ITEM|CDDS_POSTERASE)
#if (_WIN32_IE >= 0x0400)
#define CDDS_SUBITEM  0x00020000
#endif

#define CDIS_SELECTED  0x0001
#define CDIS_GRAYED  0x0002
#define CDIS_DISABLED  0x0004
#define CDIS_CHECKED  0x0008
#define CDIS_FOCUS  0x0010
#define CDIS_DEFAULT  0x0020
#define CDIS_HOT  0x0040
#define CDIS_MARKED  0x0080
#define CDIS_INDETERMINATE  0x0100
#if (_WIN32_WINNT >= 0x501)
#define CDIS_SHOWKEYBOARDCUES  0x0200
#endif

typedef struct tagNMCUSTOMDRAWINFO {
    NMHDR hdr;
    DWORD dwDrawStage;
    HDC hdc;
    RECT rc;
    DWORD_PTR dwItemSpec;
    UINT uItemState;
    LPARAM lItemlParam;
} NMCUSTOMDRAW, *LPNMCUSTOMDRAW;

typedef struct tagNMTTCUSTOMDRAW {
    NMCUSTOMDRAW nmcd;
    UINT uDrawFlags;
} NMTTCUSTOMDRAW, *LPNMTTCUSTOMDRAW;

/* ImageList API ************************************************************/

#ifndef NOIMAGEAPIS

#define CLR_NONE  0xFFFFFFFFL
#define CLR_DEFAULT  0xFF000000L

struct _IMAGELIST;
typedef struct _IMAGELIST *HIMAGELIST;

typedef struct _IMAGELISTDRAWPARAMS {
    DWORD cbSize;
    HIMAGELIST himl;
    int i;
    HDC hdcDst;
    int x;
    int y;
    int cx;
    int cy;
    int xBitmap;
    int yBitmap;
    COLORREF rgbBk;
    COLORREF rgbFg;
    UINT fStyle;
    DWORD dwRop;
#if (_WIN32_WINNT >= 0x501)
    DWORD fState;
    DWORD Frame;
    COLORREF crEffect;
#endif
} IMAGELISTDRAWPARAMS, *LPIMAGELISTDRAWPARAMS;

#define ILC_MASK  0x0001
#define ILC_COLOR  0x0000
#define ILC_COLORDDB  0x00FE
#define ILC_COLOR4  0x0004
#define ILC_COLOR8  0x0008
#define ILC_COLOR16  0x0010
#define ILC_COLOR24  0x0018
#define ILC_COLOR32  0x0020
#define ILC_PALETTE  0x0800
#if (_WIN32_WINNT >= 0x501)
#define ILC_MIRROR  0x00002000
#define ILC_PERITEMMIRROR  0x00008000
#endif

#define ILD_NORMAL  0x0000
#define ILD_TRANSPARENT  0x0001
#define ILD_MASK  0x0010
#define ILD_IMAGE  0x0020
#define ILD_ROP  0x0040
#define ILD_BLEND25  0x0002
#define ILD_BLEND50  0x0004
#define ILD_OVERLAYMASK  0x0F00

#define INDEXTOOVERLAYMASK(i)   ((i)<<8)

#define ILD_SELECTED  ILD_BLEND50
#define ILD_FOCUS  ILD_BLEND25
#define ILD_BLEND  ILD_BLEND50
#define CLR_HILIGHT  CLR_DEFAULT

#define ILCF_MOVE  (0x00000000)
#define ILCF_SWAP  (0x00000001)

#if (_WIN32_WINNT >= 0x0501)
#define ILP_NORMAL  0
#define ILP_DOWNLEVEL  1
#endif

typedef struct _IMAGEINFO {
    HBITMAP hbmImage;
    HBITMAP hbmMask;
    int Unused1;
    int Unused2;
    RECT rcImage;
} IMAGEINFO, *LPIMAGEINFO;

WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_Create(int,int,UINT,int,int);
WINCOMMCTRLAPI BOOL WINAPI ImageList_Destroy(HIMAGELIST);
WINCOMMCTRLAPI int WINAPI ImageList_GetImageCount(HIMAGELIST);
WINCOMMCTRLAPI BOOL WINAPI ImageList_SetImageCount(HIMAGELIST,UINT);
WINCOMMCTRLAPI int WINAPI ImageList_Add(HIMAGELIST,HBITMAP,HBITMAP);
WINCOMMCTRLAPI int WINAPI ImageList_ReplaceIcon(HIMAGELIST,int,HICON);
WINCOMMCTRLAPI COLORREF WINAPI ImageList_SetBkColor(HIMAGELIST,COLORREF);
WINCOMMCTRLAPI COLORREF WINAPI ImageList_GetBkColor(HIMAGELIST);
WINCOMMCTRLAPI BOOL WINAPI ImageList_SetOverlayImage(HIMAGELIST,int,int);
WINCOMMCTRLAPI BOOL WINAPI ImageList_Draw(HIMAGELIST,int,HDC,int,int,UINT);
WINCOMMCTRLAPI BOOL WINAPI ImageList_Replace(HIMAGELIST,int,HBITMAP,HBITMAP);
WINCOMMCTRLAPI int WINAPI ImageList_AddMasked(HIMAGELIST,HBITMAP,COLORREF);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DrawEx(HIMAGELIST,int,HDC,int,int,int,int,COLORREF,COLORREF,UINT);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DrawIndirect(IMAGELISTDRAWPARAMS*);
WINCOMMCTRLAPI BOOL WINAPI ImageList_Remove(HIMAGELIST,int);
WINCOMMCTRLAPI HICON WINAPI ImageList_GetIcon(HIMAGELIST,int,UINT);
#ifdef _WINCE
WINCOMMCTRLAPI HIMAGELIST  WINAPI ImageList_LoadImage(HINSTANCE,LPCTSTR,int,int,COLORREF,UINT,UINT);
#else
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_LoadImageA(HINSTANCE,LPCSTR,int,int,COLORREF,UINT,UINT);
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_LoadImageW(HINSTANCE,LPCWSTR,int,int,COLORREF,UINT,UINT);
#endif /* _WINCE */
WINCOMMCTRLAPI BOOL WINAPI ImageList_Copy(HIMAGELIST,int,HIMAGELIST,int,UINT);
WINCOMMCTRLAPI BOOL WINAPI ImageList_BeginDrag(HIMAGELIST,int,int,int);
WINCOMMCTRLAPI void WINAPI ImageList_EndDrag(void);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DragEnter(HWND,int,int);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DragLeave(HWND);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DragMove(int,int);
WINCOMMCTRLAPI BOOL WINAPI ImageList_SetDragCursorImage(HIMAGELIST,int,int,int);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DragShowNolock(BOOL);
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_GetDragImage(POINT*,POINT*);
#ifdef __IStream_INTERFACE_DEFINED__
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_Read(LPSTREAM);
WINCOMMCTRLAPI BOOL WINAPI ImageList_Write(HIMAGELIST,LPSTREAM);
#if (_WIN32_WINNT >= 0x0501)
WINCOMMCTRLAPI HRESULT WINAPI ImageList_ReadEx(DWORD,LPSTREAM,REFIID,PVOID*);
WINCOMMCTRLAPI HRESULT WINAPI ImageList_WriteEx(HIMAGELIST,DWORD,LPSTREAM);
#endif
#endif
WINCOMMCTRLAPI BOOL WINAPI ImageList_GetIconSize(HIMAGELIST,int*,int*);
WINCOMMCTRLAPI BOOL WINAPI ImageList_SetIconSize(HIMAGELIST,int,int);
WINCOMMCTRLAPI BOOL WINAPI ImageList_GetImageInfo(HIMAGELIST,int,IMAGEINFO*);
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_Merge(HIMAGELIST,int,HIMAGELIST,int,int,int);
#if (_WIN32_IE >= 0x0400)
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_Duplicate(HIMAGELIST);
#endif

#define ImageList_AddIcon(himl,hicon)  ImageList_ReplaceIcon(himl,-1,hicon)
#define ImageList_RemoveAll(himl)  ImageList_Remove(himl,-1)
#define ImageList_ExtractIcon(hi,himl,i)  ImageList_GetIcon(himl,i,0)
#define ImageList_LoadBitmap(hi,lpbmp,cx,cGrow,crMask)  ImageList_LoadImage(hi,lpbmp,cx,cGrow,crMask,IMAGE_BITMAP,0)

#ifdef UNICODE
#define ImageList_LoadImage ImageList_LoadImageW
#else
#define ImageList_LoadImage ImageList_LoadImageA
#endif

#endif /* NOIMAGEAPIS */

/* Header Control ***********************************************************/

#ifndef NOHEADER

#define WC_HEADERA  "SysHeader32"
#define WC_HEADERW  L"SysHeader32"

#ifdef UNICODE
#define WC_HEADER  WC_HEADERW
#else
#define WC_HEADER  WC_HEADERA
#endif

#define HDS_HORZ  0x0000
#define HDS_BUTTONS  0x0002
#define HDS_HOTTRACK  0x0004
#define HDS_HIDDEN  0x0008

#define HDS_DRAGDROP  0x0040
#define HDS_FULLDRAG  0x0080
#if (_WIN32_IE >= 0x0500)
#define HDS_FILTERBAR  0x0100
#endif
#if (_WIN32_WINNT >= 0x501)
#define HDS_FLAT  0x0200
#endif

#if (_WIN32_IE >= 0x0500)
#define HDFT_ISSTRING  0x0000
#define HDFT_ISNUMBER  0x0001
#define HDFT_HASNOVALUE  0x8000
#endif

#define HDI_WIDTH  0x0001
#define HDI_HEIGHT  HDI_WIDTH
#define HDI_TEXT  0x0002
#define HDI_FORMAT  0x0004
#define HDI_LPARAM  0x0008
#define HDI_BITMAP  0x0010
#define HDI_IMAGE  0x0020
#define HDI_DI_SETITEM  0x0040
#define HDI_ORDER  0x0080
#if (_WIN32_IE >= 0x0500)
#define HDI_FILTER  0x0100
#endif

#define HDF_LEFT  0
#define HDF_RIGHT  1
#define HDF_CENTER  2
#define HDF_JUSTIFYMASK  0x0003
#define HDF_RTLREADING  4

#define HDF_OWNERDRAW  0x8000
#define HDF_STRING  0x4000
#define HDF_BITMAP  0x2000
#define HDF_BITMAP_ON_RIGHT 0x1000
#define HDF_IMAGE  0x0800
#if (_WIN32_WINNT >= 0x501)
#define HDF_SORTUP  0x0400
#define HDF_SORTDOWN  0x0200
#endif

#define HHT_NOWHERE  0x0001
#define HHT_ONHEADER  0x0002
#define HHT_ONDIVIDER  0x0004
#define HHT_ONDIVOPEN  0x0008
#if (_WIN32_IE >= 0x0500)
#define HHT_ONFILTER  0x0010
#define HHT_ONFILTERBUTTON  0x0020
#endif
#define HHT_ABOVE  0x0100
#define HHT_BELOW  0x0200
#define HHT_TORIGHT  0x0400
#define HHT_TOLEFT  0x0800

#define HDM_GETITEMCOUNT  (HDM_FIRST+0)
#define HDM_INSERTITEMA  (HDM_FIRST+1)
#define HDM_INSERTITEMW  (HDM_FIRST+10)
#define HDM_DELETEITEM  (HDM_FIRST+2)
#define HDM_GETITEMA  (HDM_FIRST+3)
#define HDM_GETITEMW  (HDM_FIRST+11)
#define HDM_SETITEMA  (HDM_FIRST+4)
#define HDM_SETITEMW  (HDM_FIRST+12)
#define HDM_LAYOUT  (HDM_FIRST+5)
#define HDM_HITTEST  (HDM_FIRST+6)
#define HDM_GETITEMRECT  (HDM_FIRST+7)
#define HDM_SETIMAGELIST  (HDM_FIRST+8)
#define HDM_GETIMAGELIST  (HDM_FIRST+9)
#define HDM_ORDERTOINDEX  (HDM_FIRST+15)
#define HDM_CREATEDRAGIMAGE  (HDM_FIRST+16)
#define HDM_GETORDERARRAY  (HDM_FIRST+17)
#define HDM_SETORDERARRAY  (HDM_FIRST+18)
#define HDM_SETHOTDIVIDER  (HDM_FIRST+19)
#if (_WIN32_IE >= 0x0500)
#define HDM_SETBITMAPMARGIN  (HDM_FIRST+20)
#define HDM_GETBITMAPMARGIN  (HDM_FIRST+21)
#define HDM_SETFILTERCHANGETIMEOUT (HDM_FIRST+22)
#define HDM_EDITFILTER  (HDM_FIRST+23)
#define HDM_CLEARFILTER  (HDM_FIRST+24)
#endif
#if (_WIN32_IE >= 0x0400)
#define HDM_SETUNICODEFORMAT  CCM_SETUNICODEFORMAT
#define HDM_GETUNICODEFORMAT  CCM_GETUNICODEFORMAT
#endif

#define HDN_ITEMCHANGINGA  (HDN_FIRST-0)
#define HDN_ITEMCHANGINGW  (HDN_FIRST-20)
#define HDN_ITEMCHANGEDA  (HDN_FIRST-1)
#define HDN_ITEMCHANGEDW  (HDN_FIRST-21)
#define HDN_ITEMCLICKA  (HDN_FIRST-2)
#define HDN_ITEMCLICKW  (HDN_FIRST-22)
#define HDN_ITEMDBLCLICKA  (HDN_FIRST-3)
#define HDN_ITEMDBLCLICKW  (HDN_FIRST-23)
#define HDN_DIVIDERDBLCLICKA  (HDN_FIRST-5)
#define HDN_DIVIDERDBLCLICKW  (HDN_FIRST-25)
#define HDN_BEGINTRACKA  (HDN_FIRST-6)
#define HDN_BEGINTRACKW  (HDN_FIRST-26)
#define HDN_ENDTRACKA  (HDN_FIRST-7)
#define HDN_ENDTRACKW  (HDN_FIRST-27)
#define HDN_TRACKA  (HDN_FIRST-8)
#define HDN_TRACKW  (HDN_FIRST-28)
#define HDN_GETDISPINFOA  (HDN_FIRST-9)
#define HDN_GETDISPINFOW  (HDN_FIRST-29)
#define HDN_BEGINDRAG  (HDN_FIRST-10)
#define HDN_ENDDRAG  (HDN_FIRST-11)
#if (_WIN32_IE >= 0x0500)
#define HDN_FILTERCHANGE  (HDN_FIRST-12)
#define HDN_FILTERBTNCLICK  (HDN_FIRST-13)
#endif

#define HD_ITEMA HDITEMA
#define HD_ITEMW HDITEMW
#define HD_ITEM HDITEM

#define HDITEMA_V1_SIZE CCSIZEOF_STRUCT(HDITEMA,lParam)
#define HDITEMW_V1_SIZE CCSIZEOF_STRUCT(HDITEMW,lParam)

#define HD_LAYOUT HDLAYOUT
#define HD_HITTESTINFO HDHITTESTINFO

#define HD_NOTIFYA NMHEADERA
#define HD_NOTIFYW NMHEADERW
#define HD_NOTIFY NMHEADER

#if (_WIN32_IE >= 0x0500)
typedef struct _HD_TEXTFILTERA {
    LPSTR pszText;
    INT cchTextMax;
} HD_TEXTFILTERA, *LPHD_TEXTFILTERA;

typedef struct _HD_TEXTFILTERW {
    LPWSTR pszText;
    INT cchTextMax;
} HD_TEXTFILTERW, *LPHD_TEXTFILTERW;
#endif

typedef struct _HD_ITEMA {
    UINT mask;
    int cxy;
    LPSTR pszText;
    HBITMAP hbm;
    int cchTextMax;
    int fmt;
    LPARAM lParam;
    int iImage;
    int iOrder;
#if (_WIN32_IE >= 0x0500)
    UINT type;
    LPVOID pvFilter;
#endif
} HDITEMA, *LPHDITEMA;

typedef struct _HD_ITEMW {
    UINT mask;
    int cxy;
    LPWSTR pszText;
    HBITMAP hbm;
    int cchTextMax;
    int fmt;
    LPARAM lParam;
    int iImage;
    int iOrder;
#if (_WIN32_IE >= 0x0500)
    UINT type;
    LPVOID pvFilter;
#endif
} HDITEMW, *LPHDITEMW;

typedef struct _HD_LAYOUT {
    RECT *prc;
    WINDOWPOS *pwpos;
} HDLAYOUT, *LPHDLAYOUT;

typedef struct _HD_HITTESTINFO {
    POINT pt;
    UINT flags;
    int iItem;
} HDHITTESTINFO, *LPHDHITTESTINFO;

typedef struct tagNMHEADERA {
    NMHDR hdr;
    int iItem;
    int iButton;
    HDITEMA *pitem;
}  NMHEADERA, *LPNMHEADERA;

typedef struct tagNMHEADERW {
    NMHDR hdr;
    int iItem;
    int iButton;
    HDITEMW *pitem;
} NMHEADERW, *LPNMHEADERW;

typedef struct tagNMHDDISPINFOW {
    NMHDR hdr;
    int iItem;
    UINT  mask;
    LPWSTR pszText;
    int cchTextMax;
    int iImage;
    LPARAM lParam;
} NMHDDISPINFOW, *LPNMHDDISPINFOW;

typedef struct tagNMHDDISPINFOA {
    NMHDR hdr;
    int iItem;
    UINT mask;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    LPARAM lParam;
} NMHDDISPINFOA, *LPNMHDDISPINFOA;

#if (_WIN32_IE >= 0x0500)
typedef struct tagNMHDFILTERBTNCLICK {
    NMHDR hdr;
    INT iItem;
    RECT rc;
} NMHDFILTERBTNCLICK, *LPNMHDFILTERBTNCLICK;
#endif

#define Header_GetItemCount(hwndHD)  (int)SNDMSG((hwndHD),HDM_GETITEMCOUNT,0,0L)
#define Header_InsertItem(hwndHD,i,phdi)  (int)SNDMSG((hwndHD),HDM_INSERTITEM,(WPARAM)(int)(i),(LPARAM)(const HD_ITEM*)(phdi))
#define Header_DeleteItem(hwndHD,i)  (BOOL)SNDMSG((hwndHD),HDM_DELETEITEM,(WPARAM)(int)(i),0L)
#define Header_GetItem(hwndHD,i,phdi)  (BOOL)SNDMSG((hwndHD),HDM_GETITEM,(WPARAM)(int)(i),(LPARAM)(HD_ITEM*)(phdi))
#define Header_SetItem(hwndHD,i,phdi)  (BOOL)SNDMSG((hwndHD),HDM_SETITEM,(WPARAM)(int)(i),(LPARAM)(const HD_ITEM*)(phdi))
#define Header_Layout(hwndHD,playout)  (BOOL)SNDMSG((hwndHD),HDM_LAYOUT,0,(LPARAM)(HD_LAYOUT*)(playout))
#define Header_GetItemRect(hwnd,iItem,lprc)  (BOOL)SNDMSG((hwnd),HDM_GETITEMRECT,(WPARAM)(iItem),(LPARAM)(lprc))
#define Header_SetImageList(hwnd,himl)  (HIMAGELIST)SNDMSG((hwnd),HDM_SETIMAGELIST,0,(LPARAM)(himl))
#define Header_GetImageList(hwnd)  (HIMAGELIST)SNDMSG((hwnd),HDM_GETIMAGELIST,0,0)
#define Header_OrderToIndex(hwnd,i)  (int)SNDMSG((hwnd),HDM_ORDERTOINDEX,(WPARAM)(i),0)
#define Header_CreateDragImage(hwnd,i)  (HIMAGELIST)SNDMSG((hwnd),HDM_CREATEDRAGIMAGE,(WPARAM)(i),0)
#define Header_GetOrderArray(hwnd,iCount,lpi)  (BOOL)SNDMSG((hwnd),HDM_GETORDERARRAY,(WPARAM)(iCount),(LPARAM)(lpi))
#define Header_SetOrderArray(hwnd,iCount,lpi)  (BOOL)SNDMSG((hwnd),HDM_SETORDERARRAY,(WPARAM)(iCount),(LPARAM)(lpi))
#define Header_SetHotDivider(hwnd,fPos,dw)  (int)SNDMSG((hwnd),HDM_SETHOTDIVIDER,(WPARAM)(fPos),(LPARAM)(dw))
#if (_WIN32_IE >= 0x0500)
#define Header_SetBitmapMargin(hwnd,iWidth)  (int)SNDMSG((hwnd),HDM_SETBITMAPMARGIN,(WPARAM)(iWidth),0)
#define Header_GetBitmapMargin(hwnd)  (int)SNDMSG((hwnd),HDM_GETBITMAPMARGIN,0,0)
#define Header_SetFilterChangeTimeout(hwnd,i)  (int)SNDMSG((hwnd),HDM_SETFILTERCHANGETIMEOUT,0,(LPARAM)(i))
#define Header_EditFilter(hwnd,i,fDiscardChanges)  (int)SNDMSG((hwnd),HDM_EDITFILTER,(WPARAM)(i),MAKELPARAM(fDiscardChanges,0))
#define Header_ClearFilter(hwnd,i)  (int)SNDMSG((hwnd),HDM_CLEARFILTER,(WPARAM)(i),0)
#define Header_ClearAllFilters(hwnd)  (int)SNDMSG((hwnd),HDM_CLEARFILTER,(WPARAM)-1,0)
#endif
#if (_WIN32_IE >= 0x0400)
#define Header_SetUnicodeFormat(hwnd,fUnicode)  (BOOL)SNDMSG((hwnd),HDM_SETUNICODEFORMAT,(WPARAM)(fUnicode),0)
#define Header_GetUnicodeFormat(hwnd)  (BOOL)SNDMSG((hwnd),HDM_GETUNICODEFORMAT,0,0)
#endif

#ifdef UNICODE
#define HD_TEXTFILTER HD_TEXTFILTERW
#define HDTEXTFILTER HD_TEXTFILTERW
#define LPHD_TEXTFILTER LPHD_TEXTFILTERW
#define LPHDTEXTFILTER LPHD_TEXTFILTERW
#define HDITEM HDITEMW
#define LPHDITEM LPHDITEMW
#define HDITEM_V1_SIZE HDITEMW_V1_SIZE
#define NMHEADER NMHEADERW
#define LPNMHEADER LPNMHEADERW
#define NMHDDISPINFO NMHDDISPINFOW
#define LPNMHDDISPINFO LPNMHDDISPINFOW
#define HDM_INSERTITEM HDM_INSERTITEMW
#define HDM_GETITEM HDM_GETITEMW
#define HDM_SETITEM HDM_SETITEMW
#define HDN_ITEMCHANGING HDN_ITEMCHANGINGW
#define HDN_ITEMCHANGED HDN_ITEMCHANGEDW
#define HDN_ITEMCLICK HDN_ITEMCLICKW
#define HDN_ITEMDBLCLICK HDN_ITEMDBLCLICKW
#define HDN_DIVIDERDBLCLICK HDN_DIVIDERDBLCLICKW
#define HDN_BEGINTRACK HDN_BEGINTRACKW
#define HDN_ENDTRACK HDN_ENDTRACKW
#define HDN_TRACK HDN_TRACKW
#define HDN_GETDISPINFO HDN_GETDISPINFOW
#else
#define HD_TEXTFILTER HD_TEXTFILTERA
#define HDTEXTFILTER HD_TEXTFILTERA
#define LPHD_TEXTFILTER LPHD_TEXTFILTERA
#define LPHDTEXTFILTER LPHD_TEXTFILTERA
#define HDITEM HDITEMA
#define LPHDITEM LPHDITEMA
#define HDITEM_V1_SIZE HDITEMA_V1_SIZE
#define NMHEADER NMHEADERA
#define LPNMHEADER LPNMHEADERA
#define NMHDDISPINFO NMHDDISPINFOA
#define LPNMHDDISPINFO LPNMHDDISPINFOA
#define HDM_INSERTITEM HDM_INSERTITEMA
#define HDM_GETITEM HDM_GETITEMA
#define HDM_SETITEM HDM_SETITEMA
#define HDN_ITEMCHANGING HDN_ITEMCHANGINGA
#define HDN_ITEMCHANGED HDN_ITEMCHANGEDA
#define HDN_ITEMCLICK HDN_ITEMCLICKA
#define HDN_ITEMDBLCLICK HDN_ITEMDBLCLICKA
#define HDN_DIVIDERDBLCLICK HDN_DIVIDERDBLCLICKA
#define HDN_BEGINTRACK HDN_BEGINTRACKA
#define HDN_ENDTRACK HDN_ENDTRACKA
#define HDN_TRACK HDN_TRACKA
#define HDN_GETDISPINFO HDN_GETDISPINFOA
#endif

#endif /* NOHEADER */

/* Toolbar Control **********************************************************/

#ifndef NOTOOLBAR

#define TOOLBARCLASSNAMEW  L"ToolbarWindow32"
#define TOOLBARCLASSNAMEA  "ToolbarWindow32"

#ifdef UNICODE
#define TOOLBARCLASSNAME  TOOLBARCLASSNAMEW
#else
#define TOOLBARCLASSNAME  TOOLBARCLASSNAMEA
#endif

#ifdef _WINCE
#define I_IMAGENONE  (-2)
#endif

#define CMB_MASKED  0x02
#define TBSTATE_CHECKED  0x01
#define TBSTATE_PRESSED  0x02
#define TBSTATE_ENABLED  0x04
#define TBSTATE_HIDDEN  0x08
#define TBSTATE_INDETERMINATE  0x10
#define TBSTATE_WRAP  0x20
#define TBSTATE_ELLIPSES  0x40
#if (_WIN32_IE >= 0x0400)
#define TBSTATE_MARKED  0x80
#define TBSTATE_HIGHLIGHTED  0x80
#endif

#define TBSTYLE_BUTTON  0x0000
#define TBSTYLE_SEP  0x0001
#define TBSTYLE_CHECK  0x0002
#define TBSTYLE_GROUP  0x0004
#define TBSTYLE_CHECKGROUP  (TBSTYLE_GROUP|TBSTYLE_CHECK)
#define TBSTYLE_DROPDOWN  0x0008
#if (_WIN32_IE >= 0x0400)
#define TBSTYLE_AUTOSIZE  0x0010
#define TBSTYLE_NOPREFIX  0x0020
#endif

#define TBSTYLE_TOOLTIPS  0x0100
#define TBSTYLE_WRAPABLE  0x0200
#define TBSTYLE_ALTDRAG  0x0400
#define TBSTYLE_FLAT  0x0800
#define TBSTYLE_LIST  0x1000
#define TBSTYLE_CUSTOMERASE  0x2000
#if (_WIN32_IE >= 0x0400)
#define TBSTYLE_REGISTERDROP  0x4000
#define TBSTYLE_TRANSPARENT  0x8000
#define TBSTYLE_EX_DRAWDDARROWS 0x00000001
#endif

#if (_WIN32_IE >= 0x0500)
#define BTNS_BUTTON  TBSTYLE_BUTTON
#define BTNS_SEP  TBSTYLE_SEP
#define BTNS_CHECK  TBSTYLE_CHECK
#define BTNS_GROUP  TBSTYLE_GROUP
#define BTNS_CHECKGROUP  TBSTYLE_CHECKGROUP
#define BTNS_DROPDOWN  TBSTYLE_DROPDOWN
#define BTNS_AUTOSIZE  TBSTYLE_AUTOSIZE
#define BTNS_NOPREFIX  TBSTYLE_NOPREFIX
#define BTNS_WHOLEDROPDOWN  0x0080
#endif
#if (_WIN32_IE >= 0x0501)
#define BTNS_SHOWTEXT  0x0040
#endif

#if (_WIN32_IE >= 0x0501)
#define TBSTYLE_EX_MIXEDBUTTONS  0x00000008
#define TBSTYLE_EX_HIDECLIPPEDBUTTONS  0x00000010
#endif
#if (_WIN32_WINNT >= 0x501)
#define TBSTYLE_EX_DOUBLEBUFFER  0x00000080
#endif

#if (_WIN32_IE >= 0x0400)
#define TBCDRF_NOEDGES  0x00010000
#define TBCDRF_HILITEHOTTRACK  0x00020000
#define TBCDRF_NOOFFSET  0x00040000
#define TBCDRF_NOMARK  0x00080000
#define TBCDRF_NOETCHEDEFFECT  0x00100000
#endif
#if (_WIN32_IE >= 0x0500)
#define TBCDRF_BLENDICON  0x00200000
#endif

#if (_WIN32_IE >= 0x0400)
#define TBIMHT_AFTER  0x00000001
#define TBIMHT_BACKGROUND  0x00000002
#endif

#if (_WIN32_IE >= 0x0400)
#define TBIF_IMAGE  0x00000001
#define TBIF_TEXT  0x00000002
#define TBIF_STATE  0x00000004
#define TBIF_STYLE  0x00000008
#define TBIF_LPARAM  0x00000010
#define TBIF_COMMAND  0x00000020
#define TBIF_SIZE  0x00000040
#endif

#if (_WIN32_IE >= 0x0500)
#define TBIF_BYINDEX  0x80000000
#endif

#define TBBF_LARGE  0x0001

#if (_WIN32_IE >= 0x0500)
#define TBNRF_HIDEHELP  0x00000001
#define TBNRF_ENDCUSTOMIZE  0x00000002
#endif

#if (_WIN32_IE >= 0x0400)
#define TBNF_IMAGE  0x00000001
#define TBNF_TEXT  0x00000002
#define TBNF_DI_SETITEM  0x10000000
#endif

#if (_WIN32_IE >= 0x0400)
#define TBDDRET_DEFAULT  0
#define TBDDRET_NODEFAULT  1
#define TBDDRET_TREATPRESSED  2
#endif

#if (_WIN32_IE >= 0x0400)
#define HICF_OTHER  0x00000000
#define HICF_MOUSE  0x00000001
#define HICF_ARROWKEYS  0x00000002
#define HICF_ACCELERATOR  0x00000004
#define HICF_DUPACCEL  0x00000008
#define HICF_ENTERING  0x00000010
#define HICF_LEAVING  0x00000020
#define HICF_RESELECT  0x00000040
#define HICF_LMOUSE  0x00000080
#define HICF_TOGGLEDROPDOWN  0x00000100
#endif

#define TB_ENABLEBUTTON  (WM_USER+1)
#define TB_CHECKBUTTON  (WM_USER+2)
#define TB_PRESSBUTTON  (WM_USER+3)
#define TB_HIDEBUTTON  (WM_USER+4)
#define TB_INDETERMINATE  (WM_USER+5)
#if (_WIN32_IE >= 0x0400)
#define TB_MARKBUTTON  (WM_USER+6)
#endif
#define TB_ISBUTTONENABLED  (WM_USER+9)
#define TB_ISBUTTONCHECKED  (WM_USER+10)
#define TB_ISBUTTONPRESSED  (WM_USER+11)
#define TB_ISBUTTONHIDDEN  (WM_USER+12)
#define TB_ISBUTTONINDETERMINATE  (WM_USER+13)
#if (_WIN32_IE >= 0x0400)
#define TB_ISBUTTONHIGHLIGHTED  (WM_USER+14)
#endif
#define TB_SETSTATE  (WM_USER+17)
#define TB_GETSTATE  (WM_USER+18)
#define TB_ADDBITMAP  (WM_USER+19)
#if (_WIN32_IE >= 0x0400)
#define TB_ADDBUTTONSA  (WM_USER+20)
#define TB_INSERTBUTTONA  (WM_USER+21)
#else
#define TB_ADDBUTTONS  (WM_USER+20)
#define TB_INSERTBUTTON  (WM_USER+21)
#endif
#define TB_DELETEBUTTON  (WM_USER+22)
#define TB_GETBUTTON  (WM_USER+23)
#define TB_BUTTONCOUNT  (WM_USER+24)
#define TB_COMMANDTOINDEX  (WM_USER+25)
#define TB_SAVERESTOREA  (WM_USER+26)
#define TB_SAVERESTOREW  (WM_USER+76)
#define TB_CUSTOMIZE  (WM_USER+27)
#define TB_ADDSTRINGA  (WM_USER+28)
#define TB_ADDSTRINGW  (WM_USER+77)
#define TB_GETITEMRECT  (WM_USER+29)
#define TB_BUTTONSTRUCTSIZE  (WM_USER+30)
#define TB_SETBUTTONSIZE  (WM_USER+31)
#define TB_SETBITMAPSIZE  (WM_USER+32)
#define TB_AUTOSIZE  (WM_USER+33)
#define TB_GETTOOLTIPS  (WM_USER+35)
#ifdef _WINCE
#define TB_SETTOOLTIPS  (WM_USER+81)
#else
#define TB_SETTOOLTIPS  (WM_USER+36)
#endif /* _WINCE */
#define TB_SETPARENT  (WM_USER+37)
#define TB_SETROWS  (WM_USER+39)
#define TB_GETROWS  (WM_USER+40)
#define TB_GETBITMAPFLAGS  (WM_USER+41)
#define TB_SETCMDID  (WM_USER+42)
#define TB_CHANGEBITMAP  (WM_USER+43)
#define TB_GETBITMAP  (WM_USER+44)
#define TB_GETBUTTONTEXTA  (WM_USER+45)
#define TB_GETBUTTONTEXTW  (WM_USER+75)
#define TB_REPLACEBITMAP  (WM_USER+46)
#define TB_SETINDENT  (WM_USER+47)
#define TB_SETIMAGELIST  (WM_USER+48)
#define TB_GETIMAGELIST  (WM_USER+49)
#define TB_LOADIMAGES  (WM_USER+50)
#define TB_GETRECT  (WM_USER+51)
#define TB_SETHOTIMAGELIST  (WM_USER+52)
#define TB_GETHOTIMAGELIST  (WM_USER+53)
#define TB_SETDISABLEDIMAGELIST  (WM_USER+54)
#define TB_GETDISABLEDIMAGELIST  (WM_USER+55)
#define TB_SETSTYLE  (WM_USER+56)
#define TB_GETSTYLE  (WM_USER+57)
#define TB_GETBUTTONSIZE  (WM_USER+58)
#define TB_SETBUTTONWIDTH  (WM_USER+59)
#define TB_SETMAXTEXTROWS  (WM_USER+60)
#define TB_GETTEXTROWS  (WM_USER+61)
#if (_WIN32_IE >= 0x0400)
#define TB_GETOBJECT  (WM_USER+62)
#define TB_GETBUTTONINFOW  (WM_USER+63)
#define TB_SETBUTTONINFOW  (WM_USER+64)
#define TB_GETBUTTONINFOA  (WM_USER+65)
#define TB_SETBUTTONINFOA  (WM_USER+66)
#define TB_INSERTBUTTONW  (WM_USER+67)
#define TB_ADDBUTTONSW  (WM_USER+68)
#define TB_HITTEST  (WM_USER+69)
#define TB_SETDRAWTEXTFLAGS  (WM_USER+70)
#define TB_GETHOTITEM  (WM_USER+71)
#define TB_SETHOTITEM  (WM_USER+72)
#define TB_SETANCHORHIGHLIGHT  (WM_USER+73)
#define TB_GETANCHORHIGHLIGHT  (WM_USER+74)
#define TB_MAPACCELERATORA  (WM_USER+78)
#define TB_GETINSERTMARK  (WM_USER+79)
#define TB_SETINSERTMARK  (WM_USER+80)
#define TB_INSERTMARKHITTEST  (WM_USER+81)
#define TB_MOVEBUTTON  (WM_USER+82)
#define TB_GETMAXSIZE  (WM_USER+83)
#define TB_SETEXTENDEDSTYLE  (WM_USER+84)
#define TB_GETEXTENDEDSTYLE  (WM_USER+85)
#define TB_GETPADDING  (WM_USER+86)
#define TB_SETPADDING  (WM_USER+87)
#define TB_SETINSERTMARKCOLOR  (WM_USER+88)
#define TB_GETINSERTMARKCOLOR  (WM_USER+89)
#define TB_SETCOLORSCHEME  CCM_SETCOLORSCHEME
#define TB_GETCOLORSCHEME  CCM_GETCOLORSCHEME
#define TB_SETUNICODEFORMAT  CCM_SETUNICODEFORMAT
#define TB_GETUNICODEFORMAT  CCM_GETUNICODEFORMAT
#define TB_MAPACCELERATORW  (WM_USER+90)
#endif
#if (_WIN32_IE >= 0x0500)
#define TB_GETSTRINGW  (WM_USER+91)
#define TB_GETSTRINGA  (WM_USER+92)
#endif
#if (_WIN32_WINNT >= 0x501)
#define TB_GETMETRICS  (WM_USER+101)
#define TB_SETMETRICS  (WM_USER+102)
#define TB_SETWINDOWTHEME  CCM_SETWINDOWTHEME
#endif

#define TBN_GETBUTTONINFOA  (TBN_FIRST-0)
#define TBN_BEGINDRAG  (TBN_FIRST-1)
#define TBN_ENDDRAG  (TBN_FIRST-2)
#define TBN_BEGINADJUST  (TBN_FIRST-3)
#define TBN_ENDADJUST  (TBN_FIRST-4)
#define TBN_RESET  (TBN_FIRST-5)
#define TBN_QUERYINSERT  (TBN_FIRST-6)
#define TBN_QUERYDELETE  (TBN_FIRST-7)
#define TBN_TOOLBARCHANGE  (TBN_FIRST-8)
#define TBN_CUSTHELP  (TBN_FIRST-9)
#define TBN_DROPDOWN  (TBN_FIRST-10)
#if (_WIN32_IE >= 0x0400)
#define TBN_GETOBJECT  (TBN_FIRST-12)
#define TBN_HOTITEMCHANGE  (TBN_FIRST-13)
#define TBN_DRAGOUT  (TBN_FIRST-14)
#define TBN_DELETINGBUTTON  (TBN_FIRST-15)
#define TBN_GETDISPINFOA  (TBN_FIRST-16)
#define TBN_GETDISPINFOW  (TBN_FIRST-17)
#define TBN_GETINFOTIPA  (TBN_FIRST-18)
#define TBN_GETINFOTIPW  (TBN_FIRST-19)
#define TBN_GETBUTTONINFOW  (TBN_FIRST-20)
#endif
#if (_WIN32_IE >= 0x0500)
#define TBN_RESTORE  (TBN_FIRST-21)
#define TBN_SAVE  (TBN_FIRST-22)
#define TBN_INITCUSTOMIZE  (TBN_FIRST-23)
#endif

#if (_WIN32_WINNT >= 0x501)
#define TBMF_PAD  0x00000001
#define TBMF_BARPAD  0x00000002
#define TBMF_BUTTONSPACING  0x00000004
#endif

#define HINST_COMMCTRL  ((HINSTANCE)-1)
#define IDB_STD_SMALL_COLOR  0
#define IDB_STD_LARGE_COLOR  1
#define IDB_VIEW_SMALL_COLOR  4
#define IDB_VIEW_LARGE_COLOR  5
#define IDB_HIST_SMALL_COLOR  8
#define IDB_HIST_LARGE_COLOR  9

#define STD_CUT  0
#define STD_COPY  1
#define STD_PASTE  2
#define STD_UNDO  3
#define STD_REDOW  4
#define STD_DELETE  5
#define STD_FILENEW  6
#define STD_FILEOPEN  7
#define STD_FILESAVE  8
#define STD_PRINTPRE  9
#define STD_PROPERTIES  10
#define STD_HELP  11
#define STD_FIND  12
#define STD_REPLACE  13
#define STD_PRINT  14

#define VIEW_LARGEICONS  0
#define VIEW_SMALLICONS  1
#define VIEW_LIST  2
#define VIEW_DETAILS  3
#define VIEW_SORTNAME  4
#define VIEW_SORTSIZE  5
#define VIEW_SORTDATE  6
#define VIEW_SORTTYPE  7
#define VIEW_PARENTFOLDER  8
#define VIEW_NETCONNECT  9
#define VIEW_NETDISCONNECT  10
#define VIEW_NEWFOLDER  11
#if (_WIN32_IE >= 0x0400)
#define VIEW_VIEWMENU  12
#endif

#define HIST_BACK  0
#define HIST_FORWARD  1
#define HIST_FAVORITES  2
#define HIST_ADDTOFAVORITES  3
#define HIST_VIEWTREE  4

#define TBNOTIFYA NMTOOLBARA
#define TBNOTIFYW NMTOOLBARW
#define LPTBNOTIFYA LPNMTOOLBARA
#define LPTBNOTIFYW LPNMTOOLBARW
#define TBNOTIFY NMTOOLBAR
#define LPTBNOTIFY LPNMTOOLBAR

typedef struct _TBBUTTON {
    int iBitmap;
    int idCommand;
    BYTE fsState;
    BYTE fsStyle;
#if defined(_WIN64)
    BYTE bReserved[6];
#else
    BYTE bReserved[2];
#endif
    DWORD_PTR dwData;
    INT_PTR iString;
} TBBUTTON, *PTBBUTTON, *LPTBBUTTON;
typedef const TBBUTTON *LPCTBBUTTON;

typedef struct _COLORMAP {
    COLORREF from;
    COLORREF to;
} COLORMAP, *LPCOLORMAP;

#if (_WIN32_IE >= 0x0400)
typedef struct _NMTBCUSTOMDRAW {
    NMCUSTOMDRAW nmcd;
    HBRUSH hbrMonoDither;
    HBRUSH hbrLines;
    HPEN hpenLines;
    COLORREF clrText;
    COLORREF clrMark;
    COLORREF clrTextHighlight;
    COLORREF clrBtnFace;
    COLORREF clrBtnHighlight;
    COLORREF clrHighlightHotTrack;
    RECT rcText;
    int nStringBkMode;
    int nHLStringBkMode;
#if (_WIN32_WINNT >= 0x501)
    int iListGap;
#endif
} NMTBCUSTOMDRAW, *LPNMTBCUSTOMDRAW;
#endif

typedef struct tagTBADDBITMAP {
    HINSTANCE hInst;
    UINT_PTR nID;
} TBADDBITMAP, *LPTBADDBITMAP;

typedef struct tagTBSAVEPARAMSA {
    HKEY hkr;
    LPCSTR pszSubKey;
    LPCSTR pszValueName;
} TBSAVEPARAMSA, *LPTBSAVEPARAMSA;

typedef struct tagTBSAVEPARAMSW {
    HKEY hkr;
    LPCWSTR pszSubKey;
    LPCWSTR pszValueName;
} TBSAVEPARAMSW, *LPTBSAVEPARAMW;

#if (_WIN32_IE >= 0x0400)
typedef struct {
    int iButton;
    DWORD dwFlags;
} TBINSERTMARK, *LPTBINSERTMARK;
#endif

typedef struct {
    HINSTANCE hInstOld;
    UINT_PTR nIDOld;
    HINSTANCE hInstNew;
    UINT_PTR nIDNew;
    int nButtons;
} TBREPLACEBITMAP, *LPTBREPLACEBITMAP;

#if (_WIN32_IE >= 0x0400)
typedef struct {
    UINT cbSize;
    DWORD dwMask;
    int idCommand;
    int iImage;
    BYTE fsState;
    BYTE fsStyle;
    WORD cx;
    DWORD_PTR lParam;
    LPSTR pszText;
    int cchText;
} TBBUTTONINFOA, *LPTBBUTTONINFOA;

typedef struct {
    UINT cbSize;
    DWORD dwMask;
    int idCommand;
    int iImage;
    BYTE fsState;
    BYTE fsStyle;
    WORD cx;
    DWORD_PTR lParam;
    LPWSTR pszText;
    int cchText;
} TBBUTTONINFOW, *LPTBBUTTONINFOW;
#endif

#if (_WIN32_IE >= 0x0500)
typedef struct tagNMTBSAVE {
    NMHDR hdr;
    DWORD *pData;
    DWORD *pCurrent;
    UINT cbData;
    int iItem;
    int cButtons;
    TBBUTTON tbButton;
} NMTBSAVE, *LPNMTBSAVE;
#endif

#if (_WIN32_IE >= 0x0500)
typedef struct tagNMTBRESTORE {
    NMHDR hdr;
    DWORD *pData;
    DWORD *pCurrent;
    UINT cbData;
    int iItem;
    int cButtons;
    int cbBytesPerRecord;
    TBBUTTON tbButton;
} NMTBRESTORE, *LPNMTBRESTORE;
#endif

#if (_WIN32_IE >= 0x0400)
typedef struct tagNMTBHOTITEM {
    NMHDR hdr;
    int idOld;
    int idNew;
    DWORD dwFlags;
} NMTBHOTITEM, *LPNMTBHOTITEM;
#endif

#if (_WIN32_IE >= 0x0400)
typedef struct tagNMTBGETINFOTIPA {
    NMHDR hdr;
    LPSTR pszText;
    int cchTextMax;
    int iItem;
    LPARAM lParam;
} NMTBGETINFOTIPA, *LPNMTBGETINFOTIPA;

typedef struct tagNMTBGETINFOTIPW {
    NMHDR hdr;
    LPWSTR pszText;
    int cchTextMax;
    int iItem;
    LPARAM lParam;
} NMTBGETINFOTIPW, *LPNMTBGETINFOTIPW;
#endif

#if (_WIN32_IE >= 0x0400)
typedef struct {
    NMHDR  hdr;
    DWORD dwMask;
    int idCommand;
    DWORD_PTR lParam;
    int iImage;
    LPSTR pszText;
    int cchText;
} NMTBDISPINFOA, *LPNMTBDISPINFOA;

typedef struct {
    NMHDR hdr;
    DWORD dwMask;
    int idCommand;
    DWORD_PTR lParam;
    int iImage;
    LPWSTR pszText;
    int cchText;
} NMTBDISPINFOW, *LPNMTBDISPINFOW;
#endif

typedef struct tagNMTOOLBARA {
    NMHDR hdr;
    int iItem;
    TBBUTTON tbButton;
    int cchText;
    LPSTR pszText;
#if (_WIN32_IE >= 0x500)
    RECT rcButton;
#endif
} NMTOOLBARA, *LPNMTOOLBARA;


typedef struct tagNMTOOLBARW {
    NMHDR hdr;
    int iItem;
    TBBUTTON tbButton;
    int cchText;
    LPWSTR pszText;
#if (_WIN32_IE >= 0x500)
    RECT rcButton;
#endif
} NMTOOLBARW, *LPNMTOOLBARW;

#if (_WIN32_WINNT >= 0x501)
typedef struct {
    UINT cbSize;
    DWORD dwMask;
    int cxPad;
    int cyPad;
    int cxBarPad;
    int cyBarPad;
    int cxButtonSpacing;
    int cyButtonSpacing;
} TBMETRICS, *LPTBMETRICS;
#endif

WINCOMMCTRLAPI HWND WINAPI CreateToolbarEx(HWND,DWORD,UINT,int,HINSTANCE,UINT_PTR,LPCTBBUTTON,int,int,int,int,int,UINT);
WINCOMMCTRLAPI HBITMAP WINAPI CreateMappedBitmap(HINSTANCE,INT_PTR,UINT,LPCOLORMAP,int);

/* added by Pelles C development team 2000-09-08 */
#define ToolBar_EnableButton(hwnd,idButton,fEnable)  (BOOL)SNDMSG((hwnd),TB_ENABLEBUTTON,(WPARAM)(idButton),(LPARAM)MAKELONG(fEnable,0))
#define ToolBar_CheckButton(hwnd,idButton,fCheck)  (BOOL)SNDMSG((hwnd),TB_CHECKBUTTON,(WPARAM)(idButton),(LPARAM)MAKELONG(fCheck,0))
#define ToolBar_PressButton(hwnd,idButton,fPress)  (BOOL)SNDMSG((hwnd),TB_PRESSBUTTON,(WPARAM)(idButton),(LPARAM)MAKELONG(fPress,0))
#define ToolBar_HideButton(hwnd,idButton,fShow)  (BOOL)SNDMSG((hwnd),TB_HIDEBUTTON,(WPARAM)(idButton),(LPARAM)MAKELONG(fShow,0))
#define ToolBar_Indeterminate(hwnd,idButton,fIndeterminate)  (BOOL)SNDMSG((hwnd),TB_INDETERMINATE,(WPARAM)(idButton),(LPARAM)MAKELONG(fIndeterminate,0))
#if (_WIN32_IE >= 0x0400)
#define ToolBar_MarkButton(hwnd,idButton,fHighlight)  (BOOL)SNDMSG((hwnd),TB_MARKBUTTON,(WPARAM)(idButton),(LPARAM)MAKELONG(fHighlight,0))
#endif
#define ToolBar_IsButtonEnabled(hwnd,idButton)  (int)SNDMSG((hwnd),TB_ISBUTTONENABLED,(WPARAM)(idButton),0)
#define ToolBar_IsButtonChecked(hwnd,idButton)  (int)SNDMSG((hwnd),TB_ISBUTTONCHECKED,(WPARAM)(idButton),0)
#define ToolBar_IsButtonPressed(hwnd,idButton)  (int)SNDMSG((hwnd),TB_ISBUTTONPRESSED,(WPARAM)(idButton),0)
#define ToolBar_IsButtonHidden(hwnd,idButton)  (int)SNDMSG((hwnd),TB_ISBUTTONHIDDEN,(WPARAM)(idButton),0)
#define ToolBar_IsButtonIndeterminate(hwnd,idButton)  (int)SNDMSG((hwnd),TB_ISBUTTONINDETERMINATE,(WPARAM)(idButton),0)
#if (_WIN32_IE >= 0x0400)
#define ToolBar_IsButtonHighlighted(hwnd,idButton)  (int)SNDMSG((hwnd),TB_ISBUTTONHIGHLIGHTED,(WPARAM)(idButton),0)
#endif
#define ToolBar_SetState(hwnd,idButton,fState)  (BOOL)SNDMSG((hwnd),TB_SETSTATE,(WPARAM)(idButton),(LPARAM)MAKELONG(fState,0))
#define ToolBar_GetState(hwnd,idButton)  (int)SNDMSG((hwnd),TB_GETSTATE,(WPARAM)(idButton),0)
#define ToolBar_AddBitmap(hwnd,nButtons,lptbab)  (int)SNDMSG((hwnd),TB_ADDBITMAP,(WPARAM)(nButtons),(LPARAM)(LPTBADDBITMAP)(lptbab))
#define ToolBar_AddButtons(hwnd,uNumButtons,lpButtons)  (BOOL)SNDMSG((hwnd),TB_ADDBUTTONS,(WPARAM)(UINT)(uNumButtons),(LPARAM)(LPTBBUTTON)(lpButtons))
#define ToolBar_InsertButton(hwnd,idButton,lpButton)  (BOOL)SNDMSG((hwnd),TB_INSERTBUTTON,(WPARAM)(idButton),(LPARAM)(LPTBBUTTON)(lpButton))
#define ToolBar_DeleteButton(hwnd,idButton)  (BOOL)SNDMSG((hwnd),TB_DELETEBUTTON,(WPARAM)(idButton),0)
#define ToolBar_GetButton(hwnd,idButton,lpButton)  (BOOL)SNDMSG((hwnd),TB_GETBUTTON,(WPARAM)(idButton),(LPARAM)(LPTBBUTTON)(lpButton))
#define ToolBar_ButtonCount(hwnd)  (int)SNDMSG((hwnd),TB_BUTTONCOUNT,0,0)
#define ToolBar_CommandToIndex(hwnd,idButton)  (int)SNDMSG((hwnd),TB_COMMANDTOINDEX,(WPARAM)(idButton),0)
#define ToolBar_SaveRestore(hwnd,fSave,ptbsp)  (void)SNDMSG((hwnd),TB_SAVERESTORE,(WPARAM)(BOOL)(fSave),(LPARAM)(TBSAVEPARAMS *)(ptbsp))
#define ToolBar_Customize(hwnd)  (void)SNDMSG((hwnd),TB_CUSTOMIZE,0,0)
#define ToolBar_AddString(hwnd,hinst,idString)  (int)SNDMSG((hwnd),TB_ADDSTRING,(WPARAM)(HINSTANCE)(hinst),(LPARAM)(idString))
#define ToolBar_GetItemRect(hwnd,idButton,lprc)  (BOOL)SNDMSG((hwnd),TB_GETITEMRECT,(WPARAM)(idButton),(LPARAM)(LPRECT)(lprc))
#define ToolBar_ButtonStructSize(hwnd)  (void)SNDMSG((hwnd),TB_BUTTONSTRUCTSIZE,(WPARAM)sizeof(TBBUTTON),0)
#define ToolBar_SetButtonSize(hwnd,dxButton,dyButton)  (BOOL)SNDMSG((hwnd),TB_SETBUTTONSIZE,0,(LPARAM)MAKELONG((dxButton),(dyButton)))
#define ToolBar_SetBitmapSize(hwnd,dxBitmap,dyBitmap)  (BOOL)SNDMSG((hwnd),TB_SETBITMAPSIZE,0,(LPARAM)MAKELONG((dxBitmap),(dyBitmap)))
#define ToolBar_AutoSize(hwnd)  (void)SNDMSG((hwnd),TB_AUTOSIZE,0,0)
#define ToolBar_GetToolTips(hwnd)  (HWND)SNDMSG((hwnd),TB_GETTOOLTIPS,0,0)
#define ToolBar_SetToolTips(hwnd,hwndToolTip)  (void)SNDMSG((hwnd),TB_SETTOOLTIPS,(WPARAM)(HWND)(hwndToolTip),0)
#define ToolBar_SetParent(hwnd,hwndParent)  (void)SNDMSG((hwnd),TB_SETPARENT,(WPARAM)(HWND)(hwndParent),0)
#define ToolBar_SetRows(hwnd,cRows,fLarger,lprc)  (void)SNDMSG((hwnd),TB_SETROWS,MAKEWPARAM((cRows),(fLarger)),(LPARAM)(LPRECT)(lprc))
#define ToolBar_GetRows(hwnd)  (int)SNDMSG((hwnd),TB_GETROWS,0,0)
#define ToolBar_GetBitmapFlags(hwnd)  (int)SNDMSG((hwnd),TB_GETBITMAPFLAGS,0,0)
#define ToolBar_SetCmdID(hwnd,index,cmdId)  (BOOL)SNDMSG((hwnd),TB_SETCMDID,(WPARAM)(UINT)(index),(WPARAM)(UINT)(cmdId))
#define ToolBar_ChangeBitmap(hwnd,idButton,iBitmap)  (BOOL)SNDMSG((hwnd),TB_CHANGEBITMAP,(WPARAM)(idButton),(LPARAM)(iBitmap));
#define ToolBar_GetBitmap(hwnd,idButton)  (int)SNDMSG((hwnd),TB_GETBITMAP,(WPARAM)(idButton),0)
#define ToolBar_GetButtonText(hwnd,idButton,lpszText)  (int)SNDMSG((hwnd),TB_GETBUTTONTEXT,(WPARAM)(idButton),(LPARAM)(LPSTR)(lpszText))
#define ToolBar_ReplaceBitmap(hwnd,ptbrb)  (BOOL)SNDMSG((hwnd),TB_REPLACEBITMAP,0,(LPARAM)(LPTBREPLACEBITMAP)(ptbrb))
#define ToolBar_SetIndent(hwnd,iIndent)  (BOOL)SNDMSG((hwnd),TB_SETINDENT,(WPARAM)(iIndent),0)
#define ToolBar_SetImageList(hwnd,himlNew)  (HIMAGELIST)(DWORD)SNDMSG((hwnd),TB_SETIMAGELIST,0,(LPARAM)(HIMAGELIST)(himlNew))
#define ToolBar_GetImageList(hwnd)  (HIMAGELIST)(DWORD)SNDMSG((hwnd),TB_GETIMAGELIST,0,0)
#define ToolBar_LoadImages(hwnd,iBitmapID,hinst)  (int)SNDMSG((hwnd),TB_LOADIMAGES,(WPARAM)(iBitmapID),(LPARAM)(HINSTANCE)(hinst))
#define ToolBar_GetRect(hwnd,idButton,lprc)  (BOOL)SNDMSG((hwnd),TB_GETRECT,(WPARAM)(idButton),(LPARAM)(LPRECT)(lprc))
#define ToolBar_SetHotImageList(hwnd,himlNewHot)  (HIMAGELIST)(DWORD)SNDMSG((hwnd),TB_SETHOTIMAGELIST,0,(LPARAM)(HIMAGELIST)(himlNewHot))
#define ToolBar_GetHotImageList(hwnd)  (HIMAGELIST)(DWORD)SNDMSG((hwnd),TB_GETHOTIMAGELIST,0,0)
#define ToolBar_SetDisabledImageList(hwnd,himlNewDisabled)  (HIMAGELIST)(DWORD)SNDMSG((hwnd),TB_SETDISABLEDIMAGELIST,0,(LPARAM)(HIMAGELIST)(himlNewDisabled))
#define ToolBar_GetDisabledImageList(hwnd)  (HIMAGELIST)(DWORD)SNDMSG((hwnd),TB_GETDISABLEDIMAGELIST,0,0)
#define ToolBar_SetStyle(hwnd,dwStyle)  (BOOL)SNDMSG((hwnd),TB_SETSTYLE,0,(LPARAM)(DWORD)(dwStyle))
#define ToolBar_GetStyle(hwnd)  (int)SNDMSG((hwnd),TB_GETSTYLE,0,0)
#define ToolBar_GetButtonSize(hwnd)  (DWORD)SNDMSG((hwnd),TB_GETBUTTONSIZE,0,0)
#define ToolBar_SetButtonWidth(hwnd,cxMin,cxMax)  (DWORD)SNDMSG((hwnd),TB_SETBUTTONWIDTH,0,(LPARAM)(DWORD)MAKELONG((cxMin),(cxMax)))
#define ToolBar_SetMaxTextRows(hwnd,iMaxRows)  (BOOL)SNDMSG((hwnd),TB_SETMAXTEXTROWS,(WPARAM)(iMaxRows),0)
#define ToolBar_GetTextRows(hwnd)  (int)SNDMSG((hwnd),TB_GETTEXTROWS,0,0)
#if (_WIN32_IE >= 0x0400)
#define ToolBar_GetObject(hwnd,iid,ppvObject)  (HRESULT)SNDMSG((hwnd),TB_GETOBJECT,(WPARAM)(REFIID)(iid),(LPARAM)(LPVOID*)(ppvObject))
#define ToolBar_GetButtonInfo(hwnd,idButton,lptbbi)  (int)SNDMSG((hwnd),TB_GETBUTTONINFO,(WPARAM)(idButton),(LPARAM)(LPTBBUTTONINFO)(lptbbi))
#define ToolBar_SetButtonInfo(hwnd,idButton,lptbbi)  (int)SNDMSG((hwnd),TB_SETBUTTONINFO,(WPARAM)(idButton),(LPARAM)(LPTBBUTTONINFO)(lptbbi))
#define ToolBar_HitTest(hwnd,pptHitTest)  (int)SNDMSG((hwnd),TB_HITTEST,0,(LPARAM)(LPPOINT)(pptHitTest))
#define ToolBar_SetDrawTextFlags(hwnd,dwMask,dwDTFlags)  (DWORD)SNDMSG((hwnd),TB_SETDRAWTEXTFLAGS,(WPARAM)(DWORD)(dwMask),(LPARAM)(DWORD)(dwDTFlags))
#define ToolBar_GetHotItem(hwnd)  (int)SNDMSG((hwnd),TB_GETHOTITEM,0,0)
#define ToolBar_SetHotItem(hwnd,iHot)  (int)SNDMSG((hwnd),TB_SETHOTITEM,(WPARAM)(iHot),0)
#define ToolBar_SetAnchorHighlight(hwnd,fAnchor)  (BOOL)SNDMSG((hwnd),TB_SETANCHORHIGHLIGHT,(WPARAM)(BOOL)(fAnchor),0)
#define ToolBar_GetAnchorHighlight(hwnd)  (BOOL)SNDMSG((hwnd),TB_GETANCHORHIGHLIGHT,0,0)
#define ToolBar_MapAccelerator(hwnd,chAccel,pIDBtn)  (BOOL)SNDMSG((hwnd),TB_MAPACCELERATOR,(WPARAM)(TCHAR)(chAccel),(LPARAM)(LPUINT)(pIDBtn))
#define ToolBar_GetInsertMark(hwnd,lptbim)  (BOOL)SNDMSG((hwnd),TB_GETINSERTMARK,0,(LPARAM)(LPTBINSERTMARK)(lptbim))
#define ToolBar_SetInsertMark(hwnd,lptbim)  (BOOL)SNDMSG((hwnd),TB_SETINSERTMARK,0,(LPARAM)(LPTBINSERTMARK)(lptbim))
#define ToolBar_InsertMarkHitTest(hwnd,lppt,lptbim)  (BOOL)SNDMSG((hwnd),TB_INSERTMARKHITTEST,(WPARAM)(LPPOINT)(lppt),(LPARAM)(LPTBINSERTMARK)(lptbim))
#define ToolBar_MoveButton(hwnd,uOldPos,uNewPos)  (BOOL)SNDMSG((hwnd),TB_MOVEBUTTON,(WPARAM)(UINT)uOldPos,(LPARAM)(UINT)(uNewPos))
#define ToolBar_GetMaxSize(hwnd,lpSize)  (BOOL)SNDMSG((hwnd),TB_GETMAXSIZE,0,(LPARAM)(LPSIZE)(lpSize))
#define ToolBar_SetExtendedStyle(hwnd,dwExStyle)  (DWORD)SNDMSG((hwnd),TB_SETEXTENDEDSTYLE,0,(LPARAM)(DWORD)(dwExStyle))
#define ToolBar_GetExtendedStyle(hwnd)  (DWORD)SNDMSG((hwnd),TB_GETEXTENDEDSTYLE,0,0)
#define ToolBar_GetPadding(hwnd)  (DWORD)SNDMSG((hwnd),TB_GETPADDING,0,0)
#define ToolBar_SetPadding(hwnd,cx,cy)  (DWORD)SNDMSG((hwnd),TB_SETPADDING,0,MAKELPARAM((cx),(cy)))
#define ToolBar_SetInsertMarkColor(hwnd,clrInsertMark)  (COLORREF)SNDMSG((hwnd),TB_SETINSERTMARKCOLOR,0,(LPARAM)(COLORREF)(clrInsertMark))
#define ToolBar_GetInsertMarkColor(hwnd)  (COLORREF)SNDMSG((hwnd),TB_GETINSERTMARKCOLOR,0,0)
#define ToolBar_SetColorScheme(hwnd,lpcs)  (void)SNDMSG((hwnd),TB_SETCOLORSCHEME,0,(LPARAM)(LPCOLORSCHEME)(lpcs))
#define ToolBar_GetColorScheme(hwnd,lpcs)  (BOOL)SNDMSG((hwnd),TB_GETCOLORSCHEME,0,(LPARAM)(LPCOLORSCHEME)(lpcs))
#define ToolBar_SetUnicodeFormat(hwnd,fUnicode)  (BOOL)SNDMSG((hwnd),TB_SETUNICODEFORMAT,(WPARAM)(BOOL)(fUnicode),0)
#define ToolBar_GetUnicodeFormat(hwnd)  (BOOL)SNDMSG((hwnd),TB_GETUNICODEFORMAT,0,0)
#endif /* _WIN32_IE >= 0x0400 */
#if (_WIN32_WINNT >= 0x501)
#define ToolBar_GetMetrics(hwnd,lptbm)  (void)SNDMSG((hwnd),TB_GETMETRICS,0,(LPARAM)(LPTBMETRICS)(lptbm))
#define ToolBar_SetMetrics(hwnd,lptbm)  (void)SNDMSG((hwnd),TB_SETMETRICS,0,(LPARAM)(LPTBMETRICS)(lptbm))
#define ToolBar_SetWindowTheme(hwnd,pwStr)  (void)SNDMSG((hwnd),TB_SETWINDOWTHEME,0,(LPARAM)(LPWSTR)(pwStr))
#endif /* _WIN32_WINNT >= 0x501 */

#ifdef UNICODE
#define TBSAVEPARAMS TBSAVEPARAMSW
#define LPTBSAVEPARAMS LPTBSAVEPARAMSW
#define TBBUTTONINFO TBBUTTONINFOW
#define LPTBBUTTONINFO LPTBBUTTONINFOW
#define NMTBGETINFOTIP NMTBGETINFOTIPW
#define LPNMTBGETINFOTIP LPNMTBGETINFOTIPW
#define NMTBDISPINFO NMTBDISPINFOW
#define LPNMTBDISPINFO LPNMTBDISPINFOW
#define NMTOOLBAR NMTOOLBARW
#define LPNMTOOLBAR LPNMTOOLBARW
#define TB_GETBUTTONTEXT TB_GETBUTTONTEXTW
#define TB_SAVERESTORE TB_SAVERESTOREW
#define TB_ADDSTRING TB_ADDSTRINGW
#define TB_GETBUTTONINFO TB_GETBUTTONINFOW
#define TB_SETBUTTONINFO TB_SETBUTTONINFOW
#if (_WIN32_IE >= 0x0400)
#define TB_INSERTBUTTON TB_INSERTBUTTONW
#define TB_ADDBUTTONS TB_ADDBUTTONSW
#endif
#define TB_MAPACCELERATOR TB_MAPACCELERATORW
#define TB_GETSTRING TB_GETSTRINGW
#define TBN_GETINFOTIP TBN_GETINFOTIPW
#define TBN_GETDISPINFO TBN_GETDISPINFOW
#define TBN_GETBUTTONINFO TBN_GETBUTTONINFOW
#else
#define TBSAVEPARAMS TBSAVEPARAMSA
#define LPTBSAVEPARAMS LPTBSAVEPARAMSA
#define TBBUTTONINFO TBBUTTONINFOA
#define LPTBBUTTONINFO LPTBBUTTONINFOA
#define NMTBGETINFOTIP NMTBGETINFOTIPA
#define LPNMTBGETINFOTIP LPNMTBGETINFOTIPA
#define NMTBDISPINFO NMTBDISPINFOA
#define LPNMTBDISPINFO LPNMTBDISPINFOA
#define NMTOOLBAR NMTOOLBARA
#define LPNMTOOLBAR LPNMTOOLBARA
#define TB_GETBUTTONTEXT TB_GETBUTTONTEXTA
#define TB_SAVERESTORE TB_SAVERESTOREA
#define TB_ADDSTRING TB_ADDSTRINGA
#define TB_GETBUTTONINFO TB_GETBUTTONINFOA
#define TB_SETBUTTONINFO TB_SETBUTTONINFOA
#if (_WIN32_IE >= 0x0400)
#define TB_INSERTBUTTON TB_INSERTBUTTONA
#define TB_ADDBUTTONS TB_ADDBUTTONSA
#endif
#define TB_MAPACCELERATOR TB_MAPACCELERATORA
#define TB_GETSTRING TB_GETSTRINGA
#define TBN_GETINFOTIP TBN_GETINFOTIPA
#define TBN_GETDISPINFO TBN_GETDISPINFOA
#define TBN_GETBUTTONINFO TBN_GETBUTTONINFOA
#endif

#endif /* NOTOOLBAR */

/* ReBar Control ************************************************************/

#ifndef NOREBAR

#define REBARCLASSNAMEW  L"ReBarWindow32"
#define REBARCLASSNAMEA  "ReBarWindow32"

#ifdef UNICODE
#define REBARCLASSNAME  REBARCLASSNAMEW
#else
#define REBARCLASSNAME  REBARCLASSNAMEA
#endif

#define RBIM_IMAGELIST  0x00000001

#if (_WIN32_IE >= 0x0400)
#define RBS_TOOLTIPS  0x0100
#define RBS_VARHEIGHT  0x0200
#define RBS_BANDBORDERS  0x0400
#define RBS_FIXEDORDER  0x0800
#ifdef _WINCE
#define RBS_SMARTLABELS  0x1000
#else
#define RBS_REGISTERDROP  0x1000
#endif /* _WINCE */
#define RBS_AUTOSIZE  0x2000
#define RBS_VERTICALGRIPPER 0x4000
#define RBS_DBLCLKTOGGLE  0x8000
#else
#define RBS_TOOLTIPS  0x00000100
#define RBS_VARHEIGHT  0x00000200
#define RBS_BANDBORDERS  0x00000400
#define RBS_FIXEDORDER  0x00000800
#endif

#define RBBS_BREAK  0x00000001
#define RBBS_FIXEDSIZE  0x00000002
#define RBBS_CHILDEDGE  0x00000004
#define RBBS_HIDDEN  0x00000008
#define RBBS_NOVERT  0x00000010
#define RBBS_FIXEDBMP  0x00000020
#if (_WIN32_IE >= 0x0400)
#define RBBS_VARIABLEHEIGHT 0x00000040
#define RBBS_GRIPPERALWAYS  0x00000080
#ifdef _WINCE
#define RBBS_NOGRIPPER  0x00000100
#endif /* _WINCE */
#endif
#if (_WIN32_IE >= 0x0500)
#define RBBS_USECHEVRON  0x00000200
#endif
#if (_WIN32_IE >= 0x0501)
#define RBBS_HIDETITLE  0x00000400
#define RBBS_TOPALIGN  0x00000800
#endif

#define RBBIM_STYLE  0x00000001
#define RBBIM_COLORS  0x00000002
#define RBBIM_TEXT  0x00000004
#define RBBIM_IMAGE  0x00000008
#define RBBIM_CHILD  0x00000010
#define RBBIM_CHILDSIZE  0x00000020
#define RBBIM_SIZE  0x00000040
#define RBBIM_BACKGROUND  0x00000080
#define RBBIM_ID  0x00000100
#if (_WIN32_IE >= 0x0400)
#define RBBIM_IDEALSIZE  0x00000200
#define RBBIM_LPARAM  0x00000400
#define RBBIM_HEADERSIZE  0x00000800
#endif

#if (_WIN32_IE >= 0x0400)
#define RBNM_ID  0x00000001
#define RBNM_STYLE  0x00000002
#define RBNM_LPARAM  0x00000004
#endif

#if (_WIN32_IE >= 0x0400)
#define RBHT_NOWHERE  0x0001
#define RBHT_CAPTION  0x0002
#define RBHT_CLIENT  0x0003
#define RBHT_GRABBER  0x0004
#endif
#if (_WIN32_IE >= 0x0500)
#define RBHT_CHEVRON  0x0008
#endif

#if (_WIN32_WINNT >= 0x0501)
#define RBSTR_CHANGERECT  0x0001
#endif

#if (_WIN32_WINNT >= 0x0501)
#define RBAB_AUTOSIZE  0x0001
#define RBAB_ADDBAND  0x0002
#endif

#define RB_INSERTBANDA  (WM_USER+1)
#define RB_DELETEBAND  (WM_USER+2)
#define RB_GETBARINFO  (WM_USER+3)
#define RB_SETBARINFO  (WM_USER+4)
#if (_WIN32_IE < 0x0400)
#define RB_GETBANDINFO  (WM_USER+5)
#endif
#define RB_SETBANDINFOA  (WM_USER+6)
#define RB_SETPARENT  (WM_USER+7)
#if (_WIN32_IE >= 0x0400)
#define RB_HITTEST  (WM_USER+8)
#define RB_GETRECT  (WM_USER+9)
#endif
#define RB_INSERTBANDW  (WM_USER+10)
#define RB_SETBANDINFOW  (WM_USER+11)
#define RB_GETBANDCOUNT  (WM_USER+12)
#define RB_GETROWCOUNT  (WM_USER+13)
#define RB_GETROWHEIGHT  (WM_USER+14)
#if (_WIN32_IE >= 0x0400)
#define RB_IDTOINDEX  (WM_USER+16)
#define RB_GETTOOLTIPS  (WM_USER+17)
#define RB_SETTOOLTIPS  (WM_USER+18)
#define RB_SETBKCOLOR  (WM_USER+19)
#define RB_GETBKCOLOR  (WM_USER+20)
#define RB_SETTEXTCOLOR  (WM_USER+21)
#define RB_GETTEXTCOLOR  (WM_USER+22)
#define RB_SIZETORECT  (WM_USER+23)
#endif
#define RB_SETCOLORSCHEME  CCM_SETCOLORSCHEME
#define RB_GETCOLORSCHEME  CCM_GETCOLORSCHEME

#if (_WIN32_IE >= 0x0400)
#define RB_BEGINDRAG  (WM_USER+24)
#define RB_ENDDRAG  (WM_USER+25)
#define RB_DRAGMOVE  (WM_USER+26)
#define RB_GETBARHEIGHT  (WM_USER+27)
#define RB_GETBANDINFOW  (WM_USER+28)
#define RB_GETBANDINFOA  (WM_USER+29)
#define RB_MINIMIZEBAND  (WM_USER+30)
#define RB_MAXIMIZEBAND  (WM_USER+31)
#define RB_GETDROPTARGET  CCM_GETDROPTARGET
#define RB_GETBANDBORDERS  (WM_USER+34)
#define RB_SHOWBAND  (WM_USER+35)
#define RB_SETPALETTE  (WM_USER+37)
#define RB_GETPALETTE  (WM_USER+38)
#define RB_MOVEBAND  (WM_USER+39)
#define RB_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
#define RB_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#endif
#if (_WIN32_IE >= 0x0500)
#define RB_PUSHCHEVRON  (WM_USER+43)
#endif
#if (_WIN32_WINNT >= 0x501)
#define RB_GETBANDMARGINS  (WM_USER+40)
#define RB_SETWINDOWTHEME  CCM_SETWINDOWTHEME
#endif

#define RBN_HEIGHTCHANGE  (RBN_FIRST-0)
#if (_WIN32_IE >= 0x0400)
#define RBN_GETOBJECT  (RBN_FIRST-1)
#define RBN_LAYOUTCHANGED  (RBN_FIRST-2)
#define RBN_AUTOSIZE  (RBN_FIRST-3)
#define RBN_BEGINDRAG  (RBN_FIRST-4)
#define RBN_ENDDRAG  (RBN_FIRST-5)
#define RBN_DELETINGBAND  (RBN_FIRST-6)
#define RBN_DELETEDBAND  (RBN_FIRST-7)
#define RBN_CHILDSIZE  (RBN_FIRST-8)
#endif
#if (_WIN32_IE >= 0x0500)
#define RBN_CHEVRONPUSHED  (RBN_FIRST-10)
#define RBN_MINMAX  (RBN_FIRST-21)
#endif
#if (_WIN32_WINNT >= 0x0501)
#define RBN_AUTOBREAK  (RBN_FIRST-22)
#endif

#define REBARBANDINFOA_V3_SIZE CCSIZEOF_STRUCT(REBARBANDINFOA, wID)
#define REBARBANDINFOW_V3_SIZE CCSIZEOF_STRUCT(REBARBANDINFOW, wID)

typedef struct tagREBARINFO {
    UINT cbSize;
    UINT fMask;
#ifndef NOIMAGEAPIS
    HIMAGELIST himl;
#else
    HANDLE himl;
#endif
} REBARINFO, *LPREBARINFO;

typedef struct tagREBARBANDINFOA {
    UINT cbSize;
    UINT fMask;
    UINT fStyle;
    COLORREF clrFore;
    COLORREF clrBack;
    LPSTR lpText;
    UINT cch;
    int iImage;
    HWND hwndChild;
    UINT cxMinChild;
    UINT cyMinChild;
    UINT cx;
    HBITMAP hbmBack;
    UINT wID;
#if (_WIN32_IE >= 0x0400)
    UINT cyChild;
    UINT cyMaxChild;
    UINT cyIntegral;
    UINT cxIdeal;
    LPARAM lParam;
    UINT cxHeader;
#endif
} REBARBANDINFOA, *LPREBARBANDINFOA;
typedef REBARBANDINFOA CONST *LPCREBARBANDINFOA;

typedef struct tagREBARBANDINFOW {
    UINT cbSize;
    UINT fMask;
    UINT fStyle;
    COLORREF clrFore;
    COLORREF clrBack;
    LPWSTR lpText;
    UINT cch;
    int iImage;
    HWND hwndChild;
    UINT cxMinChild;
    UINT cyMinChild;
    UINT cx;
    HBITMAP hbmBack;
    UINT wID;
#if (_WIN32_IE >= 0x0400)
    UINT cyChild;
    UINT cyMaxChild;
    UINT cyIntegral;
    UINT cxIdeal;
    LPARAM lParam;
    UINT cxHeader;
#endif
} REBARBANDINFOW, *LPREBARBANDINFOW;
typedef REBARBANDINFOW CONST *LPCREBARBANDINFOW;

#if (_WIN32_IE >= 0x0400)
typedef struct tagNMREBARCHILDSIZE {
    NMHDR hdr;
    UINT uBand;
    UINT wID;
    RECT rcChild;
    RECT rcBand;
} NMREBARCHILDSIZE, *LPNMREBARCHILDSIZE;
#endif

#if (_WIN32_IE >= 0x0400)
typedef struct tagNMREBAR {
    NMHDR hdr;
    DWORD dwMask;
    UINT uBand;
    UINT fStyle;
    UINT wID;
    LPARAM lParam;
} NMREBAR, *LPNMREBAR;
#endif

#if (_WIN32_IE >= 0x0400)
typedef struct tagNMRBAUTOSIZE {
    NMHDR hdr;
    BOOL fChanged;
    RECT rcTarget;
    RECT rcActual;
} NMRBAUTOSIZE, *LPNMRBAUTOSIZE;
#endif

#if (_WIN32_IE >= 0x0500)
typedef struct tagNMREBARCHEVRON {
    NMHDR hdr;
    UINT uBand;
    UINT wID;
    LPARAM lParam;
    RECT rc;
    LPARAM lParamNM;
} NMREBARCHEVRON, *LPNMREBARCHEVRON;
#endif

#if (_WIN32_IE >= 0x0400)
typedef struct _RB_HITTESTINFO {
    POINT pt;
    UINT flags;
    int iBand;
} RBHITTESTINFO, *LPRBHITTESTINFO;
#endif

#if (_WIN32_WINNT >= 0x0501)
typedef struct tagNMREBARAUTOBREAK {
    NMHDR hdr;
    UINT uBand;
    UINT wID;
    LPARAM lParam;
    UINT uMsg;
    UINT fStyleCurrent;
    BOOL fAutoBreak;
} NMREBARAUTOBREAK, *LPNMREBARAUTOBREAK;
#endif

#define ReBar_InsertBand(hwnd,uIndex,lprbbi)  (BOOL)SNDMSG((hwnd),RB_INSERTBAND,(WPARAM)(UINT)(uIndex),(LPARAM)(LPREBARBANDINFO)(lprbbi))
#define ReBar_DeleteBand(hwnd,uBand)  (BOOL)SNDMSG((hwnd),RB_DELETEBAND,(WPARAM)(UINT)(uBand), 0)
#define ReBar_GetBarInfo(hwnd,lprbi)  (BOOL)SNDMSG((hwnd),RB_GETBARINFO,0,(LPARAM)(LPREBARINFO)(lprbi))
#define ReBar_SetBarInfo(hwnd,lprbi)  (BOOL)SNDMSG((hwnd),RB_SETBARINFO,0,(LPARAM)(LPREBARINFO)(lprbi))
#define ReBar_GetBandInfo(hwnd,uBand,lprbbi)  (BOOL)SNDMSG((hwnd),RB_GETBANDINFO,(WPARAM)(UINT)(uBand),(LPARAM)(LPREBARBANDINFO)(lprbbi))
#define ReBar_SetBandInfo(hwnd,uBand,lprbbi)  (BOOL)SNDMSG((hwnd),RB_SETBANDINFO,(WPARAM)(UINT)(uBand),(LPARAM)(LPREBARBANDINFO)(lprbbi))
#define ReBar_SetParent(hwnd,hwndParent)  (HWND)SNDMSG((hwnd),RB_SETPARENT,(WPARAM)(HWND)hwndParent,0)
#define ReBar_HitTest(hwnd,lprbht)  (int)SNDMSG((hwnd),RB_HITTEST,0,(LPARAM)(LPRBHITTESTINFO)(lprbht))
#define ReBar_GetRect(hwnd,uBand,lprc)  (BOOL)SNDMSG((hwnd),RB_GETRECT,(WPARAM)(UINT)(uBand),(LPARAM)(LPRECT)(lprc))
#define ReBar_GetBandCount(hwnd)  (UINT)SNDMSG((hwnd),RB_GETBANDCOUNT,0,0)
#define ReBar_GetRowCount(hwnd)  (UINT)SNDMSG((hwnd),RB_GETROWCOUNT,0,0)
#define ReBar_GetRowHeight(hwnd)  (UINT)SNDMSG((hwnd),RB_GETROWHEIGHT,0,0)
#define ReBar_IDToIndex(hwnd,uBandId)  (int)SNDMSG((hwnd),RB_IDTOINDEX,(WPARAM)(UINT)(uBandId),0)
#define ReBar_GetToolTips(hwnd)  (HWND)SNDMSG((hwnd),RB_GETTOOLTIPS,0,0)
#define ReBar_SetToolTips(hwnd,hwndTT)  (void)SNDMSG((hwnd),RB_SETTOOLTIPS,(WPARAM)(HWND)(hwndTT),0)
#define ReBar_SetBkColor(hwnd,clrBk)  (COLORREF)SNDMSG((hwnd),RB_SETBKCOLOR,0,(LPARAM)(COLORREF)(clrBk))
#define ReBar_GetBkColor(hwnd)  (COLORREF)SNDMSG((hwnd),RB_GETBKCOLOR,0,0)
#define ReBar_SetTextColor(hwnd,clrText)  (COLORREF)SNDMSG((hwnd),RB_SETTEXTCOLOR,0,(LPARAM)(COLORREF)(clrText))
#define ReBar_GetTextColor(hwnd)  (COLORREF)SNDMSG((hwnd),RB_GETTEXTCOLOR,0,0)
#define ReBar_SizeToRect(hwnd,lprc)  (BOOL)SNDMSG((hwnd),RB_SIZETORECT,0,(LPARAM)(LPRECT)(lprc))
#define ReBar_SetColorScheme(hwnd,lpcs)  (void)SNDMSG((hwnd),RB_SETCOLORSCHEME,0,(LPARAM)(LPCOLORSCHEME)(lpcs))
#define ReBar_GetColorScheme(hwnd,lpcs)  (BOOL)SNDMSG((hwnd),RB_GETCOLORSCHEME,0,(LPARAM)(LPCOLORSCHEME)(lpcs))
#define ReBar_BeginDrag(hwnd,uBand,dwPos)  (void)SNDMSG((hwnd),RB_BEGINDRAG,(WPARAM)(UINT)(uBand),(LPARAM)(DWORD)(dwPos))
#define ReBar_EndDrag(hwnd)  (HWND)SNDMSG((hwnd),RB_ENDDRAG,0,0)
#define ReBar_DragMove(hwnd,dwPos)  (void)SNDMSG((hwnd),RB_DRAGMOVE,0,(LPARAM)(DWORD)(dwPos))
#define ReBar_GetBarHeight(hwnd)  (UINT)SNDMSG((hwnd),RB_GETBARHEIGHT,0,0)
#define ReBar_MinimizeBand(hwnd,uBand)  (void)SNDMSG((hwnd),RB_MINIMIZEBAND,(WPARAM)(UINT)(uBand),0)
#define ReBar_MaximizeBand(hwnd,uBand,fIdeal)  (void)SNDMSG((hwnd),RB_MAXIMIZEBAND,(WPARAM)(UINT)(uBand),(LPARAM)(BOOL)(fIdeal))
#define ReBar_GetDropTarget(hwnd,ppDropTarget)  (void)SNDMSG((hwnd),RB_GETDROPTARGET,0,(LPARAM)(IDropTarget**)(ppDropTarget))
#define ReBar_GetBandBorders(hwnd,uBand,lprc)  (void)SNDMSG((hwnd),RB_GETBANDBORDERS,(WPARAM)(UINT)(uBand),(LPARAM)(LPRECT)(lprc))
#define ReBar_ShowBand(hwnd,uBand,fShow)  (BOOL)SNDMSG((hwnd),RB_SHOWBAND,(WPARAM)(UINT)(uBand),(LPARAM)(BOOL)(fShow))
#define ReBar_SetPalette(hwnd,hpal)  (HPALETTE)SNDMSG((hwnd),RB_SETPALETTE,0,(LPARAM)(HPALETTE)(hpal))
#define ReBar_GetPalette(hwnd)  (HPALETTE)SNDMSG((hwnd),RB_GETPALETTE,0,0)
#define ReBar_MoveBand(hwnd,iFrom,iTo)  (BOOL)SNDMSG((hwnd),RB_MOVEBAND,(WPARAM)(UINT)(iFrom),(LPARAM)(UINT)(iTo))
#define ReBar_SetUnicodeFormat(hwnd,fUnicode)  (BOOL)SNDMSG((hwnd),RB_SETUNICODEFORMAT,(WPARAM)(BOOL)(fUnicode),0)
#define ReBar_GetUnicodeFormat(hwnd)  (BOOL)SNDMSG((hwnd),RB_GETUNICODEFORMAT,0,0)
#define ReBar_PushChevron(hwnd,uBand,lAppValue)  (void)SNDMSG((hwnd),RB_PUSHCHEVRON,(WPARAM)(UINT)(uBand),(LPARAM)(long)(lAppValue))
#define ReBar_GetBandMargins(hwnd,pMargins)  (void)SNDMSG((hwnd),RB_GETBANDMARGINS,0,(LPARAM)(PMARGINS)(pMargins))
#define ReBar_SetWindowTheme(hwnd,pwStr)  (void)SNDMSG((hwnd),RB_SETWINDOWTHEME,0,(LPARAM)(LPWSTR)(pwStr))

#ifdef UNICODE
#define REBARBANDINFO REBARBANDINFOW
#define LPREBARBANDINFO LPREBARBANDINFOW
#define LPCREBARBANDINFO LPCREBARBANDINFOW
#define REBARBANDINFO_V3_SIZE REBARBANDINFOW_V3_SIZE
#define RB_INSERTBAND RB_INSERTBANDW
#define RB_SETBANDINFO RB_SETBANDINFOW
#if (_WIN32_IE >= 0x0400)
#define RB_GETBANDINFO RB_GETBANDINFOW
#endif
#else
#define REBARBANDINFO REBARBANDINFOA
#define LPREBARBANDINFO LPREBARBANDINFOA
#define LPCREBARBANDINFO LPCREBARBANDINFOA
#define REBARBANDINFO_V3_SIZE REBARBANDINFOA_V3_SIZE
#define RB_INSERTBAND RB_INSERTBANDA
#define RB_SETBANDINFO RB_SETBANDINFOA
#if (_WIN32_IE >= 0x0400)
#define RB_GETBANDINFO RB_GETBANDINFOA
#endif
#endif

#endif /* NOREBAR */

/* CommandBar Control *******************************************************/

#ifdef _WINCE
#ifndef NOCOMMANDBAR

typedef struct tagCOMMANDBANDSRESTOREINFO {
    UINT cbSize;
    UINT wID;
    UINT fStyle;
    UINT cxRestored;
    BOOL fMaximized;
} COMMANDBANDSRESTOREINFO, *LPCOMMANDBANDSRESTOREINFO;
typedef COMMANDBANDSRESTOREINFO CONST *LPCCOMMANDBANDSRESTOREINFO;

WINCOMMCTRLAPI HWND WINAPI CommandBar_Create(HINSTANCE,HWND,int);
WINCOMMCTRLAPI BOOL WINAPI CommandBar_Show(HWND,BOOL);
WINCOMMCTRLAPI int WINAPI CommandBar_AddBitmap(HWND,HINSTANCE,int,int,int,int);
WINCOMMCTRLAPI HWND WINAPI CommandBar_InsertComboBox(HWND,HINSTANCE,int,UINT,WORD,WORD);
WINCOMMCTRLAPI BOOL WINAPI CommandBar_InsertMenubar(HWND,HINSTANCE,WORD,WORD);
WINCOMMCTRLAPI BOOL WINAPI CommandBar_InsertMenubarEx(HWND,HINSTANCE,LPTSTR,WORD);
WINCOMMCTRLAPI BOOL WINAPI CommandBar_DrawMenuBar(HWND,WORD);
WINCOMMCTRLAPI HMENU WINAPI CommandBar_GetMenu(HWND,WORD);
WINCOMMCTRLAPI BOOL WINAPI CommandBar_AddAdornments(HWND,DWORD,DWORD);
WINCOMMCTRLAPI int WINAPI CommandBar_Height(HWND);
WINCOMMCTRLAPI BOOL WINAPI IsCommandBarMessage(HWND,LPMSG);
WINCOMMCTRLAPI HWND WINAPI CommandBands_Create(HINSTANCE,HWND,UINT,DWORD,HIMAGELIST);
WINCOMMCTRLAPI BOOL WINAPI CommandBands_AddBands(HWND,HINSTANCE,UINT,LPREBARBANDINFO);
WINCOMMCTRLAPI HWND WINAPI CommandBands_GetCommandBar(HWND,UINT);
WINCOMMCTRLAPI BOOL WINAPI CommandBands_AddAdornments(HWND,HINSTANCE,DWORD,LPREBARBANDINFO);
WINCOMMCTRLAPI BOOL WINAPI CommandBands_Show(HWND,BOOL);
WINCOMMCTRLAPI BOOL WINAPI CommandBands_GetRestoreInformation(HWND,UINT,LPCOMMANDBANDSRESTOREINFO);

#define CommandBar_Destroy(hwndCB)  DestroyWindow((hwndCB))
#define CommandBar_IsVisible(hwndCB)  IsWindowVisible((hwndCB))
#define CommandBar_AddButtons(hwndCB,cbButtons,lpButtons)  SNDMSG((hwndCB),TB_ADDBUTTONS,(WPARAM)(cbButtons),(LPARAM)(lpButtons))
#define CommandBar_InsertButton(hwndCB,iButton,lpButton)  SNDMSG((hwndCB),TB_INSERTBUTTON,(WPARAM)(iButton),(LPARAM)(lpButton))
#define CommandBar_AddToolTips(hwndCB,cbToolTips,lpToolTipsStrings)  SNDMSG((hwndCB),TB_SETTOOLTIPS,(WPARAM)(cbToolTips),(LPARAM)(lpToolTipsStrings))
#define CommandBands_Height(hwndCmdBands)  ((UINT)SNDMSG((hwndCmdBands),RB_GETBARHEIGHT,0,0))
#define CommandBands_IsVisible(hwndCmdBands)  IsWindowVisible((hwndCmdBands))

#define CMDBAR_HELP  0x000B
#define CMDBAR_OK  0xF000

#endif /* NOCOMMANDBAR */
#endif /* _WINCE */

/* Tooltips Control *********************************************************/

#ifndef NOTOOLTIPS

#define TOOLTIPS_CLASSW  L"tooltips_class32"
#define TOOLTIPS_CLASSA  "tooltips_class32"

#ifdef UNICODE
#define TOOLTIPS_CLASS  TOOLTIPS_CLASSW
#else
#define TOOLTIPS_CLASS  TOOLTIPS_CLASSA
#endif

#define TTS_ALWAYSTIP  0x01
#define TTS_NOPREFIX  0x02
#if (_WIN32_IE >= 0x0500)
#define TTS_NOANIMATE  0x10
#define TTS_NOFADE  0x20
#define TTS_BALLOON  0x40
#endif

#define TTF_IDISHWND  0x0001

#define TTF_CENTERTIP  0x0002
#define TTF_RTLREADING  0x0004
#define TTF_SUBCLASS  0x0010
#define TTF_TRACK  0x0020
#define TTF_ABSOLUTE  0x0080
#define TTF_TRANSPARENT  0x0100
#if (_WIN32_IE >= 0x0501)
#define TTF_PARSELINKS  0x1000
#endif
#define TTF_DI_SETITEM  0x8000

#define TTDT_AUTOMATIC  0
#define TTDT_RESHOW  1
#define TTDT_AUTOPOP  2
#define TTDT_INITIAL  3

#define TTI_NONE  0
#define TTI_INFO  1
#define TTI_WARNING  2
#define TTI_ERROR  3

#define TTM_ACTIVATE  (WM_USER+1)
#define TTM_SETDELAYTIME  (WM_USER+3)
#define TTM_ADDTOOLA  (WM_USER+4)
#define TTM_ADDTOOLW  (WM_USER+50)
#define TTM_DELTOOLA  (WM_USER+5)
#define TTM_DELTOOLW  (WM_USER+51)
#define TTM_NEWTOOLRECTA  (WM_USER+6)
#define TTM_NEWTOOLRECTW  (WM_USER+52)
#define TTM_RELAYEVENT  (WM_USER+7)
#define TTM_GETTOOLINFOA  (WM_USER+8)
#define TTM_GETTOOLINFOW  (WM_USER+53)
#define TTM_SETTOOLINFOA  (WM_USER+9)
#define TTM_SETTOOLINFOW  (WM_USER+54)
#define TTM_HITTESTA  (WM_USER+10)
#define TTM_HITTESTW  (WM_USER+55)
#define TTM_GETTEXTA  (WM_USER+11)
#define TTM_GETTEXTW  (WM_USER+56)
#define TTM_UPDATETIPTEXTA  (WM_USER+12)
#define TTM_UPDATETIPTEXTW  (WM_USER+57)
#define TTM_GETTOOLCOUNT  (WM_USER+13)
#define TTM_ENUMTOOLSA  (WM_USER+14)
#define TTM_ENUMTOOLSW  (WM_USER+58)
#define TTM_GETCURRENTTOOLA  (WM_USER+15)
#define TTM_GETCURRENTTOOLW  (WM_USER+59)
#define TTM_WINDOWFROMPOINT  (WM_USER+16)
#define TTM_TRACKACTIVATE  (WM_USER+17)
#define TTM_TRACKPOSITION  (WM_USER+18)
#define TTM_SETTIPBKCOLOR  (WM_USER+19)
#define TTM_SETTIPTEXTCOLOR  (WM_USER+20)
#define TTM_GETDELAYTIME  (WM_USER+21)
#define TTM_GETTIPBKCOLOR  (WM_USER+22)
#define TTM_GETTIPTEXTCOLOR  (WM_USER+23)
#define TTM_SETMAXTIPWIDTH  (WM_USER+24)
#define TTM_GETMAXTIPWIDTH  (WM_USER+25)
#define TTM_SETMARGIN  (WM_USER+26)
#define TTM_GETMARGIN  (WM_USER+27)
#define TTM_POP  (WM_USER+28)
#if (_WIN32_IE >= 0x0400)
#define TTM_UPDATE  (WM_USER+29)
#endif
#if (_WIN32_IE >= 0x0500)
#define TTM_GETBUBBLESIZE  (WM_USER+30)
#define TTM_ADJUSTRECT  (WM_USER+31)
#define TTM_SETTITLEA  (WM_USER+32)
#define TTM_SETTITLEW  (WM_USER+33)
#endif
#if (_WIN32_WINNT >= 0x0501)
#define TTM_POPUP  (WM_USER+34)
#define TTM_GETTITLE  (WM_USER+35)
#define TTM_SETWINDOWTHEME  CCM_SETWINDOWTHEME
#endif

#define TTN_GETDISPINFOA  (TTN_FIRST-0)
#define TTN_GETDISPINFOW  (TTN_FIRST-10)
#define TTN_SHOW  (TTN_FIRST-1)
#define TTN_POP  (TTN_FIRST-2)
#define TTN_NEEDTEXT  TTN_GETDISPINFO
#define TTN_NEEDTEXTA  TTN_GETDISPINFOA
#define TTN_NEEDTEXTW  TTN_GETDISPINFOW

#define LPTOOLINFOA LPTTTOOLINFOA
#define LPTOOLINFOW LPTTTOOLINFOW
#define TOOLINFOA TTTOOLINFOA
#define TOOLINFOW TTTOOLINFOW

#define LPTOOLINFO LPTTTOOLINFO
#define TOOLINFO TTTOOLINFO

#define TTTOOLINFOA_V1_SIZE CCSIZEOF_STRUCT(TTTOOLINFOA,lpszText)
#define TTTOOLINFOW_V1_SIZE CCSIZEOF_STRUCT(TTTOOLINFOW,lpszText)

#define LPHITTESTINFOW LPTTHITTESTINFOW
#define LPHITTESTINFOA LPTTHITTESTINFOA
#define LPHITTESTINFO LPTTHITTESTINFO

#define TOOLTIPTEXTW NMTTDISPINFOW
#define TOOLTIPTEXTA NMTTDISPINFOA
#define LPTOOLTIPTEXTA LPNMTTDISPINFOA
#define LPTOOLTIPTEXTW LPNMTTDISPINFOW
#define TOOLTIPTEXT NMTTDISPINFO
#define LPTOOLTIPTEXT LPNMTTDISPINFO

#define NMTTDISPINFOA_V1_SIZE CCSIZEOF_STRUCT(NMTTDISPINFOA,uFlags)
#define NMTTDISPINFOW_V1_SIZE CCSIZEOF_STRUCT(NMTTDISPINFOW,uFlags)

typedef struct tagTOOLINFOA {
    UINT cbSize;
    UINT uFlags;
    HWND hwnd;
    UINT_PTR uId;
    RECT rect;
    HINSTANCE hinst;
    LPSTR lpszText;
    LPARAM lParam;
#if (_WIN32_WINNT >= 0x0501)
    void *lpReserved;
#endif
} TTTOOLINFOA, *PTOOLINFOA, *LPTTTOOLINFOA;

typedef struct tagTOOLINFOW {
    UINT cbSize;
    UINT uFlags;
    HWND hwnd;
    UINT_PTR uId;
    RECT rect;
    HINSTANCE hinst;
    LPWSTR lpszText;
    LPARAM lParam;
#if (_WIN32_WINNT >= 0x0501)
    void *lpReserved;
#endif
} TTTOOLINFOW, *PTOOLINFOW, *LPTTTOOLINFOW;

typedef struct _TT_HITTESTINFOA {
    HWND hwnd;
    POINT pt;
    TTTOOLINFOA ti;
} TTHITTESTINFOA, *LPTTHITTESTINFOA;

typedef struct _TT_HITTESTINFOW {
    HWND hwnd;
    POINT pt;
    TTTOOLINFOW ti;
} TTHITTESTINFOW, *LPTTHITTESTINFOW;

typedef struct tagNMTTDISPINFOA {
    NMHDR hdr;
    LPSTR lpszText;
    char szText[80];
    HINSTANCE hinst;
    UINT uFlags;
    LPARAM lParam;
} NMTTDISPINFOA, *LPNMTTDISPINFOA;

typedef struct tagNMTTDISPINFOW {
    NMHDR hdr;
    LPWSTR lpszText;
    WCHAR szText[80];
    HINSTANCE hinst;
    UINT uFlags;
    LPARAM lParam;
} NMTTDISPINFOW, *LPNMTTDISPINFOW;

#if (_WIN32_WINNT >= 0x0501)
typedef struct _TTGETTITLE {
    DWORD dwSize;
    UINT uTitleBitmap;
    UINT cch;
    WCHAR* pszTitle;
} TTGETTITLE, *PTTGETTITLE;
#endif

/* added by Pelles C development team 2000-09-08 */
#define ToolTip_Activate(hwnd,fActivate)  (void)SNDMSG((hwnd),TTM_ACTIVATE,(WPARAM)(BOOL)(fActivate),0)
#define ToolTip_SetDelayTime(hwnd,uFlag,iDelay)  (void)SNDMSG((hwnd),TTM_SETDELAYTIME,(WPARAM)(uFlag),(LPARAM)(int)(iDelay))
#define ToolTip_AddTool(hwnd,lpti)  (BOOL)SNDMSG((hwnd),TTM_ADDTOOL,0,(LPARAM)(LPTOOLINFO)(lpti))
#define ToolTip_DelTool(hwnd,lpti)  (void)SNDMSG((hwnd),TTM_DELTOOL,0,(LPARAM)(LPTOOLINFO)(lpti))
#define ToolTip_NewToolRect(hwnd,lpti)  (void)SNDMSG((hwnd),TTM_NEWTOOLRECT,0,(LPARAM)(LPTOOLINFO)(lpti))
#define ToolTip_RelayEvent(hwnd,lpmsg)  (void)SNDMSG((hwnd),TTM_RELAYEVENT,0,(LPARAM)(LPMSG)(lpmsg))
#define ToolTip_GetToolInfo(hwnd,lpti)  (BOOL)SNDMSG((hwnd),TTM_GETTOOLINFO,0,(LPARAM)(LPTOOLINFO)(lpti))
#define ToolTip_SetToolInfo(hwnd,lpti)  (void)SNDMSG((hwnd),TTM_SETTOOLINFO,0,(LPARAM)(LPTOOLINFO)(lpti))
#define ToolTip_HitTest(hwnd,lphti)  (BOOL)SNDMSG((hwnd),TTM_HITTEST,0,(LPARAM)(LPHITTESTINFO)(lphti))
#define ToolTip_GetText(hwnd,lpti)  (void)SNDMSG((hwnd),TTM_GETTEXT,0,(LPARAM)(LPTOOLINFO)(lpti))
#define ToolTip_UpdateTipText(hwnd,lpti)  (void)SNDMSG((hwnd),TTM_UPDATETIPTEXT,0,(LPARAM)(LPTOOLINFO)(lpti))
#define ToolTip_GetToolCount(hwnd)  (int)SNDMSG((hwnd),TTM_GETTOOLCOUNT,0,0)
#define ToolTip_EnumTools(hwnd,iTool,lpti)  (BOOL)SNDMSG((hwnd),TTM_ENUMTOOLS,(WPARAM)(UINT)(iTool),(LPARAM)(LPTOOLINFO)(lpti))
#define ToolTip_GetCurrentTool(hwnd,lpti)  (BOOL)SNDMSG((hwnd),TTM_GETCURRENTTOOL,0,(LPARAM)(LPTOOLINFO)(lpti))
#define ToolTip_WindowFromPoint(hwnd,lppt)  (HWND)SNDMSG((hwnd),TTM_WINDOWFROMPOINT,0,(POINT*)(lppt))
#define ToolTip_TrackActivate(hwnd,fActivate,lpti)  (void)SNDMSG((hwnd),TTM_TRACKACTIVATE,(WPARAM)(BOOL)(fActivate),(LPARAM)(LPTOOLINFO)(lpti))
#define ToolTip_TrackPosition(hwnd,x,y)  (void)SNDMSG((hwnd),TTM_TRACKPOSITION,0,MAKELPARAM((x),(y)))
#define ToolTip_SetTipBkColor(hwnd,clr)  (void)SNDMSG((hwnd),TTM_SETTIPBKCOLOR,(WPARAM)(COLORREF)(clr),0)
#define ToolTip_SetTipTextColor(hwnd,clr)  (void)SNDMSG((hwnd),TTM_SETTIPTEXTCOLOR,(WPARAM)(COLORREF)(clr),0)
#define ToolTip_GetDelayTime(hwnd,dwDuration)  (int)SNDMSG((hwnd),TTM_GETDELAYTIME,(WPARAM)(DWORD)(dwDuration),0)
#define ToolTip_GetTipBkColor(hwnd)  (COLORREF)SNDMSG((hwnd),TTM_GETTIPBKCOLOR,0,0)
#define ToolTip_GetTipTextColor(hwnd)  (COLORREF)SNDMSG((hwnd),TTM_GETTIPTEXTCOLOR,0,0)
#define ToolTip_SetMaxTipWidth(hwnd,iWidth)  (int)SNDMSG((hwnd),TTM_SETMAXTIPWIDTH,0,(LPARAM)(int)(iWidth))
#define ToolTip_GetMaxTipWidth(hwnd)  (int)SNDMSG((hwnd),TTM_GETMAXTIPWIDTH,0,0)
#define ToolTip_SetMargin(hwnd,lprc)  (void)SNDMSG((hwnd),TTM_SETMARGIN,0,(LPARAM)(LPRECT)(lprc))
#define ToolTip_GetMargin(hwnd,lprc)  (void)SNDMSG((hwnd),TTM_GETMARGIN,0,(LPARAM)(LPRECT)(lprc))
#define ToolTip_Pop(hwnd)  (void)SNDMSG((hwnd),TTM_POP,0,0)
#if (_WIN32_IE >= 0x0400)
#define ToolTip_Update(hwnd)  (void)SNDMSG((hwnd),TTM_UPDATE,0,0)
#endif

#ifdef UNICODE
#define TTTOOLINFO TTTOOLINFOW
#define PTOOLINFO PTOOLINFOW
#define LPTTTOOLINFO LPTTTOOLINFOW
#define TTTOOLINFO_V1_SIZE TTTOOLINFOW_V1_SIZE
#define TTHITTESTINFO TTHITTESTINFOW
#define LPTTHITTESTINFO LPTTHITTESTINFOW
#define NMTTDISPINFO NMTTDISPINFOW
#define LPNMTTDISPINFO LPNMTTDISPINFOW
#define NMTTDISPINFO_V1_SIZE NMTTDISPINFOW_V1_SIZE
#define TTM_ADDTOOL TTM_ADDTOOLW
#define TTM_DELTOOL TTM_DELTOOLW
#define TTM_NEWTOOLRECT TTM_NEWTOOLRECTW
#define TTM_GETTOOLINFO TTM_GETTOOLINFOW
#define TTM_SETTOOLINFO TTM_SETTOOLINFOW
#define TTM_HITTEST TTM_HITTESTW
#define TTM_GETTEXT TTM_GETTEXTW
#define TTM_UPDATETIPTEXT TTM_UPDATETIPTEXTW
#define TTM_ENUMTOOLS TTM_ENUMTOOLSW
#define TTM_GETCURRENTTOOL TTM_GETCURRENTTOOLW
#if (_WIN32_IE >= 0x0500)
#define TTM_SETTITLE TTM_SETTITLEW
#endif
#define TTN_GETDISPINFO TTN_GETDISPINFOW
#else
#define PTOOLINFO PTOOLINFOA
#define TTTOOLINFO TTTOOLINFOA
#define LPTTTOOLINFO LPTTTOOLINFOA
#define TTTOOLINFO_V1_SIZE TTTOOLINFOA_V1_SIZE
#define TTHITTESTINFO TTHITTESTINFOA
#define LPTTHITTESTINFO LPTTHITTESTINFOA
#define NMTTDISPINFO NMTTDISPINFOA
#define LPNMTTDISPINFO LPNMTTDISPINFOA
#define NMTTDISPINFO_V1_SIZE NMTTDISPINFOA_V1_SIZE
#define TTM_ADDTOOL TTM_ADDTOOLA
#define TTM_DELTOOL TTM_DELTOOLA
#define TTM_NEWTOOLRECT TTM_NEWTOOLRECTA
#define TTM_GETTOOLINFO TTM_GETTOOLINFOA
#define TTM_SETTOOLINFO TTM_SETTOOLINFOA
#define TTM_HITTEST TTM_HITTESTA
#define TTM_GETTEXT TTM_GETTEXTA
#define TTM_UPDATETIPTEXT TTM_UPDATETIPTEXTA
#define TTM_ENUMTOOLS TTM_ENUMTOOLSA
#define TTM_GETCURRENTTOOL TTM_GETCURRENTTOOLA
#if (_WIN32_IE >= 0x0500)
#define TTM_SETTITLE TTM_SETTITLEA
#endif
#define TTN_GETDISPINFO TTN_GETDISPINFOA
#endif

#endif /* NOTOOLTIPS */

/* Status bar Control *******************************************************/

#ifndef NOSTATUSBAR

#define STATUSCLASSNAMEW  L"msctls_statusbar32"
#define STATUSCLASSNAMEA  "msctls_statusbar32"

#ifdef UNICODE
#define STATUSCLASSNAME  STATUSCLASSNAMEW
#else
#define STATUSCLASSNAME  STATUSCLASSNAMEA
#endif

#define SBARS_SIZEGRIP  0x0100
#if (_WIN32_IE >= 0x0500)
#define SBARS_TOOLTIPS  0x0800
#endif
#if (_WIN32_IE >= 0x0400)
#define SBT_TOOLTIPS  0x0800
#endif

#define SB_SETTEXTA  (WM_USER+1)
#define SB_SETTEXTW  (WM_USER+11)
#define SB_GETTEXTA  (WM_USER+2)
#define SB_GETTEXTW  (WM_USER+13)
#define SB_GETTEXTLENGTHA  (WM_USER+3)
#define SB_GETTEXTLENGTHW  (WM_USER+12)
#define SB_SETPARTS  (WM_USER+4)
#define SB_GETPARTS  (WM_USER+6)
#define SB_GETBORDERS  (WM_USER+7)
#define SB_SETMINHEIGHT  (WM_USER+8)
#define SB_SIMPLE  (WM_USER+9)
#define SB_GETRECT  (WM_USER+10)
#define SB_ISSIMPLE  (WM_USER+14)
#if (_WIN32_IE >= 0x0400)
#define SB_SETICON  (WM_USER+15)
#define SB_SETTIPTEXTA  (WM_USER+16)
#define SB_SETTIPTEXTW  (WM_USER+17)
#define SB_GETTIPTEXTA  (WM_USER+18)
#define SB_GETTIPTEXTW  (WM_USER+19)
#define SB_GETICON  (WM_USER+20)
#define SB_SETUNICODEFORMAT  CCM_SETUNICODEFORMAT
#define SB_GETUNICODEFORMAT  CCM_GETUNICODEFORMAT
#endif
#define SB_SETBKCOLOR  CCM_SETBKCOLOR

#define SBT_OWNERDRAW  0x1000
#define SBT_NOBORDERS  0x0100
#define SBT_POPOUT  0x0200
#define SBT_RTLREADING  0x0400
#if (_WIN32_IE >= 0x0500)
#define SBT_NOTABPARSING  0x0800
#endif

#if (_WIN32_IE >= 0x0400)
#define SBN_SIMPLEMODECHANGE  (SBN_FIRST-0)
#endif
#if (_WIN32_IE >= 0x0500)
#define SB_SIMPLEID  0x00ff
#endif

WINCOMMCTRLAPI void WINAPI DrawStatusTextA(HDC,LPRECT,LPCSTR,UINT);
WINCOMMCTRLAPI void WINAPI DrawStatusTextW(HDC,LPRECT,LPCWSTR,UINT);
WINCOMMCTRLAPI HWND WINAPI CreateStatusWindowA(LONG,LPCSTR,HWND,UINT);
WINCOMMCTRLAPI HWND WINAPI CreateStatusWindowW(LONG,LPCWSTR,HWND,UINT);

/* added by Pelles C development team 2000-09-08 */
#define Status_SetText(hwnd,iPart,uType,szText)  (BOOL)SNDMSG((hwnd),SB_SETTEXT,(WPARAM)((iPart)|(uType)),(LPARAM)(LPSTR)(szText))
#define Status_GetText(hwnd,iPart,szText)  (DWORD)SNDMSG((hwnd),SB_GETTEXT,(WPARAM)(iPart),(LPARAM)(LPSTR)(szText))
#define Status_GetTextLength(hwnd,iPart)  (DWORD)SNDMSG((hwnd),SB_GETTEXTLENGTH,(WPARAM)(iPart),0)
#define Status_SetParts(hwnd,nParts,aWidths)  (BOOL)SNDMSG((hwnd),SB_SETPARTS,(WPARAM)(nParts),(LPARAM)(LPINT)(aWidths))
#define Status_GetParts(hwnd,nParts,aRightCoord)  (int)SNDMSG((hwnd),SB_GETPARTS,(WPARAM)(nParts),(LPARAM)(LPINT)(aRightCoord))
#define Status_GetBorders(hwnd,aBorders)  (BOOL)SNDMSG((hwnd),SB_GETBORDERS,0,(LPARAM)(LPINT)(aBorders))
#define Status_SetMinHeight(hwnd,minHeight)  (void)SNDMSG((hwnd),SB_SETMINHEIGHT,(WPARAM)(minHeight),0)
#define Status_Simple(hwnd,fSimple)  (BOOL)SNDMSG((hwnd),SB_SIMPLE,(WPARAM)(BOOL)(fSimple),0)
#define Status_GetRect(hwnd,iPart,lprc)  (BOOL)SNDMSG((hwnd),SB_GETRECT,(WPARAM)(iPart),(LPARAM)(LPRECT)(lprc))
#define Status_IsSimple(hwnd)  (BOOL)SNDMSG((hwnd),SB_ISSIMPLE,0,0)
#if (_WIN32_IE >= 0x0400)
#define Status_SetIcon(hwnd,iPart,hIcon)  (BOOL)SNDMSG((hwnd),SB_SETICON,(WPARAM)(iPart),(LPARAM)(HICON)(hIcon))
#define Status_SetTipText(hwnd,iPart,lpszTooltip)  (void)SNDMSG((hwnd),SB_SETTIPTEXT,(WPARAM)(iPart),(LPARAM)(LPCTSTR)(lpszTooltip))
#define Status_GetTipText(hwnd,iPart,nSize,lpszTooltip)  (void)SNDMSG((hwnd),SB_GETTIPTEXT,MAKEWPARAM((iPart),(nSize)),(LPARAM)(LPCTSTR)(lpszTooltip))
#define Status_GetIcon(hwnd,iPart)  (HICON)SNDMSG((hwnd),SB_GETICON,(WPARAM)(iPart),0)
#define Status_SetUnicodeFormat(hwnd,fUnicode)  (BOOL)SNDMSG((hwnd),SB_SETUNICODEFORMAT,(WPARAM)(fUnicode),0)
#define Status_GetUnicodeFormat(hwnd)  (BOOL)SNDMSG((hwnd),SB_GETUNICODEFORMAT,0,0)
#endif /* _WIN32_IE >= 0x0400 */

#ifdef UNICODE
#define CreateStatusWindow CreateStatusWindowW
#define DrawStatusText DrawStatusTextW
#define SB_GETTEXT SB_GETTEXTW
#define SB_SETTEXT SB_SETTEXTW
#define SB_GETTEXTLENGTH SB_GETTEXTLENGTHW
#if (_WIN32_IE >= 0x0400)
#define SB_SETTIPTEXT SB_SETTIPTEXTW
#define SB_GETTIPTEXT SB_GETTIPTEXTW
#endif
#else
#define CreateStatusWindow CreateStatusWindowA
#define DrawStatusText DrawStatusTextA
#define SB_GETTEXT SB_GETTEXTA
#define SB_SETTEXT SB_SETTEXTA
#define SB_GETTEXTLENGTH SB_GETTEXTLENGTHA
#if (_WIN32_IE >= 0x0400)
#define SB_SETTIPTEXT SB_SETTIPTEXTA
#define SB_GETTIPTEXT SB_GETTIPTEXTA
#endif
#endif

#endif /* NOSTATUSBAR */

/* Meny help ****************************************************************/

#ifndef NOMENUHELP

#define MINSYSCOMMAND  SC_SIZE

WINCOMMCTRLAPI void WINAPI MenuHelp(UINT,WPARAM,LPARAM,HMENU,HINSTANCE,HWND,UINT*);
WINCOMMCTRLAPI BOOL WINAPI ShowHideMenuCtl(HWND,UINT_PTR,LPINT);
WINCOMMCTRLAPI void WINAPI GetEffectiveClientRect(HWND,LPRECT,LPINT);

#endif /* NOMENUHELP */

/* Trackbar Control *********************************************************/

#ifndef NOTRACKBAR

#define TRACKBAR_CLASSA  "msctls_trackbar32"
#define TRACKBAR_CLASSW  L"msctls_trackbar32"

#ifdef UNICODE
#define TRACKBAR_CLASS  TRACKBAR_CLASSW
#else
#define TRACKBAR_CLASS  TRACKBAR_CLASSA
#endif

#define TBS_AUTOTICKS  0x0001
#define TBS_VERT  0x0002
#define TBS_HORZ  0x0000
#define TBS_TOP  0x0004
#define TBS_BOTTOM  0x0000
#define TBS_LEFT  0x0004
#define TBS_RIGHT  0x0000
#define TBS_BOTH  0x0008
#define TBS_NOTICKS  0x0010
#define TBS_ENABLESELRANGE  0x0020
#define TBS_FIXEDLENGTH  0x0040
#define TBS_NOTHUMB  0x0080
#define TBS_TOOLTIPS  0x0100
#if (_WIN32_IE >= 0x0500)
#define TBS_REVERSED  0x0200
#endif
#if (_WIN32_IE >= 0x0501)
#define TBS_DOWNISLEFT  0x0400
#endif

#define TBM_GETPOS  (WM_USER)
#define TBM_GETRANGEMIN  (WM_USER+1)
#define TBM_GETRANGEMAX  (WM_USER+2)
#define TBM_GETTIC  (WM_USER+3)
#define TBM_SETTIC  (WM_USER+4)
#define TBM_SETPOS  (WM_USER+5)
#define TBM_SETRANGE  (WM_USER+6)
#define TBM_SETRANGEMIN  (WM_USER+7)
#define TBM_SETRANGEMAX  (WM_USER+8)
#define TBM_CLEARTICS  (WM_USER+9)
#define TBM_SETSEL  (WM_USER+10)
#define TBM_SETSELSTART  (WM_USER+11)
#define TBM_SETSELEND  (WM_USER+12)
#define TBM_GETPTICS  (WM_USER+14)
#define TBM_GETTICPOS  (WM_USER+15)
#define TBM_GETNUMTICS  (WM_USER+16)
#define TBM_GETSELSTART  (WM_USER+17)
#define TBM_GETSELEND  (WM_USER+18)
#define TBM_CLEARSEL  (WM_USER+19)
#define TBM_SETTICFREQ  (WM_USER+20)
#define TBM_SETPAGESIZE  (WM_USER+21)
#define TBM_GETPAGESIZE  (WM_USER+22)
#define TBM_SETLINESIZE  (WM_USER+23)
#define TBM_GETLINESIZE  (WM_USER+24)
#define TBM_GETTHUMBRECT  (WM_USER+25)
#define TBM_GETCHANNELRECT  (WM_USER+26)
#define TBM_SETTHUMBLENGTH  (WM_USER+27)
#define TBM_GETTHUMBLENGTH  (WM_USER+28)
#define TBM_SETTOOLTIPS  (WM_USER+29)
#define TBM_GETTOOLTIPS  (WM_USER+30)
#define TBM_SETTIPSIDE  (WM_USER+31)
#define TBM_SETBUDDY  (WM_USER+32)
#define TBM_GETBUDDY  (WM_USER+33)
#if (_WIN32_IE >= 0x0400)
#define TBM_SETUNICODEFORMAT  CCM_SETUNICODEFORMAT
#define TBM_GETUNICODEFORMAT  CCM_GETUNICODEFORMAT
#endif

#define TBTS_TOP  0
#define TBTS_LEFT  1
#define TBTS_BOTTOM  2
#define TBTS_RIGHT  3

#define TB_LINEUP  0
#define TB_LINEDOWN  1
#define TB_PAGEUP  2
#define TB_PAGEDOWN  3
#define TB_THUMBPOSITION  4
#define TB_THUMBTRACK  5
#define TB_TOP  6
#define TB_BOTTOM  7
#define TB_ENDTRACK  8

#define TBCD_TICS  0x0001
#define TBCD_THUMB  0x0002
#define TBCD_CHANNEL  0x0003

/* added by Pelles C development team 2000-09-08 */
#define TrackBar_GetPos(hwnd)  (LONG)SNDMSG((hwnd), TBM_GETPOS, 0, 0L)
#define TrackBar_GetRangeMin(hwnd)  (LONG)SNDMSG((hwnd),TBM_GETRANGEMIN,0,0)
#define TrackBar_GetRangeMax(hwnd)  (LONG)SNDMSG((hwnd),TBM_GETRANGEMAX,0,0)
#define TrackBar_GetTic(hwnd,iTic)  (LONG)SNDMSG((hwnd),TBM_GETTIC,(WPARAM)(WORD)(iTic),0)
#define TrackBar_SetTic(hwnd,lPosition)  (BOOL)SNDMSG((hwnd),TBM_SETTIC,0,(LPARAM)(LONG)(lPosition))
#define TrackBar_SetPos(hwnd,bPosition,lPosition)  (void)SNDMSG((hwnd),TBM_SETPOS,(WPARAM)(BOOL)(bPosition),(LPARAM)(LONG)(lPosition))
#define TrackBar_SetRange(hwnd,bRedraw,lMinimum,lMaximum)  (void)SNDMSG((hwnd),TBM_SETRANGE,(WPARAM)(BOOL)(bRedraw),(LPARAM)MAKELONG((lMinimum),(lMaximum)))
#define TrackBar_SetRangeMin(hwnd,bRedraw,lMinimum)  (void)SNDMSG((hwnd),TBM_SETRANGEMIN,(WPARAM)(bRedraw),(LPARAM)(lMinimum))
#define TrackBar_SetRangeMax(hwnd,bRedraw,lMaximum)  (void)SNDMSG((hwnd),TBM_SETRANGEMAX,(WPARAM)(bRedraw),(LPARAM)(lMaximum))
#define TrackBar_ClearTics(hwnd,fRedraw)  (void)SNDMSG((hwnd),TBM_CLEARTICS,(WPARAM)(BOOL)(fRedraw),0)
#define TrackBar_SetSel(hwnd,bRedraw,lMinimum,lMaximum)  (void)SNDMSG((hwnd),TBM_SETSEL,(WPARAM)(BOOL)(bRedraw),(LPARAM)MAKELONG((lMinimum),(lMaximum)))
#define TrackBar_SetSelStart(hwnd,bRedraw,lStart)  (void)SNDMSG((hwnd),TBM_SETSELSTART,(WPARAM)(BOOL)(bRedraw),(LPARAM)(LONG)(lStart))
#define TrackBar_SetSelEnd(hwnd,bRedraw,lEnd)  (void)SNDMSG((hwnd),TBM_SETSELEND,(WPARAM)(BOOL)(bRedraw),(LPARAM)(LONG)(lEnd))
#define TrackBar_GetPTics(hwnd)  (LPLONG)SNDMSG((hwnd),TBM_GETPTICS,0,0)
#define TrackBar_GetTicPos(hwnd,iTic)  (LONG)SNDMSG((hwnd),TBM_GETTICPOS,(WPARAM)(WORD)(iTic),0)
#define TrackBar_GetNumTics(hwnd)  (LONG)SNDMSG((hwnd),TBM_GETNUMTICS,0,0)
#define TrackBar_GetSelStart(hwnd)  (LONG)SNDMSG((hwnd),TBM_GETSELSTART,0,0)
#define TrackBar_GetSelEnd(hwnd)  (LONG)SNDMSG((hwnd),TBM_GETSELEND,0,0)
#define TrackBar_ClearSel(hwnd,fRedraw)  (void)SNDMSG((hwnd),TBM_CLEARSEL,(WPARAM)(BOOL)(fRedraw),0)
#define TrackBar_SetTicFreq(hwnd,wFreq,lPosition)  (void)SNDMSG((hwnd),TBM_SETTICFREQ,(WPARAM)(wFreq),(LPARAM)(LONG)(lPosition))
#define TrackBar_SetPageSize(hwnd,lPageSize)  (LONG)SNDMSG((hwnd),TBM_SETPAGESIZE,0,(LONG)(lPageSize))
#define TrackBar_GetPageSize(hwnd)  (LONG)SNDMSG((hwnd),TBM_GETPAGESIZE,0,0)
#define TrackBar_SetLineSize(hwnd,lLineSize)  (LONG)SNDMSG((hwnd),TBM_SETLINESIZE,0,(LONG)(lLineSize))
#define TrackBar_GetLineSize(hwnd)  (LONG)SNDMSG((hwnd),TBM_GETLINESIZE,0,0)
#define TrackBar_GetThumbRect(hwnd,lprc)  (void)SNDMSG((hwnd),TBM_GETTHUMBRECT,0,(LPARAM)(LPRECT)(lprc))
#define TrackBar_SetThumbLength(hwnd,iLength)  (void)SNDMSG((hwnd),TBM_SETTHUMBLENGTH,(WPARAM)(UINT)(iLength),0)
#define TrackBar_GetThumbLength(hwnd)  (UINT)SNDMSG((hwnd),TBM_GETTHUMBLENGTH,0,0)
#define TrackBar_SetToolTips(hwnd,hwndTT)  (void)SNDMSG((hwnd),TBM_SETTOOLTIPS,(WPARAM)(HWND)(hwndTT),0)
#define TrackBar_GetToolTips(hwnd,hwndTT)  (HWND)SNDMSG((hwnd),TBM_GETTOOLTIPS,0,0)
#define TrackBar_SetTipSide(hwnd,fLocation)  (int)SNDMSG((hwnd),TBM_SETTIPSIDE,(WPARAM)(int)(fLocation),0)
#define TrackBar_SetBuddy(hwnd,fLocation,hwndBuddy)  (HWND)SNDMSG((hwnd),TBM_SETBUDDY,(WPARAM)(BOOL)(fLocation),(LPARAM)(HWND)(hwndBuddy))
#define TrackBar_GetBuddy(hwnd,fLocation)  (HWND)SNDMSG((hwnd),TBM_GETBUDDY,(WPARAM)(BOOL)(fLocation),0)
#if (_WIN32_IE >= 0x0400)
#define Trackbar_SetUnicodeFormat(hwnd,fUnicode)  (BOOL)SNDMSG((hwnd),TBM_SETUNICODEFORMAT,(WPARAM)(BOOL)(fUnicode),0)
#define Trackbar_GetUnicodeFormat(hwnd)  (BOOL)SNDMSG((hwnd),TBM_GETUNICODEFORMAT,0,0)
#endif /* _WIN32_IE >= 0x0400 */

#endif /* NOTRACKBAR */

/* Drag list Control ********************************************************/

#ifndef NODRAGLIST

#define DRAGLISTMSGSTRING  TEXT("commctrl_DragListMsg")

#define DL_BEGINDRAG  (WM_USER+133)
#define DL_DRAGGING  (WM_USER+134)
#define DL_DROPPED  (WM_USER+135)
#define DL_CANCELDRAG  (WM_USER+136)

#define DL_CURSORSET  0
#define DL_STOPCURSOR  1
#define DL_COPYCURSOR  2
#define DL_MOVECURSOR  3

typedef struct tagDRAGLISTINFO {
    UINT uNotification;
    HWND hWnd;
    POINT ptCursor;
} DRAGLISTINFO, *LPDRAGLISTINFO;

WINCOMMCTRLAPI BOOL WINAPI MakeDragList(HWND);
WINCOMMCTRLAPI void WINAPI DrawInsert(HWND,HWND,int);
WINCOMMCTRLAPI int WINAPI LBItemFromPt(HWND,POINT,BOOL);

#endif /* NODRAGLIST */

/* UpDown Control ***********************************************************/

#ifndef NOUPDOWN

#define UPDOWN_CLASSA  "msctls_updown32"
#define UPDOWN_CLASSW  L"msctls_updown32"

#ifdef UNICODE
#define UPDOWN_CLASS  UPDOWN_CLASSW
#else
#define UPDOWN_CLASS  UPDOWN_CLASSA
#endif

#define UD_MAXVAL  0x7fff
#define UD_MINVAL  (-UD_MAXVAL)

#define UDS_WRAP  0x0001
#define UDS_SETBUDDYINT  0x0002
#define UDS_ALIGNRIGHT  0x0004
#define UDS_ALIGNLEFT  0x0008
#define UDS_AUTOBUDDY  0x0010
#define UDS_ARROWKEYS  0x0020
#define UDS_HORZ  0x0040
#define UDS_NOTHOUSANDS  0x0080
#define UDS_HOTTRACK  0x0100
#ifdef _WINCE 
#define UDS_EXPANDABLE  0x200  /* Smartphone only */
#define UDS_NOSCROLL  0x400  /* Smartphone only */
#endif /* _WINCE */

#define UDM_SETRANGE  (WM_USER+101)
#define UDM_GETRANGE  (WM_USER+102)
#define UDM_SETPOS  (WM_USER+103)
#define UDM_GETPOS  (WM_USER+104)
#define UDM_SETBUDDY  (WM_USER+105)
#define UDM_GETBUDDY  (WM_USER+106)
#define UDM_SETACCEL  (WM_USER+107)
#define UDM_GETACCEL  (WM_USER+108)
#define UDM_SETBASE  (WM_USER+109)
#define UDM_GETBASE  (WM_USER+110)
#if (_WIN32_IE >= 0x0400)
#define UDM_SETRANGE32  (WM_USER+111)
#define UDM_GETRANGE32  (WM_USER+112)
#define UDM_SETUNICODEFORMAT  CCM_SETUNICODEFORMAT
#define UDM_GETUNICODEFORMAT  CCM_GETUNICODEFORMAT
#endif
#if (_WIN32_IE >= 0x0500)
#define UDM_SETPOS32  (WM_USER+113)
#define UDM_GETPOS32  (WM_USER+114)
#endif

#define UDN_DELTAPOS  (UDN_FIRST-1)
#ifdef _WINCE
#define UDN_EXPANDING  (UDN_FIRST-2)  /* Smartphone only */
#endif /* _WINCE */

#define NM_UPDOWN NMUPDOWN
#define LPNM_UPDOWN LPNMUPDOWN

typedef struct _UDACCEL {
    UINT nSec;
    UINT nInc;
} UDACCEL, *LPUDACCEL;

typedef struct _NM_UPDOWN {
    NMHDR hdr;
    int iPos;
    int iDelta;
} NMUPDOWN, *LPNMUPDOWN;

WINCOMMCTRLAPI HWND WINAPI CreateUpDownControl(DWORD,int,int,int,int,HWND,int,HINSTANCE,HWND,int,int,int);

/* for some reason not defined by Micro$oft */
#define UpDown_SetRange(hwnd,nUpper,nLower)  (void)SNDMSG((hwnd),UDM_SETRANGE,0,(LPARAM)MAKELONG((short)nUpper,(short)nLower))
#define UpDown_GetRange(hwnd)  (DWORD)SNDMSG((hwnd),UDM_GETRANGE,0,0L)
#define UpDown_SetPos(hwnd,nPos)  (short)SNDMSG((hwnd),UDM_SETPOS,0,(LPARAM)MAKELONG(nPos,0))
#define UpDown_GetPos(hwnd)  (DWORD)SNDMSG((hwnd),UDM_GETPOS,0,0L)
#define UpDown_SetBuddy(hwnd,hwndBuddy)  (HWND)SNDMSG((hwnd),UDM_SETBUDDY,(WPARAM)(HWND)hwndBuddy,0L)
#define UpDown_GetBuddy(hwnd)  (HWND)SNDMSG((hwnd),UDM_GETBUDDY,0,0L)
#define UpDown_SetAccel(hwnd,nAccels,aAccels)  (BOOL)SNDMSG((hwnd),UDM_SETACCEL,(WPARAM)nAccels,(LPARAM)(LPUDACCEL)aAccels)
#define UpDown_GetAccel(hwnd,cAccels,paAccels)  (int)SNDMSG((hwnd),UDM_GETACCEL,(WPARAM)cAccels,(LPARAM)(LPUDACCEL)paAccels)
#define UpDown_SetBase(hwnd,nBase)  (int)SNDMSG((hwnd),UDM_SETBASE,(WPARAM)nBase,0L)
#define UpDown_GetBase(hwnd)  (int)SNDMSG((hwnd),UDM_GETBASE,0,0L)
#if (_WIN32_IE >= 0x0500)
#define UpDown_SetRange32(hwnd,iLow,iHigh)  (void)SNDMSG((hwnd),UDM_SETRANGE32,(WPARAM)(int)iLow,(LPARAM)(int)iHigh)
#define UpDown_GetRange32(hwnd,pLow,pHigh)  (void)SNDMSG((hwnd),UDM_GETRANGE32,(WPARAM)(LPINT)pLow,(LPARAM)(LPINT)pHigh)
#endif

#endif /* NOUPDOWN */

/* Progress Control *********************************************************/

#ifndef NOPROGRESS

#define PROGRESS_CLASSA  "msctls_progress32"
#define PROGRESS_CLASSW  L"msctls_progress32"

#ifdef UNICODE
#define  PROGRESS_CLASS  PROGRESS_CLASSW
#else
#define  PROGRESS_CLASS  PROGRESS_CLASSA
#endif

#define PBS_SMOOTH  0x01
#define PBS_VERTICAL  0x04
#if (_WIN32_WINNT >= 0x0501)
#define PBS_MARQUEE  0x08
#endif

#define PBM_SETRANGE  (WM_USER+1)
#define PBM_SETPOS  (WM_USER+2)
#define PBM_DELTAPOS  (WM_USER+3)
#define PBM_SETSTEP  (WM_USER+4)
#define PBM_STEPIT  (WM_USER+5)
#define PBM_SETRANGE32  (WM_USER+6)
#define PBM_GETRANGE  (WM_USER+7)
#define PBM_GETPOS  (WM_USER+8)
#if (_WIN32_IE >= 0x0400)
#define PBM_SETBARCOLOR  (WM_USER+9)
#define PBM_SETBKCOLOR  CCM_SETBKCOLOR
#endif
#if (_WIN32_WINNT >= 0x0501)
#define PBM_SETMARQUEE  (WM_USER+10)
#endif

typedef struct {
   int iLow;
   int iHigh;
} PBRANGE, *PPBRANGE;

/* added by Pelles C development team 2000-09-08 */
#define Progress_SetRange(hwnd,nMinRange,nMaxRange)  (DWORD)SNDMSG((hwnd),PBM_SETRANGE,0,MAKELPARAM((nMinRange),(nMaxRange)))
#define Progress_SetPos(hwnd,nNewPos)  (int)SNDMSG((hwnd),PBM_SETPOS,(WPARAM)(nNewPos),0)
#define Progress_DeltaPos(hwnd,nIncrement)  (int)SNDMSG((hwnd),PBM_DELTAPOS,(WPARAM)(nIncrement),0)
#define Progress_SetStep(hwnd,nStepInc)  (int)SNDMSG((hwnd),PBM_SETSTEP,(WPARAM)(nStepInc),0)
#define Progress_StepIt(hwnd)  (int)SNDMSG((hwnd),PBM_STEPIT,0,0)
#define Progress_SetRange32(hwnd,iLowLim,iHighLim)  (DWORD)SNDMSG((hwnd),PBM_SETRANGE32,(WPARAM)(int)(iLowLim),(LPARAM)(int)(iHighLim))
#define Progress_GetRange(hwnd,fWhichLimit,ppBRange)  (int)SNDMSG((hwnd),PBM_GETRANGE,(WPARAM)(BOOL)(fWhichLimit),(LPARAM)(PPBRANGE)(ppBRange))
#define Progress_GetPos(hwnd)  (int)SNDMSG((hwnd),PBM_GETPOS,0,0)
#if (_WIN32_IE >= 0x0400)
#define Progress_SetBarColor(hwnd,clrBar)  (COLORREF)SNDMSG((hwnd),PBM_SETBARCOLOR,0,(LPARAM)(COLORREF)(clrBar))
#define Progress_SetBkColor(hwnd,clrBk)  (COLORREF)SNDMSG((hwnd),PBM_SETBKCOLOR,0,(LPARAM)(COLORREF)(clrBk))
#endif /* _WIN32_IE >= 0x0400 */
#if (_WIN32_WINNT >= 0x0501)
#define Progress_SetMarquee(hwnd,fMarquee,ms)  (BOOL)SNDMSG((hwnd),PBM_SETMARQUEE,(WPARAM)(BOOL)(fMarquee),(LPARAM)(UINT)(ms))
#endif

#endif /* NOPROGRESS */

/* HotKey Control ***********************************************************/

#ifndef NOHOTKEY

#define HOTKEY_CLASSA  "msctls_hotkey32"
#define HOTKEY_CLASSW  L"msctls_hotkey32"

#ifdef UNICODE
#define HOTKEY_CLASS  HOTKEY_CLASSW
#else
#define HOTKEY_CLASS  HOTKEY_CLASSA
#endif

#define HOTKEYF_SHIFT  0x01
#define HOTKEYF_CONTROL  0x02
#define HOTKEYF_ALT  0x04
#define HOTKEYF_EXT  0x08

#define HKCOMB_NONE  0x0001
#define HKCOMB_S  0x0002
#define HKCOMB_C  0x0004
#define HKCOMB_A  0x0008
#define HKCOMB_SC  0x0010
#define HKCOMB_SA  0x0020
#define HKCOMB_CA  0x0040
#define HKCOMB_SCA  0x0080

#define HKM_SETHOTKEY  (WM_USER+1)
#define HKM_GETHOTKEY  (WM_USER+2)
#define HKM_SETRULES  (WM_USER+3)

/* added by Pelles C development team 2000-09-08 */
#define HotKey_SetHotKey(hwnd,bVKHotKey,bfMods)  (void)SNDMSG((hwnd),HKM_SETHOTKEY,MAKEWORD((bVKHotKey),(bfMods)),0)
#define HotKey_GetHotKey(hwnd)  (WORD)SNDMSG((hwnd),HKM_GETHOTKEY,0,0)
#define HotKey_SetRules(hwnd,fwCombInv,fwModInv)  (void)SNDMSG((hwnd),HKM_SETRULES,(WPARAM)fwCombInv,MAKELPARAM(fwModInv,0))

#endif /* NOHOTKEY */

/* ListView Control *********************************************************/

#ifndef NOLISTVIEW

#define WC_LISTVIEWA  "SysListView32"
#define WC_LISTVIEWW  L"SysListView32"

#ifdef UNICODE
#define WC_LISTVIEW  WC_LISTVIEWW
#else
#define WC_LISTVIEW  WC_LISTVIEWA
#endif

#define LVS_ICON  0x0000
#define LVS_REPORT  0x0001
#define LVS_SMALLICON  0x0002
#define LVS_LIST  0x0003
#define LVS_TYPEMASK  0x0003
#define LVS_SINGLESEL  0x0004
#define LVS_SHOWSELALWAYS  0x0008
#define LVS_SORTASCENDING  0x0010
#define LVS_SORTDESCENDING  0x0020
#define LVS_SHAREIMAGELISTS  0x0040
#define LVS_NOLABELWRAP  0x0080
#define LVS_AUTOARRANGE  0x0100
#define LVS_EDITLABELS  0x0200
#define LVS_OWNERDATA  0x1000
#define LVS_NOSCROLL  0x2000
#define LVS_TYPESTYLEMASK  0xfc00
#define LVS_ALIGNTOP  0x0000
#define LVS_ALIGNLEFT  0x0800
#define LVS_ALIGNMASK  0x0c00
#define LVS_OWNERDRAWFIXED  0x0400
#define LVS_NOCOLUMNHEADER  0x4000
#define LVS_NOSORTHEADER  0x8000

#define LVS_EX_GRIDLINES  0x00000001
#define LVS_EX_SUBITEMIMAGES  0x00000002
#define LVS_EX_CHECKBOXES  0x00000004
#define LVS_EX_TRACKSELECT  0x00000008
#define LVS_EX_HEADERDRAGDROP  0x00000010
#define LVS_EX_FULLROWSELECT  0x00000020
#define LVS_EX_ONECLICKACTIVATE 0x00000040
#define LVS_EX_TWOCLICKACTIVATE 0x00000080
#if (_WIN32_IE >= 0x0400)
#define LVS_EX_FLATSB  0x00000100
#define LVS_EX_REGIONAL  0x00000200
#define LVS_EX_INFOTIP  0x00000400
#define LVS_EX_UNDERLINEHOT  0x00000800
#define LVS_EX_UNDERLINECOLD  0x00001000
#define LVS_EX_MULTIWORKAREAS  0x00002000
#endif
#if (_WIN32_IE >= 0x0500)
#define LVS_EX_LABELTIP  0x00004000
#define LVS_EX_BORDERSELECT  0x00008000
#endif
#if (_WIN32_WINNT >= 0x501)
#define LVS_EX_DOUBLEBUFFER  0x00010000
#define LVS_EX_HIDELABELS  0x00020000
#define LVS_EX_SINGLEROW  0x00040000
#define LVS_EX_SNAPTOGRID  0x00080000
#define LVS_EX_SIMPLESELECT  0x00100000
#endif
#ifdef _WINCE
#define LVS_EX_NOHSCROLL  0x10000000  /* Smartphone only? */
#endif /* _WINCE */

#define LVSIL_NORMAL  0
#define LVSIL_SMALL  1
#define LVSIL_STATE  2
#ifdef _WINCE
#define LVSIL_HEADER  3
#endif /* _WINCE */

#ifdef _WINCE
#define LVBD_DRAGSELECT  200
#endif /* _WINCE */

#define LVIF_TEXT  0x0001
#define LVIF_IMAGE  0x0002
#define LVIF_PARAM  0x0004
#define LVIF_STATE  0x0008
#define LVIF_INDENT  0x0010
#define LVIF_NORECOMPUTE  0x0800
#if (_WIN32_WINNT >= 0x501)
#define LVIF_GROUPID  0x0100
#define LVIF_COLUMNS  0x0200
#endif

#define LVIS_FOCUSED  0x0001
#define LVIS_SELECTED  0x0002
#define LVIS_CUT  0x0004
#define LVIS_DROPHILITED  0x0008
#define LVIS_ACTIVATING  0x0020

#define LVIS_OVERLAYMASK  0x0F00
#define LVIS_STATEIMAGEMASK  0xF000

#define LPSTR_TEXTCALLBACKW  ((LPWSTR)-1L)
#define LPSTR_TEXTCALLBACKA  ((LPSTR)-1L)

#define INDEXTOSTATEIMAGEMASK(i) ((i)<<12)

#define I_INDENTCALLBACK  (-1)
#define I_IMAGECALLBACK  (-1)
#if (_WIN32_IE >= 0x0501)
#define I_IMAGENONE  (-2)
#endif
#if (_WIN32_WINNT >= 0x501)
#define I_GROUPIDCALLBACK  (-1)
#define I_GROUPIDNONE  (-2)
#define I_COLUMNSCALLBACK  ((UINT)-1)
#endif

#define LVNI_ALL  0x0000
#define LVNI_FOCUSED  0x0001
#define LVNI_SELECTED  0x0002
#define LVNI_CUT  0x0004
#define LVNI_DROPHILITED  0x0008

#define LVNI_ABOVE  0x0100
#define LVNI_BELOW  0x0200
#define LVNI_TOLEFT  0x0400
#define LVNI_TORIGHT  0x0800

#define LVFI_PARAM  0x0001
#define LVFI_STRING  0x0002
#define LVFI_PARTIAL  0x0008
#define LVFI_WRAP  0x0020
#define LVFI_NEARESTXY  0x0040

#define LVIR_BOUNDS  0
#define LVIR_ICON  1
#define LVIR_LABEL  2
#define LVIR_SELECTBOUNDS  3

#define LVHT_NOWHERE  0x0001
#define LVHT_ONITEMICON  0x0002
#define LVHT_ONITEMLABEL  0x0004
#define LVHT_ONITEMSTATEICON  0x0008
#define LVHT_ONITEM  (LVHT_ONITEMICON|LVHT_ONITEMLABEL|LVHT_ONITEMSTATEICON)
#define LVHT_ABOVE  0x0008
#define LVHT_BELOW  0x0010
#define LVHT_TORIGHT  0x0020
#define LVHT_TOLEFT  0x0040

#define LVA_DEFAULT  0x0000
#define LVA_ALIGNLEFT  0x0001
#define LVA_ALIGNTOP  0x0002
#define LVA_SNAPTOGRID  0x0005

#define LVCF_FMT  0x0001
#define LVCF_WIDTH  0x0002
#define LVCF_TEXT  0x0004
#define LVCF_SUBITEM  0x0008
#define LVCF_IMAGE  0x0010
#define LVCF_ORDER  0x0020

#define LVCFMT_LEFT  0x0000
#define LVCFMT_RIGHT  0x0001
#define LVCFMT_CENTER  0x0002
#define LVCFMT_JUSTIFYMASK  0x0003

#define LVCFMT_IMAGE  0x0800
#define LVCFMT_BITMAP_ON_RIGHT  0x1000
#define LVCFMT_COL_HAS_IMAGES  0x8000

#define LVSCW_AUTOSIZE  -1
#define LVSCW_AUTOSIZE_USEHEADER  -2

#define LVSICF_NOINVALIDATEALL  0x00000001
#define LVSICF_NOSCROLL  0x00000002

#if (_WIN32_IE >= 0x0400)
#define LV_MAX_WORKAREAS  16

#define LVBKIF_SOURCE_NONE  0x00000000
#define LVBKIF_SOURCE_HBITMAP  0x00000001
#define LVBKIF_SOURCE_URL  0x00000002
#define LVBKIF_SOURCE_MASK  0x00000003
#define LVBKIF_STYLE_NORMAL  0x00000000
#define LVBKIF_STYLE_TILE  0x00000010
#define LVBKIF_STYLE_MASK  0x00000010
#endif
#if (_WIN32_WINNT >= 0x501)
#define LVBKIF_FLAG_TILEOFFSET  0x00000100
#define LVBKIF_TYPE_WATERMARK  0x10000000
#endif

#if (_WIN32_IE >= 0x400)
#define LVKF_ALT  0x0001
#define LVKF_CONTROL  0x0002
#define LVKF_SHIFT  0x0004
#endif

#if (_WIN32_WINNT >= 0x501)
#define LV_VIEW_ICON  0x0000
#define LV_VIEW_DETAILS  0x0001
#define LV_VIEW_SMALLICON  0x0002
#define LV_VIEW_LIST  0x0003
#define LV_VIEW_TILE  0x0004
#define LV_VIEW_MAX  0x0004

#define LVGF_NONE  0x00000000
#define LVGF_HEADER  0x00000001
#define LVGF_FOOTER  0x00000002
#define LVGF_STATE  0x00000004
#define LVGF_ALIGN  0x00000008
#define LVGF_GROUPID  0x00000010

#define LVGS_NORMAL  0x00000000
#define LVGS_COLLAPSED  0x00000001
#define LVGS_HIDDEN  0x00000002

#define LVGA_HEADER_LEFT  0x00000001
#define LVGA_HEADER_CENTER  0x00000002
#define LVGA_HEADER_RIGHT  0x00000004
#define LVGA_FOOTER_LEFT  0x00000008
#define LVGA_FOOTER_CENTER  0x00000010
#define LVGA_FOOTER_RIGHT  0x00000020

#define LVGMF_NONE  0x00000000
#define LVGMF_BORDERSIZE  0x00000001
#define LVGMF_BORDERCOLOR  0x00000002
#define LVGMF_TEXTCOLOR  0x00000004

#define LVTVIF_AUTOSIZE  0x00000000
#define LVTVIF_FIXEDWIDTH  0x00000001
#define LVTVIF_FIXEDHEIGHT  0x00000002
#define LVTVIF_FIXEDSIZE  0x00000003

#define LVTVIM_TILESIZE  0x00000001
#define LVTVIM_COLUMNS  0x00000002
#define LVTVIM_LABELMARGIN  0x00000004

#define LVIM_AFTER  0x00000001
#endif

#define LVIF_DI_SETITEM  0x1000

#define LVGIT_UNFOLDED  0x0001

#define LV_ITEMA LVITEMA
#define LV_ITEMW LVITEMW
#define LV_ITEM LVITEM

#define LVITEMA_V1_SIZE CCSIZEOF_STRUCT(LVITEMA,lParam)
#define LVITEMW_V1_SIZE CCSIZEOF_STRUCT(LVITEMW,lParam)

#define LV_FINDINFOA LVFINDINFOA
#define LV_FINDINFOW LVFINDINFOW
#define LV_FINDINFO LVFINDINFO

#define LV_HITTESTINFO LVHITTESTINFO
#define LVHITTESTINFO_V1_SIZE CCSIZEOF_STRUCT(LVHITTESTINFO,iItem)

#define LV_COLUMNA LVCOLUMNA
#define LV_COLUMNW LVCOLUMNW
#define LV_COLUMN LVCOLUMN

#define LVCOLUMNA_V1_SIZE CCSIZEOF_STRUCT(LVCOLUMNA,iSubItem)
#define LVCOLUMNW_V1_SIZE CCSIZEOF_STRUCT(LVCOLUMNW,iSubItem)

#define LV_DISPINFOA NMLVDISPINFOA
#define LV_DISPINFOW NMLVDISPINFOW
#define LV_DISPINFO NMLVDISPINFO

#define LV_KEYDOWN NMLVKEYDOWN

#define LPNM_LISTVIEW LPNMLISTVIEW
#define NM_LISTVIEW NMLISTVIEW

#define NMLVCUSTOMDRAW_V3_SIZE CCSIZEOF_STRUCT(NMLVCUSTOMDRW,clrTextBk)

#define LPNM_CACHEHINT LPNMLVCACHEHINT
#define PNM_CACHEHINT LPNMLVCACHEHINT
#define NM_CACHEHINT NMLVCACHEHINT

#define PNM_FINDITEMA LPNMLVFINDITEMA
#define LPNM_FINDITEMA LPNMLVFINDITEMA
#define NM_FINDITEMA NMLVFINDITEMA

#define PNM_FINDITEMW LPNMLVFINDITEMW
#define LPNM_FINDITEMW LPNMLVFINDITEMW
#define NM_FINDITEMW NMLVFINDITEMW

#define PNM_ODSTATECHANGE LPNMLVODSTATECHANGE
#define LPNM_ODSTATECHANGE LPNMLVODSTATECHANGE
#define NM_ODSTATECHANGE NMLVODSTATECHANGE

#if (_WIN32_IE >= 0x0400)
#define LVM_SETUNICODEFORMAT  CCM_SETUNICODEFORMAT
#define LVM_GETUNICODEFORMAT  CCM_GETUNICODEFORMAT
#endif
#define LVM_GETBKCOLOR  (LVM_FIRST+0)
#define LVM_SETBKCOLOR  (LVM_FIRST+1)
#define LVM_GETIMAGELIST  (LVM_FIRST+2)
#define LVM_SETIMAGELIST  (LVM_FIRST+3)
#define LVM_GETITEMCOUNT  (LVM_FIRST+4)
#define LVM_GETITEMA  (LVM_FIRST+5)
#define LVM_GETITEMW  (LVM_FIRST+75)
#define LVM_SETITEMA  (LVM_FIRST+6)
#define LVM_SETITEMW  (LVM_FIRST+76)
#define LVM_INSERTITEMA  (LVM_FIRST+7)
#define LVM_INSERTITEMW  (LVM_FIRST+77)
#define LVM_DELETEITEM  (LVM_FIRST+8)
#define LVM_DELETEALLITEMS  (LVM_FIRST+9)
#define LVM_GETCALLBACKMASK  (LVM_FIRST+10)
#define LVM_SETCALLBACKMASK  (LVM_FIRST+11)
#define LVM_GETNEXTITEM  (LVM_FIRST+12)
#define LVM_FINDITEMA  (LVM_FIRST+13)
#define LVM_FINDITEMW  (LVM_FIRST+83)
#define LVM_GETITEMRECT  (LVM_FIRST+14)
#define LVM_SETITEMPOSITION  (LVM_FIRST+15)
#define LVM_GETITEMPOSITION  (LVM_FIRST+16)
#define LVM_GETSTRINGWIDTHA  (LVM_FIRST+17)
#define LVM_GETSTRINGWIDTHW  (LVM_FIRST+87)
#define LVM_HITTEST  (LVM_FIRST+18)
#define LVM_ENSUREVISIBLE  (LVM_FIRST+19)
#define LVM_SCROLL  (LVM_FIRST+20)
#define LVM_REDRAWITEMS  (LVM_FIRST+21)
#define LVM_ARRANGE  (LVM_FIRST+22)
#define LVM_EDITLABELA  (LVM_FIRST+23)
#define LVM_EDITLABELW  (LVM_FIRST+118)
#define LVM_GETEDITCONTROL  (LVM_FIRST+24)
#define LVM_GETCOLUMNA  (LVM_FIRST+25)
#define LVM_GETCOLUMNW  (LVM_FIRST+95)
#define LVM_SETCOLUMNA  (LVM_FIRST+26)
#define LVM_SETCOLUMNW  (LVM_FIRST+96)
#define LVM_INSERTCOLUMNA  (LVM_FIRST+27)
#define LVM_INSERTCOLUMNW  (LVM_FIRST+97)
#define LVM_DELETECOLUMN  (LVM_FIRST+28)
#define LVM_GETCOLUMNWIDTH  (LVM_FIRST+29)
#define LVM_SETCOLUMNWIDTH  (LVM_FIRST+30)
#define LVM_GETHEADER  (LVM_FIRST+31)
#define LVM_CREATEDRAGIMAGE  (LVM_FIRST+33)
#define LVM_GETVIEWRECT  (LVM_FIRST+34)
#define LVM_GETTEXTCOLOR  (LVM_FIRST+35)
#define LVM_SETTEXTCOLOR  (LVM_FIRST+36)
#define LVM_GETTEXTBKCOLOR  (LVM_FIRST+37)
#define LVM_SETTEXTBKCOLOR  (LVM_FIRST+38)
#define LVM_GETTOPINDEX  (LVM_FIRST+39)
#define LVM_GETCOUNTPERPAGE  (LVM_FIRST+40)
#define LVM_GETORIGIN  (LVM_FIRST+41)
#define LVM_UPDATE  (LVM_FIRST+42)
#define LVM_SETITEMSTATE  (LVM_FIRST+43)
#define LVM_GETITEMSTATE  (LVM_FIRST+44)
#define LVM_GETITEMTEXTA  (LVM_FIRST+45)
#define LVM_GETITEMTEXTW  (LVM_FIRST+115)
#define LVM_SETITEMTEXTA  (LVM_FIRST+46)
#define LVM_SETITEMTEXTW  (LVM_FIRST+116)
#define LVM_SETITEMCOUNT  (LVM_FIRST+47)
#define LVM_SORTITEMS  (LVM_FIRST+48)
#define LVM_SETITEMPOSITION32  (LVM_FIRST+49)
#define LVM_GETSELECTEDCOUNT  (LVM_FIRST+50)
#define LVM_GETITEMSPACING  (LVM_FIRST+51)
#define LVM_GETISEARCHSTRINGA  (LVM_FIRST+52)
#define LVM_GETISEARCHSTRINGW  (LVM_FIRST+117)
#define LVM_SETICONSPACING  (LVM_FIRST+53)
#define LVM_SETEXTENDEDLISTVIEWSTYLE (LVM_FIRST+54)
#define LVM_GETEXTENDEDLISTVIEWSTYLE (LVM_FIRST+55)
#define LVM_GETSUBITEMRECT  (LVM_FIRST+56)
#define LVM_SUBITEMHITTEST  (LVM_FIRST+57)
#define LVM_SETCOLUMNORDERARRAY (LVM_FIRST+58)
#define LVM_GETCOLUMNORDERARRAY (LVM_FIRST+59)
#define LVM_SETHOTITEM  (LVM_FIRST+60)
#define LVM_GETHOTITEM  (LVM_FIRST+61)
#define LVM_SETHOTCURSOR  (LVM_FIRST+62)
#define LVM_GETHOTCURSOR  (LVM_FIRST+63)
#define LVM_APPROXIMATEVIEWRECT (LVM_FIRST+64)
#if (_WIN32_IE >= 0x0400)
#define LVM_SETWORKAREAS  (LVM_FIRST+65)
#define LVM_GETWORKAREAS  (LVM_FIRST+70)
#define LVM_GETNUMBEROFWORKAREAS (LVM_FIRST+73)
#define LVM_GETSELECTIONMARK  (LVM_FIRST+66)
#define LVM_SETSELECTIONMARK  (LVM_FIRST+67)
#define LVM_SETHOVERTIME  (LVM_FIRST+71)
#define LVM_GETHOVERTIME  (LVM_FIRST+72)
#define LVM_SETTOOLTIPS  (LVM_FIRST+74)
#define LVM_GETTOOLTIPS  (LVM_FIRST+78)
#define LVM_SORTITEMSEX  (LVM_FIRST+81)
#define LVM_SETBKIMAGEA  (LVM_FIRST+68)
#define LVM_SETBKIMAGEW  (LVM_FIRST+138)
#define LVM_GETBKIMAGEA  (LVM_FIRST+69)
#define LVM_GETBKIMAGEW  (LVM_FIRST+139)
#endif
#if (_WIN32_WINNT >= 0x501)
#define LVM_SETSELECTEDCOLUMN  (LVM_FIRST+140)
#define LVM_SETTILEWIDTH  (LVM_FIRST+141)
#define LVM_SETVIEW  (LVM_FIRST+142)
#define LVM_GETVIEW  (LVM_FIRST+143)
#define LVM_INSERTGROUP  (LVM_FIRST+145)
#define LVM_SETGROUPINFO  (LVM_FIRST+147)
#define LVM_GETGROUPINFO  (LVM_FIRST+149)
#define LVM_REMOVEGROUP  (LVM_FIRST+150)
#define LVM_MOVEGROUP  (LVM_FIRST+151)
#define LVM_MOVEITEMTOGROUP  (LVM_FIRST+154)
#define LVM_SETGROUPMETRICS  (LVM_FIRST+155)
#define LVM_GETGROUPMETRICS  (LVM_FIRST+156)
#define LVM_ENABLEGROUPVIEW  (LVM_FIRST+157)
#define LVM_SORTGROUPS  (LVM_FIRST+158)
#define LVM_INSERTGROUPSORTED  (LVM_FIRST+159)
#define LVM_REMOVEALLGROUPS  (LVM_FIRST+160)
#define LVM_HASGROUP  (LVM_FIRST+161)
#define LVM_SETTILEVIEWINFO  (LVM_FIRST+162)
#define LVM_GETTILEVIEWINFO  (LVM_FIRST+163)
#define LVM_SETTILEINFO  (LVM_FIRST+164)
#define LVM_GETTILEINFO  (LVM_FIRST+165)
#define LVM_SETINSERTMARK  (LVM_FIRST+166)
#define LVM_GETINSERTMARK  (LVM_FIRST+167)
#define LVM_INSERTMARKHITTEST  (LVM_FIRST+168)
#define LVM_GETINSERTMARKRECT  (LVM_FIRST+169)
#define LVM_SETINSERTMARKCOLOR (LVM_FIRST+170)
#define LVM_GETINSERTMARKCOLOR  (LVM_FIRST+171)
#define LVM_SETINFOTIP  (LVM_FIRST+173)
#define LVM_GETSELECTEDCOLUMN  (LVM_FIRST+174)
#define LVM_ISGROUPVIEWENABLED  (LVM_FIRST+175)
#define LVM_GETOUTLINECOLOR  (LVM_FIRST+176)
#define LVM_SETOUTLINECOLOR  (LVM_FIRST+177)
#define LVM_CANCELEDITLABEL  (LVM_FIRST+179)
#define LVM_MAPINDEXTOID  (LVM_FIRST+180)
#define LVM_MAPIDTOINDEX  (LVM_FIRST+181)
#endif /* _WIN32_WINNT >= 0x501 */

#define LVN_ITEMCHANGING  (LVN_FIRST-0)
#define LVN_ITEMCHANGED  (LVN_FIRST-1)
#define LVN_INSERTITEM  (LVN_FIRST-2)
#define LVN_DELETEITEM  (LVN_FIRST-3)
#define LVN_DELETEALLITEMS  (LVN_FIRST-4)
#define LVN_BEGINLABELEDITA  (LVN_FIRST-5)
#define LVN_BEGINLABELEDITW  (LVN_FIRST-75)
#define LVN_ENDLABELEDITA  (LVN_FIRST-6)
#define LVN_ENDLABELEDITW  (LVN_FIRST-76)
#define LVN_COLUMNCLICK  (LVN_FIRST-8)
#define LVN_BEGINDRAG  (LVN_FIRST-9)
#define LVN_BEGINRDRAG  (LVN_FIRST-11)
#define LVN_ODCACHEHINT  (LVN_FIRST-13)
#define LVN_ODFINDITEMA  (LVN_FIRST-52)
#define LVN_ODFINDITEMW  (LVN_FIRST-79)
#define LVN_ITEMACTIVATE  (LVN_FIRST-14)
#define LVN_ODSTATECHANGED  (LVN_FIRST-15)
#if (_WIN32_IE >= 0x0400)
#define LVN_HOTTRACK  (LVN_FIRST-21)
#endif
#define LVN_GETDISPINFOA  (LVN_FIRST-50)
#define LVN_GETDISPINFOW  (LVN_FIRST-77)
#define LVN_SETDISPINFOA  (LVN_FIRST-51)
#define LVN_SETDISPINFOW  (LVN_FIRST-78)
#define LVN_KEYDOWN  (LVN_FIRST-55)
#define LVN_MARQUEEBEGIN  (LVN_FIRST-56)
#define LVN_GETINFOTIPA  (LVN_FIRST-57)
#define LVN_GETINFOTIPW  (LVN_FIRST-58)
#if (_WIN32_WINNT >= 0x501)
#define LVN_BEGINSCROLL  (LVN_FIRST-80)
#define LVN_ENDSCROLL  (LVN_FIRST-81)
#endif

typedef struct tagLVITEMA {
    UINT mask;
    int iItem;
    int iSubItem;
    UINT state;
    UINT stateMask;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    LPARAM lParam;
    int iIndent;
#if (_WIN32_WINNT >= 0x501)
    int iGroupId;
    UINT cColumns;
    PUINT puColumns;
#endif
} LVITEMA, *LPLVITEMA;

typedef struct tagLVITEMW {
    UINT mask;
    int iItem;
    int iSubItem;
    UINT state;
    UINT stateMask;
    LPWSTR pszText;
    int cchTextMax;
    int iImage;
    LPARAM lParam;
    int iIndent;
#if (_WIN32_WINNT >= 0x501)
    int iGroupId;
    UINT cColumns;
    PUINT puColumns;
#endif
} LVITEMW, *LPLVITEMW;

typedef struct tagLVFINDINFOA {
    UINT flags;
    LPCSTR psz;
    LPARAM lParam;
    POINT pt;
    UINT vkDirection;
} LVFINDINFOA, *LPFINDINFOA;

typedef struct tagLVFINDINFOW {
    UINT flags;
    LPCWSTR psz;
    LPARAM lParam;
    POINT pt;
    UINT vkDirection;
} LVFINDINFOW, *LPFINDINFOW;

typedef struct tagLVHITTESTINFO {
    POINT pt;
    UINT flags;
    int iItem;
    int iSubItem;
} LVHITTESTINFO, *LPLVHITTESTINFO;

typedef struct tagLVCOLUMNA {
    UINT mask;
    int fmt;
    int cx;
    LPSTR pszText;
    int cchTextMax;
    int iSubItem;
    int iImage;
    int iOrder;
} LVCOLUMNA, *LPLVCOLUMNA;

typedef struct tagLVCOLUMNW {
    UINT mask;
    int fmt;
    int cx;
    LPWSTR pszText;
    int cchTextMax;
    int iSubItem;
    int iImage;
    int iOrder;
} LVCOLUMNW, *LPLVCOLUMNW;

typedef int (CALLBACK *PFNLVCOMPARE)(LPARAM,LPARAM,LPARAM);

#if (_WIN32_IE >= 0x0400)
typedef struct tagLVBKIMAGEA {
    ULONG ulFlags;
    HBITMAP hbm;
    LPSTR pszImage;
    UINT cchImageMax;
    int xOffsetPercent;
    int yOffsetPercent;
} LVBKIMAGEA, *LPLVBKIMAGEA;

typedef struct tagLVBKIMAGEW {
    ULONG ulFlags;
    HBITMAP hbm;
    LPWSTR pszImage;
    UINT cchImageMax;
    int xOffsetPercent;
    int yOffsetPercent;
} LVBKIMAGEW, *LPLVBKIMAGEW;
#endif

typedef struct tagNMLISTVIEW {
    NMHDR hdr;
    int iItem;
    int iSubItem;
    UINT uNewState;
    UINT uOldState;
    UINT uChanged;
    POINT ptAction;
    LPARAM lParam;
} NMLISTVIEW, *LPNMLISTVIEW;

#if (_WIN32_IE >= 0x400)
typedef struct tagNMITEMACTIVATE {
    NMHDR hdr;
    int iItem;
    int iSubItem;
    UINT uNewState;
    UINT uOldState;
    UINT uChanged;
    POINT ptAction;
    LPARAM lParam;
    UINT uKeyFlags;
} NMITEMACTIVATE, *LPNMITEMACTIVATE;
#endif

typedef struct tagNMLVCUSTOMDRAW {
    NMCUSTOMDRAW nmcd;
    COLORREF clrText;
    COLORREF clrTextBk;
#if (_WIN32_IE >= 0x0400)
    int iSubItem;
#endif
#if (_WIN32_WINNT >= 0x501)
    DWORD dwItemType;
    COLORREF clrFace;
    int iIconEffect;
    int iIconPhase;
    int iPartId;
    int iStateId;
    RECT rcText;
    UINT uAlign;
#endif
} NMLVCUSTOMDRAW, *LPNMLVCUSTOMDRAW;

typedef struct tagNMLVCACHEHINT {
    NMHDR hdr;
    int iFrom;
    int iTo;
} NMLVCACHEHINT, *LPNMLVCACHEHINT;

typedef struct tagNMLVFINDITEMA {
    NMHDR hdr;
    int iStart;
    LVFINDINFOA lvfi;
} NMLVFINDITEMA, *LPNMLVFINDITEMA;

typedef struct tagNMLVFINDITEMW {
    NMHDR hdr;
    int iStart;
    LVFINDINFOW lvfi;
} NMLVFINDITEMW, *LPNMLVFINDITEMW;

typedef struct tagNMLVODSTATECHANGE {
    NMHDR hdr;
    int iFrom;
    int iTo;
    UINT uNewState;
    UINT uOldState;
} NMLVODSTATECHANGE, *LPNMLVODSTATECHANGE;

typedef struct tagLVDISPINFO {
    NMHDR hdr;
    LVITEMA item;
} NMLVDISPINFOA, *LPNMLVDISPINFOA;

typedef struct tagLVDISPINFOW {
    NMHDR hdr;
    LVITEMW item;
} NMLVDISPINFOW, *LPNMLVDISPINFOW;

#include <pshpack1.h>
typedef struct tagLVKEYDOWN {
    NMHDR hdr;
    WORD wVKey;
    UINT flags;
} NMLVKEYDOWN, *LPNMLVKEYDOWN;
#include <poppack.h>

#if (_WIN32_IE >= 0x0400)
typedef struct tagNMLVGETINFOTIPA {
    NMHDR hdr;
    DWORD dwFlags;
    LPSTR pszText;
    int cchTextMax;
    int iItem;
    int iSubItem;
    LPARAM lParam;
} NMLVGETINFOTIPA, *LPNMLVGETINFOTIPA;

typedef struct tagNMLVGETINFOTIPW {
    NMHDR hdr;
    DWORD dwFlags;
    LPWSTR pszText;
    int cchTextMax;
    int iItem;
    int iSubItem;
    LPARAM lParam;
} NMLVGETINFOTIPW, *LPNMLVGETINFOTIPW;
#endif

#if (_WIN32_WINNT >= 0x501)
typedef struct tagLVGROUP {
    UINT cbSize;
    UINT mask;
    LPWSTR pszHeader;
    int cchHeader;
    LPWSTR pszFooter;
    int cchFooter;
    int iGroupId;
    UINT stateMask;
    UINT state;
    UINT uAlign;
} LVGROUP, *PLVGROUP;

typedef struct tagLVGROUPMETRICS {
    UINT cbSize;
    UINT mask;
    UINT Left;
    UINT Top;
    UINT Right;
    UINT Bottom;
    COLORREF crLeft;
    COLORREF crTop;
    COLORREF crRight;
    COLORREF crBottom;
    COLORREF crHeader;
    COLORREF crFooter;
} LVGROUPMETRICS, *PLVGROUPMETRICS;

typedef int (CALLBACK *PFNLVGROUPCOMPARE)(int,int,void*);

typedef struct tagLVINSERTGROUPSORTED {
    PFNLVGROUPCOMPARE pfnGroupCompare;
    void *pvData;
    LVGROUP lvGroup;
} LVINSERTGROUPSORTED, *PLVINSERTGROUPSORTED;

typedef struct tagLVTILEVIEWINFO {
    UINT cbSize;
    DWORD dwMask;
    DWORD dwFlags;
    SIZE sizeTile;
    int cLines;
    RECT rcLabelMargin;
} LVTILEVIEWINFO, *PLVTILEVIEWINFO;

typedef struct tagLVTILEINFO {
    UINT cbSize;
    int iItem;
    UINT cColumns;
    PUINT puColumns;
} LVTILEINFO, *PLVTILEINFO;

typedef struct {
    UINT cbSize;
    DWORD dwFlags;
    int iItem;
    DWORD dwReserved;
} LVINSERTMARK, *LPLVINSERTMARK;

typedef struct tagLVSETINFOTIP {
    UINT cbSize;
    DWORD dwFlags;
    LPWSTR pszText;
    int iItem;
    int iSubItem;
} LVSETINFOTIP, *PLVSETINFOTIP;

typedef struct tagNMLVSCROLL {
    NMHDR hdr;
    int dx;
    int dy;
} NMLVSCROLL, *LPNMLVSCROLL;
#endif

#if (_WIN32_IE >= 0x0400)
#define ListView_SetUnicodeFormat(hwnd,fUnicode)  (BOOL)SNDMSG((hwnd),LVM_SETUNICODEFORMAT,(WPARAM)(fUnicode),0)
#define ListView_GetUnicodeFormat(hwnd)  (BOOL)SNDMSG((hwnd),LVM_GETUNICODEFORMAT,0,0)
#endif
#define ListView_GetBkColor(hwnd)  (COLORREF)SNDMSG((hwnd),LVM_GETBKCOLOR,0,0L)
#define ListView_SetBkColor(hwnd,clrBk)  (BOOL)SNDMSG((hwnd),LVM_SETBKCOLOR,0,(LPARAM)(COLORREF)(clrBk))
#define ListView_GetImageList(hwnd,iImageList)  (HIMAGELIST)SNDMSG((hwnd),LVM_GETIMAGELIST,(WPARAM)(INT)(iImageList),0L)
#define ListView_SetImageList(hwnd,himl,iImageList)  (HIMAGELIST)SNDMSG((hwnd),LVM_SETIMAGELIST,(WPARAM)(iImageList),(LPARAM)(HIMAGELIST)(himl))
#define ListView_GetItemCount(hwnd)  (int)SNDMSG((hwnd),LVM_GETITEMCOUNT,0,0L)
#define ListView_GetItem(hwnd,pitem)  (BOOL)SNDMSG((hwnd),LVM_GETITEM,0,(LPARAM)(LV_ITEM*)(pitem))
#define ListView_SetItem(hwnd,pitem)  (BOOL)SNDMSG((hwnd),LVM_SETITEM,0,(LPARAM)(const LV_ITEM*)(pitem))
#define ListView_InsertItem(hwnd,pitem)  (int)SNDMSG((hwnd),LVM_INSERTITEM,0,(LPARAM)(const LV_ITEM*)(pitem))
#define ListView_DeleteItem(hwnd,i)  (BOOL)SNDMSG((hwnd),LVM_DELETEITEM,(WPARAM)(int)(i),0L)
#define ListView_DeleteAllItems(hwnd)  (BOOL)SNDMSG((hwnd),LVM_DELETEALLITEMS,0,0L)
#define ListView_GetCallbackMask(hwnd)  (BOOL)SNDMSG((hwnd),LVM_GETCALLBACKMASK,0,0)
#define ListView_SetCallbackMask(hwnd,mask)  (BOOL)SNDMSG((hwnd),LVM_SETCALLBACKMASK,(WPARAM)(UINT)(mask),0)
#define ListView_GetNextItem(hwnd,i,flags)  (int)SNDMSG((hwnd),LVM_GETNEXTITEM,(WPARAM)(int)(i),MAKELPARAM((flags),0))
#define ListView_FindItem(hwnd,iStart,plvfi)  (int)SNDMSG((hwnd),LVM_FINDITEM,(WPARAM)(int)(iStart),(LPARAM)(const LV_FINDINFO*)(plvfi))
#define ListView_GetItemRect(hwnd,i,prc,code)  (BOOL)SNDMSG((hwnd),LVM_GETITEMRECT,(WPARAM)(int)(i),((prc)?(((RECT*)(prc))->left = (code),(LPARAM)(RECT*)(prc)):(LPARAM)(RECT*)NULL))
#define ListView_SetItemPosition(hwnd,i,x,y)  (BOOL)SNDMSG((hwnd),LVM_SETITEMPOSITION,(WPARAM)(int)(i),MAKELPARAM((x),(y)))
#define ListView_GetItemPosition(hwnd,i,ppt)  (BOOL)SNDMSG((hwnd),LVM_GETITEMPOSITION,(WPARAM)(int)(i),(LPARAM)(POINT*)(ppt))
#define ListView_GetStringWidth(hwnd,psz)  (int)SNDMSG((hwnd),LVM_GETSTRINGWIDTH,0,(LPARAM)(LPCTSTR)(psz))
#define ListView_HitTest(hwnd,pinfo)  (int)SNDMSG((hwnd),LVM_HITTEST,0,(LPARAM)(LV_HITTESTINFO*)(pinfo))
#define ListView_EnsureVisible(hwnd,i,fPartialOK)  (BOOL)SNDMSG((hwnd),LVM_ENSUREVISIBLE,(WPARAM)(int)(i),MAKELPARAM((fPartialOK),0))
#define ListView_Scroll(hwnd,dx,dy)  (BOOL)SNDMSG((hwnd),LVM_SCROLL,(WPARAM)(int)(dx),(LPARAM)(int)(dy))
#define ListView_RedrawItems(hwnd,iFirst,iLast)  (BOOL)SNDMSG((hwnd),LVM_REDRAWITEMS,(WPARAM)(int)(iFirst),(LPARAM)(int)(iLast))
#define ListView_Arrange(hwnd,code)  (BOOL)SNDMSG((hwnd),LVM_ARRANGE,(WPARAM)(UINT)(code),0L)
#define ListView_EditLabel(hwnd,i)  (HWND)SNDMSG((hwnd),LVM_EDITLABEL,(WPARAM)(int)(i),0L)
#define ListView_GetEditControl(hwnd)  (HWND)SNDMSG((hwnd),LVM_GETEDITCONTROL,0,0L)
#define ListView_GetColumn(hwnd,iCol,pcol)  (BOOL)SNDMSG((hwnd),LVM_GETCOLUMN,(WPARAM)(int)(iCol),(LPARAM)(LV_COLUMN*)(pcol))
#define ListView_SetColumn(hwnd,iCol,pcol)  (BOOL)SNDMSG((hwnd),LVM_SETCOLUMN,(WPARAM)(int)(iCol),(LPARAM)(const LV_COLUMN*)(pcol))
#define ListView_InsertColumn(hwnd,iCol,pcol)  (int)SNDMSG((hwnd),LVM_INSERTCOLUMN,(WPARAM)(int)(iCol),(LPARAM)(const LV_COLUMN*)(pcol))
#define ListView_DeleteColumn(hwnd,iCol)  (BOOL)SNDMSG((hwnd),LVM_DELETECOLUMN,(WPARAM)(int)(iCol),0)
#define ListView_GetColumnWidth(hwnd,iCol)  (int)SNDMSG((hwnd),LVM_GETCOLUMNWIDTH,(WPARAM)(int)(iCol),0)
#define ListView_SetColumnWidth(hwnd,iCol,cx)  (BOOL)SNDMSG((hwnd),LVM_SETCOLUMNWIDTH,(WPARAM)(int)(iCol),MAKELPARAM((cx),0))
#define ListView_GetHeader(hwnd)  (HWND)SNDMSG((hwnd),LVM_GETHEADER,0,0L)
#define ListView_CreateDragImage(hwnd,i,lpptUpLeft)  (HIMAGELIST)SNDMSG((hwnd),LVM_CREATEDRAGIMAGE,(WPARAM)(int)(i),(LPARAM)(LPPOINT)(lpptUpLeft))
#define ListView_GetViewRect(hwnd,prc)  (BOOL)SNDMSG((hwnd),LVM_GETVIEWRECT,0,(LPARAM)(RECT*)(prc))
#define ListView_GetTextColor(hwnd)  (COLORREF)SNDMSG((hwnd),LVM_GETTEXTCOLOR,0,0L)
#define ListView_SetTextColor(hwnd,clrText)  (BOOL)SNDMSG((hwnd),LVM_SETTEXTCOLOR,0,(LPARAM)(COLORREF)(clrText))
#define ListView_GetTextBkColor(hwnd)  (COLORREF)SNDMSG((hwnd),LVM_GETTEXTBKCOLOR,0,0L)
#define ListView_SetTextBkColor(hwnd,clrTextBk)  (BOOL)SNDMSG((hwnd),LVM_SETTEXTBKCOLOR,0,(LPARAM)(COLORREF)(clrTextBk))
#define ListView_GetTopIndex(hwnd)  (int)SNDMSG((hwnd),LVM_GETTOPINDEX,0,0)
#define ListView_GetCountPerPage(hwnd)  (int)SNDMSG((hwnd),LVM_GETCOUNTPERPAGE,0,0)
#define ListView_GetOrigin(hwnd,ppt)  (BOOL)SNDMSG((hwnd),LVM_GETORIGIN,(WPARAM)0,(LPARAM)(POINT*)(ppt))
#define ListView_Update(hwnd,i)  (BOOL)SNDMSG((hwnd),LVM_UPDATE,(WPARAM)(i),0L)
#define ListView_SetItemState(hwnd,i,data,mask)  { LV_ITEM _ms_lvi; _ms_lvi.stateMask = mask; _ms_lvi.state = data; SNDMSG((hwnd),LVM_SETITEMSTATE,(WPARAM)(i),(LPARAM)(LV_ITEM*)&_ms_lvi); }
#define ListView_SetCheckState(hwnd,i,fCheck)  ListView_SetItemState(hwnd,i,INDEXTOSTATEIMAGEMASK((fCheck)?2:1),LVIS_STATEIMAGEMASK)
#define ListView_GetItemState(hwnd,i,mask)  (UINT)SNDMSG((hwnd),LVM_GETITEMSTATE,(WPARAM)(i),(LPARAM)(mask))
#define ListView_GetCheckState(hwnd,i)  ((((UINT)(SNDMSG((hwnd),LVM_GETITEMSTATE,(WPARAM)(i),LVIS_STATEIMAGEMASK)))>>12)-1)
#define ListView_GetItemText(hwnd,i,iSubItem_,pszText_,cchTextMax_)  { LV_ITEM _ms_lvi; _ms_lvi.iSubItem = iSubItem_; _ms_lvi.cchTextMax = cchTextMax_; _ms_lvi.pszText = pszText_; SNDMSG((hwnd),LVM_GETITEMTEXT,(WPARAM)(i),(LPARAM)(LV_ITEM*)&_ms_lvi); }
#define ListView_SetItemText(hwnd,i,iSubItem_,pszText_)  { LV_ITEM _ms_lvi; _ms_lvi.iSubItem = iSubItem_; _ms_lvi.pszText = pszText_; SNDMSG((hwnd),LVM_SETITEMTEXT,(WPARAM)(i),(LPARAM)(LV_ITEM*)&_ms_lvi); }
#define ListView_SetItemCount(hwnd,cItems)  SNDMSG((hwnd),LVM_SETITEMCOUNT,(WPARAM)(cItems),0)
#define ListView_SetItemCountEx(hwnd,cItems,dwFlags)  SNDMSG((hwnd),LVM_SETITEMCOUNT,(WPARAM)(cItems),(LPARAM)(dwFlags))
#define ListView_SortItems(hwnd,_pfnCompare,_lPrm)  (BOOL)SNDMSG((hwnd),LVM_SORTITEMS,(WPARAM)(LPARAM)(_lPrm),(LPARAM)(PFNLVCOMPARE)(_pfnCompare))
#define ListView_SetItemPosition32(hwnd,i,x0,y0) { POINT ptNewPos; ptNewPos.x = x0; ptNewPos.y = y0; SNDMSG((hwnd),LVM_SETITEMPOSITION32,(WPARAM)(int)(i),(LPARAM)&ptNewPos); }
#define ListView_GetSelectedCount(hwnd)  (UINT)SNDMSG((hwnd),LVM_GETSELECTEDCOUNT,0,0L)
#define ListView_GetItemSpacing(hwnd,fSmall)  (DWORD)SNDMSG((hwnd),LVM_GETITEMSPACING,fSmall,0L)
#define ListView_GetISearchString(hwnd,lpsz)  (BOOL)SNDMSG((hwnd),LVM_GETISEARCHSTRING,0,(LPARAM)(LPTSTR)(lpsz))
#define ListView_SetIconSpacing(hwnd,cx,cy)  (DWORD)SNDMSG((hwnd),LVM_SETICONSPACING,0,MAKELONG(cx,cy))
#define ListView_SetExtendedListViewStyle(hwnd,dw)  (DWORD)SNDMSG((hwnd),LVM_SETEXTENDEDLISTVIEWSTYLE,0,dw)
#if (_WIN32_IE >= 0x0400)
#define ListView_SetExtendedListViewStyleEx(hwnd,dwMask,dw)  (DWORD)SNDMSG((hwnd),LVM_SETEXTENDEDLISTVIEWSTYLE,dwMask,dw)
#endif
#define ListView_GetExtendedListViewStyle(hwnd)  (DWORD)SNDMSG((hwnd),LVM_GETEXTENDEDLISTVIEWSTYLE,0,0)
#define ListView_GetSubItemRect(hwnd,iItem,iSubItem,code,prc)  (BOOL)SNDMSG((hwnd),LVM_GETSUBITEMRECT,(WPARAM)(int)(iItem),((prc)?((((LPRECT)(prc))->top = iSubItem),(((LPRECT)(prc))->left = code),(LPARAM)(prc)):(LPARAM)(LPRECT)NULL))
#define ListView_SubItemHitTest(hwnd,plvhti)  (int)SNDMSG((hwnd),LVM_SUBITEMHITTEST,0,(LPARAM)(LPLVHITTESTINFO)(plvhti))
#define ListView_SetColumnOrderArray(hwnd,iCount,pi)  (BOOL)SNDMSG((hwnd),LVM_SETCOLUMNORDERARRAY,(WPARAM)(iCount),(LPARAM)(LPINT)(pi))
#define ListView_GetColumnOrderArray(hwnd,iCount,pi)  (BOOL)SNDMSG((hwnd),LVM_GETCOLUMNORDERARRAY,(WPARAM)(iCount),(LPARAM)(LPINT)(pi))
#define ListView_SetHotItem(hwnd,i)  (int)SNDMSG((hwnd),LVM_SETHOTITEM,(WPARAM)(i),0)
#define ListView_GetHotItem(hwnd)  (int)SNDMSG((hwnd),LVM_GETHOTITEM,0,0)
#define ListView_SetHotCursor(hwnd,hcur)  (HCURSOR)SNDMSG((hwnd),LVM_SETHOTCURSOR,0,(LPARAM)(hcur))
#define ListView_GetHotCursor(hwnd)  (HCURSOR)SNDMSG((hwnd),LVM_GETHOTCURSOR,0,0)
#define ListView_ApproximateViewRect(hwnd,iWidth,iHeight,iCount)  (DWORD)SNDMSG((hwnd),LVM_APPROXIMATEVIEWRECT,iCount,MAKELPARAM(iWidth,iHeight))
#if (_WIN32_IE >= 0x0400)
#define ListView_SetWorkAreas(hwnd,nWorkAreas,prc)  (BOOL)SNDMSG((hwnd),LVM_SETWORKAREAS,(WPARAM)(int)(nWorkAreas),(LPARAM)(RECT*)(prc))
#define ListView_GetWorkAreas(hwnd,nWorkAreas,prc)  (BOOL)SNDMSG((hwnd),LVM_GETWORKAREAS,(WPARAM)(int)(nWorkAreas),(LPARAM)(RECT*)(prc))
#define ListView_GetNumberOfWorkAreas(hwnd,pnWorkAreas)  (BOOL)SNDMSG((hwnd),LVM_GETNUMBEROFWORKAREAS,0,(LPARAM)(UINT*)(pnWorkAreas))
#define ListView_GetSelectionMark(hwnd)  (int)SNDMSG((hwnd),LVM_GETSELECTIONMARK,0,0)
#define ListView_SetSelectionMark(hwnd,i)  (int)SNDMSG((hwnd),LVM_SETSELECTIONMARK,0,(LPARAM)(i))
#define ListView_SetHoverTime(hwnd,dwHoverTimeMs)  (DWORD)SNDMSG((hwnd),LVM_SETHOVERTIME,0,(LPARAM)(dwHoverTimeMs))
#define ListView_GetHoverTime(hwnd)  (DWORD)SNDMSG((hwnd),LVM_GETHOVERTIME,0,0)
#define ListView_SetToolTips(hwnd,hwndNewHwnd)  (HWND)SNDMSG((hwnd),LVM_SETTOOLTIPS,(WPARAM)(hwndNewHwnd),0)
#define ListView_GetToolTips(hwnd)  (HWND)SNDMSG((hwnd),LVM_GETTOOLTIPS,0,0)
#define ListView_SortItemsEx(hwnd,_pfnCompare,_lPrm)  (BOOL)SNDMSG((hwnd),LVM_SORTITEMSEX,(WPARAM)(LPARAM)(_lPrm),(LPARAM)(PFNLVCOMPARE)(_pfnCompare))
#define ListView_SetBkImage(hwnd,plvbki)  (BOOL)SNDMSG((hwnd),LVM_SETBKIMAGE,0,(LPARAM)(plvbki))
#define ListView_GetBkImage(hwnd,plvbki)  (BOOL)SNDMSG((hwnd),LVM_GETBKIMAGE,0,(LPARAM)(plvbki))
#endif
#if (_WIN32_WINNT >= 0x501)
#define ListView_SetSelectedColumn(hwnd,iCol)  SNDMSG((hwnd),LVM_SETSELECTEDCOLUMN,(WPARAM)iCol,0)
#define ListView_SetTileWidth(hwnd,cpWidth)  SNDMSG((hwnd),LVM_SETTILEWIDTH,(WPARAM)cpWidth,0)
#define ListView_SetView(hwnd,iView)  (DWORD)SNDMSG((hwnd),LVM_SETVIEW,(WPARAM)(DWORD)iView,0)
#define ListView_GetView(hwnd)  (DWORD)SNDMSG((hwnd),LVM_GETVIEW,0,0)
#define ListView_InsertGroup(hwnd,index,pgrp)  SNDMSG((hwnd),LVM_INSERTGROUP,(WPARAM)index,(LPARAM)pgrp)
#define ListView_SetGroupInfo(hwnd,iGroupId,pgrp)  SNDMSG((hwnd),LVM_SETGROUPINFO,(WPARAM)iGroupId,(LPARAM)pgrp)
#define ListView_GetGroupInfo(hwnd,iGroupId,pgrp)  SNDMSG((hwnd),LVM_GETGROUPINFO,(WPARAM)iGroupId,(LPARAM)pgrp)
#define ListView_RemoveGroup(hwnd,iGroupId)  SNDMSG((hwnd),LVM_REMOVEGROUP,(WPARAM)iGroupId,0)
#define ListView_MoveGroup(hwnd,iGroupId,toIndex)  SNDMSG((hwnd),LVM_MOVEGROUP,(WPARAM)iGroupId,(LPARAM)toIndex)
#define ListView_MoveItemToGroup(hwnd,idItemFrom,idGroupTo)  SNDMSG((hwnd),LVM_MOVEITEMTOGROUP,(WPARAM)idItemFrom,(LPARAM)idGroupTo)
#define ListView_SetGroupMetrics(hwnd,pGroupMetrics)  SNDMSG((hwnd),LVM_SETGROUPMETRICS,0,(LPARAM)pGroupMetrics)
#define ListView_GetGroupMetrics(hwnd,pGroupMetrics)  SNDMSG((hwnd),LVM_GETGROUPMETRICS,0,(LPARAM)pGroupMetrics)
#define ListView_EnableGroupView(hwnd,fEnable)  SNDMSG((hwnd),LVM_ENABLEGROUPVIEW,(WPARAM)fEnable,0)
#define ListView_SortGroups(hwnd, _pfnGroupCompate, _plv)  SNDMSG((hwnd),LVM_SORTGROUPS,(WPARAM)_pfnGroupCompate,(LPARAM)_plv)
#define ListView_InsertGroupSorted(hwnd,structInsert)  SNDMSG((hwnd),LVM_INSERTGROUPSORTED,(WPARAM)structInsert,0)
#define ListView_RemoveAllGroups(hwnd)  SNDMSG((hwnd),LVM_REMOVEALLGROUPS,0,0)
#define ListView_HasGroup(hwnd,dwGroupId)  SNDMSG((hwnd),LVM_HASGROUP,dwGroupId,0)
#define ListView_SetTileViewInfo(hwnd,ptvi)  SNDMSG((hwnd),LVM_SETTILEVIEWINFO,0,(LPARAM)ptvi)
#define ListView_GetTileViewInfo(hwnd,ptvi)  SNDMSG((hwnd),LVM_GETTILEVIEWINFO,0,(LPARAM)ptvi)
#define ListView_SetTileInfo(hwnd,pti)  SNDMSG((hwnd),LVM_SETTILEINFO,0,(LPARAM)pti)
#define ListView_GetTileInfo(hwnd,pti)  SNDMSG((hwnd),LVM_GETTILEINFO,0,(LPARAM)pti)
#define ListView_SetInsertMark(hwnd,lvim)  (BOOL)SNDMSG((hwnd),LVM_SETINSERTMARK,(WPARAM)0,(LPARAM)(lvim))
#define ListView_GetInsertMark(hwnd,lvim)  (BOOL)SNDMSG((hwnd),LVM_GETINSERTMARK,(WPARAM)0,(LPARAM)(lvim))
#define ListView_InsertMarkHitTest(hwnd,point,lvim)  (int)SNDMSG((hwnd),LVM_INSERTMARKHITTEST,(WPARAM)(LPPOINT)(point),(LPARAM)(LPLVINSERTMARK)(lvim))
#define ListView_GetInsertMarkRect(hwnd,rc)  (int)SNDMSG((hwnd),LVM_GETINSERTMARKRECT,(WPARAM)0,(LPARAM)(LPRECT)(rc))
#define ListView_SetInsertMarkColor(hwnd,color)  (COLORREF)SNDMSG((hwnd),LVM_SETINSERTMARKCOLOR,(WPARAM)0,(LPARAM)(COLORREF)(color))
#define ListView_GetInsertMarkColor(hwnd)  (COLORREF)SNDMSG((hwnd),LVM_GETINSERTMARKCOLOR,(WPARAM)0,(LPARAM)0)
#define ListView_SetInfoTip(hwndLV,plvInfoTip)  (BOOL)SNDMSG((hwndLV),LVM_SETINFOTIP,(WPARAM)0,(LPARAM)plvInfoTip)
#define ListView_GetSelectedColumn(hwnd)  (UINT)SNDMSG((hwnd),LVM_GETSELECTEDCOLUMN,0,0)
#define ListView_IsGroupViewEnabled(hwnd)  (BOOL)SNDMSG((hwnd),LVM_ISGROUPVIEWENABLED,0,0)
#define ListView_GetOutlineColor(hwnd)  (COLORREF)SNDMSG((hwnd),LVM_GETOUTLINECOLOR,0,0)
#define ListView_CancelEditLabel(hwnd)  (VOID)SNDMSG((hwnd),LVM_CANCELEDITLABEL,(WPARAM)0,(LPARAM)0)
#define ListView_MapIndexToID(hwnd,index)  (UINT)SNDMSG((hwnd),LVM_MAPINDEXTOID,(WPARAM)index,(LPARAM)0)
#define ListView_MapIDToIndex(hwnd,id)  (UINT)SNDMSG((hwnd),LVM_MAPIDTOINDEX,(WPARAM)id,(LPARAM)0)
#endif

#ifdef UNICODE
#define LVITEM LVITEMW
#define LPLVITEM LPLVITEMW
#define LVITEM_V1_SIZE LVITEMW_V1_SIZE
#define LPSTR_TEXTCALLBACK LPSTR_TEXTCALLBACKW
#define LVFINDINFO LVFINDINFOW
#define LVCOLUMN LVCOLUMNW
#define LPLVCOLUMN LPLVCOLUMNW
#define LVCOLUMN_V1_SIZE LVCOLUMNW_V1_SIZE
#define LVBKIMAGE LVBKIMAGEW
#define LPLVBKIMAGE LPLVBKIMAGEW
#define PNM_FINDITEM PNM_FINDITEMW
#define LPNM_FINDITEM LPNM_FINDITEMW
#define NM_FINDITEM NM_FINDITEMW
#define NMLVFINDITEM NMLVFINDITEMW
#define LPNMLVFINDITEM LPNMLVFINDITEMW
#define NMLVDISPINFO NMLVDISPINFOW
#define LPNMLVDISPINFO LPNMLVDISPINFOW
#define NMLVGETINFOTIP NMLVGETINFOTIPW
#define LPNMLVGETINFOTIP LPNMLVGETINFOTIPW
#define LVM_GETITEM LVM_GETITEMW
#define LVM_SETITEM LVM_SETITEMW
#define LVM_INSERTITEM LVM_INSERTITEMW
#define LVM_FINDITEM LVM_FINDITEMW
#define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHW
#define LVM_EDITLABEL LVM_EDITLABELW
#define LVM_GETCOLUMN LVM_GETCOLUMNW
#define LVM_SETCOLUMN LVM_SETCOLUMNW
#define LVM_INSERTCOLUMN LVM_INSERTCOLUMNW
#define LVM_GETITEMTEXT LVM_GETITEMTEXTW
#define LVM_SETITEMTEXT LVM_SETITEMTEXTW
#define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGW
#define LVM_SETBKIMAGE LVM_SETBKIMAGEW
#define LVM_GETBKIMAGE LVM_GETBKIMAGEW
#define LVN_ODFINDITEM LVN_ODFINDITEMW
#define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITW
#define LVN_ENDLABELEDIT LVN_ENDLABELEDITW
#define LVN_GETDISPINFO LVN_GETDISPINFOW
#define LVN_SETDISPINFO LVN_SETDISPINFOW
#define LVN_GETINFOTIP LVN_GETINFOTIPW
#else
#define LVITEM LVITEMA
#define LPLVITEM LPLVITEMA
#define LVITEM_V1_SIZE LVITEMA_V1_SIZE
#define LPSTR_TEXTCALLBACK LPSTR_TEXTCALLBACKA
#define LVFINDINFO LVFINDINFOA
#define LVCOLUMN LVCOLUMNA
#define LPLVCOLUMN LPLVCOLUMNA
#define LVCOLUMN_V1_SIZE LVCOLUMNA_V1_SIZE
#define LVBKIMAGE LVBKIMAGEA
#define LPLVBKIMAGE LPLVBKIMAGEA
#define PNM_FINDITEM PNM_FINDITEMA
#define LPNM_FINDITEM LPNM_FINDITEMA
#define NM_FINDITEM NM_FINDITEMA
#define NMLVFINDITEM NMLVFINDITEMA
#define LPNMLVFINDITEM LPNMLVFINDITEMA
#define NMLVDISPINFO NMLVDISPINFOA
#define LPNMLVDISPINFO LPNMLVDISPINFOA
#define NMLVGETINFOTIP NMLVGETINFOTIPA
#define LPNMLVGETINFOTIP LPNMLVGETINFOTIPA
#define LVM_GETITEM LVM_GETITEMA
#define LVM_SETITEM LVM_SETITEMA
#define LVM_INSERTITEM LVM_INSERTITEMA
#define LVM_FINDITEM LVM_FINDITEMA
#define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHA
#define LVM_EDITLABEL LVM_EDITLABELA
#define LVM_GETCOLUMN LVM_GETCOLUMNA
#define LVM_SETCOLUMN LVM_SETCOLUMNA
#define LVM_INSERTCOLUMN LVM_INSERTCOLUMNA
#define LVM_GETITEMTEXT LVM_GETITEMTEXTA
#define LVM_SETITEMTEXT LVM_SETITEMTEXTA
#define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGA
#define LVM_SETBKIMAGE LVM_SETBKIMAGEA
#define LVM_GETBKIMAGE LVM_GETBKIMAGEA
#define LVN_ODFINDITEM LVN_ODFINDITEMA
#define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITA
#define LVN_ENDLABELEDIT LVN_ENDLABELEDITA
#define LVN_GETDISPINFO LVN_GETDISPINFOA
#define LVN_SETDISPINFO LVN_SETDISPINFOA
#define LVN_GETINFOTIP LVN_GETINFOTIPA
#endif

#endif /* NOLISTVIEW */

/* TreeView Control *********************************************************/

#ifndef NOTREEVIEW

#define WC_TREEVIEWA  "SysTreeView32"
#define WC_TREEVIEWW  L"SysTreeView32"

#ifdef UNICODE
#define  WC_TREEVIEW  WC_TREEVIEWW
#else
#define  WC_TREEVIEW  WC_TREEVIEWA
#endif

#define TVS_HASBUTTONS  0x0001
#define TVS_HASLINES  0x0002
#define TVS_LINESATROOT  0x0004
#define TVS_EDITLABELS  0x0008
#define TVS_DISABLEDRAGDROP  0x0010
#define TVS_SHOWSELALWAYS  0x0020
#define TVS_RTLREADING  0x0040

#define TVS_NOTOOLTIPS  0x0080
#define TVS_CHECKBOXES  0x0100
#define TVS_TRACKSELECT  0x0200
#if (_WIN32_IE >= 0x0400)
#define TVS_SINGLEEXPAND  0x0400
#define TVS_INFOTIP  0x0800
#define TVS_FULLROWSELECT  0x1000
#define TVS_NOSCROLL  0x2000
#define TVS_NONEVENHEIGHT  0x4000
#endif
#if (_WIN32_IE >= 0x500)
#define TVS_NOHSCROLL  0x8000
#endif

#define TVIF_TEXT  0x0001
#define TVIF_IMAGE  0x0002
#define TVIF_PARAM  0x0004
#define TVIF_STATE  0x0008
#define TVIF_HANDLE  0x0010
#define TVIF_SELECTEDIMAGE  0x0020
#define TVIF_CHILDREN  0x0040
#if (_WIN32_IE >= 0x0400)
#define TVIF_INTEGRAL  0x0080
#endif
#define TVIS_SELECTED  0x0002
#define TVIS_CUT  0x0004
#define TVIS_DROPHILITED  0x0008
#define TVIS_BOLD  0x0010
#define TVIS_EXPANDED  0x0020
#define TVIS_EXPANDEDONCE  0x0040
#define TVIS_EXPANDPARTIAL  0x0080
#define TVIS_OVERLAYMASK  0x0F00
#define TVIS_STATEIMAGEMASK  0xF000
#define TVIS_USERMASK  0xF000

#define TVE_COLLAPSE  0x0001
#define TVE_EXPAND  0x0002
#define TVE_TOGGLE  0x0003
#define TVE_EXPANDPARTIAL  0x4000
#define TVE_COLLAPSERESET  0x8000

#define TVSIL_NORMAL  0
#define TVSIL_STATE  2

#define TVGN_ROOT  0x0000
#define TVGN_NEXT  0x0001
#define TVGN_PREVIOUS  0x0002
#define TVGN_PARENT  0x0003
#define TVGN_CHILD  0x0004
#define TVGN_FIRSTVISIBLE  0x0005
#define TVGN_NEXTVISIBLE  0x0006
#define TVGN_PREVIOUSVISIBLE  0x0007
#define TVGN_DROPHILITE  0x0008
#define TVGN_CARET  0x0009
#if (_WIN32_IE >= 0x0400)
#define TVGN_LASTVISIBLE  0x000A
#endif

#if (_WIN32_WINNT >= 0x501)
#define TVSI_NOSINGLEEXPAND  0x8000
#endif

#define TVHT_NOWHERE  0x0001
#define TVHT_ONITEMICON  0x0002
#define TVHT_ONITEMLABEL  0x0004
#define TVHT_ONITEM  (TVHT_ONITEMICON|TVHT_ONITEMLABEL|TVHT_ONITEMSTATEICON)
#define TVHT_ONITEMINDENT  0x0008
#define TVHT_ONITEMBUTTON  0x0010
#define TVHT_ONITEMRIGHT  0x0020
#define TVHT_ONITEMSTATEICON  0x0040
#define TVHT_ABOVE  0x0100
#define TVHT_BELOW  0x0200
#define TVHT_TORIGHT  0x0400
#define TVHT_TOLEFT  0x0800

#define TVM_INSERTITEMA  (TV_FIRST+0)
#define TVM_INSERTITEMW  (TV_FIRST+50)
#define TVM_DELETEITEM  (TV_FIRST+1)
#define TVM_EXPAND  (TV_FIRST+2)
#define TVM_GETITEMRECT  (TV_FIRST+4)
#define TVM_GETCOUNT  (TV_FIRST+5)
#define TVM_GETINDENT  (TV_FIRST+6)
#define TVM_SETINDENT  (TV_FIRST+7)
#define TVM_GETIMAGELIST  (TV_FIRST+8)
#define TVM_SETIMAGELIST  (TV_FIRST+9)
#define TVM_GETNEXTITEM  (TV_FIRST+10)
#define TVM_SELECTITEM  (TV_FIRST+11)
#define TVM_GETITEMA  (TV_FIRST+12)
#define TVM_GETITEMW  (TV_FIRST+62)
#define TVM_SETITEMA  (TV_FIRST+13)
#define TVM_SETITEMW  (TV_FIRST+63)
#define TVM_EDITLABELA  (TV_FIRST+14)
#define TVM_EDITLABELW  (TV_FIRST+65)
#define TVM_GETEDITCONTROL  (TV_FIRST+15)
#define TVM_GETVISIBLECOUNT  (TV_FIRST+16)
#define TVM_HITTEST  (TV_FIRST+17)
#define TVM_CREATEDRAGIMAGE  (TV_FIRST+18)
#define TVM_SORTCHILDREN  (TV_FIRST+19)
#define TVM_ENSUREVISIBLE  (TV_FIRST+20)
#define TVM_SORTCHILDRENCB  (TV_FIRST+21)
#define TVM_ENDEDITLABELNOW  (TV_FIRST+22)
#define TVM_GETISEARCHSTRINGA  (TV_FIRST+23)
#define TVM_GETISEARCHSTRINGW  (TV_FIRST+64)
#define TVM_SETTOOLTIPS  (TV_FIRST+24)
#define TVM_GETTOOLTIPS  (TV_FIRST+25)
// ? TVM_SETITEMSPACING  (TV_FIRST+24)  /* Smartphone only? */
#if (_WIN32_IE >= 0x0400)
#define TVM_SETINSERTMARK  (TV_FIRST+26)
#define TVM_SETUNICODEFORMAT  CCM_SETUNICODEFORMAT
#define TVM_GETUNICODEFORMAT  CCM_GETUNICODEFORMAT
#define TVM_SETITEMHEIGHT  (TV_FIRST+27)
#define TVM_GETITEMHEIGHT  (TV_FIRST+28)
#define TVM_SETBKCOLOR  (TV_FIRST+29)
#define TVM_SETTEXTCOLOR  (TV_FIRST+30)
#define TVM_GETBKCOLOR  (TV_FIRST+31)
#define TVM_GETTEXTCOLOR  (TV_FIRST+32)
#define TVM_SETSCROLLTIME  (TV_FIRST+33)
#define TVM_GETSCROLLTIME  (TV_FIRST+34)
#define TVM_SETINSERTMARKCOLOR  (TV_FIRST+37)
#define TVM_GETINSERTMARKCOLOR  (TV_FIRST+38)
#endif
#if (_WIN32_IE >= 0x0500)
#define TVM_GETITEMSTATE  (TV_FIRST+39)
#define TVM_SETLINECOLOR  (TV_FIRST+40)
#define TVM_GETLINECOLOR  (TV_FIRST+41)
#endif
#if (_WIN32_WINNT >= 0x0501)
#define TVM_MAPACCIDTOHTREEITEM  (TV_FIRST+42)
#define TVM_MAPHTREEITEMTOACCID  (TV_FIRST+43)
#endif

#define TVN_SELCHANGINGA  (TVN_FIRST-1)
#define TVN_SELCHANGINGW  (TVN_FIRST-50)
#define TVN_SELCHANGEDA  (TVN_FIRST-2)
#define TVN_SELCHANGEDW  (TVN_FIRST-51)
#define TVN_GETDISPINFOA  (TVN_FIRST-3)
#define TVN_GETDISPINFOW  (TVN_FIRST-52)
#define TVN_SETDISPINFOA  (TVN_FIRST-4)
#define TVN_SETDISPINFOW  (TVN_FIRST-53)
#define TVN_ITEMEXPANDINGA  (TVN_FIRST-5)
#define TVN_ITEMEXPANDINGW  (TVN_FIRST-54)
#define TVN_ITEMEXPANDEDA  (TVN_FIRST-6)
#define TVN_ITEMEXPANDEDW  (TVN_FIRST-55)
#define TVN_BEGINDRAGA  (TVN_FIRST-7)
#define TVN_BEGINDRAGW  (TVN_FIRST-56)
#define TVN_BEGINRDRAGA  (TVN_FIRST-8)
#define TVN_BEGINRDRAGW  (TVN_FIRST-57)
#define TVN_DELETEITEMA  (TVN_FIRST-9)
#define TVN_DELETEITEMW  (TVN_FIRST-58)
#define TVN_BEGINLABELEDITA  (TVN_FIRST-10)
#define TVN_BEGINLABELEDITW  (TVN_FIRST-59)
#define TVN_ENDLABELEDITA  (TVN_FIRST-11)
#define TVN_ENDLABELEDITW  (TVN_FIRST-60)
#define TVN_KEYDOWN  (TVN_FIRST-12)
#if (_WIN32_IE >= 0x0400)
#define TVN_GETINFOTIPA  (TVN_FIRST-13)
#define TVN_GETINFOTIPW  (TVN_FIRST-14)
#define TVN_SINGLEEXPAND  (TVN_FIRST-15)
#endif

#define TVC_UNKNOWN  0x0000
#define TVC_BYMOUSE  0x0001
#define TVC_BYKEYBOARD  0x0002

#define TVIF_DI_SETITEM  0x1000

#define TV_DISPINFOA  NMTVDISPINFOA
#define TV_DISPINFOW  NMTVDISPINFOW
#define TV_DISPINFO  NMTVDISPINFO

#if (_WIN32_IE >= 0x0400)
#define TVNRET_DEFAULT  0
#define TVNRET_SKIPOLD  1
#define TVNRET_SKIPNEW  2
#endif

#define I_CHILDRENCALLBACK  (-1)

typedef struct _TREEITEM *HTREEITEM;

#define TVI_ROOT  ((HTREEITEM)(ULONG_PTR)-0x10000)
#define TVI_FIRST  ((HTREEITEM)(ULONG_PTR)-0x0FFFF)
#define TVI_LAST  ((HTREEITEM)(ULONG_PTR)-0x0FFFE)
#define TVI_SORT  ((HTREEITEM)(ULONG_PTR)-0x0FFFD)

#define LPTV_INSERTSTRUCTA LPTVINSERTSTRUCTA
#define LPTV_INSERTSTRUCTW LPTVINSERTSTRUCTW
#define TV_INSERTSTRUCTA TVINSERTSTRUCTA
#define TV_INSERTSTRUCTW TVINSERTSTRUCTW
#define TV_INSERTSTRUCT TVINSERTSTRUCT
#define LPTV_INSERTSTRUCT LPTVINSERTSTRUCT

#define LPTV_HITTESTINFO LPTVHITTESTINFO
#define TV_HITTESTINFO TVHITTESTINFO

#define LPTV_SORTCB LPTVSORTCB
#define TV_SORTCB TVSORTCB

#define LPNM_TREEVIEWA LPNMTREEVIEWA
#define LPNM_TREEVIEWW LPNMTREEVIEWW
#define NM_TREEVIEWW NMTREEVIEWW
#define NM_TREEVIEWA NMTREEVIEWA
#define LPNM_TREEVIEW LPNMTREEVIEW
#define NM_TREEVIEW NMTREEVIEW

#define TVINSERTSTRUCTA_V1_SIZE CCSIZEOF_STRUCT(TVINSERTSTRUCTA,item)
#define TVINSERTSTRUCTW_V1_SIZE CCSIZEOF_STRUCT(TVINSERTSTRUCTW,item)

#define LPTV_ITEMW LPTVITEMW
#define LPTV_ITEMA LPTVITEMA
#define TV_ITEMW TVITEMW
#define TV_ITEMA TVITEMA
#define LPTV_ITEM LPTVITEM
#define TV_ITEM TVITEM

typedef struct tagTVITEMA {
    UINT mask;
    HTREEITEM hItem;
    UINT state;
    UINT stateMask;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    LPARAM lParam;
} TVITEMA, *LPTVITEMA;

typedef struct tagTVITEMW {
    UINT mask;
    HTREEITEM hItem;
    UINT state;
    UINT stateMask;
    LPWSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    LPARAM lParam;
} TVITEMW, *LPTVITEMW;

#if (_WIN32_IE >= 0x0400)
typedef struct tagTVITEMEXA {
    UINT mask;
    HTREEITEM hItem;
    UINT state;
    UINT stateMask;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    LPARAM lParam;
    int iIntegral;
} TVITEMEXA, *LPTVITEMEXA;

typedef struct tagTVITEMEXW {
    UINT mask;
    HTREEITEM hItem;
    UINT state;
    UINT stateMask;
    LPWSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    LPARAM lParam;
    int iIntegral;
} TVITEMEXW, *LPTVITEMEXW;
#endif

typedef struct tagTVINSERTSTRUCTA {
    HTREEITEM hParent;
    HTREEITEM hInsertAfter;
#if (_WIN32_IE >= 0x0400)
    union {
        TVITEMEXA itemex;
        TV_ITEMA item;
    } DUMMYUNIONNAME;
#else
    TV_ITEMA item;
#endif
} TVINSERTSTRUCTA, *LPTVINSERTSTRUCTA;

typedef struct tagTVINSERTSTRUCTW {
    HTREEITEM hParent;
    HTREEITEM hInsertAfter;
#if (_WIN32_IE >= 0x0400)
    union {
        TVITEMEXW itemex;
        TV_ITEMW item;
    } DUMMYUNIONNAME;
#else
    TV_ITEMW item;
#endif
} TVINSERTSTRUCTW, *LPTVINSERTSTRUCTW;

typedef struct tagTVHITTESTINFO {
    POINT pt;
    UINT flags;
    HTREEITEM hItem;
} TVHITTESTINFO, *LPTVHITTESTINFO;

typedef int (CALLBACK *PFNTVCOMPARE)(LPARAM,LPARAM,LPARAM);

typedef struct tagTVSORTCB {
    HTREEITEM hParent;
    PFNTVCOMPARE lpfnCompare;
    LPARAM lParam;
} TVSORTCB, *LPTVSORTCB;

typedef struct tagNMTREEVIEWA {
    NMHDR hdr;
    UINT action;
    TVITEMA itemOld;
    TVITEMA itemNew;
    POINT ptDrag;
} NMTREEVIEWA, *LPNMTREEVIEWA;

typedef struct tagNMTREEVIEWW {
    NMHDR hdr;
    UINT action;
    TVITEMW itemOld;
    TVITEMW itemNew;
    POINT ptDrag;
} NMTREEVIEWW, *LPNMTREEVIEWW;

typedef struct tagTVDISPINFOA {
    NMHDR hdr;
    TVITEMA item;
} NMTVDISPINFOA, *LPNMTVDISPINFOA;

typedef struct tagTVDISPINFOW {
    NMHDR hdr;
    TVITEMW item;
} NMTVDISPINFOW, *LPNMTVDISPINFOW;

#define TV_KEYDOWN  NMTVKEYDOWN

#include <pshpack1.h>
typedef struct tagTVKEYDOWN {
    NMHDR hdr;
    WORD wVKey;
    UINT flags;
} NMTVKEYDOWN, *LPNMTVKEYDOWN;
#include <poppack.h>

#define NMTVCUSTOMDRAW_V3_SIZE CCSIZEOF_STRUCT(NMTVCUSTOMDRAW,clrTextBk)

typedef struct tagNMTVCUSTOMDRAW {
    NMCUSTOMDRAW nmcd;
    COLORREF clrText;
    COLORREF clrTextBk;
#if (_WIN32_IE >= 0x0400)
    int iLevel;
#endif
} NMTVCUSTOMDRAW, *LPNMTVCUSTOMDRAW;

#if (_WIN32_IE >= 0x0400)
typedef struct tagNMTVGETINFOTIPA {
    NMHDR hdr;
    LPSTR pszText;
    int cchTextMax;
    HTREEITEM hItem;
    LPARAM lParam;
} NMTVGETINFOTIPA, *LPNMTVGETINFOTIPA;

typedef struct tagNMTVGETINFOTIPW {
    NMHDR hdr;
    LPWSTR pszText;
    int cchTextMax;
    HTREEITEM hItem;
    LPARAM lParam;
} NMTVGETINFOTIPW, *LPNMTVGETINFOTIPW;

#define TVCDRF_NOIMAGES  0x00010000
#endif

#define TreeView_InsertItem(hwnd,lpis)  (HTREEITEM)SNDMSG((hwnd),TVM_INSERTITEM,0,(LPARAM)(LPTV_INSERTSTRUCT)(lpis))
#define TreeView_DeleteItem(hwnd,hitem)  (BOOL)SNDMSG((hwnd),TVM_DELETEITEM,0,(LPARAM)(HTREEITEM)(hitem))
#define TreeView_DeleteAllItems(hwnd)  (BOOL)SNDMSG((hwnd),TVM_DELETEITEM,0,(LPARAM)TVI_ROOT)
#define TreeView_Expand(hwnd,hitem,code)  (BOOL)SNDMSG((hwnd),TVM_EXPAND,(WPARAM)(code),(LPARAM)(HTREEITEM)(hitem))
#define TreeView_GetItemRect(hwnd,hitem,prc,code)  (*(HTREEITEM*)prc = (hitem), (BOOL)SNDMSG((hwnd),TVM_GETITEMRECT,(WPARAM)(code),(LPARAM)(RECT*)(prc)))
#define TreeView_GetCount(hwnd)  (UINT)SNDMSG((hwnd),TVM_GETCOUNT,0,0)
#define TreeView_GetIndent(hwnd)  (UINT)SNDMSG((hwnd),TVM_GETINDENT,0,0)
#define TreeView_SetIndent(hwnd,indent)  (BOOL)SNDMSG((hwnd),TVM_SETINDENT,(WPARAM)(indent),0)
#define TreeView_GetImageList(hwnd,iImage)  (HIMAGELIST)SNDMSG((hwnd),TVM_GETIMAGELIST,iImage,0)
#define TreeView_SetImageList(hwnd,himl,iImage)  (HIMAGELIST)SNDMSG((hwnd),TVM_SETIMAGELIST,iImage,(LPARAM)(HIMAGELIST)(himl))
#define TreeView_GetNextItem(hwnd,hitem,code)  (HTREEITEM)SNDMSG((hwnd),TVM_GETNEXTITEM,(WPARAM)(code),(LPARAM)(HTREEITEM)(hitem))
#define TreeView_GetChild(hwnd,hitem)  TreeView_GetNextItem(hwnd,hitem,TVGN_CHILD)
#define TreeView_GetNextSibling(hwnd,hitem)  TreeView_GetNextItem(hwnd,hitem,TVGN_NEXT)
#define TreeView_GetPrevSibling(hwnd,hitem)  TreeView_GetNextItem(hwnd,hitem,TVGN_PREVIOUS)
#define TreeView_GetParent(hwnd,hitem)  TreeView_GetNextItem(hwnd,hitem,TVGN_PARENT)
#define TreeView_GetFirstVisible(hwnd)  TreeView_GetNextItem(hwnd,NULL,TVGN_FIRSTVISIBLE)
#define TreeView_GetNextVisible(hwnd,hitem)  TreeView_GetNextItem(hwnd,hitem,TVGN_NEXTVISIBLE)
#define TreeView_GetPrevVisible(hwnd,hitem)  TreeView_GetNextItem(hwnd,hitem,TVGN_PREVIOUSVISIBLE)
#define TreeView_GetSelection(hwnd)  TreeView_GetNextItem(hwnd,NULL,TVGN_CARET)
#define TreeView_GetDropHilight(hwnd)  TreeView_GetNextItem(hwnd,NULL,TVGN_DROPHILITE)
#define TreeView_GetRoot(hwnd)  TreeView_GetNextItem(hwnd,NULL,TVGN_ROOT)
#if (_WIN32_IE >= 0x0400)
#define TreeView_GetLastVisible(hwnd)  TreeView_GetNextItem(hwnd,NULL,TVGN_LASTVISIBLE)
#endif
#define TreeView_Select(hwnd,hitem,code)  (BOOL)SNDMSG((hwnd),TVM_SELECTITEM,(WPARAM)(code),(LPARAM)(HTREEITEM)(hitem))
#define TreeView_SelectItem(hwnd,hitem)  TreeView_Select(hwnd,hitem,TVGN_CARET)
#define TreeView_SelectDropTarget(hwnd,hitem)  TreeView_Select(hwnd,hitem,TVGN_DROPHILITE)
#define TreeView_SelectSetFirstVisible(hwnd,hitem)  TreeView_Select(hwnd,hitem,TVGN_FIRSTVISIBLE)
#define TreeView_GetItem(hwnd,pitem)  (BOOL)SNDMSG((hwnd),TVM_GETITEM,0,(LPARAM)(TV_ITEM*)(pitem))
#define TreeView_SetItem(hwnd,pitem)  (BOOL)SNDMSG((hwnd),TVM_SETITEM,0,(LPARAM)(const TV_ITEM*)(pitem))
#define TreeView_EditLabel(hwnd,hitem)  (HWND)SNDMSG((hwnd),TVM_EDITLABEL,0,(LPARAM)(HTREEITEM)(hitem))
#define TreeView_GetEditControl(hwnd)  (HWND)SNDMSG((hwnd),TVM_GETEDITCONTROL,0,0)
#define TreeView_GetVisibleCount(hwnd)  (UINT)SNDMSG((hwnd),TVM_GETVISIBLECOUNT,0,0)
#define TreeView_HitTest(hwnd,lpht)  (HTREEITEM)SNDMSG((hwnd),TVM_HITTEST,0,(LPARAM)(LPTV_HITTESTINFO)(lpht))
#define TreeView_CreateDragImage(hwnd,hitem)  (HIMAGELIST)SNDMSG((hwnd),TVM_CREATEDRAGIMAGE,0,(LPARAM)(HTREEITEM)(hitem))
#define TreeView_SortChildren(hwnd,hitem,recurse)  (BOOL)SNDMSG((hwnd),TVM_SORTCHILDREN,(WPARAM)(recurse),(LPARAM)(HTREEITEM)(hitem))
#define TreeView_EnsureVisible(hwnd,hitem)  (BOOL)SNDMSG((hwnd),TVM_ENSUREVISIBLE,0,(LPARAM)(HTREEITEM)(hitem))
#define TreeView_SortChildrenCB(hwnd,psort,recurse)  (BOOL)SNDMSG((hwnd),TVM_SORTCHILDRENCB,(WPARAM)(recurse),(LPARAM)(LPTV_SORTCB)(psort))
#define TreeView_EndEditLabelNow(hwnd,fCancel)  (BOOL)SNDMSG((hwnd),TVM_ENDEDITLABELNOW,(WPARAM)(fCancel),0)
#define TreeView_GetISearchString(hwnd,lpsz)  (BOOL)SNDMSG((hwnd),TVM_GETISEARCHSTRING,0,(LPARAM)(LPTSTR)(lpsz))
#define TreeView_SetToolTips(hwnd,hwndTT)  (HWND)SNDMSG((hwnd),TVM_SETTOOLTIPS,(WPARAM)(hwndTT),0)
#define TreeView_GetToolTips(hwnd)  (HWND)SNDMSG((hwnd),TVM_GETTOOLTIPS,0,0)
#if (_WIN32_IE >= 0x0400)
#define TreeView_SetInsertMark(hwnd,hItem,fAfter)  (BOOL)SNDMSG((hwnd),TVM_SETINSERTMARK,(WPARAM)(fAfter),(LPARAM)(hItem))
#define TreeView_SetUnicodeFormat(hwnd,fUnicode)  (BOOL)SNDMSG((hwnd),TVM_SETUNICODEFORMAT,(WPARAM)(fUnicode),0)
#define TreeView_GetUnicodeFormat(hwnd)  (BOOL)SNDMSG((hwnd),TVM_GETUNICODEFORMAT,0,0)
#define TreeView_SetItemHeight(hwnd,iHeight)  (int)SNDMSG((hwnd),TVM_SETITEMHEIGHT,(WPARAM)(iHeight),0)
#define TreeView_GetItemHeight(hwnd)  (int)SNDMSG((hwnd),TVM_GETITEMHEIGHT,0,0)
#define TreeView_SetBkColor(hwnd,clr)  (COLORREF)SNDMSG((hwnd),TVM_SETBKCOLOR,0,(LPARAM)(clr))
#define TreeView_SetTextColor(hwnd,clr)  (COLORREF)SNDMSG((hwnd),TVM_SETTEXTCOLOR,0,(LPARAM)(clr))
#define TreeView_GetBkColor(hwnd)  (COLORREF)SNDMSG((hwnd),TVM_GETBKCOLOR,0,0)
#define TreeView_GetTextColor(hwnd)  (COLORREF)SNDMSG((hwnd),TVM_GETTEXTCOLOR,0,0)
#define TreeView_SetScrollTime(hwnd,uTime)  (UINT)SNDMSG((hwnd),TVM_SETSCROLLTIME,uTime,0)
#define TreeView_GetScrollTime(hwnd)  (UINT)SNDMSG((hwnd),TVM_GETSCROLLTIME,0,0)
#define TreeView_SetInsertMarkColor(hwnd,clr)  (COLORREF)SNDMSG((hwnd),TVM_SETINSERTMARKCOLOR,0,(LPARAM)(clr))
#define TreeView_GetInsertMarkColor(hwnd)  (COLORREF)SNDMSG((hwnd),TVM_GETINSERTMARKCOLOR,0,0)
#endif
#if (_WIN32_IE >= 0x0500)
#define TreeView_SetItemState(hwnd,hti,data,_mask)  { TVITEM _ms_TVi; _ms_TVi.mask = TVIF_STATE; _ms_TVi.hItem = hti; _ms_TVi.stateMask = _mask; _ms_TVi.state = data; SNDMSG((hwnd),TVM_SETITEM,0,(LPARAM)(TV_ITEM*)&_ms_TVi); }
#define TreeView_SetCheckState(hwnd,hti,fCheck)  TreeView_SetItemState(hwnd,hti,INDEXTOSTATEIMAGEMASK((fCheck)?2:1),TVIS_STATEIMAGEMASK)
#define TreeView_GetItemState(hwnd,hti,mask)  (UINT)SNDMSG((hwnd),TVM_GETITEMSTATE,(WPARAM)(hti),(LPARAM)(mask))
#define TreeView_GetCheckState(hwnd,hti)  ((((UINT)(SNDMSG((hwnd),TVM_GETITEMSTATE,(WPARAM)(hti),TVIS_STATEIMAGEMASK)))>>12)-1)
#define TreeView_SetLineColor(hwnd,clr)  (COLORREF)SNDMSG((hwnd),TVM_SETLINECOLOR,0,(LPARAM)(clr))
#define TreeView_GetLineColor(hwnd)  (COLORREF)SNDMSG((hwnd),TVM_GETLINECOLOR,0,0)
#endif
#if (_WIN32_WINNT >= 0x0501)
#define TreeView_MapHTREEITEMToAccID(hwnd,htreeitem)  (UINT)SNDMSG((hwnd),TVM_MAPHTREEITEMTOACCID,(WPARAM)htreeitem,0)
#define TreeView_MapAccIDToHTREEITEM(hwnd,id)  (HTREEITEM)SNDMSG((hwnd),TVM_MAPACCIDTOHTREEITEM,id,0)
#endif

#ifdef UNICODE
#if (_WIN32_IE >= 0x0400)
typedef TVITEMEXW TVITEMEX;
typedef LPTVITEMEXW LPTVITEMEX;
#endif
#define TVITEM TVITEMW
#define LPTVITEM LPTVITEMW
#define TVINSERTSTRUCT TVINSERTSTRUCTW
#define LPTVINSERTSTRUCT LPTVINSERTSTRUCTW
#define TVINSERTSTRUCT_V1_SIZE TVINSERTSTRUCTW_V1_SIZE
#define TVM_INSERTITEM TVM_INSERTITEMW
#define TVM_GETITEM TVM_GETITEMW
#define TVM_SETITEM TVM_SETITEMW
#define TVM_EDITLABEL TVM_EDITLABELW
#define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGW
#define NMTREEVIEW NMTREEVIEWW
#define LPNMTREEVIEW LPNMTREEVIEWW
#define NMTVDISPINFO NMTVDISPINFOW
#define LPNMTVDISPINFO LPNMTVDISPINFOW
#define TVN_SELCHANGING TVN_SELCHANGINGW
#define TVN_SELCHANGED TVN_SELCHANGEDW
#define TVN_GETDISPINFO TVN_GETDISPINFOW
#define TVN_SETDISPINFO TVN_SETDISPINFOW
#define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGW
#define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDW
#define TVN_BEGINDRAG TVN_BEGINDRAGW
#define TVN_BEGINRDRAG TVN_BEGINRDRAGW
#define TVN_DELETEITEM TVN_DELETEITEMW
#define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITW
#define TVN_ENDLABELEDIT TVN_ENDLABELEDITW
#define TVN_GETINFOTIP TVN_GETINFOTIPW
#define NMTVGETINFOTIP NMTVGETINFOTIPW
#define LPNMTVGETINFOTIP LPNMTVGETINFOTIPW
#else
#if (_WIN32_IE >= 0x0400)
typedef TVITEMEXA TVITEMEX;
typedef LPTVITEMEXA LPTVITEMEX;
#endif
#define TVITEM TVITEMA
#define LPTVITEM LPTVITEMA
#define TVINSERTSTRUCT TVINSERTSTRUCTA
#define LPTVINSERTSTRUCT LPTVINSERTSTRUCTA
#define TVINSERTSTRUCT_V1_SIZE TVINSERTSTRUCTA_V1_SIZE
#define TVM_INSERTITEM TVM_INSERTITEMA
#define TVM_GETITEM TVM_GETITEMA
#define TVM_SETITEM TVM_SETITEMA
#define TVM_EDITLABEL TVM_EDITLABELA
#define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGA
#define NMTREEVIEW NMTREEVIEWA
#define LPNMTREEVIEW LPNMTREEVIEWA
#define NMTVDISPINFO NMTVDISPINFOA
#define LPNMTVDISPINFO LPNMTVDISPINFOA
#define TVN_SELCHANGING TVN_SELCHANGINGA
#define TVN_SELCHANGED TVN_SELCHANGEDA
#define TVN_GETDISPINFO TVN_GETDISPINFOA
#define TVN_SETDISPINFO TVN_SETDISPINFOA
#define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGA
#define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDA
#define TVN_BEGINDRAG TVN_BEGINDRAGA
#define TVN_BEGINRDRAG TVN_BEGINRDRAGA
#define TVN_DELETEITEM TVN_DELETEITEMA
#define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITA
#define TVN_ENDLABELEDIT TVN_ENDLABELEDITA
#define TVN_GETINFOTIP TVN_GETINFOTIPA
#define NMTVGETINFOTIP NMTVGETINFOTIPA
#define LPNMTVGETINFOTIP LPNMTVGETINFOTIPA
#endif

#endif /* NOTREEVIEW */

/* ComboboxEx Control *******************************************************/

#ifndef NOUSEREXCONTROLS

#define WC_COMBOBOXEXW  L"ComboBoxEx32"
#define WC_COMBOBOXEXA  "ComboBoxEx32"

#ifdef UNICODE
#define WC_COMBOBOXEX  WC_COMBOBOXEXW
#else
#define WC_COMBOBOXEX  WC_COMBOBOXEXA
#endif

#define CBEIF_TEXT  0x00000001
#define CBEIF_IMAGE  0x00000002
#define CBEIF_SELECTEDIMAGE  0x00000004
#define CBEIF_OVERLAY  0x00000008
#define CBEIF_INDENT  0x00000010
#define CBEIF_LPARAM  0x00000020
#define CBEIF_DI_SETITEM  0x10000000

#define CBEM_INSERTITEMA  (WM_USER+1)
#define CBEM_SETIMAGELIST  (WM_USER+2)
#define CBEM_GETIMAGELIST  (WM_USER+3)
#define CBEM_GETITEMA  (WM_USER+4)
#define CBEM_SETITEMA  (WM_USER+5)
#define CBEM_DELETEITEM  CB_DELETESTRING
#define CBEM_GETCOMBOCONTROL  (WM_USER+6)
#define CBEM_GETEDITCONTROL  (WM_USER+7)
#if (_WIN32_IE >= 0x0400)
#define CBEM_SETEXSTYLE  (WM_USER+8)
#define CBEM_SETEXTENDEDSTYLE  (WM_USER+14)
#define CBEM_GETEXSTYLE  (WM_USER+9)
#define CBEM_GETEXTENDEDSTYLE  (WM_USER+9)
#define CBEM_SETUNICODEFORMAT  CCM_SETUNICODEFORMAT
#define CBEM_GETUNICODEFORMAT  CCM_GETUNICODEFORMAT
#else
#define CBEM_SETEXSTYLE  (WM_USER+8)
#define CBEM_GETEXSTYLE  (WM_USER+9)
#endif
#define CBEM_HASEDITCHANGED  (WM_USER+10)
#define CBEM_INSERTITEMW  (WM_USER+11)
#define CBEM_SETITEMW  (WM_USER+12)
#define CBEM_GETITEMW  (WM_USER+13)
#if (_WIN32_WINNT >= 0x501)
#define CBEM_SETWINDOWTHEME  CCM_SETWINDOWTHEME
#endif

#define CBES_EX_NOEDITIMAGE  0x00000001
#define CBES_EX_NOEDITIMAGEINDENT  0x00000002
#define CBES_EX_PATHWORDBREAKPROC  0x00000004

#if (_WIN32_IE >= 0x0400)
#define CBES_EX_NOSIZELIMIT  0x00000008
#define CBES_EX_CASESENSITIVE  0x00000010

typedef struct tagCOMBOBOXEXITEMA {
    UINT mask;
    INT_PTR iItem;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int iOverlay;
    int iIndent;
    LPARAM lParam;
} COMBOBOXEXITEMA, *PCOMBOBOXEXITEMA;
typedef COMBOBOXEXITEMA CONST *PCCOMBOEXITEMA;

typedef struct tagCOMBOBOXEXITEMW {
    UINT mask;
    INT_PTR iItem;
    LPWSTR pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int iOverlay;
    int iIndent;
    LPARAM lParam;
} COMBOBOXEXITEMW, *PCOMBOBOXEXITEMW;
typedef COMBOBOXEXITEMW CONST *PCCOMBOEXITEMW;

typedef struct {
    NMHDR hdr;
    COMBOBOXEXITEMA ceItem;
} NMCOMBOBOXEXA, *PNMCOMBOBOXEXA;

typedef struct {
    NMHDR hdr;
    COMBOBOXEXITEMW ceItem;
} NMCOMBOBOXEXW, *PNMCOMBOBOXEXW;

#else /* _WIN32_IE >= 0x0400 */

#if 0
typedef struct {
    NMHDR hdr;
    COMBOBOXEXITEM ceItem;
} NMCOMBOBOXEX, *PNMCOMBOBOXEX;
#endif

#define CBEN_GETDISPINFO  (CBEN_FIRST-0)

#endif /* _WIN32_IE >= 0x0400 */

#if (_WIN32_IE >= 0x0400)
#define CBEN_GETDISPINFOA  (CBEN_FIRST-0)
#endif
#define CBEN_INSERTITEM  (CBEN_FIRST-1)
#define CBEN_DELETEITEM  (CBEN_FIRST-2)
#define CBEN_BEGINEDIT  (CBEN_FIRST-4)
#define CBEN_ENDEDITA  (CBEN_FIRST-5)
#define CBEN_ENDEDITW  (CBEN_FIRST-6)
#if (_WIN32_IE >= 0x0400)
#define CBEN_GETDISPINFOW  (CBEN_FIRST-7)
#define CBEN_DRAGBEGINA  (CBEN_FIRST-8)
#define CBEN_DRAGBEGINW  (CBEN_FIRST-9)
#endif

#define CBENF_KILLFOCUS  1
#define CBENF_RETURN  2
#define CBENF_ESCAPE  3
#define CBENF_DROPDOWN  4

#define CBEMAXSTRLEN 260

#if (_WIN32_IE >= 0x0400)
typedef struct {
    NMHDR hdr;
    int iItemid;
    WCHAR szText[CBEMAXSTRLEN];
} NMCBEDRAGBEGINW, *LPNMCBEDRAGBEGINW, *PNMCBEDRAGBEGINW;

typedef struct {
    NMHDR hdr;
    int iItemid;
    char szText[CBEMAXSTRLEN];
}NMCBEDRAGBEGINA, *LPNMCBEDRAGBEGINA, *PNMCBEDRAGBEGINA;
#endif

typedef struct {
    NMHDR hdr;
    BOOL fChanged;
    int iNewSelection;
    WCHAR szText[CBEMAXSTRLEN];
    int iWhy;
} NMCBEENDEDITW, *LPNMCBEENDEDITW, *PNMCBEENDEDITW;

typedef struct {
    NMHDR hdr;
    BOOL fChanged;
    int iNewSelection;
    char szText[CBEMAXSTRLEN];
    int iWhy;
} NMCBEENDEDITA, *LPNMCBEENDEDITA,*PNMCBEENDEDITA;

#define ComboBoxEx_InsertItem(hwnd,pitem)  (int)SNDMSG((hwnd),CBEM_INSERTITEM,0,(LPARAM)(const COMBOBOXEXITEM*)(pitem))
#define ComboBoxEx_SetImageList(hwnd,himl)  (HIMAGELIST)SNDMSG((hwnd),CBEM_SETIMAGELIST,0,(LPARAM)(HIMAGELIST)(himl))
#define ComboBoxEx_GetImageList(hwnd)  (HIMAGELIST)SNDMSG((hwnd),CBEM_GETIMAGELIST,0,0)
#define ComboBoxEx_GetItem(hwnd,pitem)  (BOOL)SNDMSG((hwnd),CBEM_GETITEM,0,(LPARAM)(COMBOBOXEXITEM*)(pitem))
#define ComboBoxEx_SetItem(hwnd,pitem)  (BOOL)SNDMSG((hwnd),CBEM_SETITEM,0,(LPARAM)(const COMBOBOXEXITEM*)(pitem))
#define ComboBoxEx_DeleteItem(hwnd,i)  (int)SNDMSG((hwnd),CBEM_DELETEITEM,(WPARAM)(int)(i),0)
#define ComboBoxEx_GetComboControl(hwnd)  (HWND)SNDMSG((hwnd),CBEM_GETCOMBOCONTROL,0,0)
#define ComboBoxEx_GetEditControl(hwnd)  (HWND)SNDMSG((hwnd),CBEM_GETEDITCONTROL,0,0)
#if (_WIN32_IE >= 0x0400)
#define ComboBoxEx_SetExtendedStyle(hwnd,dwExMask,dwExStyle)  (DWORD)SNDMSG((hwnd),CBEM_SETEXTENDEDSTYLE,(dwExMask),(dwExStyle))
#define ComboBoxEx_GetExtendedStyle(hwnd)  (DWORD)SNDMSG((hwnd),CBEM_GETEXTENDEDSTYLE,0,0)
#else
#define ComboBoxEx_GetExtendedStyle(hwnd)  (DWORD)SNDMSG((hwnd),CBEM_GETEXSTYLE,0,0)
#endif
#define ComboBoxEx_HasEditChanged(hwnd)  (BOOL)SNDMSG((hwnd),CBEM_HASEDITCHANGED,0,0)
#if (_WIN32_WINNT >= 0x501)
#define ComboBoxEx_SetWindowTheme(hwnd,pwStr)  (void)SNDMSG((hwnd),CBEM_SETWINDOWTHEME,0,(LPARAM)(LPWSTR)(pwStr))
#endif

#ifdef UNICODE
#define COMBOBOXEXITEM COMBOBOXEXITEMW
#define PCOMBOBOXEXITEM PCOMBOBOXEXITEMW
#define PCCOMBOBOXEXITEM PCCOMBOBOXEXITEMW
#define CBEM_INSERTITEM CBEM_INSERTITEMW
#define CBEM_SETITEM CBEM_SETITEMW
#define CBEM_GETITEM CBEM_GETITEMW
#define NMCOMBOBOXEX NMCOMBOBOXEXW
#define PNMCOMBOBOXEX PNMCOMBOBOXEXW
#if (_WIN32_IE >= 0x0400)
#define CBEN_GETDISPINFO CBEN_GETDISPINFOW
#endif
#define CBEN_ENDEDIT CBEN_ENDEDITW
#define CBEN_DRAGBEGIN CBEN_DRAGBEGINW
#define NMCBEDRAGBEGIN NMCBEDRAGBEGINW
#define LPNMCBEDRAGBEGIN LPNMCBEDRAGBEGINW
#define PNMCBEDRAGBEGIN PNMCBEDRAGBEGINW
#define NMCBEENDEDIT NMCBEENDEDITW
#define LPNMCBEENDEDIT LPNMCBEENDEDITW
#define PNMCBEENDEDIT PNMCBEENDEDITW
#else
#define COMBOBOXEXITEM COMBOBOXEXITEMA
#define PCOMBOBOXEXITEM PCOMBOBOXEXITEMA
#define PCCOMBOBOXEXITEM PCCOMBOBOXEXITEMA
#define CBEM_INSERTITEM CBEM_INSERTITEMA
#define CBEM_SETITEM CBEM_SETITEMA
#define CBEM_GETITEM CBEM_GETITEMA
#define NMCOMBOBOXEX NMCOMBOBOXEXA
#define PNMCOMBOBOXEX PNMCOMBOBOXEXA
#if (_WIN32_IE >= 0x0400)
#define CBEN_GETDISPINFO CBEN_GETDISPINFOA
#endif
#define CBEN_ENDEDIT CBEN_ENDEDITA
#define CBEN_DRAGBEGIN CBEN_DRAGBEGINA
#define NMCBEDRAGBEGIN NMCBEDRAGBEGINA
#define LPNMCBEDRAGBEGIN LPNMCBEDRAGBEGINA
#define PNMCBEDRAGBEGIN PNMCBEDRAGBEGINA
#define NMCBEENDEDIT NMCBEENDEDITA
#define LPNMCBEENDEDIT LPNMCBEENDEDITA
#define PNMCBEENDEDIT PNMCBEENDEDITA
#endif

#endif /* NOUSEREXCONTROLS */

/* Tab Control **************************************************************/

#ifndef NOTABCONTROL

#define WC_TABCONTROLA  "SysTabControl32"
#define WC_TABCONTROLW  L"SysTabControl32"

#ifdef UNICODE
#define  WC_TABCONTROL  WC_TABCONTROLW
#else
#define  WC_TABCONTROL  WC_TABCONTROLA
#endif

#define TCS_SCROLLOPPOSITE  0x0001
#define TCS_BOTTOM  0x0002
#define TCS_RIGHT  0x0002
#define TCS_MULTISELECT  0x0004
#if (_WIN32_IE >= 0x0400)
#define TCS_FLATBUTTONS  0x0008
#endif
#define TCS_FORCEICONLEFT  0x0010
#define TCS_FORCELABELLEFT  0x0020
#define TCS_HOTTRACK  0x0040
#define TCS_VERTICAL  0x0080
#define TCS_TABS  0x0000
#define TCS_BUTTONS  0x0100
#define TCS_SINGLELINE  0x0000
#define TCS_MULTILINE  0x0200
#define TCS_RIGHTJUSTIFY  0x0000
#define TCS_FIXEDWIDTH  0x0400
#define TCS_RAGGEDRIGHT  0x0800
#define TCS_FOCUSONBUTTONDOWN  0x1000
#define TCS_OWNERDRAWFIXED  0x2000
#define TCS_TOOLTIPS  0x4000
#define TCS_FOCUSNEVER  0x8000

#if (_WIN32_IE >= 0x0400)
#define TCS_EX_FLATSEPARATORS  0x00000001
#define TCS_EX_REGISTERDROP  0x00000002
#endif

#define TCIF_TEXT  0x0001
#define TCIF_IMAGE  0x0002
#define TCIF_RTLREADING  0x0004
#define TCIF_PARAM  0x0008
#define TCIF_STATE  0x0010

#define TCIS_BUTTONPRESSED  0x0001
#if (_WIN32_IE >= 0x0400)
#define TCIS_HIGHLIGHTED  0x0002
#endif

#define TCHT_NOWHERE  0x0001
#define TCHT_ONITEMICON  0x0002
#define TCHT_ONITEMLABEL  0x0004
#define TCHT_ONITEM  (TCHT_ONITEMICON|TCHT_ONITEMLABEL)

#define TCM_GETIMAGELIST  (TCM_FIRST+2)
#define TCM_SETIMAGELIST  (TCM_FIRST+3)
#define TCM_GETITEMCOUNT  (TCM_FIRST+4)
#define TCM_GETITEMA  (TCM_FIRST+5)
#define TCM_GETITEMW  (TCM_FIRST+60)
#define TCM_SETITEMA  (TCM_FIRST+6)
#define TCM_SETITEMW  (TCM_FIRST+61)
#define TCM_INSERTITEMA  (TCM_FIRST+7)
#define TCM_INSERTITEMW  (TCM_FIRST+62)
#define TCM_DELETEITEM  (TCM_FIRST+8)
#define TCM_DELETEALLITEMS  (TCM_FIRST+9)
#define TCM_GETITEMRECT  (TCM_FIRST+10)
#define TCM_GETCURSEL  (TCM_FIRST+11)
#define TCM_SETCURSEL  (TCM_FIRST+12)
#define TCM_HITTEST  (TCM_FIRST+13)
#define TCM_SETITEMEXTRA  (TCM_FIRST+14)
#define TCM_ADJUSTRECT  (TCM_FIRST+40)
#define TCM_SETITEMSIZE  (TCM_FIRST+41)
#define TCM_REMOVEIMAGE  (TCM_FIRST+42)
#define TCM_SETPADDING  (TCM_FIRST+43)
#define TCM_GETROWCOUNT  (TCM_FIRST+44)
#define TCM_GETTOOLTIPS  (TCM_FIRST+45)
#define TCM_SETTOOLTIPS  (TCM_FIRST+46)
#define TCM_GETCURFOCUS  (TCM_FIRST+47)
#define TCM_SETCURFOCUS  (TCM_FIRST+48)
#define TCM_SETMINTABWIDTH  (TCM_FIRST+49)
#define TCM_DESELECTALL  (TCM_FIRST+50)
#if (_WIN32_IE >= 0x0400)
#define TCM_HIGHLIGHTITEM  (TCM_FIRST+51)
#define TCM_SETEXTENDEDSTYLE  (TCM_FIRST+52)
#define TCM_GETEXTENDEDSTYLE  (TCM_FIRST+53)
#define TCM_SETUNICODEFORMAT  CCM_SETUNICODEFORMAT
#define TCM_GETUNICODEFORMAT  CCM_GETUNICODEFORMAT
#endif

#define TCN_KEYDOWN  (TCN_FIRST-0)
#define TCN_SELCHANGE  (TCN_FIRST-1)
#define TCN_SELCHANGING  (TCN_FIRST-2)
#if (_WIN32_IE >= 0x0400)
#define TCN_GETOBJECT  (TCN_FIRST-3)
#endif
#if (_WIN32_IE >= 0x0500)
#define TCN_FOCUSCHANGE  (TCN_FIRST-4)
#endif

#define TC_ITEMA TCITEMA
#define TC_ITEMW TCITEMW
#define TC_ITEM TCITEM

#define TC_ITEMHEADERA TCITEMHEADERA
#define TC_ITEMHEADERW TCITEMHEADERW
#define TC_ITEMHEADER TCITEMHEADER

#define LPTC_HITTESTINFO LPTCHITTESTINFO
#define TC_HITTESTINFO TCHITTESTINFO
#define TC_KEYDOWN NMTCKEYDOWN

typedef struct tagTCITEMHEADERA {
    UINT mask;
    UINT lpReserved1;
    UINT lpReserved2;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
} TCITEMHEADERA, *LPTCITEMHEADERA;

typedef struct tagTCITEMHEADERW {
    UINT mask;
    UINT lpReserved1;
    UINT lpReserved2;
    LPWSTR pszText;
    int cchTextMax;
    int iImage;
} TCITEMHEADERW, *LPTCITEMHEADERW;

typedef struct tagTCITEMA {
    UINT mask;
    DWORD dwState;
    DWORD dwStateMask;
    LPSTR pszText;
    int cchTextMax;
    int iImage;
    LPARAM lParam;
} TCITEMA, *LPTCITEMA;

typedef struct tagTCITEMW {
    UINT mask;
    DWORD dwState;
    DWORD dwStateMask;
    LPWSTR pszText;
    int cchTextMax;
    int iImage;
    LPARAM lParam;
} TCITEMW, *LPTCITEMW;

typedef struct tagTCHITTESTINFO {
    POINT pt;
    UINT flags;
} TCHITTESTINFO, *LPTCHITTESTINFO;

#include <pshpack1.h>
typedef struct tagTCKEYDOWN {
    NMHDR hdr;
    WORD wVKey;
    UINT flags;
} NMTCKEYDOWN;
#include <poppack.h>

#define TabCtrl_GetImageList(hwnd)  (HIMAGELIST)SNDMSG((hwnd),TCM_GETIMAGELIST,0,0L)
#define TabCtrl_SetImageList(hwnd,himl)  (HIMAGELIST)SNDMSG((hwnd),TCM_SETIMAGELIST,0,(LPARAM)(HIMAGELIST)(himl))
#define TabCtrl_GetItemCount(hwnd)  (int)SNDMSG((hwnd),TCM_GETITEMCOUNT,0,0L)
#define TabCtrl_GetItem(hwnd,iItem,pitem)  (BOOL)SNDMSG((hwnd),TCM_GETITEM,(WPARAM)(int)(iItem),(LPARAM)(TC_ITEM*)(pitem))
#define TabCtrl_SetItem(hwnd,iItem,pitem)  (BOOL)SNDMSG((hwnd),TCM_SETITEM,(WPARAM)(int)(iItem),(LPARAM)(TC_ITEM*)(pitem))
#define TabCtrl_InsertItem(hwnd,iItem,pitem)  (int)SNDMSG((hwnd),TCM_INSERTITEM,(WPARAM)(int)(iItem),(LPARAM)(const TC_ITEM*)(pitem))
#define TabCtrl_DeleteItem(hwnd,i)  (BOOL)SNDMSG((hwnd),TCM_DELETEITEM,(WPARAM)(int)(i),0L)
#define TabCtrl_DeleteAllItems(hwnd)  (BOOL)SNDMSG((hwnd),TCM_DELETEALLITEMS,0,0L)
#define TabCtrl_GetItemRect(hwnd,i,prc)  (BOOL)SNDMSG((hwnd),TCM_GETITEMRECT,(WPARAM)(int)(i),(LPARAM)(RECT*)(prc))
#define TabCtrl_GetCurSel(hwnd)  (int)SNDMSG((hwnd),TCM_GETCURSEL,0,0)
#define TabCtrl_SetCurSel(hwnd,i)  (int)SNDMSG((hwnd),TCM_SETCURSEL,(WPARAM)(i),0)
#define TabCtrl_HitTest(hwnd,pinfo)  (int)SNDMSG((hwnd),TCM_HITTEST,0,(LPARAM)(TC_HITTESTINFO*)(pinfo))
#define TabCtrl_SetItemExtra(hwnd,cb)  (BOOL)SNDMSG((hwnd),TCM_SETITEMEXTRA,(WPARAM)(cb),0L)
#define TabCtrl_AdjustRect(hwnd,bLarger,prc)  (int)SNDMSG(hwnd,TCM_ADJUSTRECT,(WPARAM)(BOOL)(bLarger),(LPARAM)(RECT*)prc)
#define TabCtrl_SetItemSize(hwnd,x,y)  (DWORD)SNDMSG((hwnd),TCM_SETITEMSIZE,0,MAKELPARAM(x,y))
#define TabCtrl_RemoveImage(hwnd,i)  (void)SNDMSG((hwnd),TCM_REMOVEIMAGE,i,0L)
#define TabCtrl_SetPadding(hwnd,cx,cy)  (void)SNDMSG((hwnd),TCM_SETPADDING,0,MAKELPARAM(cx,cy))
#define TabCtrl_GetRowCount(hwnd)  (int)SNDMSG((hwnd),TCM_GETROWCOUNT,0,0L)
#define TabCtrl_GetToolTips(hwnd)  (HWND)SNDMSG((hwnd),TCM_GETTOOLTIPS,0,0L)
#define TabCtrl_SetToolTips(hwnd,hwndTT)  (void)SNDMSG((hwnd),TCM_SETTOOLTIPS,(WPARAM)(hwndTT),0L)
#define TabCtrl_GetCurFocus(hwnd)  (int)SNDMSG((hwnd),TCM_GETCURFOCUS,0,0)
#define TabCtrl_SetCurFocus(hwnd,i)  SNDMSG((hwnd),TCM_SETCURFOCUS,i,0)
#define TabCtrl_SetMinTabWidth(hwnd,x)  (int)SNDMSG((hwnd),TCM_SETMINTABWIDTH,0,x)
#define TabCtrl_DeselectAll(hwnd,fExcludeFocus)  (void)SNDMSG((hwnd),TCM_DESELECTALL,fExcludeFocus,0)
#if (_WIN32_IE >= 0x0400)
#define TabCtrl_HighlightItem(hwnd,i,fHighlight)  (BOOL)SNDMSG((hwnd),TCM_HIGHLIGHTITEM,(WPARAM)(i),(LPARAM)MAKELONG(fHighlight,0))
#define TabCtrl_SetExtendedStyle(hwnd,dw)  (DWORD)SNDMSG((hwnd),TCM_SETEXTENDEDSTYLE,0,dw)
#define TabCtrl_GetExtendedStyle(hwnd)  (DWORD)SNDMSG((hwnd),TCM_GETEXTENDEDSTYLE,0,0)
#define TabCtrl_SetUnicodeFormat(hwnd,fUnicode)  (BOOL)SNDMSG((hwnd),TCM_SETUNICODEFORMAT,(WPARAM)(fUnicode),0)
#define TabCtrl_GetUnicodeFormat(hwnd)  (BOOL)SNDMSG((hwnd),TCM_GETUNICODEFORMAT,0,0)
#endif

#ifdef UNICODE
#define TCITEMHEADER TCITEMHEADERW
#define LPTCITEMHEADER LPTCITEMHEADERW
#define TCITEM TCITEMW
#define LPTCITEM LPTCITEMW
#define TCM_GETITEM TCM_GETITEMW
#define TCM_SETITEM TCM_SETITEMW
#define TCM_INSERTITEM TCM_INSERTITEMW
#else
#define TCITEMHEADER TCITEMHEADERA
#define LPTCITEMHEADER LPTCITEMHEADERA
#define TCITEM TCITEMA
#define LPTCITEM LPTCITEMA
#define TCM_GETITEM TCM_GETITEMA
#define TCM_SETITEM TCM_SETITEMA
#define TCM_INSERTITEM TCM_INSERTITEMA
#endif

#endif /* NOTABCONTROL */

/* Animate Control **********************************************************/

#ifndef NOANIMATE

#define ANIMATE_CLASSW  L"SysAnimate32"
#define ANIMATE_CLASSA  "SysAnimate32"

#ifdef UNICODE
#define ANIMATE_CLASS  ANIMATE_CLASSW
#else
#define ANIMATE_CLASS  ANIMATE_CLASSA
#endif

#define ACS_CENTER  0x0001
#define ACS_TRANSPARENT  0x0002
#define ACS_AUTOPLAY  0x0004
#define ACS_TIMER  0x0008

#define ACM_OPENA  (WM_USER+100)
#define ACM_OPENW  (WM_USER+103)
#define ACM_PLAY  (WM_USER+101)
#define ACM_STOP  (WM_USER+102)

#define ACN_START  1
#define ACN_STOP  2

#define Animate_Create(hwndP,id,dwStyle,hInstance)  CreateWindow(ANIMATE_CLASS,NULL,dwStyle,0,0,0,0,hwndP,(HMENU)(id),hInstance,NULL)
#define Animate_Open(hwnd,szName)  (BOOL)SNDMSG(hwnd,ACM_OPEN,0,(LPARAM)(LPTSTR)(szName))
#define Animate_OpenEx(hwnd,hInst,szName)  (BOOL)SNDMSG(hwnd,ACM_OPEN,(WPARAM)(hInst),(LPARAM)(LPTSTR)(szName))
#define Animate_Play(hwnd,from,to,rep)  (BOOL)SNDMSG(hwnd,ACM_PLAY,(WPARAM)(rep),(LPARAM)MAKELONG(from,to))
#define Animate_Stop(hwnd)  (BOOL)SNDMSG(hwnd,ACM_STOP,0,0)
#define Animate_Close(hwnd)  Animate_Open(hwnd,NULL)
#define Animate_Seek(hwnd,frame)  Animate_Play(hwnd,frame,frame,1)

#ifdef UNICODE
#define ACM_OPEN ACM_OPENW
#else
#define ACM_OPEN ACM_OPENA
#endif

#endif /* NOANIMATE */

/* MonthCal Control *********************************************************/

#ifndef NOMONTHCAL

#define MONTHCAL_CLASSW  L"SysMonthCal32"
#define MONTHCAL_CLASSA  "SysMonthCal32"

#ifdef UNICODE
#define MONTHCAL_CLASS  MONTHCAL_CLASSW
#else
#define MONTHCAL_CLASS  MONTHCAL_CLASSA
#endif

#define MCSC_BACKGROUND  0
#define MCSC_TEXT  1
#define MCSC_TITLEBK  2
#define MCSC_TITLETEXT  3
#define MCSC_MONTHBK  4
#define MCSC_TRAILINGTEXT  5

#define MCHT_TITLE  0x00010000
#define MCHT_CALENDAR  0x00020000
#define MCHT_TODAYLINK  0x00030000
#define MCHT_NEXT  0x01000000
#define MCHT_PREV  0x02000000
#define MCHT_NOWHERE  0x00000000
#define MCHT_TITLEBK  (MCHT_TITLE)
#define MCHT_TITLEMONTH  (MCHT_TITLE|0x0001)
#define MCHT_TITLEYEAR  (MCHT_TITLE|0x0002)
#define MCHT_TITLEBTNNEXT  (MCHT_TITLE|MCHT_NEXT|0x0003)
#define MCHT_TITLEBTNPREV  (MCHT_TITLE|MCHT_PREV|0x0003)
#define MCHT_CALENDARBK  (MCHT_CALENDAR)
#define MCHT_CALENDARDATE  (MCHT_CALENDAR|0x0001)
#define MCHT_CALENDARDATENEXT  (MCHT_CALENDARDATE|MCHT_NEXT)
#define MCHT_CALENDARDATEPREV  (MCHT_CALENDARDATE|MCHT_PREV)
#define MCHT_CALENDARDAY  (MCHT_CALENDAR|0x0002)
#define MCHT_CALENDARWEEKNUM  (MCHT_CALENDAR|0x0003)

#define MCS_DAYSTATE  0x0001
#define MCS_MULTISELECT  0x0002
#define MCS_WEEKNUMBERS  0x0004
#if (_WIN32_IE >= 0x0400)
#define MCS_NOTODAYCIRCLE  0x0008
#define MCS_NOTODAY  0x0010
#else
#define MCS_NOTODAY  0x0008
#endif

#define GMR_VISIBLE  0
#define GMR_DAYSTATE  1

#define MCM_FIRST  0x1000
#define MCM_GETCURSEL  (MCM_FIRST+1)
#define MCM_SETCURSEL  (MCM_FIRST+2)
#define MCM_GETMAXSELCOUNT  (MCM_FIRST+3)
#define MCM_SETMAXSELCOUNT  (MCM_FIRST+4)
#define MCM_GETSELRANGE  (MCM_FIRST+5)
#define MCM_SETSELRANGE  (MCM_FIRST+6)
#define MCM_GETMONTHRANGE  (MCM_FIRST+7)
#define MCM_SETDAYSTATE  (MCM_FIRST+8)
#define MCM_GETMINREQRECT  (MCM_FIRST+9)
#define MCM_SETCOLOR  (MCM_FIRST+10)
#define MCM_GETCOLOR  (MCM_FIRST+11)
#define MCM_SETTODAY  (MCM_FIRST+12)
#define MCM_GETTODAY  (MCM_FIRST+13)
#define MCM_HITTEST  (MCM_FIRST+14)
#define MCM_SETFIRSTDAYOFWEEK  (MCM_FIRST+15)
#define MCM_GETFIRSTDAYOFWEEK  (MCM_FIRST+16)
#define MCM_GETRANGE  (MCM_FIRST+17)
#define MCM_SETRANGE  (MCM_FIRST+18)
#define MCM_GETMONTHDELTA  (MCM_FIRST+19)
#define MCM_SETMONTHDELTA  (MCM_FIRST+20)
#define MCM_GETMAXTODAYWIDTH  (MCM_FIRST+21)
#if (_WIN32_IE >= 0x0400)
#define MCM_SETUNICODEFORMAT  CCM_SETUNICODEFORMAT
#define MCM_GETUNICODEFORMAT  CCM_GETUNICODEFORMAT
#endif

#define MCN_SELCHANGE  (MCN_FIRST+1)
#define MCN_GETDAYSTATE  (MCN_FIRST+3)
#define MCN_SELECT  (MCN_FIRST+4)

typedef struct {
    UINT cbSize;
    POINT pt;
    UINT uHit;
    SYSTEMTIME st;
} MCHITTESTINFO, *PMCHITTESTINFO;

typedef struct tagNMSELCHANGE {
    NMHDR nmhdr;
    SYSTEMTIME stSelStart;
    SYSTEMTIME stSelEnd;
} NMSELCHANGE, *LPNMSELCHANGE;

typedef DWORD MONTHDAYSTATE, *LPMONTHDAYSTATE;

typedef struct tagNMDAYSTATE {
    NMHDR nmhdr;
    SYSTEMTIME stStart;
    int cDayState;
    LPMONTHDAYSTATE prgDayState;
} NMDAYSTATE, *LPNMDAYSTATE;

typedef NMSELCHANGE NMSELECT, *LPNMSELECT;

#define MonthCal_GetCurSel(hmc,pst)  (BOOL)SNDMSG(hmc,MCM_GETCURSEL,0,(LPARAM)(pst))
#define MonthCal_SetCurSel(hmc,pst)  (BOOL)SNDMSG(hmc,MCM_SETCURSEL,0,(LPARAM)(pst))
#define MonthCal_GetMaxSelCount(hmc)  (DWORD)SNDMSG(hmc,MCM_GETMAXSELCOUNT,0,0L)
#define MonthCal_SetMaxSelCount(hmc,n)  (BOOL)SNDMSG(hmc,MCM_SETMAXSELCOUNT,(WPARAM)(n),0L)
#define MonthCal_GetSelRange(hmc,rgst)  SNDMSG(hmc,MCM_GETSELRANGE,0,(LPARAM)(rgst))
#define MonthCal_SetSelRange(hmc, rgst)  SNDMSG(hmc,MCM_SETSELRANGE,0,(LPARAM)(rgst))
#define MonthCal_GetMonthRange(hmc,gmr,rgst)  (DWORD)SNDMSG(hmc,MCM_GETMONTHRANGE,(WPARAM)(gmr),(LPARAM)(rgst))
#define MonthCal_SetDayState(hmc,cbds,rgds)  SNDMSG(hmc,MCM_SETDAYSTATE,(WPARAM)(cbds),(LPARAM)(rgds))
#define MonthCal_GetMinReqRect(hmc,prc)  SNDMSG(hmc,MCM_GETMINREQRECT,0,(LPARAM)(prc))
#define MonthCal_SetColor(hmc,iColor,clr)  SNDMSG(hmc,MCM_SETCOLOR,iColor,clr)
#define MonthCal_GetColor(hmc,iColor)  SNDMSG(hmc,MCM_GETCOLOR,iColor,0)
#define MonthCal_SetToday(hmc,pst)  SNDMSG(hmc,MCM_SETTODAY,0,(LPARAM)(pst))
#define MonthCal_GetToday(hmc,pst)  (BOOL)SNDMSG(hmc,MCM_GETTODAY,0,(LPARAM)(pst))
#define MonthCal_HitTest(hmc,pinfo)  SNDMSG(hmc,MCM_HITTEST,0,(LPARAM)(PMCHITTESTINFO)(pinfo))
#define MonthCal_SetFirstDayOfWeek(hmc,iDay)  SNDMSG(hmc,MCM_SETFIRSTDAYOFWEEK,0,iDay)
#define MonthCal_GetFirstDayOfWeek(hmc)  (DWORD)SNDMSG(hmc,MCM_GETFIRSTDAYOFWEEK,0,0)
#define MonthCal_GetRange(hmc,rgst)  (DWORD)SNDMSG(hmc,MCM_GETRANGE,0,(LPARAM)(rgst))
#define MonthCal_SetRange(hmc,gd,rgst)  (BOOL)SNDMSG(hmc,MCM_SETRANGE,(WPARAM)(gd),(LPARAM)(rgst))
#define MonthCal_GetMonthDelta(hmc)  (int)SNDMSG(hmc,MCM_GETMONTHDELTA,0,0)
#define MonthCal_SetMonthDelta(hmc,n)  (int)SNDMSG(hmc,MCM_SETMONTHDELTA,n,0)
#define MonthCal_GetMaxTodayWidth(hmc)  (DWORD)SNDMSG(hmc,MCM_GETMAXTODAYWIDTH,0,0)
#if (_WIN32_IE >= 0x0400)
#define MonthCal_SetUnicodeFormat(hwnd,fUnicode)  (BOOL)SNDMSG((hwnd),MCM_SETUNICODEFORMAT,(WPARAM)(fUnicode),0)
#define MonthCal_GetUnicodeFormat(hwnd)  (BOOL)SNDMSG((hwnd),MCM_GETUNICODEFORMAT,0,0)
#endif

#endif /* NOMONTHCAL */

/* DateTime Picker Control **************************************************/

#ifndef NODATETIMEPICK

#define DATETIMEPICK_CLASSW  L"SysDateTimePick32"
#define DATETIMEPICK_CLASSA  "SysDateTimePick32"

#ifdef UNICODE
#define DATETIMEPICK_CLASS  DATETIMEPICK_CLASSW
#else
#define DATETIMEPICK_CLASS  DATETIMEPICK_CLASSA
#endif

#define DTS_UPDOWN  0x0001
#define DTS_SHOWNONE  0x0002
#define DTS_SHORTDATEFORMAT 0x0000
#define DTS_LONGDATEFORMAT  0x0004
#if (_WIN32_IE >= 0x500 || defined(_WINCE) /* Smartphone only? */)
#define DTS_SHORTDATECENTURYFORMAT 0x000C
#endif
#define DTS_TIMEFORMAT  0x0009
#define DTS_APPCANPARSE  0x0010
#define DTS_RIGHTALIGN  0x0020

#define GDTR_MIN  0x0001
#define GDTR_MAX  0x0002

#define GDT_ERROR  -1
#define GDT_VALID  0
#define GDT_NONE  1

#define DTM_FIRST  0x1000
#define DTM_GETSYSTEMTIME  (DTM_FIRST+1)
#define DTM_SETSYSTEMTIME  (DTM_FIRST+2)
#define DTM_GETRANGE  (DTM_FIRST+3)
#define DTM_SETRANGE  (DTM_FIRST+4)
#define DTM_SETFORMATA  (DTM_FIRST+5)
#define DTM_SETFORMATW  (DTM_FIRST+50)
#define DTM_SETMCCOLOR  (DTM_FIRST+6)
#define DTM_GETMCCOLOR  (DTM_FIRST+7)
#define DTM_GETMONTHCAL  (DTM_FIRST+8)
#if (_WIN32_IE >= 0x0400)
#define DTM_SETMCFONT  (DTM_FIRST+9)
#define DTM_GETMCFONT  (DTM_FIRST+10)
#endif

#define DTN_DATETIMECHANGE  (DTN_FIRST+1)
#define DTN_USERSTRINGA  (DTN_FIRST+2)
#define DTN_USERSTRINGW  (DTN_FIRST+15)
#define DTN_WMKEYDOWNA  (DTN_FIRST+3)
#define DTN_WMKEYDOWNW  (DTN_FIRST+16)
#define DTN_FORMATA  (DTN_FIRST+4)
#define DTN_FORMATW  (DTN_FIRST+17)
#define DTN_FORMATQUERYA  (DTN_FIRST+5)
#define DTN_FORMATQUERYW  (DTN_FIRST+18)
#define DTN_DROPDOWN  (DTN_FIRST+6)
#define DTN_CLOSEUP  (DTN_FIRST+7)

typedef struct tagNMDATETIMECHANGE {
    NMHDR nmhdr;
    DWORD dwFlags;
    SYSTEMTIME st;
} NMDATETIMECHANGE, *LPNMDATETIMECHANGE;

typedef struct tagNMDATETIMESTRINGA {
    NMHDR nmhdr;
    LPCSTR pszUserString;
    SYSTEMTIME st;
    DWORD dwFlags;
} NMDATETIMESTRINGA, *LPNMDATETIMESTRINGA;

typedef struct tagNMDATETIMESTRINGW {
    NMHDR nmhdr;
    LPCWSTR pszUserString;
    SYSTEMTIME st;
    DWORD dwFlags;
} NMDATETIMESTRINGW, *LPNMDATETIMESTRINGW;

typedef struct tagNMDATETIMEWMKEYDOWNA {
    NMHDR nmhdr;
    int nVirtKey;
    LPCSTR pszFormat;
    SYSTEMTIME st;
} NMDATETIMEWMKEYDOWNA, *LPNMDATETIMEWMKEYDOWNA;

typedef struct tagNMDATETIMEWMKEYDOWNW {
    NMHDR nmhdr;
    int nVirtKey;
    LPCWSTR pszFormat;
    SYSTEMTIME st;
} NMDATETIMEWMKEYDOWNW, *LPNMDATETIMEWMKEYDOWNW;

typedef struct tagNMDATETIMEFORMATA {
    NMHDR nmhdr;
    LPCSTR pszFormat;
    SYSTEMTIME st;
    LPCSTR pszDisplay;
    CHAR szDisplay[64];
} NMDATETIMEFORMATA, *LPNMDATETIMEFORMATA;

typedef struct tagNMDATETIMEFORMATW {
    NMHDR nmhdr;
    LPCWSTR pszFormat;
    SYSTEMTIME st;
    LPCWSTR pszDisplay;
    WCHAR szDisplay[64];
} NMDATETIMEFORMATW, *LPNMDATETIMEFORMATW;

typedef struct tagNMDATETIMEFORMATQUERYA {
    NMHDR nmhdr;
    LPCSTR pszFormat;
    SIZE szMax;
} NMDATETIMEFORMATQUERYA, *LPNMDATETIMEFORMATQUERYA;

typedef struct tagNMDATETIMEFORMATQUERYW {
    NMHDR nmhdr;
    LPCWSTR pszFormat;
    SIZE szMax;
} NMDATETIMEFORMATQUERYW, *LPNMDATETIMEFORMATQUERYW;

#define DateTime_GetSystemtime(hdp,pst)  (DWORD)SNDMSG(hdp,DTM_GETSYSTEMTIME,0,(LPARAM)(pst))
#define DateTime_SetSystemtime(hdp,gd,pst)  (BOOL)SNDMSG(hdp,DTM_SETSYSTEMTIME,(WPARAM)(gd),(LPARAM)(pst))
#define DateTime_GetRange(hdp,rgst)  (DWORD)SNDMSG(hdp,DTM_GETRANGE,0,(LPARAM)(rgst))
#define DateTime_SetRange(hdp,gd,rgst)  (BOOL)SNDMSG(hdp,DTM_SETRANGE,(WPARAM)(gd),(LPARAM)(rgst))
#define DateTime_SetFormat(hdp,sz)  (BOOL)SNDMSG(hdp,DTM_SETFORMAT,0,(LPARAM)(sz))
#define DateTime_SetMonthCalColor(hdp,iColor,clr)  SNDMSG(hdp,DTM_SETMCCOLOR,iColor,clr)
#define DateTime_GetMonthCalColor(hdp, iColor)  SNDMSG(hdp,DTM_GETMCCOLOR,iColor,0)
#define DateTime_GetMonthCal(hdp)  (HWND)SNDMSG(hdp,DTM_GETMONTHCAL,0,0)
#if (_WIN32_IE >= 0x0400)
#define DateTime_SetMonthCalFont(hdp,hfont,fRedraw)  SNDMSG(hdp,DTM_SETMCFONT,(WPARAM)(hfont),(LPARAM)(fRedraw))
#define DateTime_GetMonthCalFont(hdp)  SNDMSG(hdp,DTM_GETMCFONT,0,0)
#endif

#ifdef UNICODE
#define DTM_SETFORMAT DTM_SETFORMATW
#define DTN_USERSTRING DTN_USERSTRINGW
#define NMDATETIMESTRING NMDATETIMESTRINGW
#define LPNMDATETIMESTRING LPNMDATETIMESTRINGW
#define DTN_WMKEYDOWN DTN_WMKEYDOWNW
#define NMDATETIMEWMKEYDOWN NMDATETIMEWMKEYDOWNW
#define LPNMDATETIMEWMKEYDOWN LPNMDATETIMEWMKEYDOWNW
#define DTN_FORMAT DTN_FORMATW
#define NMDATETIMEFORMAT NMDATETIMEFORMATW
#define LPNMDATETIMEFORMAT LPNMDATETIMEFORMATW
#define DTN_FORMATQUERY DTN_FORMATQUERYW
#define NMDATETIMEFORMATQUERY NMDATETIMEFORMATQUERYW
#define LPNMDATETIMEFORMATQUERY LPNMDATETIMEFORMATQUERYW
#else
#define DTM_SETFORMAT DTM_SETFORMATA
#define DTN_USERSTRING DTN_USERSTRINGA
#define NMDATETIMESTRING NMDATETIMESTRINGA
#define LPNMDATETIMESTRING LPNMDATETIMESTRINGA
#define DTN_WMKEYDOWN DTN_WMKEYDOWNA
#define NMDATETIMEWMKEYDOWN NMDATETIMEWMKEYDOWNA
#define LPNMDATETIMEWMKEYDOWN LPNMDATETIMEWMKEYDOWNA
#define DTN_FORMAT DTN_FORMATA
#define NMDATETIMEFORMAT NMDATETIMEFORMATA
#define LPNMDATETIMEFORMAT LPNMDATETIMEFORMATA
#define DTN_FORMATQUERY DTN_FORMATQUERYA
#define NMDATETIMEFORMATQUERY NMDATETIMEFORMATQUERYA
#define LPNMDATETIMEFORMATQUERY LPNMDATETIMEFORMATQUERYA
#endif

#endif /* NODATETIMEPICK */

#if (_WIN32_IE >= 0x0400)

/* IP Address edit control **************************************************/

#ifndef NOIPADDRESS

#define WC_IPADDRESSW  L"SysIPAddress32"
#define WC_IPADDRESSA  "SysIPAddress32"

#ifdef UNICODE
#define WC_IPADDRESS  WC_IPADDRESSW
#else
#define WC_IPADDRESS  WC_IPADDRESSA
#endif

#define IPM_CLEARADDRESS  (WM_USER+100)
#define IPM_SETADDRESS  (WM_USER+101)
#define IPM_GETADDRESS  (WM_USER+102)
#define IPM_SETRANGE  (WM_USER+103)
#define IPM_SETFOCUS  (WM_USER+104)
#define IPM_ISBLANK  (WM_USER+105)

#define IPN_FIELDCHANGED  (IPN_FIRST-0)

#define MAKEIPRANGE(low, high)  ((LPARAM)(WORD)(((BYTE)(high)<<8) + (BYTE)(low)))
#define MAKEIPADDRESS(b1,b2,b3,b4)  ((LPARAM)(((DWORD)(b1)<<24)+((DWORD)(b2)<<16)+((DWORD)(b3)<<8)+((DWORD)(b4))))

#define FIRST_IPADDRESS(x)  ((x>>24)&0xFF)
#define SECOND_IPADDRESS(x) ((x>>16)&0xFF)
#define THIRD_IPADDRESS(x)  ((x>>8)&0xFF)
#define FOURTH_IPADDRESS(x) (x&0xFF)

typedef struct tagNMIPADDRESS {
    NMHDR hdr;
    int iField;
    int iValue;
} NMIPADDRESS, *LPNMIPADDRESS;

#endif /* NOIPADDRESS */

/* Pager Control ************************************************************/

#ifndef NOPAGESCROLLER

#define WC_PAGESCROLLERW  L"SysPager"
#define WC_PAGESCROLLERA  "SysPager"

#ifdef UNICODE
#define WC_PAGESCROLLER  WC_PAGESCROLLERW
#else
#define WC_PAGESCROLLER  WC_PAGESCROLLERA
#endif

#define PGS_VERT  0x00000000
#define PGS_HORZ  0x00000001
#define PGS_AUTOSCROLL  0x00000002
#define PGS_DRAGNDROP  0x00000004

#define PGF_INVISIBLE  0
#define PGF_NORMAL  1
#define PGF_GRAYED  2
#define PGF_DEPRESSED  4
#define PGF_HOT  8

#define PGB_TOPORLEFT  0
#define PGB_BOTTOMORRIGHT  1

#define PGF_SCROLLUP  1
#define PGF_SCROLLDOWN  2
#define PGF_SCROLLLEFT  4
#define PGF_SCROLLRIGHT  8

#define PGK_SHIFT  1
#define PGK_CONTROL  2
#define PGK_MENU  4

#define PGF_CALCWIDTH  1
#define PGF_CALCHEIGHT  2

#define PGM_SETCHILD  (PGM_FIRST+1)
#define PGM_RECALCSIZE  (PGM_FIRST+2)
#define PGM_FORWARDMOUSE  (PGM_FIRST+3)
#define PGM_SETBKCOLOR  (PGM_FIRST+4)
#define PGM_GETBKCOLOR  (PGM_FIRST+5)
#define PGM_SETBORDER  (PGM_FIRST+6)
#define PGM_GETBORDER  (PGM_FIRST+7)
#define PGM_SETPOS  (PGM_FIRST+8)
#define PGM_GETPOS  (PGM_FIRST+9)
#define PGM_SETBUTTONSIZE  (PGM_FIRST+10)
#define PGM_GETBUTTONSIZE  (PGM_FIRST+11)
#define PGM_GETBUTTONSTATE  (PGM_FIRST+12)
#define PGM_GETDROPTARGET  CCM_GETDROPTARGET

#define PGN_SCROLL  (PGN_FIRST-1)
#define PGN_CALCSIZE  (PGN_FIRST-2)

#include <pshpack1.h>
typedef struct {
    NMHDR hdr;
    WORD fwKeys;
    RECT rcParent;
    int iDir;
    int iXpos;
    int iYpos;
    int iScroll;
} NMPGSCROLL, *LPNMPGSCROLL;
#include <poppack.h>

typedef struct {
    NMHDR hdr;
    DWORD dwFlag;
    int iWidth;
    int iHeight;
} NMPGCALCSIZE, *LPNMPGCALCSIZE;

#define Pager_SetChild(hwnd,hwndChild)  (void)SNDMSG((hwnd),PGM_SETCHILD,0,(LPARAM)(hwndChild))
#define Pager_RecalcSize(hwnd)  (void)SNDMSG((hwnd),PGM_RECALCSIZE,0,0)
#define Pager_ForwardMouse(hwnd,bForward)  (void)SNDMSG((hwnd),PGM_FORWARDMOUSE,(WPARAM)(bForward),0)
#define Pager_SetBkColor(hwnd,clr)  (COLORREF)SNDMSG((hwnd),PGM_SETBKCOLOR,0,(LPARAM)(clr))
#define Pager_GetBkColor(hwnd)  (COLORREF)SNDMSG((hwnd),PGM_GETBKCOLOR,0,0)
#define Pager_SetBorder(hwnd,iBorder)  (int)SNDMSG((hwnd),PGM_SETBORDER,0,(LPARAM)(iBorder))
#define Pager_GetBorder(hwnd)  (int)SNDMSG((hwnd),PGM_GETBORDER,0,0)
#define Pager_SetPos(hwnd,iPos)  (int)SNDMSG((hwnd),PGM_SETPOS,0,(LPARAM)(iPos))
#define Pager_GetPos(hwnd)  (int)SNDMSG((hwnd),PGM_GETPOS,0,0)
#define Pager_SetButtonSize(hwnd,iSize)  (int)SNDMSG((hwnd),PGM_SETBUTTONSIZE,0,(LPARAM)(iSize))
#define Pager_GetButtonSize(hwnd)  (int)SNDMSG((hwnd),PGM_GETBUTTONSIZE,0,0)
#define Pager_GetButtonState(hwnd,iButton)  (DWORD)SNDMSG((hwnd),PGM_GETBUTTONSTATE,0,(LPARAM)(iButton))
#define Pager_GetDropTarget(hwnd,ppdt)  (void)SNDMSG((hwnd),PGM_GETDROPTARGET,0,(LPARAM)(ppdt))

#endif /* NOPAGESCROLLER */

/* Native Font Control ******************************************************/

#ifndef NONATIVEFONTCTL

#define WC_NATIVEFONTCTLW  L"NativeFontCtl"
#define WC_NATIVEFONTCTLA  "NativeFontCtl"

#ifdef UNICODE
#define WC_NATIVEFONTCTL  WC_NATIVEFONTCTLW
#else
#define WC_NATIVEFONTCTL  WC_NATIVEFONTCTLA
#endif

#define NFS_EDIT  0x0001
#define NFS_STATIC  0x0002
#define NFS_LISTCOMBO  0x0004
#define NFS_BUTTON  0x0008
#define NFS_ALL  0x0010
#define NFS_USEFONTASSOC  0x0020

#endif /* NONATIVEFONTCTL */

/* Button Control ***********************************************************/

#ifndef NOBUTTON

#define WC_BUTTONA  "Button"
#define WC_BUTTONW  L"Button"

#ifdef UNICODE
#define WC_BUTTON  WC_BUTTONW
#else
#define WC_BUTTON  WC_BUTTONA
#endif

#if (_WIN32_WINNT >= 0x501)

#define BUTTON_IMAGELIST_ALIGN_LEFT  0
#define BUTTON_IMAGELIST_ALIGN_RIGHT  1
#define BUTTON_IMAGELIST_ALIGN_TOP  2
#define BUTTON_IMAGELIST_ALIGN_BOTTOM  3
#define BUTTON_IMAGELIST_ALIGN_CENTER  4

#define BCM_GETIDEALSIZE  (BCM_FIRST+0x0001)
#define BCM_SETIMAGELIST  (BCM_FIRST+0x0002)
#define BCM_GETIMAGELIST  (BCM_FIRST+0x0003)
#define BCM_SETTEXTMARGIN  (BCM_FIRST+0x0004)
#define BCM_GETTEXTMARGIN  (BCM_FIRST+0x0005)

#define BCN_HOTITEMCHANGE  (BCN_FIRST+0x0001)

#define BST_HOT  0x0200

typedef struct {
    HIMAGELIST himl;
    RECT margin;
    UINT uAlign;
} BUTTON_IMAGELIST, *PBUTTON_IMAGELIST;

typedef struct tagNMBCHOTITEM {
    NMHDR hdr;
    DWORD dwFlags;
} NMBCHOTITEM, * LPNMBCHOTITEM;

#define Button_GetIdealSize(hwnd,psize)  (BOOL)SNDMSG((hwnd),BCM_GETIDEALSIZE,0,(LPARAM)(psize))
#define Button_SetImageList(hwnd,pbuttonImagelist)  (BOOL)SNDMSG((hwnd),BCM_SETIMAGELIST,0,(LPARAM)(pbuttonImagelist))
#define Button_GetImageList(hwnd,pbuttonImagelist)  (BOOL)SNDMSG((hwnd),BCM_GETIMAGELIST,0,(LPARAM)(pbuttonImagelist))
#define Button_SetTextMargin(hwnd,pmargin)  (BOOL)SNDMSG((hwnd),BCM_SETTEXTMARGIN,0,(LPARAM)(pmargin))
#define Button_GetTextMargin(hwnd,pmargin)  (BOOL)SNDMSG((hwnd),BCM_GETTEXTMARGIN,0,(LPARAM)(pmargin))

#endif /* _WIN32_WINNT >= 0x501 */

#endif /* NOBUTTON */

/* Static Control ***********************************************************/

#ifndef NOSTATIC

#define WC_STATICA  "Static"
#define WC_STATICW  L"Static"

#ifdef UNICODE
#define WC_STATIC  WC_STATICW
#else
#define WC_STATIC  WC_STATICA
#endif

#endif /* NOSTATIC */

/* Edit Control *************************************************************/

#ifndef NOEDIT

#define WC_EDITA  "Edit"
#define WC_EDITW  L"Edit"

#ifdef UNICODE
#define WC_EDIT  WC_EDITW
#else
#define WC_EDIT  WC_EDITA
#endif

#if (_WIN32_WINNT >= 0x501)

#define EM_SETCUEBANNER  (ECM_FIRST+1)
#define EM_GETCUEBANNER  (ECM_FIRST+2)
#define EM_SHOWBALLOONTIP  (ECM_FIRST+3)
#define EM_HIDEBALLOONTIP  (ECM_FIRST+4)

typedef struct _tagEDITBALLOONTIP {
    DWORD cbStruct;
    LPCWSTR pszTitle;
    LPCWSTR pszText;
    INT ttiIcon;
} EDITBALLOONTIP, *PEDITBALLOONTIP;

#define Edit_SetCueBannerText(hwnd,lpcwText)  (BOOL)SNDMSG((hwnd),EM_SETCUEBANNER,0,(LPARAM)(lpcwText))
#define Edit_GetCueBannerText(hwnd,lpwText,cchText)  (BOOL)SNDMSG((hwnd),EM_GETCUEBANNER,(WPARAM)(lpwText),(LPARAM)(cchText))
#define Edit_ShowBalloonTip(hwnd,peditballoontip)  (BOOL)SNDMSG((hwnd),EM_SHOWBALLOONTIP,0,(LPARAM)(peditballoontip))
#define Edit_HideBalloonTip(hwnd)  (BOOL)SNDMSG((hwnd),EM_HIDEBALLOONTIP,0,0)

#endif /* _WIN32_WINNT >= 0x501 */

#endif /* NOEDIT */

/* Listbox Control **********************************************************/

#ifndef NOLISTBOX

#define WC_LISTBOXA  "ListBox"
#define WC_LISTBOXW  L"ListBox"

#ifdef UNICODE
#define WC_LISTBOX  WC_LISTBOXW
#else
#define WC_LISTBOX  WC_LISTBOXA
#endif

#endif /* NOLISTBOX */

/* Combobox Control *********************************************************/

#ifndef NOCOMBOBOX

#define WC_COMBOBOXA  "ComboBox"
#define WC_COMBOBOXW  L"ComboBox"

#ifdef UNICODE
#define WC_COMBOBOX  WC_COMBOBOXW
#else
#define WC_COMBOBOX  WC_COMBOBOXA
#endif

#if (_WIN32_WINNT >= 0x501)

#define CB_SETMINVISIBLE  (CBM_FIRST+1)
#define CB_GETMINVISIBLE  (CBM_FIRST+2)

#define ComboBox_SetMinVisible(hwnd,iMinVisible)  (BOOL)SNDMSG((hwnd),CB_SETMINVISIBLE,(WPARAM)iMinVisible,0)
#define ComboBox_GetMinVisible(hwnd)  (int)SNDMSG((hwnd),CB_GETMINVISIBLE,0,0)

#endif /* _WIN32_WINNT >= 0x501 */

#endif /* NOCOMBOBOX */

/* Scrollbar Control ********************************************************/

#ifndef NOSCROLLBAR

#define WC_SCROLLBARA  "ScrollBar"
#define WC_SCROLLBARW  L"ScrollBar"

#ifdef UNICODE
#define WC_SCROLLBAR  WC_SCROLLBARW
#else
#define WC_SCROLLBAR  WC_SCROLLBARA
#endif

#endif /* NOSCROLLBAR */

/* SysLink Control **********************************************************/

#if (_WIN32_WINNT >= 0x501)

#define INVALID_LINK_INDEX  (-1)
#define MAX_LINKID_TEXT  48
#define L_MAX_URL_LENGTH  (2048 + 32 + sizeof("://"))

#define WC_LINK  L"SysLink"

#define LWS_TRANSPARENT  0x0001
#define LWS_IGNORERETURN  0x0002

#define LIF_ITEMINDEX  0x00000001
#define LIF_STATE  0x00000002
#define LIF_ITEMID  0x00000004
#define LIF_URL  0x00000008

#define LIS_FOCUSED  0x00000001
#define LIS_ENABLED  0x00000002
#define LIS_VISITED  0x00000004

typedef struct tagLITEM {
    UINT mask;
    int iLink;
    UINT state;
    UINT stateMask;
    WCHAR szID[MAX_LINKID_TEXT];
    WCHAR szUrl[L_MAX_URL_LENGTH];
} LITEM, *PLITEM;

typedef struct tagLHITTESTINFO {
    POINT pt;
    LITEM item;
} LHITTESTINFO, *PLHITTESTINFO;

typedef struct tagNMLINK {
    NMHDR hdr;
    LITEM item;
} NMLINK, *PNMLINK;

#define LM_HITTEST  (WM_USER+0x300)
#define LM_GETIDEALHEIGHT  (WM_USER+0x301)
#define LM_SETITEM  (WM_USER+0x302)
#define LM_GETITEM  (WM_USER+0x303)

#define SysLink_HitTest(hwnd,plht)  (BOOL)SNDMSG((hwnd),LM_HITTEST,0,(LPARAM)(PLHITTESTINFO)(plht))
#define SysLink_GetIdealHeight(hwnd)  (int)SNDMSG((hwnd),LM_GETIDEALHEIGHT,0,0)
#define SysLink_SetItem(hwnd,plitem)  (BOOL)SNDMSG((hwnd),LM_SETITEM,0,(LPARAM)(PLITEM)(plitem))
#define SysLink_GetItem(hwnd,plitem)  (BOOL)SNDMSG((hwnd),LM_GETITEM,0,(LPARAM)(PLITEM)(plitem))

#endif /* _WIN32_WINNT >= 0x501 */

/* MUI API ******************************************************************/

#ifndef NOMUI

void WINAPI InitMUILanguage(LANGID);
LANGID WINAPI GetMUILanguage(void);

#endif /* NOMUI */

#endif /* _WIN32_IE >= 0x0400 */

/* Dynamic Pointer Array, Dynamic Structure Array ***************************/

#ifndef _WINCE

#define DA_LAST  (0x7FFFFFFF)
#define DPA_APPEND  (0x7fffffff)
#define DPA_ERR  (-1)

#define DSA_APPEND  (0x7fffffff)
#define DSA_ERR  (-1)

#define DPAS_SORTED  0x0001
#define DPAS_INSERTBEFORE  0x0002
#define DPAS_INSERTAFTER  0x0004

typedef struct _DSA *HDSA;
typedef struct _DPA *HDPA;

typedef int (CALLBACK *PFNDPAENUMCALLBACK)(void*,void*);
typedef int (CALLBACK *PFNDSAENUMCALLBACK)(void*,void*);
typedef int (CALLBACK *PFNDPACOMPARE)(void*,void*,LPARAM);

WINCOMMCTRLAPI HDSA WINAPI DSA_Create(int,int);
WINCOMMCTRLAPI BOOL WINAPI DSA_Destroy(HDSA);
WINCOMMCTRLAPI void WINAPI DSA_DestroyCallback(HDSA,PFNDSAENUMCALLBACK,void*);
WINCOMMCTRLAPI PVOID WINAPI DSA_GetItemPtr(HDSA,int);
WINCOMMCTRLAPI int WINAPI DSA_InsertItem(HDSA,int,void*);

WINCOMMCTRLAPI HDPA WINAPI DPA_Create(int);
WINCOMMCTRLAPI BOOL WINAPI DPA_Destroy(HDPA);
WINCOMMCTRLAPI PVOID WINAPI DPA_DeletePtr(HDPA,int);
WINCOMMCTRLAPI BOOL WINAPI DPA_DeleteAllPtrs(HDPA);
WINCOMMCTRLAPI void WINAPI DPA_EnumCallback(HDPA,PFNDPAENUMCALLBACK,void*);
WINCOMMCTRLAPI void WINAPI DPA_DestroyCallback(HDPA,PFNDPAENUMCALLBACK,void*);
WINCOMMCTRLAPI BOOL WINAPI DPA_SetPtr(HDPA,int,void*);
WINCOMMCTRLAPI int WINAPI DPA_InsertPtr(HDPA,int,void*);
WINCOMMCTRLAPI PVOID WINAPI DPA_GetPtr(HDPA,INT_PTR);
WINCOMMCTRLAPI BOOL WINAPI DPA_Sort(HDPA,PFNDPACOMPARE,LPARAM);
WINCOMMCTRLAPI int WINAPI DPA_Search(HDPA,void*,int,PFNDPACOMPARE,LPARAM,UINT);
WINCOMMCTRLAPI BOOL WINAPI Str_SetPtrW(LPWSTR*,LPCWSTR);

#endif /* _WINCE */

/* TrackMouseEvent **********************************************************/

#ifndef NOTRACKMOUSEEVENT

#ifndef WM_MOUSEHOVER
#define WM_MOUSEHOVER  0x02A1
#define WM_MOUSELEAVE  0x02A3
#endif

#ifndef TME_HOVER

#define TME_HOVER  0x00000001
#define TME_LEAVE  0x00000002
#if (WINVER >= 0x0500)
#define TME_NONCLIENT  0x00000010
#endif
#define TME_QUERY  0x40000000
#define TME_CANCEL  0x80000000

#define HOVER_DEFAULT  0xFFFFFFFF

typedef struct tagTRACKMOUSEEVENT {
    DWORD cbSize;
    DWORD dwFlags;
    HWND hwndTrack;
    DWORD dwHoverTime;
} TRACKMOUSEEVENT, *LPTRACKMOUSEEVENT;

#endif /* TME_HOVER */

WINCOMMCTRLAPI BOOL WINAPI _TrackMouseEvent(LPTRACKMOUSEEVENT);

#endif /* NOTRACKMOUSEEVENT */

#if (_WIN32_IE >= 0x0400)

/* Flat scrollbar API *******************************************************/

#ifndef NOFLATSBAPIS

#define WSB_PROP_CYVSCROLL  0x00000001L
#define WSB_PROP_CXHSCROLL  0x00000002L
#define WSB_PROP_CYHSCROLL  0x00000004L
#define WSB_PROP_CXVSCROLL  0x00000008L
#define WSB_PROP_CXHTHUMB  0x00000010L
#define WSB_PROP_CYVTHUMB  0x00000020L
#define WSB_PROP_VBKGCOLOR  0x00000040L
#define WSB_PROP_HBKGCOLOR  0x00000080L
#define WSB_PROP_VSTYLE  0x00000100L
#define WSB_PROP_HSTYLE  0x00000200L
#define WSB_PROP_WINSTYLE  0x00000400L
#define WSB_PROP_PALETTE  0x00000800L
#define WSB_PROP_MASK  0x00000FFFL

#define FSB_FLAT_MODE  2
#define FSB_ENCARTA_MODE  1
#define FSB_REGULAR_MODE  0

WINCOMMCTRLAPI BOOL WINAPI FlatSB_EnableScrollBar(HWND,int,UINT);
WINCOMMCTRLAPI BOOL WINAPI FlatSB_ShowScrollBar(HWND,int,BOOL);
WINCOMMCTRLAPI BOOL WINAPI FlatSB_GetScrollRange(HWND,int,LPINT,LPINT);
WINCOMMCTRLAPI BOOL WINAPI FlatSB_GetScrollInfo(HWND,int,LPSCROLLINFO);
WINCOMMCTRLAPI int WINAPI FlatSB_GetScrollPos(HWND,int);
WINCOMMCTRLAPI BOOL WINAPI FlatSB_GetScrollProp(HWND,int,LPINT);
WINCOMMCTRLAPI int WINAPI FlatSB_SetScrollPos(HWND,int,int,BOOL);
WINCOMMCTRLAPI int WINAPI FlatSB_SetScrollInfo(HWND,int,LPSCROLLINFO,BOOL);
WINCOMMCTRLAPI int WINAPI FlatSB_SetScrollRange(HWND,int,int,int,BOOL);
WINCOMMCTRLAPI BOOL WINAPI FlatSB_SetScrollProp(HWND,UINT,INT_PTR,BOOL);
WINCOMMCTRLAPI BOOL WINAPI InitializeFlatSB(HWND);
WINCOMMCTRLAPI HRESULT WINAPI UninitializeFlatSB(HWND);
#ifdef _WIN64
WINCOMMCTRLAPI BOOL WINAPI FlatSB_GetScrollPropPtr(HWND,int,PINT_PTR);
#else
#define FlatSB_GetScrollPropPtr  FlatSB_GetScrollProp
#endif

#define FlatSB_SetScrollPropPtr FlatSB_SetScrollProp

#endif /* NOFLATSBAPIS */
#endif /* _WIN32_IE >= 0x0400 */

#if (_WIN32_WINNT >= 0x501)

/* Subclassing **************************************************************/

typedef LRESULT (CALLBACK *SUBCLASSPROC)(HWND,UINT,WPARAM,LPARAM,UINT_PTR,DWORD_PTR);
BOOL WINAPI SetWindowSubclass(HWND,SUBCLASSPROC,UINT_PTR,DWORD_PTR);
BOOL WINAPI GetWindowSubclass(HWND,SUBCLASSPROC,UINT_PTR,DWORD_PTR*);
BOOL WINAPI RemoveWindowSubclass(HWND,SUBCLASSPROC,UINT_PTR);
LRESULT WINAPI DefSubclassProc(HWND,UINT,WPARAM,LPARAM);

/* Misc *********************************************************************/

int WINAPI DrawShadowText(HDC,LPCWSTR,UINT,RECT*,DWORD,COLORREF,COLORREF,int,int);

#endif /* _WIN32_WINNT >= 0x501 */

/* Pocket PC special controls ***********************************************/

#ifdef _WINCE

#define WC_CAPEDIT  L"CAPEDIT"
#define WC_TSTATIC  L"TTSTATIC"
#define WC_TBUTTON  L"TTBUTTON"
#define WC_SBEDIT  L"edit"

#endif /* _WINCE */

#if __POCC__ >= 290
#pragma warn(pop)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _COMMCTRL_H */