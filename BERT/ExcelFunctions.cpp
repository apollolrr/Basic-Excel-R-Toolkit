/*
 * Basic Excel R Toolkit (BERT)
 * Copyright (C) 2014 Structured Data, LLC
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "stdafx.h"
#include "BERT.h"
#include "RInterface.h"

BOOL WINAPI xlAutoOpen(void)
{
	XLOPER12 xlName;
	if (!Excel12(xlGetName, &xlName, 0))
	{
		int i, len = xlName.val.str[0];
		for (i = 0; i < len; i++) dllpath += ( xlName.val.str[i + 1] & 0xff );
		Excel12(xlFree, 0, 1, &xlName);
	}

	SysInit();

	return true;

}

void WINAPI xlAutoFree12(LPXLOPER12 pxFree)
{
	if (pxFree->xltype == (xltypeMulti | xlbitDLLFree))
	{
		// NOTE: ALWAYS NEW ARRAYS (wait, what about multidim? CHECKME FIXME TODO)
		delete[] pxFree->val.array.lparray;
	}
	else if (pxFree->xltype == (xltypeStr | xlbitDLLFree))
	{
		// NOTE: ALWAYS NEW XCHAR[] FOR STRINGS
		delete[] pxFree->val.str;
	}
	else
	{
		// ?? 
	}
}

BOOL WINAPI xlAutoClose(void)
{
	SysCleanup();
	return true;
}

LPXLOPER12 WINAPI xlAddInManagerInfo12(LPXLOPER12 xAction)
{
	static XLOPER12 xInfo, xIntAction;
	static XCHAR szAddInStr[128] = L" Basic Excel R Toolkit (Internal)";

	XLOPER12 xlInt;
	xlInt.xltype = xltypeInt;
	xlInt.val.w = xltypeInt; // ??

	Excel12(xlCoerce, &xIntAction, 2, xAction, &xlInt);

	if (xIntAction.val.w == 1)
	{
		xInfo.xltype = xltypeStr;
		szAddInStr[0] = (XCHAR)(wcslen(szAddInStr + 1));
		xInfo.val.str = szAddInStr;
	}
	else
	{
		xInfo.xltype = xltypeErr;
		xInfo.val.err = xlerrValue;
	}

	return (LPXLOPER12)&xInfo;
}


