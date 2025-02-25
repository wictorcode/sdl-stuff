# SDL Stuff

Just messing around with SDL3.

Stuff I made so far

- Event manager to bind SDL Events and Keycodes to callback functions (addEventListener)
- Input Manager; it uses the previously made Event Manager. Allows to predefine actions and to map & remap to given keys

## Building & Running
### Building
To build/compile the program automatically , must be on Windows to run `./build.bat` (Planning to switch to Lua)

The libraries are not included in the repo so it won't work, but I have included the exact versions of each library at the end of the file.

If you do manage to run it, you should just see an empty 500px by 500px window. Nothing crazy.

### Running
If you built it yourself using the given batch script, the program will automatically ask if you want to run it.

If you already compiled it and want to run it, go to [the bin folder](https://github.com/wictorcode/sdl-stuff/tree/main/bin)

## Libraries & External Dependencies used
I did not put the libraries inside of the project because of size issues. So here is the list of libraries used with the exact version.

The full libraries and binaries are included in the releases.

- [SDL v3.2.4 devel mingw](https://github.com/libsdl-org/SDL/releases/tag/release-3.2.4)
- [Dear ImGui v1.91.8](https://github.com/ocornut/imgui/releases/tag/v1.91.8)  **(Not Currently used, but you have the compilation lines in the batch file)**
