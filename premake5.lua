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

group "Dependencies"

group ""

include "Spark"
include "SandBox"