@ECHO OFF

CD %~dp0
PUSHD %CD%
CD ..
SET project_dir=%CD%
POPD

IF NOT EXIST "%project_dir%\Build" (MD "%project_dir%\Build")

SET common_compiler_flags=/MTd /nologo /Od /W4 /Z7 /wd4100 /wd4101 /wd4189 /wd4201 /I"%project_dir%\Source\Backend\Include"
SET common_linker_flags=/DEBUG:FASTLINK /INCREMENTAL:NO /OPT:REF

PUSHD "%project_dir%\Build"
IF %ERRORLEVEL% == 0 (CL /LD %common_compiler_flags% "%project_dir%\Source\Backend\Include\Library\platform.c" /link /EXPORT:PlatformFormatString /EXPORT:PlatformWriteConsole %common_linker_flags%)
IF %ERRORLEVEL% == 0 (CL %common_compiler_flags% "%project_dir%\Source\Backend\windows_http_server.c" /link %common_linker_flags% "platform.lib" "ws2_32.lib")
IF %ERRORLEVEL% == 0 (CL %common_compiler_flags% "%project_dir%\Source\Backend\windows_backend.c" /link %common_linker_flags% "platform.lib")
POPD