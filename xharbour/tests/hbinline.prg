/*
 * $Id: hbinline.prg,v 1.2 2007/01/09 14:10:22 druzus Exp $
 */

/*
 * Harbour Project source code:
 *    new Hb_inLine {} test
 *
 * Copyright 2006 Przemyslaw Czerpak <druzus / at / priv.onet.pl>
 * www - http://www.harbour-project.org
 *
 */

proc main()
local hb_inLine := " (var) "

? hb_inLine { hb_retc("inLine"); } + hb_inLine(" parameter ") {
     hb_retc( hb_parc( 1 ) );
     } + "!" + hb_inLine + hb_inLine() { hb_retc( ":-)" ); } + ;
  hb_inLine() + "{}"

return

function hb_inLine()
return " func() "