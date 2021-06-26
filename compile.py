import os,json

ProjectLibsPath="src\\libs\\"
rootPath=os.getcwd()

config = json.loads(open("compile_config.json").read())

SDL_include_path = config["SDL_include"]
SDL_lib_path = config["SDL_lib"]

if SDL_include_path[0] == ".":
    SDL_include_path = os.path.join(rootPath,SDL_include_path[2:])

if SDL_lib_path[0] == ".":
    SDL_lib_path = os.path.join(rootPath,SDL_lib_path[2:])

compiled = []

os.chdir(ProjectLibsPath)

for file in os.listdir(path="."):
    if(file[file.rfind("."):] == ".cpp"):
        print(file)
        os.system('g++ -c {file} -I"{include}" -L"{lib}" -lSDL2main -lSDL2'.format(file=file,include=SDL_include_path,lib=SDL_lib_path))
        compiled.append(os.path.join(rootPath,ProjectLibsPath+file[:file.rfind(".")] + ".o"))

os.chdir(rootPath)

finalCompileCommand = 'g++ {libs} -I"{include}" -L"{lib}" main.cpp -lSDL2main -lSDL2 -o main -municode'.format(libs=" ".join(compiled),include=SDL_include_path,lib=SDL_lib_path)
print(finalCompileCommand)

os.system(finalCompileCommand)