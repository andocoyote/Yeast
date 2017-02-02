#Best nmake tutorial: http://www.bogotobogo.com/cplusplus/make.php
INCS=\

# Specify the location to my SDK libs (e.g. DbgHelp.Lib)
LIBS="c:\Program Files (x86)\Windows Kits\10\Lib\10.0.14393.0\um\x86\" 
	
CC=cl
CFLAGS=/c /EHsc /Od /MTd
#CFLAGS=/c /EHsc /Od
LDFLAGS=/link /LIBPATH:$(LIBS) /verbose:lib /debug
SOURCES=main.cpp yeast.cpp
OBJECTS=$(SOURCES:.cpp=.obj)
EXECUTABLE=main.exe

#Uncomment the following to enable debugging
DBGFLAGS=/Zi

all: $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(DBGFLAGS) $(OBJECTS) -Fe$@ $(LDFLAGS)

.cpp.obj:
	$(CC) $(CFLAGS) $< -Fe$@

clean:
   del *.exe *.obj *.pdb *.ilk