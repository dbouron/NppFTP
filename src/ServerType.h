/*
    NppFTP: FTP/SFTP functionality for Notepad++
    Copyright (C) 2016  Dimitri Bouron (bouron.d@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SERVERTYPE_H
#define SERVERTYPE_H

#include <vector>
#include <string>
#include <map>
#include <cwchar>

#include <winnt.h>


enum ServerType
  {
    AUTO,
    UNIX,
    DOS,
    MVS
  };

struct ServerTypeTraits {
  char separators;
  char enclosure;
  bool hasRoot;
};

const std::vector<struct ServerTypeTraits> serverTraits =
{
    { '/', 0, true },       // Default
    { '/', 0, true },       // Unix
    { '/', 0, false },      // DOS
    { '.', '\'', false }    // MVS
};

const std::map<ServerType, const wchar_t*> serverNames =
{
  { AUTO, TEXT("Default (Autodetect)") },
  { UNIX, TEXT("Unix, GNU/Linux") },
  { DOS, TEXT("DOS") },
  { MVS, TEXT("MVS, OS/390, z/OS") }
};

#endif /* !SERVERTYPE_H */
