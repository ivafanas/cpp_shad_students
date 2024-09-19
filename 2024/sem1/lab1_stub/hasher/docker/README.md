
Build docker image for testing environment.

```
docker build -t cpp_shad_testing/cpp_shad_testing:1.0 -f Dockerfile .
```

Launch testing environment.

```
docker run -it --rm --name=cpp_shad_testing --mount type=bind,source="${PWD}/..",target=/src cpp_shad_testing/cpp_shad_testing:1.0 bash 
```

