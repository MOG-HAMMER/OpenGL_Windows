OpenGL Study for a 3D modeling/viewer application
==================================================


Here we are gonna try to create a 3D application using the latest OpenGL 4.0-4.4 graphics layer API.

We will make use of Visual Studio 2013 C++ features

Choice of windowing API can be:


FreeGlut: probably one of the best windowing manager, but closer to windows.h

SDL2.0: Easier to use than FreeGlut, and has much more feature that cover more than graphics. Has support for DirectX API.

Windows.h (no requirement of making the software portable, will probably use #define statements for different platform compilers like GCC, VC11++, LLVM, depending on the IDE used. The most tedious to use, since it is pretty low-level programming, but probably the most thourough set of features, that should obviously cover anything possible to create Windows styles windows. Recommended to any wannabe developper that want to learn what goes on under the hood. Fun to use, and it comes with the benefit of coming with the VS IDE by default. You will however need another OpenGL library collection to be able to program anything higher than OpenGL 1.1 (which is the default Windows OpenGL API version, the one that wasn't open source). 

wxWidgets: The easiest one to use, you create windows withing only a handfull of lines of codes (recommended)

Qt: did not use, but I intend to also learn that one.

And there is many more, we just have to make sure the one we choose has the 

Obviously, to get the most out of OpenGL latest features, we will use the latest OpenGL library available.

GLEW seems to be the most complete; it contains Windows/Mac version (GL/gl.h, GL/glu.h), wgl, and glx, so we cover most of OSes. It also contains ES versions of OpenGL for mobile and ARM based devices.

Mainly, to keep from compatibility issues, and to have a standard IDE compiler and linker configuration, we will stick to Visual Studio/Visual Studio Express 2013 developement IDE, which in my opinion is the most complete solution for this project. VS 2013 have very easy out-of-the-box git and team foundation repository setup. As of 2013 release, any dev can now create for free an account on team foundation, only requires Express versions of VS 2013 and a Microsoft Live account.

OS requirement: obviously we will only support Windows 7 SP1, Windows 8, and Windows 8.1 editions of Windows.

We will provide support for OSX (latest version), and also the most recent Linux Ubuntu distro; by specifying this we can make sure that we will not encounter compatibility problems concerning the OpenGL API version installed on most popular OSes.
