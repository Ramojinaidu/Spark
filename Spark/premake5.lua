project "Spark"
kind "StaticLib"
language "C++"
cppdialect "C++17"
staticruntime "off"

targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

pchheader "pch.h"
pchsource "pch.cpp"

files
{
    "Src/**.h",
    "Src/**.cpp",
}

defines
{
    "GLFW_INCLUDE_NONE"
}

includedirs
{
    "Src",
    "%{IncludeDirs.GLFW}",
	"vendor/spdlog/include"

}

links
{
    "GLFW",
}


filter "system:linux"
systemversion "latest"

defines
{
}

links
{
}

filter "configurations:Debug"
defines "SPARK_DEBUG"
runtime "Debug"
symbols "on"

links
{
}

filter "configurations:Release"
defines "SPARK_RELEASE"
runtime "Release"
optimize "on"

links
{
}