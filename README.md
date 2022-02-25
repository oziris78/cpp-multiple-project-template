

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


# Steps



# Final Results

⭕ For MainProject:

General:

| Option  | Will Be Changed To  |
| ------------- | ------------- |
| Output Directory  | `$(SolutionDir)bin\$(Platform)\$(Configuration)\`  |
| Intermediate Directory  | `$(SolutionDir)bin\intermediates\$(Platform)\$(Configuration)\`  |
| Configuration Type  | Application (.exe) |

C/C++ > General

| Option  | Will Be Changed To  |
| ------------- | ------------- |
| Additional Include Directories  | `$(SolutionDir)MyStaticLibrary\src; $(SolutionDir)dependencies\GLFW\include;`  |

Linker > General

| Option  | Will Be Changed To  |
| ------------- | ------------- |
| Additional Library Directories  | `$(SolutionDir)dependencies\GLFW\lib-vc2019`  |

Linker > Input

| Option  | Will Be Added To The Beginning  |
| ------------- | ------------- |
| Additional Dependencies  | `glfw3.lib;`  |

<br><br>
⭕ For MyStaticLibrary:

General:

| Option  | Will Be Changed To  |
| ------------- | ------------- |
| Configuration Type  | Static library (.lib) |


