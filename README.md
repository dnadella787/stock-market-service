This is a simple backend to get data about the NYSE and NASDAQ exchanges as well as the securities listed on them. (WIP)

generating gRPC and Protobuf files:
```bash
find ./api/proto/ -name "*.proto" -exec ~/Downloads/protoc-31.1-osx-aarch_64/bin/protoc --proto_path=./api/proto \
       --cpp_out=./api \
       --grpc_out=./api \
       --plugin=protoc-gen-grpc=/opt/homebrew/Cellar/grpc/1.74.1/bin/grpc_cpp_plugin {} +
```

to start server:
```bash
export CONFIG_LOCATION={PathToRepo}/stock-market-service/src/api/config
./cmake-build-debug/src/api/stock-market-api --env local 
```

to start local db for first time:
```bash
cd postgresdb/local-docker
docker compose up # add -d for detached mode 
```

to start up local db every other time
```bash 
docker start stock-db
```

to initialize local DB with some basic data and schema:
```bash 
psql -h localhost -p 5432 -U localdbusr -d stock-db -f postgresdb/scripts/sql/init.sql
```

to access db:
```bash 
psql -h localhost -p 5432 -U localdbusr -d stock-db
```

to build:
```bash
mkdir build 
cd build
CMAKE_POLICY_VERSION_MINIMUM=3.5 cmake ..
cmake --build .
```

to run clang-format:
```bash
find ./src -type f \( -name "*.h" -o -name "*.cpp" \) -exec clang-format -i {} +
```

to run clang-tidy:
```bash
find ./src -type f \( -name "*.h" -o -name "*.cpp" \) | xargs -I{} /opt/homebrew/opt/llvm/bin/clang-tidy {} -p build --header-filter='^./src/.*'
```