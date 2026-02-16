workspace "Spark"
architecture "x86_64"
language "C++"
cppdialect "C++17"
startproject "SandBox"
configurations
{
    "Debug",
    "Release",
    "Dist"
}


outputdir = "%{cfg.buildcfg}-%{cfg.system}"

IncludeDirs = {}
IncludeDirs["GLFW"] = "%{wks.location}/Spark/vendor/GLFW/include"

group "Dependencies"
include "Spark/vendor/GLFW"
group ""

include "Spark"
include "SandBox"