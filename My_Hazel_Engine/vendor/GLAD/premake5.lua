project "GLAD"
    kind "StaticLib"
    language "C"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c"
    }

    includedirs
    {
        "include"
    }


    filter "system:windows"--windows平台的配置
        staticruntime "On"
        systemversion "latest"

    filter {"system:windows","configurations:Release"}
        buildoptions "/MT"