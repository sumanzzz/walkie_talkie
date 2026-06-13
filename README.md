# WALKIE TALKIE

A multiplayer social sandbox built using **C++**, **Raylib**, **Winsock2**, and **Blender**.

Walkie Talkie is a real-time multiplayer project where players control bunny avatars in a shared 3D environment. Players can move freely, rotate relative to the camera, communicate through synchronized chat bubbles, and see other connected players in real time.

The primary goal of this project was to gain hands-on experience with:

* Multiplayer networking
* Client-server architecture
* Real-time state synchronization
* 3D rendering with Raylib
* Asset creation and integration using Blender
* UI and gameplay system design

---

# Overview

## Features

* Real-time multiplayer movement synchronization
* Camera-relative player movement
* Remote player rendering
* Username synchronization
* Global chat system
* Floating chat bubbles
* Player disconnect handling
* Custom 3D bunny avatar
* Client-server architecture using TCP sockets

## Technologies Used

* C++
* Raylib
* Winsock2
* Blender
* STL (unordered_map, vector, thread, string)

---

# Network Architecture

The project follows a **client-server architecture**.

Each client sends its player state to the server. The server receives this information and broadcasts it to all connected clients. Every client then creates and updates remote player representations using the received data.

### Synchronized Data

* Position
* Rotation
* Username
* Chat Messages
* Connection / Disconnection Events

### Architecture Diagram

*Insert Network Architecture Diagram Here*

### Server Responsibilities

* Accept incoming client connections
* Assign unique player IDs
* Receive player state packets
* Broadcast packets to connected clients
* Handle player disconnections
* Relay chat messages

### Client Responsibilities

* Capture player input
* Send movement updates
* Send chat messages
* Receive remote player data
* Render remote players
* Display usernames and chat bubbles

---

# Character Design

The player avatar used in Walkie Talkie was created in Blender and exported as a GLB model.

The objective was to create a lightweight and easily recognizable character that could be rendered efficiently while still giving the project a unique identity.

### Asset Pipeline

Blender Model
↓
GLB Export
↓
Raylib Model Loading
↓
Networked Multiplayer Character

### Bunny Model

*Insert Blender Bunny Screenshot Here*

---

# Implementation

## Multiplayer Movement

Each client periodically sends its current position and rotation to the server.

The server broadcasts this information to all connected clients.

Remote clients receive the data and update remote player representations accordingly.

### Movement Synchronization Flow

Client
↓
Movement Packet
↓
Server
↓
Broadcast
↓
Remote Clients
↓
Remote Player Update

---

## Username Synchronization

Each player provides a username when connecting.

The username is transmitted to the server and distributed to all connected clients.

Usernames are rendered above each player's bunny avatar.

---

## Chat System

Players can communicate using a global chat system.

Messages are sent to the server and relayed to all connected clients.

Each player's most recent message appears inside a temporary chat bubble positioned near their avatar.

### Chat System Diagram

*Insert Chat Mechanic Blueprint Here*

### Chat Behaviour

1. Each player has a chat bubble that displays their most recent message to other connected players.
2. The chat input box remains inactive until the player presses the Enter key.
3. After typing a message and pressing Enter, the message is sent to the server and displayed in the sender's chat bubble on all remote clients.
4. A chat bubble appears when a message is sent and automatically disappears after 5 seconds.
5. The chat input box is displayed at the bottom of the screen.

---

## Remote Player Rendering

Every client maintains a collection of remote players.

For each remote player:

* Position is synchronized through network packets.
* Rotation is synchronized relative to the player's camera orientation.
* Username is rendered above the avatar.
* Chat messages are displayed through temporary speech bubbles.

---

## Connection Handling

The server automatically detects client disconnections.

When a player disconnects:

* A disconnect packet is generated.
* Connected clients remove the corresponding remote player.
* The game world updates without requiring a restart.

---

# Final Output

The final result is a fully functional multiplayer prototype where multiple players can:

* Join the same session
* Move around a shared 3D environment
* See other connected players
* View synchronized usernames
* Exchange real-time chat messages
* Observe player rotations and movements in real time

### Gameplay Screenshot

*Insert In-Game Screenshot Here*

---

# Future Improvements

* Movement interpolation and smoothing
* Dedicated server deployment
* Lobby and menu system
* ImGui-based UI
* Chat history panel
* Emotes and player expressions
* Improved character animations
* Voice communication support
* Enhanced visual effects and lighting

---

# Learning Outcomes

This project provided practical experience with:

* Socket programming
* Multiplayer game architecture
* Client-server communication
* Real-time synchronization
* 3D graphics programming
* Asset creation workflows
* Game system design
* Debugging distributed systems

Walkie Talkie serves as a foundation for future multiplayer game development projects and demonstrates the integration of networking, graphics, and gameplay systems into a cohesive application.
