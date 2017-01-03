@echo off
if not defined TargetName call env
echo copying plugin
if not exist "buildvs\out\%TargetName%.dll" echo no build file found && goto skip
if not exist "samp03" echo no samp server dir found && goto skip
if not exist "samp03\plugins" mkdir "samp03\plugins"
if exist "samp03\plugins\%TargetName%.dll" del "samp03\plugins\%TargetName%.dll"
copy "buildvs\out\%TargetName%.dll" "samp03\plugins"
:skip
if [%~1] NEQ [] (echo.>nul) ELSE pause