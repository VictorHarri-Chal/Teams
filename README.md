# Teams

## A network project based on the Microsoft Teams application

The purpose of this project was to reproduce how Teams is working and to learn socket-programming.
This network project made us learn about mutli-clients handling orcommunication protocol implementation.

## Usage
``` zsh
make
```

- Open a terminal and execute this command in order to run the server on the specified port.
``` zsh
./my_teams_server <PORT>
```
- Open one other terminal(s) (or many others) and execute this command in order to run a client on the specified IP adress and port.
``` zsh
./my_teams_cli <IP> <PORT>
```
