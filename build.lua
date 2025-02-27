--[[

UNUSED & UNFINISHED
UNUSED & UNFINISHED
UNUSED & UNFINISHED
UNUSED & UNFINISHED
UNUSED & UNFINISHED
UNUSED & UNFINISHED
UNUSED & UNFINISHED
UNUSED & UNFINISHED

USE BUILD.BAT

]]

-- Change OPERATING_SYSTEM to the following, depending on your operating system
-- Windows = 1
-- Unix (Linux & MacOS) = 2
-- This is due to command line functions being different
local OPERATING_SYSTEM = 1

-- C with GCC = 1
-- C++ with G++ = 2
local LANGUAGE = 2

--===========================================================================================--
--===== MODULES =====-
local os_utils = require("build/utils")

-- for /R .\src %%f in (*.cpp) do (
--  g++ -c "%%f" -o ".\build\%%~nf.o" -I.\src -I.\lib\SDL\SDL3\include -I.\lib\imgui
-- )

os_utils.compile_file(OPERATING_SYSTEM, LANGUAGE, "src\\main.cpp")

--===========================================================================================--
--===== INCLUDE FILES/FOLDERS =====-

--===========================================================================================--
--===== COMPILING =====-


--===========================================================================================--
--===== LINKING =====-

--===========================================================================================--
--===== MISC (copy/move folders, etc..) =====-