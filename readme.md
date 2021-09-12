## cpp-bufferRender
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=flat&logo=cmake&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=flat&logo=windows&logoColor=white)
![Lines of code](https://img.shields.io/tokei/lines/github/ulrich-barnstedt/cpp-bufferRender?style=flat) 
![GitHub top language](https://img.shields.io/github/languages/top/ulrich-barnstedt/cpp-bufferRender?style=flat)
![Version](https://badgen.net/badge/library%20version/2.2/green)


_A CPP library for rendering text to the terminal, efficiently, on a buffer-mirror principle._  

**Note: The API is mostly undocumented, however due to the simplicity of the library, the relevant header files will be mostly self-explanatory.  
        Library is only tested on linux.**

### Relevant headers

- `/lib/exBufferRender.h`
  - Defines the "extended" API, with memory safety, and additional utility functions
- `/lib/bufferRender.h`
  - The underlying raw renderer, with only the buffer and a render function. 
  - Note: This API is not completely memory safe - the library only "owns" and automatically deletes pointers after renders, therefore overwriting cells may cause memory loss.

