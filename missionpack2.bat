@echo off
setlocal

set "oldcd=%cd%"

:: Navigate to the directory containing this script, then up one level
cd /d "%~dp0"
cd ..

:: List of popular Quake 3 client executables in order of priority
for %%E in (
    quake3e.x64.exe
    quake3e-vulkan.x64.exe
    quake3e.x86.exe
    quake3e-vulkan.x86.exe
    quake3e-vulkan.exe
    quake3e.exe
    cnq3-x64.exe
    cnq3-x86.exe
    ioquake3.x86_64.exe
    ioquake3.x86.exe
    ioquake3.exe
    spearmint.x86_64.exe
    spearmint.x86.exe
    spearmint.exe
    quake3.exe
) do (
    if exist "%%E" (
        start "" "%%E" +set fs_game missionpack2 %*
        goto QUIT
    )
)

:: Fallback if absolutely no engine is found
echo [ERROR] No suitable Quake 3 executable found in: %cd%
echo Press any key to exit . . .
pause > NUL
goto QUIT

:QUIT
cd /d "%oldcd%"
endlocal