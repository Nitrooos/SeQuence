solution "Genome Sequencing"

    project "Converter"
        configurations { "debug", "release" }
            language "C++"
            kind "ConsoleApp"
            files "src/*.cpp"
            buildoptions { "-w -Wall -std=c++11" }
            linkoptions { "" }
            objdir "obj/src"

        configuration { "debug" }
            targetdir "debug"
            flags "Symbols"

        configuration { "release" }
            targetdir "release"
            flags "OptimizeSpeed"

        if _ACTION == "clean" then
            os.rmdir("debug")
            os.rmdir("release")
            os.rmdir("obj")
        end

    project "ConverterTest"
        configurations { "debug" }
            language "C++"
            kind "ConsoleApp"
            files "test/*.cpp"
            buildoptions { "-w -Wall" }
            linkoptions { "-lcppunit" }
            objdir "obj/test"
        
        configuration { "debug" }
            targetdir "debug"
            flags "Symbols"
