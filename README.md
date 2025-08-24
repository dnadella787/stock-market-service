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
./cmake-build-debug/smsrv --db-host localhost --db-port 5432 --db-name stock-db --db-user localdbusr --db-pwd localdbpwd
```

to start local db:
```bash
cd postgresdb/local-docker
docker compose up # add -d for detached mode 
```

to initialize local DB with some basic data and schema:
```bash 
psql -h localhost -p 5432 -U localdbusr -d stock-db -f postgresdb/scripts/sql/init.sql
```

to access db:
```bash 
psql -h localhost -p 5432 -U localdbusr -d stock-db
```