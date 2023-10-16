---
description: Infinity Void Unreal Engine SDK - Getting Started
cover: >-
  https://images.unsplash.com/photo-1542751371-adc38448a05e?crop=entropy&cs=tinysrgb&fm=jpg&ixid=MnwxOTcwMjR8MHwxfHNlYXJjaHwzfHxnYW1pbmd8ZW58MHx8fHwxNjYzOTI1MzI5&ixlib=rb-1.2.1&q=80
coverY: 0
---

# Level Setup

Certainly, here's an example of documentation based on the provided instructions for creating a new map and setting up certain gameplay elements:

## New Map and Gameplay Setup Documentation

### Introduction

This documentation provides step-by-step instructions for creating a new map in your game development project and setting up various gameplay elements to enhance the player experience. Follow these steps to create a new map and configure essential elements within it.

### Creating a New Map

#### Step 1: Create a New Map

1. Inside your project's Content folder, create a new folder named "Maps" to organize your map assets.
2. To create a new map, follow these steps:
   * Click on "File" in the menu.
   * Select "New Level."
   * You'll be presented with various options; choose the one that suits your project's needs. For a large world, select "Open World," and for a small scene, choose the "Basic Level" option.
3. After creating your level, ensure that you save it and give it a meaningful name.

#### Step 2: Set Default Server Map

1. In your project settings, navigate to the "Maps and Modes" section.
2. Update the "Server Default Map" setting with the map you've just created. This ensures that your new map is set as the default server map for your project.

### Adding Gameplay Elements

#### Step 3: Add Player Start

1. Open your newly created map.
2. To add a player start point, follow these steps:
   * Choose the "Place Actors" panel.
   * Select "Player Start" from the available options.
   * Place the player start in your scene. This determines where players will spawn in your map.

#### Step 4: Configuring the Crosshair

1. Open the Level Blueprint for your map.
2. Add the following script to ensure that players see a crosshair while playing.

#### Step 5: Adding a Close UI Actor

1. From the Content Browser, select the "Close\_UI" actor.
2. Place it in your scene. The purpose of this actor is to communicate with the frontend to close the loading screen.
3. You can adjust the delay by changing the delay value in the actor's details.

#### Step 6: Linking to the Lobby Map

1. Navigate to the "Lobby" map, located in the plugins folder.
2. In the "Outline," select "BP\_InfinityVoidSDK" and go to "Details."
3. In the "Gameplay Level" field, choose the map you've just created. This links your new map to the lobby map.

#### Step 7: Adding an Exit Volume (Optional)

* For a more immersive experience, you can add a volume actor called "BP\_Exit." Placing this actor and configuring the volume inside it will allow players to return to the city if they enter this designated area.

### Making Elements Interactable

#### Step 8: Making Elements Interactable

* If you want to make in-game objects interactable, use the "BP\_InteractableBase" actor. Create a child class from it, modify the static mesh within the actor, and add interaction logic to the event graph.
* To add interaction functionality to any other class, like a pawn, add the "IVInterface" to it and follow the same interaction logic.

### Conclusion

You have successfully created a new map and configured essential gameplay elements to enhance the player experience in your project. Save your changes and test your map to ensure everything works as intended. For further assistance or troubleshooting, refer to your project's documentation or consult the development platform you are using.

Thank you for using our tools and plugins, and best of luck with your game development project!
