##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab3_Taken
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/An Phan/Documents/3"
ProjectPath            :="C:/Users/An Phan/Documents/3/Lab3_Taken"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=An Phan
Date                   :=10/04/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Lab3_Taken.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/racer.cpp$(ObjectSuffix) $(IntermediateDirectory)/sensor.cpp$(ObjectSuffix) $(IntermediateDirectory)/timeStamp.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/An Phan/Documents/3/Lab3_Taken/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/racer.cpp$(ObjectSuffix): racer.cpp $(IntermediateDirectory)/racer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/An Phan/Documents/3/Lab3_Taken/racer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/racer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/racer.cpp$(DependSuffix): racer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/racer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/racer.cpp$(DependSuffix) -MM racer.cpp

$(IntermediateDirectory)/racer.cpp$(PreprocessSuffix): racer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/racer.cpp$(PreprocessSuffix) racer.cpp

$(IntermediateDirectory)/sensor.cpp$(ObjectSuffix): sensor.cpp $(IntermediateDirectory)/sensor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/An Phan/Documents/3/Lab3_Taken/sensor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sensor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sensor.cpp$(DependSuffix): sensor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sensor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/sensor.cpp$(DependSuffix) -MM sensor.cpp

$(IntermediateDirectory)/sensor.cpp$(PreprocessSuffix): sensor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sensor.cpp$(PreprocessSuffix) sensor.cpp

$(IntermediateDirectory)/timeStamp.cpp$(ObjectSuffix): timeStamp.cpp $(IntermediateDirectory)/timeStamp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/An Phan/Documents/3/Lab3_Taken/timeStamp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/timeStamp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/timeStamp.cpp$(DependSuffix): timeStamp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/timeStamp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/timeStamp.cpp$(DependSuffix) -MM timeStamp.cpp

$(IntermediateDirectory)/timeStamp.cpp$(PreprocessSuffix): timeStamp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/timeStamp.cpp$(PreprocessSuffix) timeStamp.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


