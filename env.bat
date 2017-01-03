set MySQLConnectorCPath=K:\Program Files (x86)\MySQL\MySQL Connector C 6.1
set MySQLConnectorCIncludePath=%MySQLConnectorCPath%\include
set MySQLConnectorCLibraryPath=%MySQLConnectorCPath%\lib;%MySQLConnectorCPath%\lib\vs12
set MSBuild=C:\Program Files (x86)\MSBuild\12.0\Bin\MSBuild.exe
set PlatformToolset=v120
set VisualStudioVersion=12.0
set ToolsVersion=%VisualStudioVersion%

set ProjectName=bnfs
set TargetName=bnfs

set WorkingDir=%cd%
set SourceDir=%WorkingDir%\src
set AdditionalIncludeDirectories=%SourceDir%;%SourceDir%\sampgdk;%SourceDir%\sampgdk\amx;%MySQLConnectorCIncludePath%
set AdditionalLibraryDirectories=%MySQLConnectorCLibraryPath%
set AdditionalDependencies=libmysql.lib;mysqlclient.lib
set PreprocessorDefinitions=WIN32;_WINDOWS;_DEBUG;HAVE_INTTYPES_H;HAVE_MALLOC_H;HAVE_STDINT_H;SAMPGDK_AMALGAMATION