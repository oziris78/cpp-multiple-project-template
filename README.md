

# About The Template

A Microsoft Visual Studio solution setup demonstrating both static and dynamic linking in C++ using GLFW and our own static libraries (projects).



# Tutorials Used

I followed these tutorials to create this template:

<a href="https://www.youtube.com/watch?v=or1dAmUO8k0">
    <img width="320" src="http://img.youtube.com/vi/or1dAmUO8k0/maxresdefault.jpg">
</a>

<a href="https://www.youtube.com/watch?v=pLy69V2F_8M">
    <img width="320" src="http://img.youtube.com/vi/pLy69V2F_8M/maxresdefault.jpg">
</a>

<a href="https://www.youtube.com/watch?v=Wt4dxDNmDA8">
    <img width="320" src="http://img.youtube.com/vi/Wt4dxDNmDA8/maxresdefault.jpg">
</a>
<br><br>
<b>
Before you watch these videos or read this tutorial make sure to take a look at <a href="https://github.com/oziris78/cpp-project-template">here</a> 
since this tutorial will use things that were explained in there.
</b>


# C++ and Static/Dynamic Libraries

C++ libraries usually have two parts to them: includes (header files) and libraries. (.lib or .dll files) <br>
Not all libraries will let you add them both statically and dynamically but the popular ones usually have both of these options for you. <br><br>

| Static Libraries  | Dynamic Libraries  |
| ----------------- | ----------------- |
| binaries / source code to build the binaries  | .dll files |
| put directly into your .exe file during compile time  | .exe file searches for them in it's root directory during runtime |
| technically faster because of compiler optimizations  | slower than statically linking |
| whole code is inside one .lib file | pointers are inside a .lib file and implementations are inside a .dll file |



# Adding our static libraries

1- Setup a solution with one project in it (like you did in <a href="https://github.com/oziris78/cpp-project-template">here</a>) <br>
2- Double click on the solution's name > add > new project > empty project <br>
3- Go to properties of your new static library project and in `General` change the `Configuration Type` to `Static library (.lib)` (don't forget to do this for all configurations and all platforms) <br>
6- In your main project go to properties, in `C/C++ > General` add `$(SolutionDir)<YOUR_STATIC_PROJECT_NAME>\src;` to `Additional Include Libraries`.

Example: `$(SolutionDir)MyStaticLibrary\src;` <br>

7- Right click on your main project's name > add > reference > add your static library <br><br>


# Adding other static libraries

1- Setup a solution with one project in it (like you did in <a href="https://github.com/oziris78/cpp-project-template">here</a>) <br>
2- Well, go get your desired library's binaries so you can add them... In this example I will use GLFW to demonstrate. <br>
3- Create a sibling folder to your main project's folder (the directory of your solution) and name it `dependencies`. (or anything you want) <br>
4- Create a folder called `GLFW` in `dependencies`. (create dependencies/GLFW folder) <br>
5- Put the `include` and `lib-vc2019` folders in `dependencies/GLFW`. <br>
6- In your main project go to properties, in `C/C++ > General` add `$(SolutionDir)dependencies\GLFW\lib-vc2019` to `Additional Library Directories`. <br>
7- In your main project go to properties, in `Linker > General` add `$(SolutionDir)dependencies\GLFW\include;` to `Additional Include Libraries`.  <br>
8- In your main project go to properties, in `Linker > Input` add `glfw3.lib;` to `Additional Dependencies`. <br><br>


# Adding dynamic libraries

Mostly same as adding a static library, the only things you'll need to do different are these: <br>

1- Instead of adding `glfw3.lib` you'll add `glfwdll.lib` in `Linked > Input` for your main project. (This tells your application the pointers) <br>
2- After building your .exe file in that file's root directory you'll need to put your .dll files. So for this example we'll need to copy paste `glfw3.dll` into `$(SolutionDir)bin\x64\Debug` since our .exe is in there. (I did a x64 Debug build) <br><br>


# Adding static libraries using source code

1- Pick a library and get it's source code (header files and cpp files), for this example I will use ImGUI.
2- Create a `vendor` folder in your `src` folder and create an `imgui` folder inside vendor folder. (Create `src/vendor/imgui`)
3- Put your cpp files inside that imgui folder
4- Create a folder called `imgui` inside `dependencies` and then put your header files in there within a folder called `include`
5- In your main project go to properties, in `C/C++ > General` add `$(SolutionDir)dependencies\imgui\include;` to `Additional Library Directories`. <br>
6- In your main project go to properties, in `Linker > Input` add `opengl32.lib;` to `Additional Dependencies`. (This step is needed because of Imgui, you might not need this one depending on the library you're using) <br><br>


# Final Results

??? For MainProject:

General:

| Option  | Will Be Changed To  |
| ------------- | ------------- |
| Output Directory  | `$(SolutionDir)bin\$(Platform)\$(Configuration)\`  |
| Intermediate Directory  | `$(SolutionDir)bin\intermediates\$(Platform)\$(Configuration)\`  |
| Configuration Type  | Application (.exe) |

C/C++ > General

| Option  | Will Be Changed To  |
| ------------- | ------------- |
| Additional Include Directories  | `$(SolutionDir)MyStaticLibrary\src;$(SolutionDir)dependencies\GLFW\include;$(SolutionDir)dependencies\imgui\include;`  |

Linker > General

| Option  | Will Be Changed To  |
| ------------- | ------------- |
| Additional Library Directories  | `$(SolutionDir)dependencies\GLFW\lib-vc2019`  |

Linker > Input

| Option  | Will Be Added To The Beginning  |
| ------------- | ------------- |
| Additional Dependencies  | `glfw3.lib;opengl32.lib;`  |

<br><br>
??? For MyStaticLibrary:

General:

| Option  | Will Be Changed To  |
| ------------- | ------------- |
| Configuration Type  | Static library (.lib) |


