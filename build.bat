@echo off
call env
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