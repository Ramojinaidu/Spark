project "Spark"
kind "StaticLib"
staticruntime "off"

targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

pchheader "pch.h"
pchsource "pch.cpp"

files
{
    "Src/**.cpp",
    "Src/**.h",
	
}


includedirs
{
    "Src",
	"%{IncludeDirs.GLFW}",
	"vendor/spdlog/include",
}

defines
{
	"GLFW_INCLUDE_NONE",
}

links
{
	"GLFW"
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
