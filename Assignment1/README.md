#分布式网络作业1

环境运行

service rpcbind start
sudo service nfs-kernbel-server restart

预处理

rpcgen -C date.x

cc -o client client.c date_clnt.c -lnsl

cc -o serve -DRPC_SVC_FG server.c date_svc.c -lnsl

运行服务器
./server

运行客户端
./client localhost

