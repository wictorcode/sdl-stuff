@echo off
::======================================================
:: SETTINGS
::======================================================
set executable_name=program
::======================================================
:: COMPILATION
::======================================================
echo Compiling...

:: Create necessary directories if they don't exist
if not exist .\build mkdir .\build
if not exist .\bin mkdir .\bin
if not exist .\bin\assets mkdir .\bin\assets



:: COMPILE IMGUI (OH LAWD THATS A LOT)
:: COMPILE IMGUI (OH LAWD THATS A LOT)
:: COMPILE IMGUI (OH LAWD THATS A LOT)

:: commented out because i'm not using it right now

:: g++ -c ".\lib\imgui\imgui.cpp" -o ".\build\imgui.o" -I.\lib\imgui
:: g++ -c ".\lib\imgui\imgui_draw.cpp" -o ".\build\imgui_draw.o" -I.\lib\imgui
:: g++ -c ".\lib\imgui\imgui_tables.cpp" -o ".\build\imgui_tables.o" -I.\lib\imgui
:: g++ -c ".\lib\imgui\imgui_widgets.cpp" -o ".\build\imgui_widgets.o" -I.\lib\imgui
:: g++ -c ".\lib\imgui\imgui_demo.cpp" -o ".\build\imgui_demo.o" -I.\lib\imgui
:: g++ -c ".\lib\imgui\backends\imgui_impl_sdl3.cpp" -o ".\build\imgui_impl_sdl3.o" -I.\lib\imgui -I.\lib\SDL\SDL3\include
:: g++ -c ".\lib\imgui\backends\imgui_impl_sdlrenderer3.cpp" -o ".\build\imgui_impl_sdlrenderer3.o" -I.\lib\imgui -I.\lib\SDL\SDL3\include







:: Loop over all .c files in the src folder recursively
:: Add include directory with -I flag
:: if you're writing in C, change all of the '.cpp' to '.c' and put 'gcc' instead of 'g++'
:: To respect C99 standard, add the '-std=c99' flag to the compilation
for /R .\src %%f in (*.cpp) do (
    g++ -c "%%f" -o ".\build\%%~nf.o" -I.\src -I.\lib\SDL\SDL3\include -I.\lib\imgui
)

:: Link all object files into the final bin
:: Add -lgdi32 for Windows GDI functions
g++ .\build\*.o -o .\bin\%executable_name%.exe -L.\lib\SDL\SDL3\lib -lSDL3 -lgdi32

:: Copy SDL3.dll to bin directory
copy .\lib\SDL\SDL3\bin\SDL3.dll .\bin\
copy .\assets\ .\bin\assets\



echo Compilation finished!

::======================================================
:: USER INPUT & RUN PROGRAM
::======================================================
set /p userChoice=Run? [y] 

if /i "%userChoice%"=="y" (
    echo :::::::::::::::::::::::::::::::::::::::::::::
    echo :::::::::::::::::: RUNNING ::::::::::::::::::
    echo :::::::::::::::::::::::::::::::::::::::::::::
    .\bin\%executable_name%.exe
    exit
)