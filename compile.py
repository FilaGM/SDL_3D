import os

libsPath="src\\libs\\"
rootPath=os.getcwd()

compiled = []

os.chdir(libsPath)

for file in os.listdir(path="."):
    if(file[file.rfind("."):] == ".cpp"):
        print(file)
        os.system('g++ -c {file} -I"D:\libraries\SDL2\\x86_64-w64-mingw32\include" -L"D:\libraries\SDL2\\x86_64-w64-mingw32\lib" -lSDL2main -lSDL2'.format(file=file))
        compiled.append(os.path.join(rootPath,libsPath+file[:file.rfind(".")] + ".o"))

os.chdir(rootPath)

finalCompileCommand = 'g++ {libs} -I"D:\libraries\SDL2\\x86_64-w64-mingw32\include" -L"D:\libraries\SDL2\\x86_64-w64-mingw32\lib" main.cpp -lSDL2main -lSDL2 -o main -municode'.format(libs=" ".join(compiled))
print(finalCompileCommand)

os.system(finalCompileCommand)