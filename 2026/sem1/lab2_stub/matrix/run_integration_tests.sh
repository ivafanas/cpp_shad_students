
echo "build docker"
cd docker
docker build -t cpp_shad_testing/cpp_shad_testing:1.0 -f Dockerfile .
cd ..

echo "run docker"
docker run --rm --name=cpp_shad_testing --mount type=bind,source="${PWD}",target=/src cpp_shad_testing/cpp_shad_testing:1.0 bash -lc "python3 ./src/docker/run_tests.py"
