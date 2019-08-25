
set abi=armeabi-v7a

set build_dir=build\%abi%
if exist %build_dir% rd %build_dir%
md %build_dir%
cd %build_dir%

%ANDROID_SDK_HOME%/cmake/3.10.2.4988404/bin/cmake ^
  -DANDROID_ABI=%abi% ^
  -DANDROID_NDK=%ANDROID_SDK_HOME%/ndk-bundle ^
  -DCMAKE_BUILD_TYPE=Debug ^
  -DCMAKE_TOOLCHAIN_FILE=%ANDROID_SDK_HOME%/ndk-bundle/build/cmake/android.toolchain.cmake ^
  -DANDROID_NATIVE_API_LEVEL=21 ^
  -DANDROID_TOOLCHAIN=clang -DCMAKE_GENERATOR="Ninja" ^
  -DCMAKE_MAKE_PROGRAM=%ANDROID_SDK_HOME%/cmake/3.10.2.4988404/bin/ninja ^
  ../..

%ANDROID_SDK_HOME%/cmake/3.10.2.4988404/bin/ninja

cd ../..