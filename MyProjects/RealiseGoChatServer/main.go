package main

import (
	"fmt"
	"net"
	"bufio"
	"container/list"
	"github.com/prestonTao/upnp"
	"strconv"
)

var clients *list.List

func handlClient(socket net.Conn){
	for{
		buffer, err:=bufio.NewReader(socket).ReadString('\r')
		if err!=nil{
			fmt.Println("Пользователь отключился")
			socket.Close()
			return
		}
		fmt.Println(buffer)
		for i:=clients.Front();i!=nil; i=i.Next(){
			fmt.Fprint(i.Value.(net.Conn), buffer)
		}
	}
}
func main() {
	fmt.Println("Server started")
	clients=list.New()
	fmt.Println("Imput port server")
	var imput string
	fmt.Scanln(&imput)
	mapping := new(upnp.Upnp)
	port, _ := strconv.Atoi(imput)
	if err := mapping.AddPortMapping(port, port, "TCP"); err == nil {
		fmt.Println("Порт " + imput + " открыт")
	} else {
		fmt.Println("Ошибка")
	}

	imput = ":" + imput
	server, err := net.Listen("tcp", imput)
	if err!= nil{
		fmt.Printf("Error %s", err.Error())
		return
	}
	fmt.Printf("Сервер запущен, порт(%s)\n", imput)
	for {
		client, err:=server.Accept()
		if err!= nil{
			fmt.Printf("Error %s", err.Error())
			return
		}
		fmt.Printf("Подключился новый клиент: %s\n", client.RemoteAddr())
		fmt.Fprint(client, "Connected\r")
		clients.PushBack(client)
		go handlClient(client)
	}
}


