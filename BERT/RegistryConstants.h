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

#ifndef __REGISTRY_CONSTANTS_H
#define __REGISTRY_CONSTANTS_H

#define REGISTRY_KEY					"Software\\BERT"
#define REGISTRY_VALUE_ENVIRONMENT		"Environment"
#define REGISTRY_VALUE_R_USER			"R_USER"
#define REGISTRY_VALUE_R_HOME			"R_HOME"
#define REGISTRY_VALUE_STARTUP			"StartupFile"
#define REGISTRY_VALUE_HIDE_MENU		"HideMenu"

#define REGISTRY_VALUE_CONSOLE_FONT		"ConsoleFont"
#define REGISTRY_VALUE_CONSOLE_SIZE		"ConsoleFontSize"
#define REGISTRY_VALUE_CONSOLE_USER		"ConsoleUserTextColor"
#define REGISTRY_VALUE_CONSOLE_MESSAGE	"ConsoleMessageTextColor"
#define REGISTRY_VALUE_CONSOLE_BACK		"ConsoleBackgroundColor"

#define REGISTRY_VALUE_CONSOLE_WIDTH		"ConsoleWidth"
#define REGISTRY_VALUE_CONSOLE_AUTO_WIDTH	"ConsoleAutoWidth"

#define DEFAULT_ENVIRONMENT				""
#define DEFAULT_R_USER					"%APPDATA%\\BERT"
#define DEFAULT_R_HOME					"%APPDATA%\\BERT\\R-3.1.1"
#define DEFAULT_R_STARTUP				"Functions.R"

#define DEFAULT_CONSOLE_WIDTH			80
#define DEFAULT_CONSOLE_AUTO_WIDTH		1

#endif // #ifndef __REGISTRY_CONSTANTS_H


