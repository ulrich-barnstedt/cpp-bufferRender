## cpp-bufferRender
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=flat&logo=cmake&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=flat&logo=windows&logoColor=white)
![Lines of code](https://img.shields.io/tokei/lines/github/ulrich-barnstedt/cpp-bufferRender?style=flat) 
![GitHub top language](https://img.shields.io/github/languages/top/ulrich-barnstedt/cpp-bufferRender?style=flat)
![Version](https://badgen.net/badge/library%20version/3.1/green)


_A CPP library for rendering text to the terminal, efficiently, on a buffer-mirror principle._  

### General info

The library is only tested on linux.  
Documentation is not really existent at this point in time.  
The code has been tested since v3, but flawless functionality is not guaranteed.
V2 has been tested more extensively but offers worse performance and is not maintained anymore.

### Libraries

- `CBR-util`
  - This library is used in both of the other libraries and provides generic functionality such as cursor movement and terminal interaction.
  - This library provides no functions for the end-user.
- `CBR-str`
  - The "original" library, which operates on string pointers and dynamic memory.
  - It has remained mostly unchanged since v2, even though it could be ported to use the template library.
  - The relevant headers for this library are
      - `/lib/str/exBufferRender.h`
        - Defines the "extended" API, with memory safety, and additional utility functions
      - `/lib/str/bufferRender.h`
        - The underlying raw renderer, with only the buffer and a render function.
        - Note: This API is not completely memory safe - the library only "owns" and automatically deletes pointers after renders, therefore overwriting cells may cause memory loss.
- `CBR-ext`
  - The current and recommended library, "v3".
  - Operates on custom classes, instantiating the class via template parameters.
  - Is not completely tested/error free.
  - The relevant headers for this library are
    - `/lib/ext/Base.h`
      - Provides the schema that all classes that are used in the template parameter **have to** derive from.
    - `/lib/ext/U_DCMP.h`
      - _U_DCMP - Utility Data CoMPare_
      - Provides the extended version of the library with a handful of utility functions.
    - `/lib/ext/DCMP.h`
      - _DCMP - Data CoMPare_
      - Provides the base functionality (renderer and data vectors), core class
      - _U_DCMP inherits from this class._

