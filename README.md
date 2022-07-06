# Teams

## A network project based on the Microsoft Teams application

The purpose of this project was to reproduce how Teams is working and to learn socket-programming.
This network project made us learn about mutli-clients handling or communication protocol implementation.

With our Teams, you can communicate with other users; create teams, channels, threads and replies; subscribe to specific teams you want to have events from and many others features.

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
I made this project with 1 teammate :
- [Simon LeFourn](https://github.com/simlf)

## Features
- ``` /help ``` : show help
- ``` /login ["username"] ``` : log yourself to teams
- ``` /logout ``` : disconnect yourself from the server
- ``` /users ``` : display the list of all users using teams currently
- ``` /user ["user_uuid"] ``` : display information about a specific user
- ``` /send ["user_uuid"] ["message_body"] ``` : send a message to a specific user
- ``` /messages ["user_uuid"] ``` : display the list of all exchanges with a user
- ``` /subscribe ["team_uuid"] ``` : subscribe to the events if a team and its sub directories
- ``` /unsubscribe ["team_uuid"]  ``` : unsubscribe from a specific team
- ``` /use ["team_uuid"] | ["channel_uuid"] | ["thread_uuid"] ``` : user specify context team/channel/thread
- ``` /create ["team_name"] ["team_description"] ``` : create a new team, you can do it only at root
- ``` /create ["channel_name"] ["channel_description"] ``` : create a new channel, you can do it only in a team
- ``` /create ["thread_name"] ["thread_description"] ``` : create a new thread, you can do it only in a channel
- ``` /create ["reply_body"] ``` : create a new reply, you can do it only in a thread
- ``` /info ``` : depending on context : root, team, channel, thread
