@echo off
color 18
call env
set AdditionalIncludeDirectories=%SourceDir%;%SourceDir%\sampgdk;%SourceDir%\sampgdk\amx;%MySQLConnectorCIncludePath%
set AdditionalLibraryDirectories=%MySQLConnectorCLibraryPath%
set AdditionalDependencies=libmysql.lib;mysqlclient.lib
set PreprocessorDefinitions=WIN32;_WINDOWS;_DEBUG;HAVE_INTTYPES_H;HAVE_MALLOC_H;HAVE_STDINT_H;SAMPGDK_AMALGAMATION;MMPG_VERSION=%version%;MAX_PLAYERS_OVERRIDE=%MAX_PLAYERS%
if not exist "%SourceDir%\db.h" goto nodbfile
:b
"%MSBuild%" buildvs/%ProjectName%.vcxproj /p:Configuration=Debug /p:VisualStudioVersion=%VisualStudioVersion%
cd >nul
call copyplugin "nopause"
pause
cls
goto b
:nodbfile
echo copy the file db.sample.h to db.h and change the database settings before attempting to build
pause