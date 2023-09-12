@ECHO OFF

REM --> Save Environment
    SET _PATH=%PATH%
    SET _INCLUDE=%INCLUDE%
    SET _LIB=%LIB%

REM --> Set Environment
    IF "%PROG_PATH%"=="" SET PROG_PATH=%ProgramFiles%

    SET INCLUDE=
    SET LIB=

    IF EXIST xbuild.ini         DEL xBuild.ini > NUL:
    IF EXIST xbuild.windows.ini DEL xBuild.Windows.ini > NUL:
    SET OLD_PATH=%PATH%
    IF "%XBUILD_XCC%"=="YES" CALL .\xbldfull-XCC.bat
	SET PATH=%OLD_PATH%
	SET OLD_PATH=%PATH%
    IF "%XBUILD_VC8%"=="YES" CALL .\xbldfull-VC8.bat
	SET PATH=%OLD_PATH%
    SET OLD_PATH=%PATH%
    IF "%XBUILD_VC2022%"=="YES" CALL .\xbldfull-VC2022.bat
	SET PATH=%OLD_PATH%

REM --> Cleanup for -ALL
    IF "%1"=="-all" GOTO CLEAN_ALL
    IF "%1"=="-All" GOTO CLEAN_ALL
    IF "%1"=="-ALL" GOTO CLEAN_ALL

    GOTO AFTER_CLEAN_ALL

    :CLEAN_ALL

	 IF "%XCC_XCC%"=="NO" (
	    ATTRIB +R \xHB\Bin\xCC.exe
            ATTRIB +R \xHB\Bin\xCC.dll
	    ATTRIB +R \xHB\Bin\xLib.exe
	    ATTRIB +R \xHB\Bin\xLink.exe
	    ATTRIB +R \xHB\Bin\xRC.exe
            ATTRIB +R \xHB\Bin\xRC.dll
	 )
	 
	 IF "%XCC_XBUILD%"=="NO" (
	    ATTRIB +R \xHB\Bin\xBuild.exe
	    )
    
    IF "%XBUILD_XCC%"=="YES" (
       DEL \xHB\bin\*.exe /s
       DEL \xHB\bin\*.map /s
       DEL \xHB\bin\*.exp /s
       DEL \xHB\bin\*.dll /s
       RD  \xHB\bin\Demo /s /q
       RD  \xHB\bin\Personal /s /q
       RD  \xHB\bin\Professional /s /q
       DEL \xHB\dll\*.dll /s
       RD  \xHB\dll\Ads /s /q
       RD  \xHB\dll\ApolloRDD /s /q
       RD  \xHB\dll\SQLRDD /s /q
       DEL \xHB\lib\*.lib /s
       )
    
    IF "%XBUILD_VC8%"=="YES" (
       RD \xHB\bin\vc8 /s /q
       MD \xHB\bin\vc8
       RD \xHB\dll\vc8 /s /q
       RD \xHB\lib\vc8 /s /q
       MD \xHB\dll\vc8
       MD \xHB\lib\vc8
      )

    IF "%XBUILD_VC2022%"=="YES" (
       RD \xHB\bin\vc2022 /s /q
       MD \xHB\bin\vc2022
       RD \xHB\dll\vc2022 /s /q
       RD \xHB\lib\vc2022 /s /q
       MD \xHB\dll\vc2022
       MD \xHB\lib\vc2022
      )
		
	IF "%XCC_XBUILD%"=="NO" (
	    ATTRIB -R \xHB\Bin\xBuild.exe
	    )
		
	 IF "%XCC_XCC%"=="NO" (
	   ATTRIB -R \xHB\Bin\xCC.exe
           ATTRIB -R \xHB\Bin\xCC.dll
	   ATTRIB -R \xHB\Bin\xLib.exe
	   ATTRIB -R \xHB\Bin\xLink.exe
	   ATTRIB -R \xHB\Bin\xRC.exe
           ATTRIB -R \xHB\Bin\xRC.dll
         ) ELSE ( 
      DEL ..\..\bin\xCC.*
      DEL ..\..\bin\xRC.*
      DEL ..\..\bin\xLib.exe
      DEL ..\..\bin\xLink.exe
	 )

    IF EXIST ..\..\bin\xHB.exe DEL ..\..\bin\xHB.exe

    IF EXIST \xHB\include    RD \xHB\include /s /q
    IF EXIST ..\..\c_include RD ..\..\c_include /s /q
    IF EXIST ..\..\c_lib     RD ..\..\c_lib /s /q

    REM We will use only \xharbour\lib\vc or bc5 so make sure that's the case
    REM when done using make_vc all or make_b32 all will quickly copy them back!
    DEL ..\..\lib\*.lib
	 COPY ..\..\lib\vc\xharbour.lib ..\..\lib\vc\harbour.lib
    COPY ..\..\lib\vc\*.lib ..\..\lib\*.lib
	

    REM Clean up XBP
    RD \xbp /S /Q

    :AFTER_CLEAN_ALL



REM --> Copy files

   IF "%XBUILD_VC8%"=="YES" (
      MD \xHB\bin\vc8
      MD \xHB\dll\vc8
      MD \xHB\lib\vc8
   )

   IF "%XBUILD_VC2022%"=="YES" (
      IF NOT EXIST "\xHB\bin\vc2022" MD \xHB\bin\vc2022
      IF NOT EXIST "\xHB\dll\vc2022" MD \xHB\dll\vc2022
      IF NOT EXIST "\xHB\lib\vc2022" MD \xHB\lib\vc2022
   )   

   IF NOT EXIST "\xHB\bin"         MD "\xHB\bin"
   IF NOT EXIST "\xHB\lib"         MD "\xHB\lib"
   IF NOT EXIST "\xHB\dll"         MD "\xHB\dll"
   IF NOT EXIST "\xHB\include\w32" MD "\xHB\include\w32"

    REM ** SQLRDD **
    IF NOT EXIST \xHB\dll\SQLRDD MD \xHB\dll\SQLRDD
    XCOPY ..\xHarbour-SQLRDD\dll\*.dll      \xHB\dll\SQLRDD /d /y
    XCOPY ..\xHarbour-SQLRDD\lib\*.lib      \xHB\lib /d /y

   IF "%XBUILD_VC8%"=="YES" (	
	XCOPY ..\xHarbour-SQLRDD\lib\*.lib      \xHB\lib\vc8 /d /y 
   )
   IF "%XBUILD_VC2022%"=="YES" (	
	XCOPY ..\xHarbour-SQLRDD\lib\*.lib      \xHB\lib\vc2022 /d /y 
   )
   
    XCOPY ..\xHarbour-SQLRDD\include        \xHB\include /d /y /i
    XCOPY ..\xHarbour-SQLRDD\source\*.ch    \xHB\include /d /y
    XCOPY ..\xHarbour-SQLRDD\source\mysql.h \xHB\include /d /y
    IF EXIST \xHB\include\sqlrdd.xns DEL \xHB\include\sqlrdd.xns
    COPY ..\xHarbour-SQLRDD\dll\fbclient.dll \xHB\bin /Y
    COPY ..\xHarbour-SQLRDD\dll\libmysql.dll \xHB\bin /Y


    REM ** ADS **
    REM HB_DIR_ADS is the ONE place ace32.dll SHOULD be in.
    IF NOT EXIST \xHB\dll\ADS MD \xHB\dll\ADS
    XCOPY ".\xHarbour-ADS\Ace32.dll"           \xHB\dll\ADS /d /y
    XCOPY ".\xHarbour-ADS\Ace32.dll"           \xHB\Bin\    /d /y
    XCOPY ".\xHarbour-ADS\AdsLoc32.dll"        \xHB\dll\ADS /d /y
    XCOPY ".\xHarbour-ADS\AXCws32.dll"         \xHB\dll\ADS /d /y
    XCOPY ".\xHarbour-ADS\Ansi.chr"            \xHB\dll\ADS /d /y
    XCOPY ".\xHarbour-ADS\Extend.chr"          \xHB\dll\ADS /d /y
    XCOPY ".\xHarbour-ADS\AdsLocal.cfg"        \xHB\dll\ADS /d /y
    XCOPY ".\Visual-xHarbour\Library\include\ACE.h"    \xHB\include\w32 /d /y
    XCOPY ..\..\contrib\rdd_ads\rddads.h \xHB\include\w32 /d /y
    XCOPY ..\..\contrib\rdd_ads\ads*.ch  \xHB\include /d /y


    REM ** FreeImage **
    IF "%XBUILD_VC8%"=="YES" (
       IF NOT EXIST \xHB\lib\vc8 MD \xHB\lib\vc8
       XCOPY ..\..\xHarbourBuilder\FreeImage\FreeImage.lib \xHB\lib\vc8  /d /y /i
    )
    IF "%XBUILD_VC2022%"=="YES" (
       IF NOT EXIST \xHB\lib\vc2022 MD \xHB\lib\vc2022
       XCOPY ..\..\xHarbourBuilder\FreeImage\FreeImage.lib \xHB\lib\vc2022  /d /y /i
    )
    XCOPY ..\FreeImage\FreeImage.lib    \xHB\lib\     /d /y /i
    XCOPY ..\FreeImage\FreeImage.dll    \xHB\dll\     /d /y /i
    XCOPY ..\FreeImage\FreeImage.dll    \xHB\bin\     /d /y /i
    XCOPY ..\..\contrib\FreeImage\include\*.ch \xHB\include\ /d /y /i
    XCOPY ..\..\contrib\FreeImage\include\*.h  \xHB\include\ /d /y /i


    REM ** ApolloRDD **
    IF "%_BUILD_APOLLORDD%"=="YES" (
       IF NOT EXIST \xHB\dll\ApolloRDD MD \xHB\dll\ApolloRDD
       XCOPY ..\xHarbour-ApolloRDD\dll\*.dll \xHB\dll\ApolloRDD /d /y /i
       XCOPY ..\xHarbour-ApolloRDD\*.h  \xHB\include /d /y /i
       XCOPY ..\xHarbour-ApolloRDD\*.ch \xHB\include /d /y /i
    )

    REM ** BGD.DLL **
    IF "%_BUILD_BGD%"=="YES" (
       XCOPY ..\xHarbour-Builder\BGD.DLL \xHB\dll  /d /y /i
    )

    XCOPY ..\..\include\*.api                       \xHB\include /d /y /i
    XCOPY ..\..\include\*.ch                        \xHB\include /d /y /i
    XCOPY ..\..\include\*.h                         \xHB\include /d /y /i
    XCOPY ..\..\include\*.c                         \xHB\include /d /y /i

    XCOPY ..\..\source\rtl\pcre\*.h                 \xHB\include /d /y /i
    XCOPY ..\..\source\rtl\pcre\*.generic           \xHB\include /d /y /i
    XCOPY ..\..\include\hbverbld.h                  \xHB\include /d /y /i
    XCOPY ..\..\contrib\gd\include                  \xHB\include /d /y /i

    XCOPY ..\xHarbour-Builder\include        \xHB\include /d /y /i
    XCOPY ..\xHarbour-ActiveX\ole.ch         \xHB\include\w32 /d /y
    XCOPY ..\xHarbour-Builder\xcc*.lib       ..\xHarbour-XCC\xcc\xcc*.lib /d /y /i
 
    REM ** VXH **
    XCOPY ..\Visual-xHarbour\library\include \xHB\include\w32 /y /i
    IF EXIST \xHB\Include\w32\Oleserver.h      DEL \xHB\Include\w32\Oleserver.h
    IF EXIST \xHB\Include\w32\Structures_HB.ch DEL \xHB\Include\w32\Structures_HB.ch
    IF EXIST \xHB\Include\w32\Globals.ch       DEL \xHB\Include\w32\Globals.ch
    XCOPY ..\Visual-xHarbour\Extras \xHB\Bin /d /y /i

    IF "%_BUILD_IEGUI_LIB%"=="YES" XCOPY ..\IEGui\iegui.ch \xHB\include /d /y

    IF EXIST ..\..\include\Ado.ch      DEL ..\..\include\Ado.ch
    IF EXIST ..\..\include\Colors.ch   DEL ..\..\include\Colors.ch
    IF EXIST ..\..\include\CommCtrl.ch DEL ..\..\include\CommCtrl.ch
    IF EXIST ..\..\include\CommDlg.ch  DEL ..\..\include\CommDlg.ch
    IF EXIST ..\..\include\Debug.ch.ch DEL ..\..\include\Debug.ch.ch
    IF EXIST ..\..\include\Import.ch   DEL ..\..\include\Import.ch
    IF EXIST ..\..\include\Ole.ch      DEL ..\..\include\Ole.ch
    IF EXIST ..\..\include\RichEdit.ch DEL ..\..\include\RichEdit.ch
    IF EXIST ..\..\include\SQLTypes.ch DEL ..\..\include\SQLTypes.ch
    IF EXIST ..\..\include\VXH.ch      DEL ..\..\include\VXH.ch
    IF EXIST ..\..\include\What32.ch   DEL ..\..\include\What32.ch
    IF EXIST ..\..\include\WinApi.ch   DEL ..\..\include\WinApi.ch
    IF EXIST ..\..\include\WinGDI.ch   DEL ..\..\include\WinGDI.ch
    IF EXIST ..\..\include\WinInet.ch  DEL ..\..\include\WinInet.ch
    IF EXIST ..\..\include\WinReg.ch   DEL ..\..\include\WinReg.ch
    IF EXIST ..\..\include\WinStruc.ch DEL ..\..\include\WinStruc.ch
    IF EXIST ..\..\include\WinUser.ch  DEL ..\..\include\WinUser.ch

    IF EXIST \xHB\include\Ado.ch           DEL \xHB\include\Ado.ch
    IF EXIST \xHB\include\Colors.ch        DEL \xHB\include\Colors.ch
    IF EXIST \xHB\include\CommCtrl.ch      DEL \xHB\include\CommCtrl.ch
    IF EXIST \xHB\include\CommDlg.ch       DEL \xHB\include\CommDlg.ch
    IF EXIST \xHB\include\Debug.ch.ch      DEL \xHB\include\Debug.ch.ch
    IF EXIST \xHB\include\Import.ch        DEL \xHB\include\Import.ch
    IF EXIST \xHB\include\Ole.ch           DEL \xHB\include\Ole.ch
    IF EXIST \xHB\include\RichEdit.ch      DEL \xHB\include\RichEdit.ch
    IF EXIST \xHB\include\SQLTypes.ch      DEL \xHB\include\SQLTypes.ch
    IF EXIST \xHB\include\VXH.ch           DEL \xHB\include\VXH.ch
    IF EXIST \xHB\include\What32.ch        DEL \xHB\include\What32.ch
    IF EXIST \xHB\include\WinApi.ch        DEL \xHB\include\WinApi.ch
    IF EXIST \xHB\include\WinGDI.ch        DEL \xHB\include\WinGDI.ch
    IF EXIST \xHB\include\WinInet.ch       DEL \xHB\include\WinInet.ch
    IF EXIST \xHB\include\WinReg.ch        DEL \xHB\include\WinReg.ch
    IF EXIST \xHB\include\WinStruc.ch      DEL \xHB\include\WinStruc.ch
    IF EXIST \xHB\include\WinUser.ch       DEL \xHB\include\WinUser.ch
    IF EXIST \xHB\include\W32\WinTypes.ch  DEL \xHB\include\W32\WinTypes.ch


REM  ===============================================
REM  ===============================================
REM  ===============================================
REM  ===============================================


IF "%XBUILD_XCC%"=="YES"    CALL .\xbldfull2.bat %1
IF "%XBUILD_VC8%"=="YES"    CALL .\xbldfull2.bat %1
IF "%XBUILD_VC2022%"=="YES" CALL .\xbldfull2.bat %1

REM  ===============================================
REM  ===============================================
REM  ===============================================
REM  ===============================================


REM  ===============================================
ECHO Restore Environment
REM  ===============================================
    SET PATH=%_PATH%
    SET INCLUDE=%_INCLUDE%
    SET LIB=%_LIB%

    SET _PATH=
    SET _INCLUDE=
    SET _LIB=

    SET _XB_NonDebug=
    SET _XB_Debug=
    SET _XB_Exe=

    SET _XB_Compiler=

    SET _XHB_LIB=
    SET _XHB_DLL=

    SET VC8_MT=
    SET VC8_DEMO=
    SET VC8_PERSONAL=
    SET VC8_PROF=
    SET VC8_XHB_EXE=
    SET VC8_XHB_LIB=
    SET VC8_XHB_DLL=
    SET VC8_CORELIBS=
    SET VC8_CONTRIB=
    SET VC8_DMAIN_LIB=
    SET VC8_VXHDLL=
    SET VC8_XBUILDW_AS=
    SET VC8_VXH_AS=
    SET VC8_XEDITW_AS=
    SET VC8_XDEBUGW_AS=
    SET VC8_XPROMPT_AS=
    SET VC8_DEBUG=

    SET VC2022_MT=
    SET VC2022_DEMO=
    SET VC2022_PERSONAL=
    SET VC2022_PROF=
    SET VC2022_XHB_EXE=
    SET VC2022_XHB_LIB=
    SET VC2022_XHB_DLL=
    SET VC2022_CORELIBS=
    SET VC2022_CONTRIB=
    SET VC2022_DMAIN_LIB=
    SET VC2022_VXHDLL=
    SET VC2022_XBUILDW_AS=
    SET VC2022_VXH_AS=
    SET VC2022_XEDITW_AS=
    SET VC2022_XDEBUGW_AS=
    SET VC2022_XPROMPT_AS=
    SET VC2022_DEBUG=

    SET XCC_MT=
    SET XCC_DEMO=
    SET XCC_PERSONAL=
    SET XCC_PROF=
    SET XCC_XHB_EXE=
    SET XCC_XHB_LIB=
    SET XCC_XHB_DLL=
    SET XCC_CORELIBS=
    SET XCC_CONTRIB=
    SET XCC_DMAIN_LIB=
    SET XCC_VXHDLL=
    SET XCC_XBUILDW_AS=
    SET XCC_VXH_AS=
    SET XCC_XEDITW_AS=
    SET XCC_XDEBUGW_AS=
    SET XCC_XPROMPT_AS=
    SET XCC_DEBUG=

    SET _BUILD_MT=
    SET _BUILD_DEMO=
    SET _BUILD_PERSONAL=
    SET _BUILD_PROF=
    SET _BUILD_XHB_EXE=
    SET _BUILD_XHB_LIB=
    SET _BUILD_XHB_DLL=
    SET _BUILD_CORE=
    SET _BUILD_CONTRIB=
    SET _BUILD_DMAIN_LIB=
    SET _BUILD_VXHDLL=
    SET _BUILD_XBUILDW_AS=
    SET _BUILD_VXH_AS=
    SET _BUILD_XEDITW_AS=
    SET _BUILD_XDEBUGW_AS=
    SET _BUILD_XPROMPT_AS=

    SET _BUILD_ACTIVEX=
    SET _BUILD_ADS=
    SET _BUILD_APOLLORDD=
    SET _BUILD_CT3COMM=
    SET _BUILD_DBG_CLIENT=
    SET _BUILD_HBZLIB=
    SET _BUILD_OLE=
    SET _BUILD_RMDBFCDX=
    SET _BUILD_SQLRDD=
    SET _BUILD_BMDBFCDX=
    SET _BUILD_REDEBFCD=
    SET _BUILD_TPROJECT_LIB=
    SET _BUILD_WINAPI_LIB=
    SET _BUILD_WINCORE=
    SET _BUILD_XBSCRIPT_LIB=
    SET _BUILD_XBUILD=
    SET _BUILD_XDO_DLL=
    SET _BUILD_XEDIT_LIB=
    SET _BUILD_XHBCOMM=

    SET _XB_Exe=

    CD ..

:Done1

