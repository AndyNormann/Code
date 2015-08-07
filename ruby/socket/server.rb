require 'socket'

server = TCPServer.open(1500)

loop{
    client = server.accept
    client.puts("Connection established")
    client.puts("Closing")
    client.close
}
