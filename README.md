Hello welcome to our assignment x

---------------------------------

For ease of use and portability, the SDL2.dll libary is included 
WITHIN the assigment. This makes it easy to build the code whatever
computer you are using.

---------------------------------

Please build the code using the following:
g++ src/*.cpp -I include -I include/SDL2/include -L include/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -o complexity.exe

And then of course run with:
./app.exe

---------------------------------

Also note the possible presence of the CMakeLists.txt file.
This can be used if using cmake to help compile!
